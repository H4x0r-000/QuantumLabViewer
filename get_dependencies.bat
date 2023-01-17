git clone https://github.com/microsoft/vcpkg .\dependencies\vcpkg\
call .\dependencies\vcpkg\bootstrap-vcpkg.bat -disableMetrics

setlocal
for /f "tokens=4-7 delims=[.] " %%i in ('ver') do @(if %%i==Version (set WINVER=%%j.%%k) else (set WINVER=%%i.%%j))
if %WINVER% == 6.1 (goto :downgrade) else (goto :install)
endlocal
goto :install

:downgrade
call downgrade_vcpkg_win7.bat

:install
.\dependencies\vcpkg\vcpkg.exe install drogon:x64-windows



echo Finished installing dependencies!