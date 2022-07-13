
#include "prefix.h"
#include "adsboard.h"
#include "utility.h"

extern vector<object3d*> gShapeVector;

adsboard::adsboard()
{
	 texsphere= new texture("logo.jpg",kContinuousTone,kMipmaps);
	ad = new tsphere(80);
	ad->setScale(7);
	ad->setTexture(texsphere);
	ad->setParent(this);

	texwheel = new texture("blackbot.jpg", kContinuousTone, kMipmaps);
	bot = new tWheel(80);
	bot->setScale(0.2);
	bot -> setTexture(texwheel);
	bot->setParent(ad);
	bot->setPosition(0.0,-2,0.0);

	supptex = new texture("metal.jpg", kContinuousTone, kMipmaps);
	supp = new cylinder(80);
	supp->setScale(0.2);
	supp->setTexture(supptex);
	supp->setPosition(0.0,-2.0,0.0);
	supp->setParent(ad);

	supp = new cylinder(80);
	supp->setScale(0.2);
	supp->setTexture(supptex);
	supp->setPosition(0.0, -2.4, 0.0);
	supp->setParent(ad);

	supp = new cylinder(80);
	supp->setScale(0.2);
	supp->setTexture(supptex);
	supp->setPosition(0.0, -2.8, 0.0);
	supp->setParent(ad);

	supp = new cylinder(80);
	supp->setScale(0.2);
	supp->setTexture(supptex);
	supp->setPosition(0.0, -3.2, 0.0);
	supp->setParent(ad);

	supp = new cylinder(80);
	supp->setScale(0.2);
	supp->setTexture(supptex);
	supp->setPosition(0.0, -3.6, 0.0);
	supp->setParent(ad);

	supp = new cylinder(80);
	supp->setScale(0.2);
	supp->setTexture(supptex);
	supp->setPosition(0.0, -3.8, 0.0);
	supp->setParent(ad);

	supp = new cylinder(80);
	supp->setScale(0.2);
	supp->setTexture(supptex);
	supp->setPosition(0.0, -4.2, 0.0);
	supp->setParent(ad);

	supp = new cylinder(80);
	supp->setScale(0.2);
	supp->setTexture(supptex);
	supp->setPosition(0.0, -4.4, 0.0);
	supp->setParent(ad);

	bot = new tWheel(80);
	bot->setScale(0.3);
	bot -> setTexture(texwheel);
	bot->setParent(ad);
	bot->setPosition(0.0, -4.8, 0.0);

	




}
void adsboard::show()
{
	supp->show();
	bot->show();
	ad->show();


}
void adsboard::hide()
{
	ad->hide();
	bot->hide();
	supp->hide();
}

void adsboard::animate(float time)
{
	this->setPosition(-40, 45, 40);
	ad->setRotation('x', 0, 'y', -time * 30, 'z', 0);
}

