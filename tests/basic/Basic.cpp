#include "Basic.h"
#include <iostream>

namespace Basic
{
	void
	GameScene::begin()
	{
	}

	void
	GameScene::end()
	{
	}
	
	void
	GameScene::update()
	{
	}
	
	void
	GameScene::render()
	{
		glBegin(GL_QUADS);
			glColor3f(1, 0, 0); glVertex3i(0, 0, 0);
			glColor3f(1, 1, 0); glVertex3i(100, 0, 0);
			glColor3f(1, 0, 1); glVertex3i(100, 100, 0);
			glColor3f(1, 1, 1); glVertex3i(0, 100, 0);
		glEnd();
	}
}