#include "TextureManager.h"
#include "Exception.h"
#include "LogManager.h"
#include <iostream>

using namespace std;


TextureManager::TextureManager()
	: ResourceManager(),
	  m_textures()
{
	m_assetType = ASSET_TEXTURE;
}

TextureManager::~TextureManager()
{
	TextureMap::iterator iter;
	for (iter = m_textures.begin(); iter != m_textures.end(); iter++)
	{
		if (iter->second)
			delete iter->second;
	}
}

TextureManager*
TextureManager::getSingleton()
{
	static TextureManager instance;
	return &instance;
}

Texture*
TextureManager::getTexture(const std::string& textureName)
{
    // check if texture already loaded
    TextureMap::const_iterator iter = m_textures.find(textureName);
    if (iter != m_textures.end())
        return iter->second;

    // if it was not found, load it
    Texture* pNewTex = NULL;
    try
    {
        pNewTex = new Texture(textureName);
    }
    catch (Exception& e)
    {
        delete pNewTex;
        throw e;
    }

    m_textures[textureName] = pNewTex;
    return pNewTex;
}

bool
TextureManager::releaseTexture(const std::string& textureName)
{
	bool found = false;
    TextureMap::iterator iter = m_textures.find(textureName);
    if (iter != m_textures.end())
    {
		LogManager::getSingleton()->logMessage("Releasing :");
		LogManager::getSingleton()->logMessage(textureName);
        found = true;
        if (iter->second)
            delete iter->second;
        m_textures.erase(iter);
    }
    else
	{
		LogManager::getSingleton()->logMessage("Couldn't release :");
		LogManager::getSingleton()->logMessage(textureName);	
	}

    return found;
}
