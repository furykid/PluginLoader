#include "stdafx.h"
#include "DLLPluginLoader.h"

DLLPluginLoader::~DLLPluginLoader()
{
	_modules.clear();
}

std::vector<HINSTANCE> &DLLPluginLoader::LoadPlugins(const std::string& path)
{
	// The data for each file we find.
	WIN32_FIND_DATA fileData;

	// Find the first DLL file in out plugins folder,
	// and store the data in out fileData structure.
	std::string fullPath = path + "\*.dll";
	HANDLE fileHandle = FindFirstFile(fullPath.c_str(), &fileData);

	if (fileHandle == (void*)ERROR_INVALID_HANDLE ||
		fileHandle == (void*)ERROR_FILE_NOT_FOUND) {
		// We couldn't find any plugins, lets just
		// return for now (imagine this is in main)
	}

	// Loop over every plugin in the folder, and store
	// the handle in our modules list
	do {
		// Load the plugin. We need to condense the plugin
		// name and the path together to correctly load the
		// file (There are other ways, I won't get into it here)
		HINSTANCE temp = LoadLibrary((fullPath.c_str() + std::string(fileData.cFileName)).c_str());

		if (!temp) {
			// Couldn't load the library, continue on
		}

		// Add the loaded module to our list of modules
		_modules.push_back(temp);

		// Continue while there are more files to find
	} while (FindNextFile(fileHandle, &fileData));

	return _modules;
}
