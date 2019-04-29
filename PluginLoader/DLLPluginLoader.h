#pragma once
#include "IPluginLoader.h"

class DLLPluginLoader :
	public IPluginLoader
{
public:
	DLLPluginLoader() = default;
	~DLLPluginLoader();
	std::vector<HINSTANCE> &LoadPlugins(const std::string& path) override;
private:
	std::vector<HINSTANCE> _modules;
};