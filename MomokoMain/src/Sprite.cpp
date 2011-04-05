#include "../include/Sprite.h"
#include "../include/Exception.h"
#include "../include/TextureManager.h"
#include "../include/LogManager.h"

using namespace std;

Sprite::Sprite(const string& filename)
  : m_texture(NULL), m_rectTexCoord()
{
    // This line will throw an exception if the texture is not found.
    m_texture = TextureManager::getSingleton()->getTexture(filename);
    m_texture->addReference();

    // Set the texture coordinate to the full texture
    m_rectTexCoord.m_Top = m_rectTexCoord.m_Left = 0;
    m_rectTexCoord.m_Bottom = m_texture->getHeight();
    m_rectTexCoord.m_Right = m_texture->getWidth();
}

Sprite::Sprite(const string& filename, const Rectanglei& texCoord)
  : m_texture(NULL), m_rectTexCoord(texCoord)
{
    // This line will throw an exception if the texture is not found.
    m_texture = TextureManager::getSingleton()->getTexture(filename);
    m_texture->addReference();
}

Sprite::~Sprite()
{
  if (m_texture)
    m_texture->removeReference();
}

void
Sprite::blit(int offsetX, int offsetY) const
{
    if (m_texture)
    {
        m_texture->bind();

        // Get the coordinates of the image in the texture, expressed
        // as a value from 0 to 1.
        float Top = ((float)m_rectTexCoord.m_Top) / m_texture->getHeight();
        float Bottom = ((float)m_rectTexCoord.m_Bottom) / m_texture->getHeight();
        float Left = ((float)m_rectTexCoord.m_Left) / m_texture->getWidth();
        float Right = ((float)m_rectTexCoord.m_Right) / m_texture->getWidth();

        glBegin(GL_QUADS);
            glTexCoord2f(Left, Top);
            glVertex3i(offsetX, offsetY, 0);

            glTexCoord2f(Left, Bottom);
            glVertex3i(offsetX, offsetY + m_rectTexCoord.getHeight(), 0);

            glTexCoord2f(Right, Bottom);
            glVertex3i(offsetX + m_rectTexCoord.getWidth(),
                    offsetY + m_rectTexCoord.getHeight(), 0);

            glTexCoord2f(Right, Top);
            glVertex3i(offsetX + m_rectTexCoord.getWidth(), offsetY, 0);
        glEnd();
    }
}

Texture*
Sprite::getTexture() const
{
    return m_texture;
}

SpritePtr
Sprite::createSprite(const string& filename)
{
    SpritePtr spritePtr(new Sprite(filename));
    return spritePtr;
}

SpritePtr
Sprite::createSprite(const string& filename, const Rectanglei& texCoord)
{
    SpritePtr spritePtr(new Sprite(filename, texCoord));
    return spritePtr;
}

