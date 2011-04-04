#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "Asset.h"
#include <string>
#include <GL/gl.h>

class Texture : public Asset
{
	friend class TextureManager;
	
public:
	void setColorKey(unsigned char r, unsigned char g, unsigned char b);
	unsigned int getWidth() const;
	unsigned int getHeight() const;
	
	void bind() const;

protected: // constructed in TextureManager only
	Texture(const std::string& filename);
	~Texture();

private:
	void loadFile(const std::string& filename);
	
private:
	struct StructTextureData
	{
		unsigned int   width;
		unsigned int   height;
		unsigned char* data;
	};
	StructTextureData m_textureData;
	
	mutable GLuint m_texGLID;
};

#endif // _TEXTURE_H