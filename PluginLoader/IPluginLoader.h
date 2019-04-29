#pragma once

#include <vector>

class __declspec(dllexport) IPluginLoader
{
public:
	virtual ~IPluginLoader() = default;
	virtual std::vector<HINSTANCE> &LoadPlugins(const std::string &path) = 0;
};