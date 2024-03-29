// This file defines the face class




// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "face.h"
#include "utility.h"




// -----------------------------------------------------------------------------------------
// default face constructor
// -----------------------------------------------------------------------------------------

face::face()
{
	vertices = 0;
}





// -----------------------------------------------------------------------------------------
// face destructor
// -----------------------------------------------------------------------------------------

face::~face()
{
}




// -----------------------------------------------------------------------------------------
// face initialiser when three vertex indices are specified in the call
// -----------------------------------------------------------------------------------------

void face::init(unsigned int a, unsigned int b, unsigned int c)
{
	vert[0] = a;
	vert[1] = b;
	vert[2] = c;
	vertices = 3;
}





// -----------------------------------------------------------------------------------------
// face initialiser when four vertex indices are specified in the call
// -----------------------------------------------------------------------------------------

void face::init(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
	vert[0] = a;
	vert[1] = b;
	vert[2] = c;
	vert[3] = d;
	vertices = 4;
}





// -----------------------------------------------------------------------------------------
// returns the index of vertex n
// -----------------------------------------------------------------------------------------

unsigned int face::vertex(unsigned int n)
{
	if (n > vertices)
		fatal("face::vertex() tried to read invalid vertex index");

	return vert[n];
}



