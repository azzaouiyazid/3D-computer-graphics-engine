#include "prefix.h"
#include "space.h"
#include "utility.h"

extern vector<object3d*> gShapeVector;


space::space() {
	bottex = new texture("tapis.jpg", kContinuousTone, kMipmaps);
	bot = new squareplane();
	bot->setTexture(bottex);
	bot->setPosition(0.0, -4.0, 0.0);	
	bot->setRotation('x', 90, 'y', 0, 'z', 0);
	bot->setScale(20);


	/*backtex = new texture("back.png", kContinuousTone, kMipmaps);
	back= new squareplane();
	back->setTexture(backtex);
	back->setPosition(0.0, 46.0, -50.0);
	back->setScale(50);

	toptex = new texture("top.png", kContinuousTone, kMipmaps);
	top = new squareplane();
	top->setTexture(toptex);
	top->setPosition(0.0, 96.0, 0.0);
	top->setRotation('x', 90, 'y', 0, 'z', 0);
	top->setScale(50);

    lefttex = new texture("left.png", kContinuousTone, kMipmaps);
	left= new squareplane();
	left->setTexture(lefttex);
	left->setPosition(-50.0, 46.0, 0.0);
	left->setRotation('x', 90, 'y', 90, 'z', 90);
	left->setScale(50);

	righttex = new texture("right.png", kContinuousTone, kMipmaps);
	right = new squareplane();
	right->setTexture(righttex);
	right->setPosition(100.0, 46.0, 0.0);
	right->setRotation('x', 90, 'y', 90, 'z', 90);
	right->setScale(50);



	fronttex = new texture("front.png", kContinuousTone, kMipmaps);
	front = new squareplane();
	front->setTexture(fronttex);
	front->setPosition(0.0, 46.0, 50.0);
	front->setScale(50);
	*/
	
}

void space :: show() {

}
void space::hide()
{

}