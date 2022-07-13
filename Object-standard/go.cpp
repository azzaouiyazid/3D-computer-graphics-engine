
#include "prefix.h"
#include "go.h"
#include "utility.h"

extern vector<object3d*> gShapeVector;


gogame::gogame() {

	setName("go");
	goboardtex = new texture("goboard.jpg", kContinuousTone, kMipmaps);
	goboard = new plane();
	goboard->setTexture(goboardtex);
	goboard->setPosition(0.0, 1.05, 1.0);
	goboard->setRotation('x', 90, 'y', 90, 'z', 0);
	goboard->setScale(1.5);
	
	
	

	
	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.8, 1.15, 1.2);
	blackgo->setScale(0.1);
	
	


	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.8, 1.15, 1);
	blackgo->setScale(0.1);
	
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.8, 1.15, 0.6);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.8, 1.15, 0.4);
	blackgo->setScale(0.1);


	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.8, 1.15, 0.2);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.6, 1.15, 0.6);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.6, 1.15, 0.2);
	blackgo->setScale(0.1);

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.6, 1.15, -0.2);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.6, 1.15, 0.0);
	blackgo->setScale(0.1);


	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.4, 1.15, 0.4);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(1, 1, 1);
	blackgo->setPosition(-0.4, 1.15, -0.4);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(1, 1, 1);
	blackgo->setPosition(-0.4, 1.15, -0.6);
	blackgo->setScale(0.1);


	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.4, 1.15, -0.8);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.2, 1.15, -0.8);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(1, 1, 1);
	blackgo->setPosition(-0.0, 1.15, -0.8);
	blackgo->setScale(0.1);


	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.2, 1.15, 0.6);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(-0.0, 1.15, 0.6);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.2, 1.15, 0.2);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.2, 1.15, 0.0);
	blackgo->setScale(0.1);


	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.2, 1.15, -0.2);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.2, 1.15, -0.8);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.4, 1.15, 0.2);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.4, 1.15, 0.4);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.4, 1.15, 0.6);
	blackgo->setScale(0.1);


	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.6, 1.15, 0.8);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.6, 1.15, 1.0);
	blackgo->setScale(0.1);


	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.8, 1.15, 1.2);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.8, 1.15, 1.0);
	blackgo->setScale(0.1);
	

	blackgo = new sphere(16);
	blackgo->setColour(0, 0, 0);
	blackgo->setPosition(0.8, 1.15, 0.8);
	blackgo->setScale(0.1);


	



	whitego = new sphere(16);
	whitego->setColour(0, 0, 0);
	whitego->setPosition(-0.4, 1.15, -0.2);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(-1, 1.15, 1.2);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(-1, 1.15, 1);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(-1, 1.15, 0.8);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(-0.8, 1.15, 0.8);
	whitego->setScale(0.1);


	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(-0.6, 1.15, 0.4);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(-0.4, 1.15, 0.4);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(-0.4, 1.15, 0.6);
	whitego->setScale(0.1);


	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(-0.4, 1.15, 0.2);
	whitego->setScale(0.1);


	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(-0.4, 1.15, 0.0);
	whitego->setScale(0.1);


	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(-0.2, 1.15, -0.6);
	whitego->setScale(0.1);


	whitego = new sphere(16);
	whitego->setColour(0, 0, 0);
	whitego->setPosition(-0.0, 1.15, -0.6);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(0.2, 1.15, 0.6);
	whitego->setScale(0.1);


	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(0.2, 1.15, 0.4);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(0.2, 1.15, -0.4);
	whitego->setScale(0.1);


	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(0.2, 1.15, -0.6);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(0.4, 1.15, 0.0);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(0.4, 1.15, -0.2);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(0.6, 1.15, 0.2);
	whitego->setScale(0.1);


	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(0.6, 1.15, 0.4);
	whitego->setScale(0.1);
	

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(0.6, 1.15, 0.6);
	whitego->setScale(0.1);

	whitego = new sphere(16);
	whitego->setColour(1, 1, 1);
	whitego->setPosition(0.6, 1.15, 1.2);
	whitego->setScale(0.1);
	



		
	

}
void gogame::show()
{
	whitego->show();
	blackgo->show();
	goboard->show();
}
void gogame::hide() 
{
	whitego->hide();
	blackgo->hide();
	goboard->hide();
}
