#ifndef _BASIC_H
#define _BASIC_H

#include "../../MomokoMain/include/Engine.h"


namespace Basic
{
	class GameScene : public Scene
	{
	public:
		void begin();
		void end();
		void update();
		void render();
		
	private:
	};
}

#endif // _BASIC_H
