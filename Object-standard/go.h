#pragma once

#ifndef _GO_H
#define _GO_H

#include "face.h"
#include "object3d.h"
#include "sphere.h"
#include "plane.h"

class gogame :public object3d
{
public:
	gogame();
	virtual void hide(void);
	virtual void show(void);
private:
	
	texture* goboardtex;
	texture* gotex;
	plane* goboard;
	sphere* blackgo;
	sphere* whitego;
	






};
#endif 