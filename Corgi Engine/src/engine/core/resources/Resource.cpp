#include "Resource.h"

Resource::Resource(std::string& filePath)
{
	size_t lastSlashIndex = filePath.find_last_of("/\\");

	// initialize variables
	this->m_FilePath = filePath;
	this->m_FileName = filePath.substr(lastSlashIndex + 1);
}