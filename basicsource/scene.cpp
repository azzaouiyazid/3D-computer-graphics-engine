
// scene.cpp



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "constants.h"			// system-wide constants
#include "utility.h"			// general utility functions
#include "light.h"
#include "camera.h"
#include "texture.h"
#include "scene.h"
#include "snd.h"
#include "skybox.h"
#include "fog.h"
#include "viewfrustum.h"


#include "../go.h"           // in case the file couldn't find these ../files , remove it from the object-student directely to the basecode
#include "../roundtable.h"
#include "../chair.h"
#include "../composite1.h"
#include "../road.h"
#include "../sequenceb.h"
#include "../adsboard.h"
#include "../composite3.h"
#include "sweep.h"
#include "extrusion.h"
#include "cube.h"
#include "sphere.h"
#include "torus.h"
#include "terrain.h"
#include "billboard.h"
#include "plane.h"
#include "tsphere.h"
#include "cylinder.h"
#include "disc.h"



// -----------------------------------------------------------------------------------------
// global variables
// -----------------------------------------------------------------------------------------
extern ProgramMode		gProgramMode;							// initially, we're not animating

extern cameraClass		gCamera;								// the camera
extern object3d* gSky;									// the global skybox
extern fog* gFog;									// the global fog
extern viewfrustum* gViewFrustum;							// the global view frustum object
extern float			gCurrentFrameTime;						// the time that the current animation frame was started

extern vector<object3d*> gShapeVector;
typedef vector<object3d*>::iterator shapeVectorIterator;






// -----------------------------------------------------------------------------------------
// variables that represent 3D objects being used in the animation
// -----------------------------------------------------------------------------------------
// these are really global variables, but you shouldn't need to access them from anywere
// except in this file 
// -----------------------------------------------------------------------------------------

// shapes

snd* s;
snd* s1;
car* c;
car* c1;
car* c2;
car* c3;
roundtable* cozytable; 
gogame* go; 
terrain* theground;
chair* couch; 
chair* couch1;
chair* couch2;
chair* couch3;
road* r; 
texture* roadtex;
sequenceb* b;
adsboard* zjut;
trafficlight* traffic; 





// some lights
light* ambient, * light0, * light1, * light2;



// -----------------------------------------------------------------------------------------
// constructScene
// -----------------------------------------------------------------------------------------
// This function constructs the objects required for the animation.  It is only called once
// when the program is first run.
// Use this to create child objects and bind them to their parents.
// -----------------------------------------------------------------------------------------

void constructScene()
{
	// create the lights first
	ambient = new light(GL_LIGHT_MODEL_AMBIENT);
	light0 = new light(GL_LIGHT0);
	light1 = new light(GL_LIGHT1);



	traffic = new trafficlight();
	traffic->setScale(2.0);
	traffic->setPosition(-63, 16, -55); 

	gSky = new skybox("sky22-");
	
	
	
	b = new sequenceb();
    s = new snd("Traffic-Noise-Sound-Effect.ogg");
	s1 = new snd("Mario Kart Race Start - traffic light beeping.ogg");
	

	c = new car();
	c->setScale(1.5);
	c->setPosition(-45.0, 4.5, -65.0);

	c1 = new car();
	c1->setScale(1.5);
	c1->setPosition(70.0004, 4.5, -78.0);
	c1->setRotation('x', 0.0, 'y', -90.0, 'z', 0.0);

	c2 = new car();
	c2->setScale(1.5);
	c2->setPosition(70.0004,4.5,95);
	c2->setRotation('x', 0.0, 'y', -180.0, 'z', 0.0);

	c3 = new car();
	c3->setScale(1.5);
	c3->setPosition(-80.0, 4.5, 95);
	c3->setRotation('x', 0.0, 'y', 90, 'z', 0.0);
	
	

	theground = new terrain("ground.bmp");
	theground->setPosition(0, -25, -50);
	theground->setColour(0, 1, 0);
	theground->setShininess(2);
	theground->setScale(20);
	

	cozytable = new roundtable();
	go = new gogame();
	
	couch = new chair();
	couch->setPosition(-8.0, -1.5, 0.0);
	couch->setScale(0.6);

	couch1 = new chair();
	couch1->setPosition(8.0, -1.5, 0.0);
	couch1->setScale(0.6);

	couch2 = new chair();
	couch2->setPosition(40, -3, 40);
	couch2->setScale(0.6);

	couch3 = new chair();
	couch3->setPosition(30, -3, 40);
	couch3->setScale(0.6);

	roadtex = new texture("road.jpg",kContinuousTone,kMipmaps);

	r = new road();
	r->setTexture(roadtex);
	r->setPosition(-90.0, -5.0, -78.0);
	r->setRotation('x', -90.0, 'y', 0.0, 'z', 0.0);
	r->setScale(1.5);

	r = new road();
	r->setTexture(roadtex);
	r->setPosition(-86.0, -5.0, -99.0);
	r->setRotation('x', -90.0, 'y', -90.0, 'z', 0.0);
	r->setScale(1.5);
	
	r = new road();
	r->setTexture(roadtex);
	r->setPosition(80.0, -5.0, -99.0);
	r->setRotation('x', -90.0, 'y', -90.0, 'z', 0.0);
	r->setScale(1.5);

	r = new road();
	r->setTexture(roadtex);
	r->setPosition(-107.0, -5.0, 90.0);
	r->setRotation('x', -90.0,'y', 0.0, 'z', 0.0);
	r->setScale(1.75);
	

	zjut = new adsboard();
	zjut->setScale(1.5);
	zjut->setPosition(-40, 45, 40); 
	
	
	


	

	


}




