#include "MyCefWebPluginInfoVisitor.h"
#include <windows.h>

bool MyCefWebPluginInfoVisitor::Visit(CefRefPtr<CefWebPluginInfo> info, int count, int total)
{
    MessageBox(NULL, L"ABC", L"DEF", MB_OK);
    return true;
}
