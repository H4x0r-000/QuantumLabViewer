#include "utils.h"
#include <Windows.h>
#include <codecvt>

std::wstring getAppPath()
{
	WCHAR myPath[_MAX_PATH + 1];
	GetModuleFileName(NULL, myPath, _MAX_PATH);

	std::wstringstream wss;
	for (int i = 0; i < _MAX_PATH + 1; i++)
	{
		wss << (char)myPath[i];
		if (myPath[i] == 0)
		{
			break;
		}
	}
	return wss.str();
}

std::string ws2s(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}

std::wstring path2dir(std::wstring path)
{
	std::wstring ws;
	bool slash = false;

	for (int i = path.length() - 1; i >= 0; i--)
	{
		if (slash == true)
		{
			ws = path.at(i) + ws;
		}
		else
		{
			if (path.at(i) == '\\')
			{
				slash = true;
			}
		}
	}

	return ws;
}

std::wstring s2ws(const std::string& str)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.from_bytes(str);
}