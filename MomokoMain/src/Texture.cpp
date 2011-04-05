#include "../include/Texture.h"
#include "../include/Exception.h"
#include "../include/LogManager.h"
#include <IL/il.h>

using namespace std;

Texture::Texture(const string& filename)
	: Asset(), m_textureData(), m_texGLID(0)
{
	m_textureData.width = m_textureData.height = 0;
	m_textureData.data = NULL;
	
	loadFile(filename);
	m_filename = filename;	
}

Texture::~Texture()
{
	if (m_textureData.data)
	{
		delete[] m_textureData.data;
		m_textureData.data = NULL;
	}
}

void
Texture::loadFile(const std::string& filename)
{
	// Generate a new image Id and bind it with the
	// current image.
	ILuint imgId;
	ilGenImages(1, &imgId);
	ilBindImage(imgId);

	// Load the file data in the current image.
	if (!ilLoadImage(filename.c_str()))
	{
		string strError = "Failed to load file: " + filename;
		throw Exception(strError);
	}

	m_textureData.width = ilGetInteger(IL_IMAGE_WIDTH);
	m_textureData.height = ilGetInteger(IL_IMAGE_HEIGHT);

	unsigned int size = m_textureData.width * m_textureData.height * 4;
	m_textureData.data = new unsigned char[size];
	ilCopyPixels(0, 0, 0, m_textureData.width, m_textureData.height,
		1, IL_RGBA, IL_UNSIGNED_BYTE, m_textureData.data);

	ilDeleteImage(imgId);
}

unsigned int
Texture::getWidth() const
{
	return m_textureData.width;
}

unsigned int
Texture::getHeight() const
{
	return m_textureData.height;
}

void
Texture::bind() const
{
	// If the texture has not been generated in OpenGL yet,
	// generate it.
	if(!m_texGLID)
	{
		// Generate one new texture Id.
		glGenTextures(1, &m_texGLID);
		// Make this texture the active one, so that each
		// subsequent glTex* calls will affect it.
		glBindTexture(GL_TEXTURE_2D, m_texGLID);

		// Specify a linear filter for both the minification and
		// magnification.
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		// Sets drawing mode to GL_MODULATE
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		// Finally, generate the texture data in OpenGL.
		glTexImage2D(GL_TEXTURE_2D, 0, 4, m_textureData.width, m_textureData.height,
				0, GL_RGBA, GL_UNSIGNED_BYTE, m_textureData.data);
	}

	// Make the existing texture specified by its OpenGL id
	// the active texture.
	glBindTexture(GL_TEXTURE_2D, m_texGLID);
}

void
Texture::setColorKey(unsigned char r, unsigned char g, unsigned char b)
{
	// If the texture has already been specified to OpenGL,
	// we delete it.
	if (m_texGLID)
	{
		glDeleteTextures(1, &m_texGLID);
		m_texGLID = 0;
	}

	// For all the pixels that correspond to the specifed color,
	// set the alpha channel to 0 (transparent) and reset the other
	// ones to 255.
	unsigned long count = m_textureData.width * m_textureData.height * 4;
	for (unsigned long i = 0; i < count; i += 4)
	{
		if ( (m_textureData.data[i] == r) 
			&& (m_textureData.data[i+1] == g) 
			&& (m_textureData.data[i+2] == b) )
			m_textureData.data[i+3] = 0;
		else
			m_textureData.data[i+3] = 255;
	}
}

