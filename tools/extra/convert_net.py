import sys
sys.path.append('../../python/')
import os
from caffe import pycaffe
from caffe.proto import caffe_pb2
from google.protobuf import text_format
import cPickle as pickle

class CudaConvNetReader(object):
    def __init__(self, net, blobs=False):
        self.net = pickle.load(open(net))
        self.name = os.path.basename(net)

    neurontypemap = {'relu': 'relu',
                     'logistic': 'sigmoid',
                     'dropout': 'dropout'}

    poolmethod = {
        'max': caffe_pb2.LayerParameter.MAX,
        'avg': caffe_pb2.LayerParameter.AVE 
    }

    def read(self):
        layers = []
        for i, layer in enumerate(self.net):
            layertype = layer['type'].split('.')[0]
            readfn = getattr(self, 'read_' + layertype)

            layerconnection = {}
            layerconnection['layer'] = readfn(layer)
            layerconnection['top'] = [layer['name']]
            layerconnection['bottom'] = [l['name'] for l in layer.get('inputLayers', [])]

            layers.append(layerconnection)

        return {'name': self.name, 
                'layers': layers}

    def read_data(self, layer):
        return {'type': 'data',
                'name': layer['name']
                }

    def read_conv(self, layer):
        assert len(layer['groups']) == 1
        assert layer['filters'] % layer['groups'][0] == 0
        assert layer['sharedBiases'] == True

        return {'type': 'conv',
                'name': layer['name'],
                'num_output': layer['filters'],
                'weight_filler': {'type': 'gaussian',
                                  'std': layer['initW'][0]},
                'bias_filler': {'type': 'constant',
                                'value': layer['initB']},
                'pad': -layer['padding'][0],
                'kernelsize': layer['filterSize'][0],
                'group': 1,
                'stride': layer['stride'][0],
                #'blobs': None
                }

    def read_pool(self, layer):
        return {'type': 'pool',
                'name': layer['name'],
                'num_output': layer['outputs'],
                'pool': self.poolmethod[layer['pool']],
                'kernelsize': layer['sizeX'],
                'stride': layer['stride'],
                #'blobs': None
                }

    def read_fc(self, layer):
        return {'type': 'innerproduct',
                'name': layer['name'],
                'num_output': layer['outputs'],
                'weight_filler': {'type': 'gaussian',
                                  'std': layer['initW'][0]},
                'bias_filler': {'type': 'constant',
                                'value': layer['initB']},
                #'blobs': None
                }

    def read_softmax(self, layer):
        return {'type': 'softmax',
                'name': layer['name']}

    def read_cost(self, layer):
        # TODO recognise when combined with softmax and
        # use softmax_loss instead
        if layer['type'] == "cost.logreg":
            return {'type': 'multinomial_logistic_loss',
                    'name': layer['name']}

    def read_neuron(self, layer):
        assert layer['neuron']['type'] in self.neurontypemap.keys()
        return {'name': layer['name'],
                'type': self.neurontypemap[layer['neuron']['type']]}

    def read_cmrnorm(self, layer):
        return {'name': layer['name'],
                'type': "lrn",
                'local_size': layer['size'],
                # cuda-convnet sneakily divides by size when reading the
                # net parameter file (layer.py:1041) so correct here
                'alpha': layer['scale'] * layer['size'],
                'beta': layer['pow']
                }

    def read_rnorm(self, layer):
        pass

    def read_cnorm(self, layer):
        pass


def cudaconv_to_prototxt(cudanet):
    netdict = CudaConvNetReader(cudanet, blobs=False).read()
    protobufnet = dict_to_protobuf(netdict)
    return text_format.MessageToString(protobufnet)


# adapted from https://github.com/davyzhang/dict-to-protobuf/

def list_to_protobuf(values, message):
    '''parse list to protobuf message'''
    if values == []:
        pass
    elif isinstance(values[0],dict):#value needs to be further parsed
        for v in values:
            cmd = message.add()
            dict_to_protobuf(v,cmd)
    else:#value can be set
        message.extend(values)

def dict_to_protobuf(values, message=None):
    if message is None:
        message = caffe_pb2.NetParameter()

    for k,v in values.iteritems():
        if isinstance(v,dict):#value needs to be further parsed
            dict_to_protobuf(v,getattr(message,k))
        elif isinstance(v,list):
            list_to_protobuf(v,getattr(message,k))
        else:#value can be set
            setattr(message, k, v)

    return message