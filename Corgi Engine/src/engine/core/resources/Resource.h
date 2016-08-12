#ifndef _ENGINE_RESOURCE_H
#define _ENGINE_RESOURCE_H

#include "../../Engine.h"

class Resource
{
friend class ResourceManager;
public:
	const std::string& GetFileName() const { return this->m_FileName; }
	const std::string& GetFilePath() const { return this->m_FilePath; }
	const int GetReferenceCount() const { return this->m_ReferenceCount; }

	Resource(std::string& filePath);
	virtual ~Resource() { }
protected:
	// Uniform initialization
	Resource(const Resource&) { }
	Resource& operator=(const Resource&) { return *this; }

	virtual void Load() = 0;
private:
	std::string m_FileName;
	std::string m_FilePath;

	int m_ReferenceCount;
	void AddReference() { this->m_ReferenceCount++; }
	void RemoveReference() { this->m_ReferenceCount--; }
};

#endif