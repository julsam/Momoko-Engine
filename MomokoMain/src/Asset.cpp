#include "../include/Asset.h"
#include "../include/TextureManager.h"
#include "../include/LogManager.h"

using namespace std;

Asset::Asset() : m_refCount(0), m_filename()
{
}

Asset::~Asset()
{
}

void
Asset::addReference()
{
	m_refCount++;
}

void
Asset::removeReference()
{
	m_refCount--;
	
	if (m_refCount == 0)
	{
		//unload();
		// have to find a way to remove different types of assets
		TextureManager::getSingleton()->releaseTexture(m_filename);
		
	}
}
