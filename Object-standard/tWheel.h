#pragma once
#ifndef _TWHEEL_H
#define _TWHEEL_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"




class tWheel :public object3d
{
public:

	tWheel(int density);
	void privateDraw(bool drawmode);

};

#endif