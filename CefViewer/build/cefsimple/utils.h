#include <string>
#include <sstream>

std::wstring getAppPath();
std::wstring path2dir(std::wstring path);
std::string ws2s(const std::wstring& wstr);
std::wstring s2ws(const std::string& str);