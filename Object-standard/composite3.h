#pragma once


#ifndef _TRAFFICLIGHT_H
#define _TRAFFICLIGHT_H



#include "face.h"
#include "object3d.h"
#include "sphere.h"
#include "tcuboid.h"
#include "cylinder.h"





class trafficlight : public object3d
{
public:
	trafficlight();
	virtual void hide(void);
	virtual void show(void);
	void animate(float time);

private:
	sphere* red;
	sphere* yellow;
	sphere* green;
	cylinder* supp;
	tcuboid* top;
	texture* textop;
	texture* texsupp;
};
#endif
