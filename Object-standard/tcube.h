


#ifndef _TCUBE_H

#define _TCUBE_H




// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"




// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class tcube : public object3d
{
public:
	tcube();
	void privateDraw(bool drawmode);

};


#endif // _CUBE_H