
#include "prefix.h"
#include "chair.h"
#include "utility.h"

extern vector<object3d*> gShapeVector;

chair::chair()
{
	toptex = new texture("couch.jpg", kContinuousTone, kMipmaps);
	top = new tWheel(80);
	top->setTexture(toptex);
	top->setParent(this);


	supptex = new texture("metal.jpg", kContinuousTone, kMipmaps);
	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(0.0, 0.0, -2.5);
	supp->setParent(top);

	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(0.0, -1.0, -2.5);
	supp->setParent(top);

	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(0.0, -2.0, -2.5);
	supp->setParent(top);
	

	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(0.0, 0.0, 2.5);
	supp->setParent(top);

	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(0.0, -1.0, 2.5);
	supp->setParent(top);

	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(0.0, -2.0, 2.5);
	supp->setParent(top);

	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(-2.5, 0.0, 0.0);
	supp->setParent(top);

	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(-2.5, -1.0, 0.0);
	supp->setParent(top);

	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(-2.5, -2.0, 0.0);
	supp->setParent(top);

	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(2.5, 0.0, 0.0);
	supp->setParent(top);

	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(2.5, -1.0, 0.0);
	supp->setParent(top);

	supp = new cylinder(16);
	supp->setTexture(supptex);
	supp->setScale(0.5);
	supp->setPosition(2.5, -2.0, 0.0);
	supp->setParent(top);


	gShapeVector.push_back(this);

}

void chair::show()
{
	top->show();
	supp->show();
	
}
void chair::hide()
{
	top->hide();
	supp->hide();
	
}