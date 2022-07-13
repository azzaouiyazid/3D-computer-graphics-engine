#pragma once


#ifndef _SEQUENCEB_H
#define _SEQUENCEB_H



#include "face.h"
#include "object3d.h"
#include "composite2.h"





class sequenceb : public object3d
{
public:
	sequenceb();
	virtual void hide(void);
	virtual void show(void);
	void animate(float time);
private:
	building* b;
	building* b1;
	building* b2;
	building* b3;
	building* b4;
	building* b5;
	building* b6; 
	building* b7;
};
#endif // !_SEQUENCEB_H