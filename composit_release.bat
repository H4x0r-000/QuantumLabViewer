@echo off

if not exist ".\composited\" goto :create_compositeddir
:compositeddir_exists
if not exist ".\composited\Release\" goto :create_releasedir
:releasedir_exists
goto :copyfiles1

:create_compositeddir
echo creating composited folder...
md composited
goto :compositeddir_exists

:create_releasedir
echo createing composited\Release folder...
md ".\composited\Release"
goto :releasedir_exists


:copyfiles1
echo copying files...
xcopy /e ".\CefViewer\build\cefsimple\bin\Release" ".\composited\Release\"
xcopy /e ".\Launcher\QuantumLabViewerLauncher\bin\Release" ".\composited\Release\" /EXCLUDE:composit_exclude.txt

if not exist ".\composited\Release\Net3.1\" goto :create_net31dir
goto :copyfiles2

:create_net31dir
md ".\composited\Release\Net3.1Launcher\"
goto :copyfiles2

:copyfiles2
xcopy /e ".\Net3.1Launcher\QuantumLabViewerLauncher\bin\Release\netcoreapp3.1" ".\composited\Release\Net3.1Launcher\" /EXCLUDE:composit_exclude.txt

echo creating manual start files...
echo start viewer.exe >> ".\composited\Release\QuantumLab Manuel Start Online.bat"
echo start viewer.exe --offline-mode >> ".\composited\Release\QuantumLab Manuel Start Offline.bat"

echo --------------------------------------------------------------------------------
echo FINISHED - press any key to exit
pause

start explorer ".\composited\Release\"