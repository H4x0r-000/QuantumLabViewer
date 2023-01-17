@echo off

if not exist ".\composited\Release\" goto :error
rem xcopy ".\patch\drogon" ".\composited\Release\"
xcopy ".\dependencies\vcpkg\installed\x64-windows\bin" ".\composited\Release\" /exclude:drogon_patch_exclude.txt
goto :success


:error
cls
echo You have to composit this project first !!! (run composit_release.bat / composit_debug.bat)
pause
goto :end


:success
cls
echo Drogon Patch applied successfuly!
pause
:end