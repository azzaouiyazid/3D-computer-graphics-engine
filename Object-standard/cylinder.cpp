// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// cylinder.cpp
//
// This file defines a class for (optionally textured) cylinders (if a texture has been
// assigned to the cylinder, it is drawn, otherwise a non-textured cylinder is drawn).
//
// This class was developed as a demonstration of texturing.  It currently does
// not draw the end-caps.
//
// This class doesn't create any stored-geometry - just a display list of the vertex
// data and texture coordinates.  Because of this, it can't show face normals if this
// feature is turned on ("n" key).
//
// One (optional) parameter may be used:
// density	- the mesh density for radial sweep



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "cylinder.h"
#include "utility.h"




// -----------------------------------------------------------------------------------------
// external globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;
extern unsigned long	gPolygonCount;
extern bool             gWireFrameOnly;




// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------
cylinder::cylinder() : object3d()
{
	setName("cylinder");
	builder(16);								// if no density provided, default to 16
}


cylinder::cylinder(int r) : object3d()
{
	builder(r);
}




// -----------------------------------------------------------------------------------------
// the "real" constructor
// not exported,  but called by the real constructor
// -----------------------------------------------------------------------------------------

void cylinder::builder(int r)
{
	polygonCount = density = r;	

	// create a list and start recording into it
	listName = glGenLists(1);
	if (listName == 0) fatal("tsphere constructor couldn't create an OpenGL list");
	glNewList(listName, GL_COMPILE);
	

	// we draw the cylinder as a strip of quads
	glBegin(GL_QUAD_STRIP);
	
	for (int i=0; i <= density; i++)
	{
		float angle=i * (360.0/density);
		float x = -cos_d(angle);
		float z = sin_d(angle);
		
		// normal for lighting
		glNormal3f(x, 0, z);

		// texture and geometry top coordinate
		glTexCoord2f((angle/360.0), 1.0);
		glVertex3f(x,  1.0, z);

		// texture and geometry bottom coordinate
		glTexCoord2f((angle/360.0), 0.0);
		glVertex3f(x, -1, z);
	}
	glEnd();
	
	// stop recording the list
	glEndList();
	
	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);
}
/*void cylinder::privateDraw(bool drawMode)
{

	if (theTexture && !gWireFrameOnly)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, theTexture->id());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, theTexture->bestMagFilter());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, theTexture->bestMinFilter());
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glScalef(textureScaleX, textureScaleY, 1.0);
		glMatrixMode(GL_MODELVIEW);
	}
	const double PI = 3.1415926;
	double radius = 1;
	double height = 1.4;

	double i, n = 0.1; //the n variable kind of work the same way how the density work , it will move by 0.1 to the next point of the circle 



	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= 2 * PI; i += n)//this loop will rotate around the circle in a clockwise movement
	{
		const float tcenter = (i / (float)(2 * PI));//to get a number that varies from 0.0 and 1.0 we need to devide i by 2*PI to get the center
		glTexCoord2f(tcenter, 0.0);
		glVertex3f(radius * cos(i), 0, radius * sin(i));
		glTexCoord2f(tcenter, 1.0);
		glVertex3f(radius * cos(i), height, radius * sin(i));
	}
	//texture coordinates to close the loop ;
	glTexCoord2f(0.0, 0.0);
	glVertex3f(radius, 0, 0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(radius, height, 0);

	glEnd();

 }*/



