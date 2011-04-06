#ifndef _SCENE_H
#define _SCENE_H

class Scene
{
public:
	Scene();
	virtual ~Scene(); 
	
	virtual void begin();
	virtual void end();
	
	virtual void update();
	virtual void render(); // temp virtual
};

#endif // _SCENE_H
