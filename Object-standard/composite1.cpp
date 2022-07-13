
#include "prefix.h"
#include "composite1.h"
#include "utility.h"

extern vector<object3d*> gShapeVector;

car::car()
{
	up = new tcuboid();
	up->setPosition(0.0, 2.0, 0.0);
	up -> setColour(1.0, 0.0, 0.0);
	up->setScale(3);
	up->setParent(this);

	up1 = new tcuboid();
	up1->setColour(1.0, 1.0, 1.0);
	up1->setPosition(2.0, -0.5, 0.0);
	up1->setScale(0.5);
	up1->setParent(up);

	up1 = new tcuboid();
	up1->setColour(0.0, 0, 0.0);
	up1->setPosition(1.5, 0.3, 0.0);
	up1->setScale(0.3);
	up1->setParent(up);

	wheeltex = new texture("wheel.jpg", kContinuousTone, kMipmaps);
	wheel = new tWheel(80);
	wheel->setTexture(wheeltex);
	wheel->setPosition(-2, -1.8, -1.0);
	wheel->setRotation('x',90.0,'y',0.0,'z', 90.0);
	wheel->setScale(0.2);
	wheel->setParent(up);

	wheel1 = new tWheel(80);
	wheel1->setTexture(wheeltex);
	wheel1->setPosition(1, -1.8, 0.8);
	wheel1->setRotation('x', 90.0, 'y', 0.0, 'z', 90.0);
	wheel1->setScale(0.2);
	wheel1->setParent(up);

	wheel2 = new tWheel(80);
	wheel2->setTexture(wheeltex);
	wheel2->setPosition(1, -1.8, -1);
	wheel2->setRotation('x', 90.0, 'y', 0.0, 'z', 90.0);
	wheel2->setScale(0.2);
	wheel2->setParent(up);

	wheel3 = new tWheel(80);
	wheel3->setTexture(wheeltex);
	wheel3->setPosition(-2, -1.8, 1.0);
	wheel3->setRotation('x', 90.0, 'y', 0.0, 'z', 90.0);
	wheel3->setScale(0.2);
	wheel3->setParent(up);

	
	window = new plane();
	window->setScale(0.3);
	window->setPosition(0.1,0.2,1.009);
	window->setParent(up);

	window = new plane();
	window->setScale(0.3);
	window->setPosition(-1.4, 0.2, 1.009);
	window->setParent(up);


}

void car::show()
{
	window->show();
	up->show();
	up1->show();
	wheel->show();
	wheel1->show();
	wheel2->show();
	wheel3->show();


}
void car::hide()
{
	window->hide();
	up->hide();
	up1->hide();
	wheel->hide();
	wheel1->hide();
	wheel2->hide();
	wheel3 ->hide();
	

}

void car::animate(float time)
{
	wheel->setRotation('x', 90, 'z', -time * 30);
	wheel1->setRotation('x', 90, 'z', -time * 30);
	wheel2->setRotation('x', 90, 'z', -time * 30);
	wheel3->setRotation('x', 90, 'z', -time * 30);
	
}