#pragma once
#include "include/cef_web_plugin.h"

class MyCefWebPluginInfoVisitor : public CefWebPluginInfoVisitor
{
public: 

	MyCefWebPluginInfoVisitor(){}
	~MyCefWebPluginInfoVisitor(){}

	virtual bool Visit(CefRefPtr<CefWebPluginInfo> info, int count, int total) override;

	IMPLEMENT_REFCOUNTING(MyCefWebPluginInfoVisitor);
};

