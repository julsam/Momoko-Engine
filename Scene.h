#ifndef _SCENE_H
#define _SCENE_H

class Scene
{
public:
	Scene();
	~Scene();
	
	virtual void update();
	virtual void render(); // temp virtual
	
	virtual void begin();
	virtual void end();
};

#endif // _SCENE_H
