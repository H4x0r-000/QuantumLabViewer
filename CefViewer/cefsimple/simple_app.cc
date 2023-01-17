// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "cefsimple/simple_app.h"

#include <string>

#include "cefsimple/simple_handler.h"
#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/wrapper/cef_helpers.h"

#include "utils.h"




SimpleApp::SimpleApp() {
}

void SimpleApp::OnContextInitialized() {
  CEF_REQUIRE_UI_THREAD();

  // SimpleHandler implements browser-level callbacks.
  CefRefPtr<SimpleHandler> handler(new SimpleHandler());

  // Specify CEF browser settings here.
  CefBrowserSettings browser_settings;

  browser_settings.plugins = STATE_ENABLED;

  std::string url;

  // Check if a "--url=" value was provided via the command-line. If so, use
  // that instead of the default URL.
  CefRefPtr<CefCommandLine> command_line =
      CefCommandLine::GetGlobalCommandLine();
  url = command_line->GetSwitchValue("url");

  //Window title
  CefString title = "Viewer - browsing custom URL...";

  if (url.empty())
  {
      if (command_line->HasSwitch("offline-mode"))
      {
          url = "http://127.0.0.1:6981";
          title = "QuantumLab (Offline Mode)";
      }
      else
      {
          url = "https://www.quantumlab.nat.fau.de";
          title = "QuantumLab";
      }
  }

  // Information used when creating the native window.
  CefWindowInfo window_info;

#if defined(OS_WIN)
  // On Windows we need to specify certain flags that will be passed to
  // CreateWindowEx().
  window_info.SetAsPopup(NULL, title);
#endif

  // Create the first browser window.
  CefBrowserHost::CreateBrowser(window_info, handler.get(), url,
                                browser_settings, NULL);
}

void SimpleApp::OnBeforeCommandLineProcessing(const CefString& process_type, CefRefPtr<CefCommandLine> command_line)
{
    command_line->AppendSwitch("enable-npapi");
}