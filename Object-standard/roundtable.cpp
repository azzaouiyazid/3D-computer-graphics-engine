
#include "prefix.h"
#include "roundtable.h"
#include "utility.h"

extern vector<object3d*> gShapeVector;


 roundtable:: roundtable() {
	setName("roundtable");

	tabletex = new texture("wood.jpg", kContinuousTone, kMipmaps);
	table = new tWheel(100);
	table->setTexture(tabletex);
	table->setParent(this);
	
	
	supptex = new texture("metal.jpg", kContinuousTone, kMipmaps);
	supp = new cylinder(80);
	supp->setTexture(supptex);
	supp->setPosition(0.0, 0.0, 0.0);
	supp->setScale(0.7);
	supp->setParent(table);
	
	


	supp = new cylinder(80);
	supp->setTexture(supptex);
	supp->setPosition(0.0, -1.0, 0.0);
	supp->setScale(0.7);
	supp->setParent(table);
	

	supp = new cylinder(80);
	supp->setTexture(supptex);
	supp->setPosition(0.0, -2.0, 0.0);
	supp->setScale(0.7);
	supp->setParent(table);
	
	bottex = new texture("blackbot.jpg", kContinuousTone, kMipmaps);
	bot = new tWheel(80);
	bot->setTexture(bottex);
	bot->setPosition(0.0, -3, 0.0);
	bot->setScale(0.5);
	bot->setParent(table);
	


	gShapeVector.push_back(this);


}






void roundtable::hide() {
	 table->hide();
	 bot->hide();
	 supp->hide();
	 
	

}
void roundtable :: show() {
	
	table->show();
	bot->show();
	supp->show();
	
}