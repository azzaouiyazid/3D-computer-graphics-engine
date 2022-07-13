#pragma once
#pragma once

#ifndef _ADSBOARD_H
#define _ADSBOARD_H



#include "face.h"
#include "object3d.h"
#include "tsphere.h"
#include "cylinder.h"
#include "tWheel.h"

class adsboard : public  object3d
{
public:
	adsboard();
	virtual void hide(void);
	virtual void show(void);
	void animate(float time);
private:
	texture* supptex;
	texture* texsphere;
	texture* texwheel;
	cylinder* supp;
	tsphere* ad;
	tWheel* bot;




};
#endif