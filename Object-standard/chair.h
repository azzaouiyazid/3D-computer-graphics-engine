#pragma once

#ifndef _CHAIR_H
#define _CHAIR_H



#include "face.h"
#include "object3d.h"
#include "tWheel.h"
#include "cylinder.h"




class chair: public object3d
{
public:
	chair();
	virtual void hide(void);
	virtual void show(void); 
private: 
	texture* toptex;
	texture* supptex;
	tWheel* top; 
	cylinder* supp; 



};

#endif