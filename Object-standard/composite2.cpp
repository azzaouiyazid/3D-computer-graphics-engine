
#include "prefix.h"
#include "composite2.h"
#include "utility.h"

extern vector<object3d*> gShapeVector;

building::building()
{
	texbuild = new texture("brick.jpg", kContinuousTone, kMipmaps);
	build = new tcuboid();
	build->setTexture(texbuild);
	build->setRotation('x', 0.0, 'y', 0.0, 'z', 90.0);
	build->setScale(10);
	build->setParent(this);

	wind4 = new plane();
	wind4->setColour(0.0,0.0,0.0);
	wind4->setParent(build);
	wind4->setScale(0.2);
	wind4->setPosition(0.6, 0.4, 1.01);
	wind4->setRotation('x', 0.0, 'y', 0.0, 'z', 90.0);

	wind1 = new plane();
	wind1->setColour(0.0, 0.0, 0.0);
	wind1->setParent(build);
	wind1->setScale(0.2);
	wind1->setPosition(0.0, 0.4, 1.01);
	wind1->setRotation('x', 0.0, 'y', 0.0, 'z', 90.0);

	wind2 = new plane();
	wind2->setColour(0.0, 0.0, 0.0);
	wind2->setParent(build);
	wind2->setScale(0.2);
	wind2->setPosition(-0.6, 0.4, 1.01);
	wind2->setRotation('x', 0.0, 'y', 0.0, 'z', 90.0);

	wind3 = new plane();
	wind3->setColour(0.0, 0.0, 0.0);
	wind3->setParent(build);
	wind3->setScale(0.2);
	wind3->setPosition(0.6, -0.5, 1.01);
	wind3->setRotation('x', 0.0, 'y', 0.0, 'z', 90.0);

	wind = new plane();
	wind->setColour(0.0, 0.0, 0.0);
	wind->setParent(build);
	wind->setScale(0.2);
	wind->setPosition(0.0, -0.5, 1.01);
	wind->setRotation('x', 0.0, 'y', 0.0, 'z', 90.0);

	wind = new plane();
	wind->setColour(0.0, 0.0, 0.0);
	wind->setParent(build);
	wind->setScale(0.2);
	wind->setPosition(-0.6, -0.5, 1.01);
	wind->setRotation('x', 0.0, 'y', 0.0, 'z', 90.0);
	





}
void building::show()
{
	build->show();
	wind->show();
	wind1->show();



}
void building::hide()
{
	wind1->hide();
	wind->hide();
	build->hide();
}

void building::animate(int time)
{
	if (time % 2 == 0)
	{
		wind1->setColour(1.0, 1.0, 0.0);
		wind->setColour(0.0, 0.0, 0.0);
		wind2->setColour(0.0, 0.0, 0.0);
		wind3->setColour(0.0, 0.0, 0.0);
		wind4->setColour(1.0, 1.0, 0.0);



	}
	else if (!(time % 2 == 0))
	{
		wind1->setColour(0.0, 0.0, 0.0);
		wind->setColour(1.0, 1.0, 0.0);
		wind2->setColour(1.0, 1.0, 0.0);
		wind3->setColour(1.0, 1.0, 0.0);
		wind4->setColour(0.0, 0.0, 0.0);
	}

}