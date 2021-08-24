#pragma once
	
#include "nfd.h"
#include <string>

namespace ofxNFD
{

	static bool openFileDialog(std::string* path_p, const std::string filter_p, const std::string defaultPath_p)
	{
		std::string result;
		nfdchar_t* outPath = NULL;
		const nfdresult_t resultNFD = NFD_OpenDialog(filter_p.c_str(), defaultPath_p.c_str(), &outPath);

		if (resultNFD == NFD_OKAY)
		{
			*path_p = std::string(outPath);
			free(outPath);
			return true;
		}
		else if (resultNFD == NFD_CANCEL)
		{
			return false;
		}


		return false;
	}
}


