#ifndef _ASSET_H
#define _ASSET_H

#include <string>

class Asset
{
public:
	Asset();
	~Asset();
	
	void addReference();
	void removeReference();
	int getReferenceCount() { return m_refCount; }

protected:
	virtual void loadFile(const std::string& filename) = 0;
	//virtual void unload() = 0;
	
protected:
	int m_refCount;
	std::string m_filename;
};

#endif // _ASSET_H
