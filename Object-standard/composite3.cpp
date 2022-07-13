
#include "prefix.h"
#include "composite3.h"
#include "utility.h"

extern vector<object3d*> gShapeVector;

trafficlight::trafficlight()
{
	textop = new texture("blackbot.jpg", kContinuousTone, kMipmaps);
	top = new tcuboid();
	top->setTexture(textop);
	top->setRotation('x', 0, 'y', 0.0, 'z', 90.0);
	top->setScale(1.8);
	top->setParent(this);

	red = new sphere(80);
	red->setScale(0.5);
	red->setColour(0.0, 0.0, 0.0);
	red -> setPosition(0.4, 0.0, 0.8);
	red->setParent(top);

	yellow = new sphere(80);
	yellow->setScale(0.5);
	yellow->setColour(0.0, 0.0, 0.0);
	yellow->setPosition(-0.5, 0.0, 0.8);
	yellow->setParent(top);

	green = new sphere(80);
	green->setScale(0.5);
	green->setColour(0.0, 0.0, 0.0);
	green->setPosition(-1.4, 0.0, 0.8);
	green->setParent(top);

	texsupp = new texture("metal.jpg", kContinuousTone, kMipmaps);

	supp = new cylinder(80);
	supp->setScale(0.4);
	supp->setTexture(texsupp);
	supp->setPosition(-2.3, 0.0, 0.0);
	supp->setRotation('x', 0, 'y', 0.0, 'z', 90.0);
	supp->setParent(top);

	supp = new cylinder(80);
	supp->setScale(0.4);
	supp->setTexture(texsupp);
	supp->setPosition(-3.0, 0.0, 0.0);
	supp->setRotation('x', 0, 'y', 0.0, 'z', 90.0);
	supp->setParent(top);

	supp = new cylinder(80);
	supp->setScale(0.4);
	supp->setTexture(texsupp);
	supp->setPosition(-3.7, 0.0, 0.0);
	supp->setRotation('x', 0, 'y', 0.0, 'z', 90.0);
	supp->setParent(top);

	supp = new cylinder(80);
	supp->setScale(0.4);
	supp->setTexture(texsupp);
	supp->setPosition(-4.4, 0.0, 0.0);
	supp->setRotation('x', 0, 'y', 0.0, 'z', 90.0);
	supp->setParent(top);

	supp = new cylinder(80);
	supp->setScale(0.4);
	supp->setTexture(texsupp);
	supp->setPosition(-5.0, 0.0, 0.0);
	supp->setRotation('x', 0, 'y', 0.0, 'z', 90.0);
	supp->setParent(top);

	supp = new cylinder(80);
	supp->setScale(0.4);
	supp->setTexture(texsupp);
	supp->setPosition(-5.7, 0.0, 0.0);
	supp->setRotation('x', 0, 'y', 0.0, 'z', 90.0);
	supp->setParent(top);
	



}
void trafficlight::show()
{
	top->show();
	red->show();
	yellow->show();
	green->show();
	supp->show();
}
void trafficlight::hide()
{
	top->hide();
	red->hide();
	yellow->hide();
	green->hide();
	supp->hide();

}

void trafficlight::animate(float time)
{
	if (time > 0.0 && time <= 1.5)
	{
		red->setColour(1.0, 0.0, 0.0);
		yellow->setColour(0.0, 0.0, 0.0);
		green->setColour(0.0, 0.0, 0.0);
	}
	if (time > 1.5 && time <= 3)
	{
		red->setColour(0.0, 0.0, 0.0);
		yellow->setColour(1.0, 1.0, 0.0);
		green->setColour(0.0, 0.0, 0.0);

	}
	if (time > 3 && time <= 4.5)
	{
		red->setColour(0.0, 0.0, 0.0);
		yellow->setColour(0.0, 0.0, 0.0);
		green->setColour(0.0, 1.0, 0.0);
	}


};