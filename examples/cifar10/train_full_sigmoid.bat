REM going to the caffe root
SET currentDirectory=%~dp0
PUSHD %CD%
CD ..
CD ..
SET ROOT=%CD%
SET TOOLS=%ROOT%\build\install\bin
"%TOOLS%/caffe.exe" train --solver=examples/cifar10/cifar10_full_sigmoid_solver.prototxt
POPD
pause