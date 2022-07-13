#pragma once
#ifndef _ROUNDTABLE_H
#define _ROUNDTABLE_H

#include "face.h"
#include "object3d.h"
#include "tWheel.h"
#include "cylinder.h"
#include "sphere.h"
#include "plane.h"

class roundtable :public object3d
{
public : 
	roundtable();

	virtual void hide(void);
	virtual void show(void);
private :
	texture* tabletex;
	texture* bottex; 
	texture* supptex;
	tWheel* table;
	tWheel* bot; 
	cylinder* supp;
	
	

	
	


};
#endif 

