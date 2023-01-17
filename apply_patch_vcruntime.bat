@echo off

if not exist ".\composited\Release\" goto :error
xcopy ".\patch\runtime" ".\composited\Release\"
goto :success


:error
cls
echo You have to composit this project first !!! (run composit_release.bat / composit_debug.bat)
pause
goto :end


:success
cls
echo VCRuntime Patch applied successfuly!
pause
:end