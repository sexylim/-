#pragma once
#include "room.h"

class image;


class hallwayRoom1:public room
{


public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void colliderMake();

	hallwayRoom1();
	~hallwayRoom1();
};

