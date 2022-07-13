// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// cube.cpp
//
// This file defines the class for cube objects



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "tpyramid.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;
extern unsigned long	gPolygonCount;			
extern bool             gWireFrameOnly;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

tpyramid::tpyramid()
{
	// Initialise the object's state
	setName("tpyramid");


	vertexCount = 6;
	faceCount = 5;
	polygonCount = 5;

	// allocate memory for the vertex and face arrays
	vertices.resize(vertexCount);
	faces.resize(faceCount);


	
	vertices[0].set(0, 1, 0);				// apex
	vertices[1].set(-1, -1, 1);				// front, top, right
	vertices[2].set(1, -1, 1);				// front, bot, right
	vertices[3].set(1, -1, -1);				// front, bot, left
	vertices[4].set(-1, -1, -1);				// back,  top, left


	// now set up the faces - note that the vertex order is always
	// specified counter-clockwise when that face is viewed front on
	faces[0].init(0, 1, 2);
	faces[1].init(0, 2, 3);
	faces[2].init(0, 3, 4);
	faces[3].init(0, 4, 1);
	faces[4].init(1, 4, 3, 2);


	// calculate the face and vertex normals
	calculateNormals();


	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);
}
void tpyramid::privateDraw(bool drawMode)
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


	glBegin(GL_TRIANGLES);

	
	glNormal3fv(faces[0].faceNormal.data);
	glTexCoord2f(0.0,0.5);
	glVertex3fv(vertices[0].coordinate.data);		
	glTexCoord2f(0.25,0.25);
	glVertex3fv(vertices[1].coordinate.data);		
	glTexCoord2f(0.25,0.75);
	glVertex3fv(vertices[2].coordinate.data);		


	
	glNormal3fv(faces[1].faceNormal.data);
	glTexCoord2f(0.25,0.25);
	glVertex3fv(vertices[0].coordinate.data);	
	glTexCoord2f(0.5,0.0);	
	glVertex3fv(vertices[2].coordinate.data);
	glTexCoord2f(0.75,0.25);
	glVertex3fv(vertices[3].coordinate.data);		


	
	glNormal3fv(faces[2].faceNormal.data);
	glTexCoord2f(0.75,0.25);
	glVertex3fv(vertices[0].coordinate.data);
	glTexCoord2f(1,0.5);
	glVertex3fv(vertices[3].coordinate.data);
	glTexCoord2f(0.75,0.75);
	glVertex3fv(vertices[4].coordinate.data);		

	
	glNormal3fv(faces[3].faceNormal.data);
	glTexCoord2f(0.75,0.75);
	glVertex3fv(vertices[0].coordinate.data);
	glTexCoord2f(0.5,1.0);
	glVertex3fv(vertices[4].coordinate.data);
	glTexCoord2f(0.25,0.75);
	glVertex3fv(vertices[1].coordinate.data);		
	glEnd();

	glBegin(GL_QUADS);
	
	glNormal3fv(faces[4].faceNormal.data);
	glTexCoord2f(0.25, 0.75);
	glVertex3fv(vertices[4].coordinate.data);
	glTexCoord2f(0.25, 0.25);
	glVertex3fv(vertices[3].coordinate.data);
	glTexCoord2f(0.75, 0.25);
	glVertex3fv(vertices[2].coordinate.data);
	glTexCoord2f(0.75, 0.75);
	glVertex3fv(vertices[1].coordinate.data);		// top (back) left
	glEnd();




	// disable texturing
	if (theTexture && !gWireFrameOnly) glDisable(GL_TEXTURE_2D);

}
