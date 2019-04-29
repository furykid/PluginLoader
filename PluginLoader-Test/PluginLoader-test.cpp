#include "pch.h"
#include "../PluginLoader/DLLPluginLoader.h"

TEST(PluginLoaderTest, TestLoadLibrary)
{
	auto pluginLoader_DLL = std::make_unique<DLLPluginLoader>();
	auto pluginVector = pluginLoader_DLL->LoadPlugins("D:\Source\personal\PluginLoader\Debug");
}