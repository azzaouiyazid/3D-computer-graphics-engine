#include "prefix.h"
#include "sequenceb.h"
#include "utility.h"

extern vector<object3d*> gShapeVector;

sequenceb::sequenceb()
{
	b = new building();
	b->setScale(2);
	b->setPosition(0.0, 35.0, -120);
	b1 = new building();
	b1->setScale(1.7);
	b1->setPosition(40, 30.0, -115);
	b2 = new building();
	b2->setScale(1.7);
	b2->setPosition(80, 30.0, -115);
	b3 = new building();
	b3->setScale(2.2);
	b3->setPosition(-45, 40.0, -120);
	b4 = new building();
	b4->setScale(2.2);
	b4->setPosition(-45, 80.0, -120);
	b5= new building();
	b5->setScale(1.7);
	b5->setPosition(-85, 30.0, -115);
	b6 = new building();
	b6->setScale(1.7);
	b6->setPosition(-85, 60.0, -115);
	b7 = new building();
	b7->setScale(2);
	b7->setPosition(0.0, 75.0, -120);
}
void sequenceb::show()
{
	b->show();
	b1->show();
	b2->show();
	b3->show();
	b4->show();
	b5->show();
	b6->show();
	b7->show();


}
void sequenceb::hide()
{
	b->hide();
	b1->hide();
	b2->hide();
	b3->hide();
	b4->hide();
	b5->hide();
	b6->hide();
	b7->hide();

}

void sequenceb::animate(float time)
{
	b->animate(time);
	b1->animate(time);
	b2->animate(time);
	b3->animate(time);
	b4->animate(time);
	b5->animate(time);
	b6->animate(time);
	b7->animate(time);

}