#include "../include/Engine.h"

using namespace std;

Engine* Engine::instance = NULL;

Engine::Engine(int argc, char **argv)
	: mConfig(argc, argv),
	  mScene(NULL),
	  mSwitchTo(NULL),
	  m_quit(false),
	  deltaTime(0.0f),
	  thisTime(0),
	  lastTime(0)
{
	instance = this;
}

Engine::~Engine()
{
	delete mWindow;
	if (mScene != NULL)
		delete mScene;
	if (mSwitchTo != NULL)
		delete mSwitchTo;
}

bool
Engine::init()
{
	mLogManager.init(); // first thing to init
	mConfig.init();

	mWindow = new Window(Config::getCaption(),
						 Config::getInfos().windowSize.x,
						 Config::getInfos().windowSize.y,
						 Config::getInfos().fullscreen);

	if(!mWindow->init())
		return false;
	mEvent.init();
	mGraphics.init();

	return true;
}

int
Engine::execute()
{
	while(!mEvent.isExitPressed() && !m_quit)
	{
		thisTime = SDL_GetTicks();
		deltaTime = (double)(thisTime - lastTime) / 1000.0;
		lastTime = thisTime;

		if (mSwitchTo != NULL)
		{
			if (mScene != NULL)
			{
				mScene->end();
				delete mScene;
			}
			
			mScene = mSwitchTo;
			mSwitchTo = NULL;
			LogManager::getSingleton()->logMessage( "New Scene loaded." );
			
			if (mScene != NULL)
			{
				mScene->begin();
			}
		}
		
		mEvent.update();
		if (mScene != NULL)
			mScene->update();
		
		
		if(Event::isKeyPressed(SDLK_ESCAPE))
			m_quit = true;
		if(Event::isKeyPressed(SDLK_f))
			Window::changeFullscreen();



		mGraphics.beginFrame();
		
		if (mScene != NULL)
			mScene->render();
		
		mGraphics.endFrame();

		SDL_Delay(33);
	}
	return 0;
}

void
Engine::setScene(Scene* scene)
{
	instance->mSwitchTo = scene;	
}

Scene*
Engine::getScene()
{
	return instance->mScene;
}
