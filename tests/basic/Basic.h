#ifndef _BASIC_H
#define _BASIC_H

#include "../../MomokoMain/include/Engine.h"


namespace Basic
{
	class GameScene : public Scene
	{
	public:
		virtual void begin();
		virtual void end();
		virtual void update();
		virtual void render();
		
	private:
	};
}

#endif // _BASIC_H
