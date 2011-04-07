#ifndef _HELLOBOX2D_H
#define _HELLOBOX2D_H

#include "../../MomokoMain/include/Engine.h"
#include "../../MomokoMain/include/Entity.h"
#include "../../libs/Box2D/Box2D.h"
#include <cstdio>
#include <vector>

namespace helloBox2d
{
	class Crate;
	
	class GameScene : public Scene
	{
	public:
		virtual void begin();
		virtual void end();
		virtual void update();
		virtual void render();
		
	private:
		void setupWorld();
		void createWallsAndFloor();
		void addACrate(b2Vec2 pos, b2Vec2 size, int angle);
		void addARandomCrate();
		
		void drawRect(b2Vec2 pos, b2Vec2 size, float angle);
		
		int randomInt(int lowVal, int highVal);
		
	public:
		static const float RATIO; // ratio of pixels to meters
		
	private:
		b2World* m_world;
		b2Body* m_groundBody;
		b2Body* m_leftWallBody;
		b2Body* m_rightWallBody;
		//b2Body* m_crate;
		
		std::vector<Crate*> m_crates;
		
		float32 m_timeStep;
		int32 m_velocityIterations;
		int32 m_positionIterations;
		
		int m_nextCrateIn;
	};
	
	class Crate : public Entity
	{
	public:
		Crate();
	};
}

#endif // _HELLOBOX2D_H
