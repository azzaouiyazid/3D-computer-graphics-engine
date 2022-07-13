#include "prefix.h"
#include "tWheel.h"
#include "platform.h"
#include "utility.h"

extern vector<object3d*> gShapeVector;
extern unsigned long	gPolygonCount;			// counts how many polygons get displayed each frame
extern bool             gWireFrameOnly;


tWheel::tWheel(int density) {

	setName("tWheel");
	faceCount =density*3;
	polygonCount = density*3;
	vertexCount =  (density*2)+2;


	vertices.resize(vertexCount);
	faces.resize(faceCount);
	
	int radius = 4; 
	int counter = 0; 
	int facecounter = 0;
	for (int i = 0; i < density; i++)
	{
		float yRot = i * (360.0 / density);
		float x = cos_d(yRot)*radius;
		float z = sin_d(yRot)*radius;
		
		vertices[i].set(x, 1, z);
		vertices[i+density].set(x, 0.8, z);

		counter++; 
	
		
	}
	counter *= 2; 
	vertices[counter++].set(0, 1, 0);
	vertices[counter++].set(0,0.8, 0);
	for (int i = 0; i < density; i++)
	{
		int j = (i + 1) % density;
		faces[facecounter].init(density * 2, j, i);
		faces[facecounter + density].init(density * 2 + 1, i + density, j + density);
		faces[facecounter + density * 2].init(i, j, j + density, i + density);
		facecounter++;
	}
	facecounter *= 3; 

	
	calculateNormals();
	gShapeVector.push_back(this);
	

	
	
}
/* personal Approach : the top and the bot side of the Wheel consist of two circles, these circle can be divided into many triangles shape
	* this will allow us to better allocate the image to be textured .
	* on the other hand , the side Wheel is  different from the previous shapes , since it can be divided into Quads .
	* 
	* --the Cylinder shown is the lecture was mainly to wrap an image on the side cylinder , so i thought it would be better for me to also texture 
	* the circle top and bot since it would be better for optimizing my final project . 
	* 
	* --the idea is " almost simple " : the image will be used three time ; loop each of the three sides around and THEN close the loop by 
	* making the textured image back the angle 0 ;
	* 
	* --Trigonometry will strongly be used to solve the problem since the rotation is highly  implicated .
	* 
	* --since the shape is already drawn using the function tWheel(int density) , the only variable that we need to take in consideration
	* is the Radius and the hight .
	* 
	* the only Problem that i have faced using this approach , is that for some reason , even after closing back the loop of both circles 
	* i still get a small unclear part " kind of blurred image " , i'm strongly open for your suggestions to better optimizing my code , thanks. 
	* 
	* 
	*/

void  tWheel::privateDraw(bool drawmode)
{
	if (theTexture && !gWireFrameOnly)
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, theTexture->id());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, theTexture->bestMagFilter());
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, theTexture->bestMinFilter());
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glScalef(textureScaleX, textureScaleY, 1.0);
		glMatrixMode(GL_MODELVIEW);
	}
	const double PI = 3.1415926;
	double radius = 4;
	double height = 1;

	double i, n = 0.1; //the n variable kind of work the same way how the density work , it will move by 0.1 to the next point of the circle 
	
	 

	glBegin(GL_QUAD_STRIP);
	for (i = 0; i <= 2 * PI; i += n)//this loop will rotate around the circle in a clockwise movement
	{
		const float tcenter = (i / (float)(2 * PI));//to get a number that varies from 0.0 and 1.0 we need to devide i by 2*PI to get the center
		glTexCoord2f(tcenter, 0.0);
		glVertex3f(radius * cos(i), 0, radius * sin(i));
		glTexCoord2f(tcenter, 1.0);
		glVertex3f(radius * cos(i), height, radius * sin(i));
	}
	//texture coordinates to close the loop ;
	glTexCoord2f(0.0, 0.0);
	glVertex3f(radius, 0, 0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(radius, height, 0);

	glEnd();

	//top Circle 
	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0, height, 0);  //center 
	for (i = 2 * PI; i >= 0; i -= n)//this loop will rotate around the circle in a clockwise movement 

	{
		glTexCoord2f(0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f);
		glVertex3f(radius * cos(i), height, radius * sin(i));
	}
	// close the loop back to 0 degrees 
	glTexCoord2f(0.5, 0.5);
	glVertex3f(radius, height, 0);
	glEnd();

	//bot
	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2f(0.5, 0.5);
	glVertex3f(0, 0, 0);  //center 
	for(i = 0; i <= 2 * PI; i += n)//this loop will rorate around the circle in a anticlockwise movement 
	{
		glTexCoord2f(0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f);// we scale the range by using sin/cos (-1 to 1) by 0.5 to have -0.5 to 0.5
		glVertex3f(radius * cos(i), 0, radius * sin(i));
	}
	glTexCoord2f(0.5, 0.5);
	glVertex3f(radius, 0, 0);
	glEnd();
	
	

	if (theTexture && !gWireFrameOnly) glDisable(GL_TEXTURE_2D);
}




	
		

	

	
	
	
