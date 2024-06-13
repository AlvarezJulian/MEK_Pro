cls
set scriptpath=%~dp0
cd ..
set currentpath=%cd%
dir %scriptpath%
dir %currentpath%
robocopy  %currentpath%\ %currentpath%\EVK070019A\ /xd ToolChainPath EVK070019A /s /e /MOVE