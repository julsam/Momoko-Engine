#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H

#include "ResourceManager.h"
#include "Texture.h"
#include <string>
#include <map>

class TextureManager : public ResourceManager
{
public:
	static TextureManager* getSingleton();
	
	Texture* getTexture(const std::string& textureName);
	bool releaseTexture(const std::string& textureName);
	
	protected:
	TextureManager();
	~TextureManager();

private:
	typedef std::map<std::string,Texture*> TextureMap;
	TextureMap m_textures;
};

#endif // _TEXTUREMANAGER_H
