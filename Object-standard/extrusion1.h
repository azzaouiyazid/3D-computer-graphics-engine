#pragma once
// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// extrusion.h
//
// This file declares the class for extrusion objects, based on the
// generic 3D object


#ifndef _EXTRUSION1_H
#define _EXTRUSION1_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"



// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------
class extrusion1 : public object3d
{
private:
	int			plotCommands;
	int			profileVertexCount;

public:
	extrusion1(string profileFilename, string pathFilename);

};



#endif // _EXTRUSION_H
