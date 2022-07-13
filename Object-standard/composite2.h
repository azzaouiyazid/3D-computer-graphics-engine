#pragma once

#ifndef _BUILDINGS_H
#define _BUILDINGS_H



#include "face.h"
#include "object3d.h"
#include "tcuboid.h"
#include "plane.h"

class building : public object3d
{
public:
	building();
	virtual void hide(void);
	virtual void show(void);
	void animate(int time);
private:
	tcuboid* build;
	plane* wind;
	plane* wind1;
	plane* wind2;
	plane* wind3; 
	plane* wind4; 
	texture* texbuild;


};

#endif

