#include "../include/Entity.h"

using namespace std;

Entity::Entity()
	: width(0),
	  height(0),
	  position(0, 0)
{
}

Entity::~Entity()
{
}

Vector2
Entity::getPosition()
{
	return position;
}