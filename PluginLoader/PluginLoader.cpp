// PluginLoader.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <memory>

#include "IPluginLoader.h"
#include "DLLPluginLoader.h"

// Returns dynamic link library references
__declspec(dllexport) std::shared_ptr<IPluginLoader> GetPluginLoader_DLL()
{
	return std::make_shared<DLLPluginLoader>();
}

// Returns shared object references
__declspec(dllexport) std::shared_ptr<IPluginLoader> GetPluginLoader_SO()
{
	// Not implemented
	return 0;
}