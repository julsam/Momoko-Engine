#ifndef _SPRITE_H
#define _SPRITE_H

#include "Texture.h"
#include "Rectangle.h"
#include "SmartPtr.h"

class Sprite;
typedef CSmartPtr<Sprite> SpritePtr;

/*
 * Shouldn't instantiate this class directly
 * but should use SpritePtr & createSprite() instead !
 **/
class Sprite
{
public:
    void blit(int offsetX=0, int offsetY=0) const;
    Texture* getTexture() const;

    static SpritePtr createSprite(const std::string& filename);
    static SpritePtr createSprite(const std::string& filename,
            const Rectanglei& texCoord);

    ~Sprite();

protected:
    Sprite(const std::string& filename);
    Sprite(const std::string& filename, const Rectanglei& texCoord);

private:
    Texture* m_texture;
    Rectanglei m_rectTexCoord;
};

#endif // _SPRITE_H

