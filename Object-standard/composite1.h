

#ifndef _CAR_H
#define _CAR_H



#include "face.h"
#include "object3d.h"
#include "tWheel.h"
#include "tcuboid.h"
#include "plane.h"





class car : public object3d
{
public:
	car();
	virtual void hide(void);
	virtual void show(void);
	void animate(float time);
private:
	
	texture* wheeltex;
	tWheel* wheel;
	tWheel* wheel1;
	tWheel* wheel2;
	tWheel* wheel3;
	tcuboid* up; 
	tcuboid* up1;
	tcuboid* up2;
	plane* window;

	



};
#endif