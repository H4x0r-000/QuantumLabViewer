# Disclaimer

This software is a viewer for the website <a href="https://quantumlab.nat.fau.de">quantumlab.nat.fau.de</a> (or other Flah dependent websites) since it uses Flash to display parts of its content and newer browsers don't support Flash anymore. Therefore, all content viewed with this software in online/offline mode belongs to © Didaktik der Physik, Universität Erlangen-Nürnberg.

This repository contains a mostly complete backup of <a href="https://quantumlab.nat.fau.de">quantumlab.nat.fau.de</a> in case it goes offline. However, if the owner does not want the contents to be in this repo I will take it down as soon as possible. If you are one of the owners you can contact me through my github email.

The source-code other than in Resources/offline_data/http/QuantumLab/quantumlab.nat.fau.de belong to me. Forking/copying/editing is allowed however credit is required and you may have to take it offline on request.

The file vcruntime140_1.dll in patch/runtime belongs to Microsoft and is only shipped for compatibility reasons.
The files inside patch/drogon belong to the Drogon Framework Dev team and are shipped for compatibility reasons.

The Viewer is based on an older version Chromium Embedded Framework to enable the usage of the Flash plugin.

# Download
You can either download the source and compile it yourself or download binaries from the <a href="https://github.com/H4x0r-000/QuantumLabViewer/releases/latest">release section</a>.

# Building
This section explains how to build the binaries from source.

## Requirements
Before starting the build you have to ensure you have Visual Studio 2016 or similar (some tweaks may be needed if you have a slightly different version). Also, you may have to run get_dependencies.bat first to download the Drogon Framework which is used for offline mode. If you already have Drogon installed, you may have to change lib/include directories in the solution settings.

## Build steps

### Viewer
After downloading, extracting and preparing the source files, go to CefViewer/build and open the Viewer. sln solution file. Start build with Build > Build Solution. Afterwards, you can close the solution.

### Launcher
Open Launcher/QuantumLabViewerLauncher/QuantumLabViewerLauncher. sln and build it as well.
Open Net3.1Launcher/QuantumLabViewerLauncher/QuantumLabViewerLauncher. sln and build it.

### Composit all together
Run composit_release.bat to pack all together. Afterwards, you can find all files inside composited/Release.

### Patching
Since all necessary drogon files are not included by default, you have to run at least apply_patch_min.bat which currently just runs apply_patch_drogon.bat to copy these files into composited/Release. If necessary, you can also run apply_patch_vcruntime.bat to copy vcruntime140_1.dll to composited/Release as well. You can also just run apply_patch_all.bat to do both.

### Finished!

# Usage

## Startup
To use it you can just run QuantumLabViewerLauncher.exe inside the composited/Release folder, or if you Net Framework version doesn't support it you can find an Net3.1 version of the Launcher inside composited/Release/Net3.1Launcher

Alternatively, you can run "QuantumLab Manuel Start Offline.bat" or "QuantumLab Manuel Start Online.bat" to start manually.

## Launcher controls
After starting the Launcher, you should see mainly four buttons. Currently, the launcher is only available in German language. The first button from top to bottom, labeled "Online Modus" starts the actual viewer in online mode. The second button starts the offline mode. The "Benutzerdefinierte URL öffnen" labeled button prompts you to input a custom URL which will be shown in the viewer after clicking "Starten". This allows to view other Flash dependent content. The last button from the main window labeled "Abbrechen" closes the launcher.

The tick in the bottom left corner gives you the option to close the launcher after selecting the mode (checked) or to leave it open (unchecked).
