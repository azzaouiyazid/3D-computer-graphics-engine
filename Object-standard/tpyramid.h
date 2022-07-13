#pragma once
// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// cube.h
//
// This file declares the class for cube objects, based on the
// generic 3D object


#ifndef _TPYRAMID_H
#define _TPYRAMID_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"




// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class tpyramid : public object3d
{
public:
	tpyramid();
	void  privateDraw(bool drawmode);

};


#endif 