// -----------------------------------------------------------------------------------------
// resetScene
// -----------------------------------------------------------------------------------------
// This function is called whenever the animation is restarted.  Use it to reset objects
// to their starting position or size, or to reset any aspects of the objects that
// might have been altered during an animation sequence.
// -----------------------------------------------------------------------------------------

void resetScene()
{
	// initialise the camera
	gCamera.setPosition(-63, 16, 0.1);
	gCamera.setTarget(-63, 16, 0);

	

	ambient->setColour(0.5, 0.5, 0.5, 1.0);

	light0->turnOn();
	light0->setPosition(0, 20.0, 20);
	light0->setColour(0.7, 0.7, 0.7, 1.0);
	light0->setSpecularColour(0.7, 0.7, 0.7, 1.0);
	light0->makePositional();
	light0->setLinearAttenuation(0.1);

	light1->turnOn();
	light1->setPosition(10, 20.0, 0);
	light1->setColour(0.7, 0.7, 0.7, 1.0);
	light1->setSpecularColour(0.7, 0.7, 0.7, 1.0);
	light1->makePositional();
	light1->setLinearAttenuation(0.1);
}




// -----------------------------------------------------------------------------------------
// animateForNextFrame
// -----------------------------------------------------------------------------------------
// This function is called to animate objects ready for the next frame
// -----------------------------------------------------------------------------------------

void animateForNextFrame(float time, long frame)
{
	if (time >= 0 && time <= 5.0)
	{
		s1->startSound();
		traffic->animate(time);

	}
		
	
	
	else  
	{
		s1->stopSound();
		s->startSound();
		zjut->animate(time);
		b->animate(time);

		float z1 = 0.1 + (pow(time,2));
		float p1 = -20;
		float p2 = +70;
		float duration = 50.0;

		float x = (((p2 - p1) / duration) * time) + p1;
		c->setPosition(x, 4.5, -65.0);
		c->animate(time);
		c1->setPosition(70.0004, 4.5, x);
		c1->animate(time);
		c2->setPosition(-x, 4.5, 95);
		c2->animate(time);
		c3->setPosition(-80.0, 4.5, -x);
		c3->animate(time);
		gCamera.setTarget(0.0, 0.0, 0.0);

			gCamera.setPosition(0, 50, z1);
			
			if (z1 >= 230)
			{
				gCamera.setPosition(0, 50, 230);
			}
				
			
		
		

		
		

	}
	

	if ( time >= 30)
	{
		gProgramMode = kpmFinished;
	}
	
	
	
		
	
	

	
	
	
	


	
	
	
	
}
		
		

	
	
	
	
	




	

		

	
	






