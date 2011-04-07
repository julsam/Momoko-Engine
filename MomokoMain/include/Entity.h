#ifndef _ENTITY_H
#define _ENTITY_H

#include "Vector2.h"
#include "../../libs/Box2D/Box2D.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();
	
	virtual Vector2 getPosition();
	
	b2Body* m_body;
	
	float width;
	float height;
	
protected:
	Vector2 position;
};

#endif // _ENTITY_H