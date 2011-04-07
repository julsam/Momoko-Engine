#include "helloBox2d.h"
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;
namespace helloBox2d
{
	const float GameScene::RATIO = 30.0f;
	
	void
	GameScene::begin()
	{
		m_nextCrateIn = 0;
		srand(time(NULL)); // initialize random seed
		
		setupWorld();
		createWallsAndFloor();
		addACrate(b2Vec2(250, -30), b2Vec2(25, 25), 30);
		
		
		
		m_timeStep = 1.0f / 60.0f;
		//m_timeStep = Engine::getDeltaTime()/4.0f;
		
		m_velocityIterations = 6;
		m_positionIterations = 2;
		
		//glScalef(3.5f, 3.5f, 1.0f);
		
		//m_body->SetAngularVelocity(-500);
	}

	void
	GameScene::end()
	{
		delete m_world;
	}
	
	void
	GameScene::update()
	{
		m_world->Step(m_timeStep, m_velocityIterations, m_positionIterations);

		m_world->ClearForces();
		
		m_nextCrateIn--;
		if (m_nextCrateIn <= 0 && m_world->GetBodyCount() < 80)
		{
			addARandomCrate();
			m_nextCrateIn = 30;
		}

		//b2Vec2 position = m_crate->GetPosition();

		//float32 angle = m_crate->GetAngle();    
		
		//printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
	}
	
	void
	GameScene::render()
	{
		for (unsigned int i = 0; i < m_crates.size(); ++i)
		{
			b2Vec2 pos = m_crates[i]->m_body->GetPosition();
			b2Vec2 size = b2Vec2(m_crates[i]->width, m_crates[i]->height);
			float angle = m_crates[i]->m_body->GetAngle() * (180 / b2_pi);
			
			drawRect(pos, size, angle);
		}
		
		b2Vec2 pos = m_groundBody->GetPosition();
		b2Vec2 size = b2Vec2(300.0f, 10.0f);
		float angle = m_groundBody->GetAngle() * (180 / b2_pi);
		
		drawRect(pos, size, angle);
		
		// Left
		pos = m_leftWallBody->GetPosition();
		size = b2Vec2(5.0f, 195.0f);
		angle = m_leftWallBody->GetAngle() * (180 / b2_pi);
		
		drawRect(pos, size, angle);
		
		// Right
		pos = m_rightWallBody->GetPosition();
		size = b2Vec2(5.0f, 195.0f);
		angle = m_rightWallBody->GetAngle() * (180 / b2_pi);
		
		drawRect(pos, size, angle);
	}
	
	
	void
	GameScene::drawRect(b2Vec2 pos, b2Vec2 size, float angle)
	{
		glPushMatrix();
	
		glTranslatef(pos.x * RATIO, pos.y * RATIO, 0);
		glRotatef(angle, 0, 0, 1);
		
		glBegin(GL_LINE_LOOP);
			glColor3f(1, 1, 1); 
			glVertex3i(-size.x, -size.y, 0);
			glVertex3i(size.x, -size.y, 0);
			glVertex3i(size.x, size.y, 0);
			glVertex3i(-size.x, size.y, 0);
		glEnd();
		
		glPopMatrix();
	}
	
	void
	GameScene::setupWorld()
	{
		b2Vec2 gravity(0.0f, 9.8f);
		bool doSleep = true;
		
		// world
		m_world = new b2World(gravity, doSleep);		
	}
	
	
	void
	GameScene::createWallsAndFloor()
	{
		// Ground static body
		b2BodyDef groundBodyDef;
		groundBodyDef.position.Set(320.0f / RATIO, 460.0f / RATIO);
		
		m_groundBody = m_world->CreateBody(&groundBodyDef);
		
		
		b2PolygonShape groundBox;
		groundBox.SetAsBox(300.0f / RATIO, 10.0f / RATIO);
		
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &groundBox;
		fixtureDef.friction = 0.4f;
		fixtureDef.restitution = 0.3f;
		fixtureDef.density = 1.0f;
		
		m_groundBody->CreateFixture(&fixtureDef);
		
		//m_groundBody->CreateFixture(&groundBox, 0.0f);
		
		
		
		
		b2PolygonShape tallSkinnyShape;
		tallSkinnyShape.SetAsBox(5 / RATIO, 195 / RATIO);
		
		b2FixtureDef tallSkinnyShapeDef;
		tallSkinnyShapeDef.shape = &tallSkinnyShape;
		tallSkinnyShapeDef.friction = 0.4f;
		tallSkinnyShapeDef.restitution = 0.3f;
		tallSkinnyShapeDef.density = 1.0f;
		
		// WALL 1
		b2BodyDef wallBodyDef;
		wallBodyDef.position.Set(15 / RATIO, 255 / RATIO);
		
		m_leftWallBody = m_world->CreateBody(&wallBodyDef);
		m_leftWallBody->CreateFixture(&tallSkinnyShapeDef);
		
		// WALL 2
		wallBodyDef.position.Set(625 / RATIO, 255 / RATIO);
		
		m_rightWallBody = m_world->CreateBody(&wallBodyDef);
		m_rightWallBody->CreateFixture(&tallSkinnyShapeDef);
	}
	
	void
	GameScene::addACrate(b2Vec2 pos, b2Vec2 size, int angle)
	{
		b2PolygonShape fallingCrateDef;
		fallingCrateDef.SetAsBox(size.x / RATIO, size.y / RATIO);
		
		b2FixtureDef fallingBodyFixture;
		fallingBodyFixture.shape = &fallingCrateDef;
		fallingBodyFixture.friction = 0.8f;
		fallingBodyFixture.restitution = 0.3f;
		fallingBodyFixture.density = 0.7f;
		
		b2BodyDef fallingBodyDef;
		fallingBodyDef.type = b2_dynamicBody;
		fallingBodyDef.position.Set(pos.x / RATIO, pos.y / RATIO);
		fallingBodyDef.angle = angle * b2_pi / 180;
		
		b2Body* crateBody = m_world->CreateBody(&fallingBodyDef);		
		crateBody->CreateFixture(&fallingBodyFixture);
		
		Crate* crate = new Crate();
		crate->width = size.x;
		crate->height = size.y;
		crate->m_body = crateBody;
		
		m_crates.push_back(crate);
		
		string s = "The world now has " + to_str(m_world->GetBodyCount()) + " crates in it !";
		cout << s << endl;
	}
	
	void
	GameScene::addARandomCrate()
	{
		b2Vec2 pos(randomInt(20,600), randomInt(-100, -10));
		b2Vec2 size(randomInt(5, 40), randomInt(5, 40));
		float angle = randomInt(0, 360);
		
		addACrate(pos, size, angle);
	}
	
	int
	GameScene::randomInt(int lowVal, int highVal)
	{
		if (lowVal <= highVal)
			return (lowVal + (rand() % (highVal - lowVal)));
		else
			return (lowVal - highVal + 1);
	}
	
	
	
	/*
	 * Crate Class
	 */
	Crate::Crate()		
	{
		
	}
}
