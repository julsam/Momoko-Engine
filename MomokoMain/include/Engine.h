#ifndef _ENGINE_H
#define _ENGINE_H

#include "Config.h"
#include "Window.h"
#include "Event.h"
#include "Graphics.h"
#include "LogManager.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "Scene.h"
#include "Exception.h"

class Engine
{
public:
	Engine(int argc, char **argv);
	~Engine();
	bool init();
	int execute();
	
	static void setScene(Scene* scene);
	static Scene* getScene();

private:
	static Engine* instance;
	
	LogManager mLogManager;
	Config mConfig;
	Window* mWindow;
	Event mEvent;
	Graphics mGraphics;
	
	Scene* mScene;
	Scene* mSwitchTo;

	bool m_quit;
	double deltaTime;
	long thisTime;
	long lastTime;
};

#endif // _ENGINE_H
