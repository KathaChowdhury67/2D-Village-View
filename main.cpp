#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#define PI 3.1416


int windowWidth=1000;
int windowHeight=500;

double xboat1=0;
double yboat1=0;
double xboat2=0;
double yboat2=0;
double sun=0;
double cld=0;
double xvan=0;
double yvan=0;
double xcar=0;
double ycar=0;
double xbird=0;
double ybird=0;
bool flagScale=false;


//sun
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 100; //of triangles used to draw circle
	GLfloat twicePi = 2.0f * PI;


	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); //center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}


//cloud 1
void cloud (void)
{
   glPushMatrix();
   glColor3f(1.000, 1.000, 1.000);
   glTranslatef(cld,0,0);
   drawFilledCircle(20,180,9.5);
   glPopMatrix();

   glPushMatrix();
   glColor3f(1.000, 1.000, 1.000);
   glTranslatef(cld,0,0);
   drawFilledCircle(46,180,9.5);
   glPopMatrix();

    glPushMatrix();
   glColor3f(1.000, 1.000, 1.000);
   glTranslatef(cld,0,0);
   drawFilledCircle(33,185,10.5);
   glPopMatrix();

    glPushMatrix();
   glColor3f(1.000, 1.000, 1.000);
   glTranslatef(cld,0,0);
   drawFilledCircle(33,175,10.5);
   glPopMatrix();
}


void bird (void)
{
      glPushMatrix();
  glBegin(GL_POLYGON);
   glColor3f(0.0,0.0,0.0);

  glVertex2f(xbird+301,ybird+177.5);
  glVertex2f(xbird+300.5,ybird+176);
  glVertex2f(xbird+302,ybird+176);
  glVertex2f(xbird+300,ybird+174.5);

 glEnd();
glPopMatrix();
}



void pahar (void)
{
      glPushMatrix();
  glBegin(GL_TRIANGLES);

  glColor3f(0.133, 0.545, 0.133);
  glVertex2f(0,135);
  glColor3f(0.196, 0.804, 0.196);
  glVertex2f(50,135);
  glColor3f(0.502, 0.502, 0.000);
  glVertex2f(25,160);

   glEnd();
glPopMatrix();
}


//tree 1
void tree1 (void)
{
       glPushMatrix();
   glBegin(GL_QUADS);
   glColor3f(0.622, 0.425, 0.033);

   glVertex2f(45,153);
   glVertex2f(51,153);
   glVertex2f(51,128);
   glVertex2f(45,128);

 glEnd();
glPopMatrix();

   glPushMatrix();
   glColor3f(0.196, 0.804, 0.196);
   drawFilledCircle(43,155,6.5);
   glPopMatrix();

   glPushMatrix();
   glColor3f(0.196, 0.804, 0.196);
   drawFilledCircle(53,155,6.5);
   glPopMatrix();

    glPushMatrix();
   glColor3f(0.196, 0.804, 0.196);
   drawFilledCircle(48,161,6.5);
   glPopMatrix();
}



void tree2 (void)
{
  glPushMatrix();
  glBegin(GL_TRIANGLES);

  glColor3f(0.196, 0.804, 0.196);
  glVertex2f(180,143);
  glColor3f(0.000, 1.000, 0.000);
  glVertex2f(196,143);
  glColor3f(0.420, 0.557, 0.137);
  glVertex2f(188,150);

  glColor3f(0.196, 0.804, 0.196);
  glVertex2f(178,138);
  glColor3f(0.000, 1.000, 0.000);
  glVertex2f(198,138);
  glColor3f(0.420, 0.557, 0.137);
  glVertex2f(188,148);

  glColor3f(0.196, 0.804, 0.196);
  glVertex2f(176,133);
  glColor3f(0.000, 1.000, 0.000);
  glVertex2f(200,133);
  glColor3f(0.420, 0.557, 0.137);
  glVertex2f(188,146);

 glEnd();
glPopMatrix();


  glPushMatrix();
  glBegin(GL_QUADS);
 glColor3f(0.622, 0.425, 0.033);

  glVertex2f(185,133);
  glVertex2f(191,133);
  glVertex2f(191,108);
  glVertex2f(185,108);

 glEnd();
glPopMatrix();
}


void street_strip (void)
{
      glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(1.000, 1.000, 1.000);

  glVertex2f(3,64.5);
  glVertex2f(13,66);
  glVertex2f(13,68);
  glVertex2f(3,66.5);

 glEnd();
glPopMatrix();
}



void lamp_post (void)
{
      glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.000, 0.000, 0.000);

  glVertex2f(117,79.5);
  glVertex2f(117,99.5);
  glVertex2f(119,99.5);
  glVertex2f(119,79.7);
  glEnd();
  glPopMatrix();


      glPushMatrix();
   glColor3f(1.000, 1.000, 1.000);
   drawFilledCircle(118,102.5,3);
   glPopMatrix();
}



void strip (void)
{
      glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(1.0, 1.0, 1.);

  glVertex2f(xboat2+263,yboat2+29);
  glVertex2f(xboat2+263,yboat2+31);
  glVertex2f(xboat2+276,yboat2+31);
  glVertex2f(xboat2+276,yboat2+29);

   glEnd();
glPopMatrix();
}


void piller (void)
{
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.0, 0.0, 0.0);

  glVertex2f(xboat2+265,yboat2+35);
  glVertex2f(xboat2+265,yboat2+55);
  glVertex2f(xboat2+275,yboat2+55);
  glVertex2f(xboat2+275,yboat2+35);

  glColor3f(1.000, 0.843, 0.000);

  glVertex2f(xboat2+265,yboat2+57);
  glVertex2f(xboat2+265,yboat2+55);
  glVertex2f(xboat2+275,yboat2+55);
  glVertex2f(xboat2+275,yboat2+57);

 glEnd();
glPopMatrix();
}


void display(void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
gluOrtho2D(0, 400, 0, 200);
glMatrixMode( GL_MODELVIEW );
glLoadIdentity();
glViewport(0, 0 ,windowWidth ,windowHeight);


//sky
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(0.802, 0.802, 0.990);

  glVertex2f(0,135);
  glVertex2f(0,200);
  glVertex2f(400,200);
  glVertex2f(400,135);

 glEnd();
glPopMatrix();


//sun
   glPushMatrix();
   glColor3f(1.000, 1.000, 0.000);
   glTranslatef(sun,0,0);
   drawFilledCircle(120,185,7.5);
   glPopMatrix();

   glPushMatrix();
   glColor3f(1.0, 0.850, 0.000);
   glTranslatef(sun,0,0);
   drawFilledCircle(120,185,5.5);
   glPopMatrix();

   glPushMatrix();
   glColor3f(1.000, 0.700, 0.000);
   glTranslatef(sun,0,0);
   drawFilledCircle(120,185,3.5);
   glPopMatrix();


//cloud 2,3
cloud();
glPushMatrix();
glTranslatef(150,0, 0);
cloud();
glTranslatef(190,0, 0);
cloud();
glPopMatrix();



//bird
bird();
glPushMatrix();
glTranslatef(-3,0,0);
bird();
glTranslatef(-3,0,0);
bird();
glTranslatef(-3,0,0);
bird();
glPopMatrix();

glPushMatrix();
glTranslatef(-3,3,0);
bird();
glTranslatef(-3,0,0);
bird();
glTranslatef(-3,0,0);
bird();
glTranslatef(-3,0,0);
bird();
glPopMatrix();

glPushMatrix();
glTranslatef(-3,-3,0);
bird();
glTranslatef(-3,0,0);
bird();
glTranslatef(-3,0,0);
bird();
glTranslatef(-3,0,0);
bird();
glPopMatrix();




//pahar
pahar();
  glPushMatrix();
  glBegin(GL_TRIANGLES);
  glColor3f(0.133, 0.545, 0.133);
//1
  glVertex2f(0,135);
  glVertex2f(25,135);
  glVertex2f(0,155);
//17
  glVertex2f(375,135);
  glVertex2f(400,135);
  glVertex2f(400,155);
glEnd();
glPopMatrix();
//pahar 3,5,7,9,11,13,15
glPushMatrix();
glTranslatef(25,20.5, 0);
glScalef(1,0.85, 1);
pahar();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glPopMatrix();
//pahar 2,4,6,8,10,12,14,16
glPushMatrix();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glTranslatef(50,0, 0);
pahar();
glPopMatrix();



//field
  glPushMatrix();
  glBegin(GL_POLYGON);
   glColor3f(0.801,0.778,0.480);

  glVertex2f(0,135);
  glVertex2f(400,135);
  glVertex2f(400,100);
  glVertex2f(0,50);

 glEnd();
glPopMatrix();



//tree 1
tree1();
glPushMatrix();
glTranslatef(-40,0,0);
tree1();
glTranslatef(80,0,0);
tree1();
glPopMatrix();

glPushMatrix();
glTranslatef(-20,-10,0);
tree1();
glTranslatef(40,0,0);
tree1();
glPopMatrix();


//tree 2
tree2();
glPushMatrix();
glTranslatef(-14,14,0);
tree2();
glTranslatef(25,0,0);
tree2();
glTranslatef(25,0,0);
tree2();
glPopMatrix();

glPushMatrix();
glTranslatef(25,0,0);
tree2();
glTranslatef(25,0,0);
tree2();
glPopMatrix();


//tree 3

glPushMatrix();
glTranslatef(210,-2,0);
tree1();
glTranslatef(45,0,0);
tree1();
glTranslatef(45,0,0);
tree1();
glPopMatrix();

glPushMatrix();
glTranslatef(233,-10,0);
tree1();
glTranslatef(45,3,0);
tree1();
glPopMatrix();



//house 1
//large rectangle
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(0.867, 0.627, 0.867);

  glVertex2f(26.5,123);
  glVertex2f(29,121);
  glVertex2f(84.5,129);
  glVertex2f(84.5,110.5);
  glVertex2f(26.5,100);

 glEnd();
glPopMatrix();


//top
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.8,0.8,0.8);

  glVertex2f(13,135);
  glVertex2f(75,142);
  glVertex2f(87,129);
  glVertex2f(28,121);

 glEnd();
glPopMatrix();


//left triangle
  glPushMatrix();
  glBegin(GL_TRIANGLES);
  glColor3f(0.9,0.9,0.9);

  glVertex2f(13,135);
  glVertex2f(3.5,124.6);
  glVertex2f(26.5,123);

 glEnd();
glPopMatrix();


//left rectangle
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.855, 0.539, 0.839);

  glVertex2f(6,124.5);
  glVertex2f(6,103);
  glVertex2f(26.5,100);
  glVertex2f(26.5,123);

 glEnd();
glPopMatrix();


//door
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);

  glVertex2f(51.5,122.75);
  glVertex2f(51.5,104.2);
  glVertex2f(60.5,105.9);
  glVertex2f(60.5,124);

 glEnd();
glPopMatrix();


//door left part
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.722, 0.525, 0.043);

  glVertex2f(51.5,122.75);
  glVertex2f(51.5,104.2);
  glVertex2f(54,106);
  glVertex2f(54,120.5);

glEnd();
glPopMatrix();


//door right part
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.722, 0.525, 0.043);

  glVertex2f(60.5,124);
  glVertex2f(60.5,105.9);
  glVertex2f(58.2,106.7);
  glVertex2f(58.2,121.5);

 glEnd();
glPopMatrix();


//window 1
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.98,0.98,0.98);

  glVertex2f(12,118.5);
  glVertex2f(12,110.3);
  glVertex2f(19,109.2);
  glVertex2f(19,118.2);

   glEnd();
glPopMatrix();

//gril 1
  glPushMatrix();
  glBegin(GL_LINES);
  glColor3f(0.0,0.0,0.0);

  glVertex2f(12,115.52);
  glVertex2f(19,115.1);

  glVertex2f(12,112.8);
  glVertex2f(19,112.15);

  glVertex2f(14.2,117.6);
  glVertex2f(14.2,110);

  glVertex2f(16.5,118.05);
  glVertex2f(16.5,109.3);

   glEnd();
glPopMatrix();

//window 2
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.98,0.98,0.98);

  glVertex2f(33,108.2);
  glVertex2f(33,117.2);
  glVertex2f(43,118.6);
  glVertex2f(43,110);

   glEnd();
glPopMatrix();

//gril 2
  glPushMatrix();
  glBegin(GL_LINES);
  glColor3f(0.0,0.0,0.0);

  glVertex2f(33,114.2);
  glVertex2f(43,115.9);

  glVertex2f(33,111.2);
  glVertex2f(43,112.7);

  glVertex2f(36.25,117.63);
  glVertex2f(36.25,108.18);

  glVertex2f(39.75,117.75);
  glVertex2f(39.75,109.5);

    glEnd();
glPopMatrix();

//window 3
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.98,0.98,0.98);

  glVertex2f(68.5,113.5);
  glVertex2f(68.5,122.5);
  glVertex2f(78.5,123.7);
  glVertex2f(78.5,115.5);

   glEnd();
glPopMatrix();

//gril 3
  glPushMatrix();
  glBegin(GL_LINES);
  glColor3f(0.0,0.0,0.0);

  glVertex2f(68.5,119.5);
  glVertex2f(78.5,121);

  glVertex2f(68.5,116.5);
  glVertex2f(78.5,118.5);

  glVertex2f(72,122.95);
  glVertex2f(72,113.8);

  glVertex2f(75,123.2);
  glVertex2f(75,114.1);

  glEnd();
glPopMatrix();

//siri 1
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.933,0.910,0.667);

  glVertex2f(31,100.9);
  glVertex2f(81,109.9);
  glVertex2f(83,108);
  glVertex2f(33,98.5);

   glEnd();
glPopMatrix();

//siri 2
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.741, 0.718, 0.420);

  glVertex2f(33,98.5);
  glVertex2f(83,108);
  glVertex2f(83,106.8);
  glVertex2f(33,97.3);

   glEnd();
glPopMatrix();

//siri 3
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.933,0.910,0.667);

  glVertex2f(33,97.3);
  glVertex2f(83,106.8);
  glVertex2f(84.5,105.3);
  glVertex2f(34.5,95.8);

   glEnd();
glPopMatrix();

//siri 4
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.741, 0.718, 0.420);

  glVertex2f(34.5,95.8);
  glVertex2f(84.5,105.3);
  glVertex2f(84.5,104.1);
  glVertex2f(34.5,94.6);

 glEnd();
glPopMatrix();



//dhaaaan
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(0.855, 0.647, 0.125);
  //left
  glVertex2f(90,111);
  glVertex2f(89.34,117);
  glVertex2f(90.67,123);
  glVertex2f(94,127.5);
  //middle
  glVertex2f(100,132);
  //right
  glVertex2f(106,127.5);
  glVertex2f(109.34,123);
  glVertex2f(110.67,117);
  glVertex2f(110,111);

    glEnd();
glPopMatrix();

  //bottom
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(0.801,0.778,0.480);

  glVertex2f(110,111);
  glVertex2f(104.34,112.5);
  glVertex2f(99.68,113);
  glVertex2f(95.68,112.5);
  glVertex2f(90,110.5);
  glVertex2f(90,111);

  glEnd();
glPopMatrix();

  //top
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.722, 0.525, 0.043);

  glVertex2f(99.5,132);
  glVertex2f(99.5,137);
  glVertex2f(100.5,137);
  glVertex2f(100.5,132);

 glEnd();
glPopMatrix();



//house 2
//top
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.8,0.8,0.8);

  glVertex2f(126,142);
  glVertex2f(161,135);
  glVertex2f(155,121);
  glVertex2f(117.5,129);

 glEnd();
glPopMatrix();

//right triangle
  glPushMatrix();
  glBegin(GL_TRIANGLES);
  glColor3f(0.9,0.9,0.9);

  glVertex2f(161,135);
  glVertex2f(155,121);
  glVertex2f(169,123);

 glEnd();
glPopMatrix();

//right rectangle
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.855, 0.539, 0.839);

  glVertex2f(156.5,121.2);
  glVertex2f(156.5,100);
  glVertex2f(168,103);
  glVertex2f(168,123);

 glEnd();
glPopMatrix();

//large rectangle
  glPushMatrix();
  glBegin(GL_POLYGON);
glColor3f(0.867, 0.627, 0.867);

  glVertex2f(156.5,121.2);
  glVertex2f(155,121);
  glVertex2f(119,129);
  glVertex2f(119,110.5);
  glVertex2f(156.5,100);

 glEnd();
glPopMatrix();

//door
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.622, 0.425, 0.033);

  glVertex2f(132.7,124.5);
  glVertex2f(132.7,106.5);
  glVertex2f(140.3,104.4);
  glVertex2f(140.3,122.72);

 glEnd();
glPopMatrix();


//window 1
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.622, 0.425, 0.033);

  glVertex2f(122.3,115.5);
  glVertex2f(122.3,123.7);
  glVertex2f(129,122.5);
  glVertex2f(129,114);

   glEnd();
glPopMatrix();

//window 2
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.622, 0.425, 0.033);

  glVertex2f(144.8,110);
  glVertex2f(144.8,118.6);
  glVertex2f(151.5,117.2);
  glVertex2f(151.5,108.2);

   glEnd();
glPopMatrix();

//window 3
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.622, 0.425, 0.033);

  glVertex2f(159,117.2);
  glVertex2f(159,108.7);
  glVertex2f(166,110.3);
  glVertex2f(166,118.5);

   glEnd();
glPopMatrix();

//siri 1
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.933,0.910,0.667);

  glVertex2f(121,110);
  glVertex2f(120,108.2);
  glVertex2f(152.5,99);
  glVertex2f(153.5,100.8);

   glEnd();
glPopMatrix();

//siri 2
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.741, 0.718, 0.420);

  glVertex2f(120,108.2);
  glVertex2f(120,107.4);
  glVertex2f(152.5,98);
  glVertex2f(152.5,99);

   glEnd();
glPopMatrix();



//river
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(0.640,0.738,0.992);

  glVertex2f(0,50);
  glVertex2f(400,100);
  glVertex2f(400,0);
  glVertex2f(0,0);

   glEnd();
glPopMatrix();



//boat 1
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.0,0.0,0.0);

  glVertex2f(xboat1+33,yboat1+35);
  glVertex2f(xboat1+43,yboat1+25);
  glVertex2f(xboat1+67,yboat1+25);
  glVertex2f(xboat1+77,yboat1+35);

 glEnd();
glPopMatrix();


  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(1.0,0.0,0.0);

  glVertex2f(xboat1+43,yboat1+35);
  glVertex2f(xboat1+43,yboat1+42);
  glVertex2f(xboat1+55,yboat1+45);
  glVertex2f(xboat1+67,yboat1+42);
  glVertex2f(xboat1+67,yboat1+35);
  glVertex2f(xboat1+55,yboat1+31);

 glEnd();
glPopMatrix();



//boat 2
//bottom
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.0,0.0,0.0);

  glVertex2f(xboat2+245,yboat2+25);
  glVertex2f(xboat2+255,yboat2+9);
  glVertex2f(xboat2+355,yboat2+9);
  glVertex2f(xboat2+365,yboat2+25);

 glEnd();
glPopMatrix();

//top
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.663, 0.663, 0.663);

  glVertex2f(xboat2+258,yboat2+25);
  glVertex2f(xboat2+258,yboat2+30);
  glVertex2f(xboat2+352,yboat2+30);
  glVertex2f(xboat2+352,yboat2+25);

  glVertex2f(xboat2+261,yboat2+30);
  glVertex2f(xboat2+261,yboat2+35);
  glVertex2f(xboat2+349,yboat2+35);
  glVertex2f(xboat2+349,yboat2+30);

 glEnd();
glPopMatrix();


strip();
//strip 2,3,4
glPushMatrix();
glTranslatef(23,0, 0);
strip();
glTranslatef(23,0, 0);
strip();
glTranslatef(23,0, 0);
strip();
glPopMatrix();


piller();
//piler 2,3,4
glPushMatrix();
glTranslatef(23,0, 0);
piller();
glTranslatef(23,0, 0);
piller();
glTranslatef(23,0, 0);
piller();
glPopMatrix();





//street
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(0.663, 0.663, 0.663);

  glVertex2f(0,56);
  glVertex2f(400,106);
  glVertex2f(400,125);
  glVertex2f(0,75);

 glEnd();
glPopMatrix();



street_strip ();
glPushMatrix();
glTranslatef(20,2.4,0);
street_strip ();
glTranslatef(20,2.4,0);
street_strip ();
glTranslatef(20,2.4,0);
street_strip ();
glTranslatef(20,2.5,0);
street_strip ();
glTranslatef(20,2.5,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glTranslatef(20,2.6,0);
street_strip ();
glPopMatrix();



//traffic light
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.000, 0.000, 0.000);

  glVertex2f(247,105.5);
  glVertex2f(247,121.5);
  glVertex2f(249,121.5);
  glVertex2f(249,105.7);
  glEnd();
  glPopMatrix();


    glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.000, 0.000, 0.000);

  glVertex2f(245,121.5);
  glVertex2f(251,121.5);
  glVertex2f(251,133.5);
  glVertex2f(245,133.5);

  glEnd();
  glPopMatrix();

   glPushMatrix();
   glColor3f(1.000, 0.000, 0.000);
   drawFilledCircle(248,132,1.5);
   glPopMatrix();

      glPushMatrix();
   glColor3f(1.000, 1.000, 0.000);
   drawFilledCircle(248,128,1.5);
   glPopMatrix();

      glPushMatrix();
   glColor3f(0.000, 1.000, 0.000);
   drawFilledCircle(248,124,1.5);
   glPopMatrix();



//car
  glPushMatrix();//body
  glBegin(GL_POLYGON);
  glColor3f(0.545, 0.000, 0.000);

  glVertex2f(xcar+63,ycar+76.5);
  glVertex2f(xcar+86.5,ycar+80);
  glVertex2f(xcar+86,ycar+84);
  glVertex2f(xcar+80,ycar+86);
  glVertex2f(xcar+77,ycar+89);
  glVertex2f(xcar+68,ycar+88);
  glVertex2f(xcar+65,ycar+83.5);
  glVertex2f(xcar+62,ycar+82);
  glEnd();
  glPopMatrix();


   glPushMatrix();//window1
  glBegin(GL_POLYGON);
  glColor3f(1.0, 1.0, 1.0);

  glVertex2f(xcar+79.3,ycar+84.8);
  glVertex2f(xcar+76.4,ycar+87.7);
  glVertex2f(xcar+72.6,ycar+87.5);
  glVertex2f(xcar+73.1,ycar+84);


   glEnd();
glPopMatrix();


glPushMatrix();
glBegin(GL_POLYGON);//window2
glColor3f(1.0, 1.0, 1.0);

  glVertex2f(xcar+72,ycar+84);
  glVertex2f(xcar+71.6,ycar+87.5);
  glVertex2f(xcar+69,ycar+87);
  glVertex2f(xcar+66,ycar+83);

 glEnd();
glPopMatrix();

//chaka1
  glPushMatrix();
  glColor3f(0.961, 0.961, 0.961);
  glTranslatef(xcar+69,ycar+77,0);
  glRotatef(180,xcar+0,ycar+0,0);
  glutWireTorus(0.3, 2.5, 3, 30);
  glPopMatrix();

   glPushMatrix();
   glColor3f(0.000, 0.000, 0.000);
   drawFilledCircle(xcar+69,ycar+77,1.3);
   glPopMatrix();

//chaka2
  glPushMatrix();
  glColor3f(0.961, 0.961, 0.961);
  glTranslatef(xcar+80,ycar+79,0);
  glRotatef(180,xcar+0,ycar+0,0);
  glutWireTorus(0.3, 2.5, 3, 30);
  glPopMatrix();

     glPushMatrix();
   glColor3f(0.000, 0.000, 0.000);
   drawFilledCircle(xcar+80,ycar+79,1.3);
   glPopMatrix();

//lamp post 2
lamp_post();
glPushMatrix();
glTranslatef(200,26.2,0);
lamp_post();
glPopMatrix();


//van
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3f(0.184, 0.310, 0.310);

  glVertex2f(xvan+369,yvan+111.5);
  glVertex2f(xvan+390,yvan+115);
  glVertex2f(xvan+389,yvan+121);
  glVertex2f(xvan+367,yvan+118);
  glEnd();
  glPopMatrix();

   glPushMatrix();//head
  glBegin(GL_POLYGON);
  glColor3f(0.184, 0.310, 0.310);

  glVertex2f(xvan+369,yvan+111.5);
  glVertex2f(xvan+367.5,yvan+125);
  glVertex2f(xvan+362,yvan+123);
  glVertex2f(xvan+358,yvan+118);
  glVertex2f(xvan+358,yvan+110);

   glEnd();
glPopMatrix();


glPushMatrix();
glBegin(GL_POLYGON);
glColor3f(1.0, 1.0, 1.0);

  glVertex2f(xvan+366.5,yvan+116.5);
  glVertex2f(xvan+366,yvan+122.2);
  glVertex2f(xvan+362.5,yvan+120.8);
  glVertex2f(xvan+360,yvan+118);
  glVertex2f(xvan+360,yvan+115);

 glEnd();
glPopMatrix();

  glPushMatrix();//bottom
  glBegin(GL_QUADS);
  glColor3f(0.0, 0.0, 0.0);

  glVertex2f(xvan+358,yvan+110);
  glVertex2f(xvan+390,yvan+115);
  glVertex2f(xvan+390,yvan+112);
  glVertex2f(xvan+358,yvan+107);

   glEnd();
glPopMatrix();


//chaka1
  glPushMatrix();
  glColor3f(0.961, 0.961, 0.961);
  glTranslatef(xvan+365,yvan+107,0);
  glRotatef(180,xvan+0,yvan+0,0);
  glutWireTorus(0.5, 3, 4, 30);
  glPopMatrix();

   glPushMatrix();
   glColor3f(0.000, 0.000, 0.000);
   drawFilledCircle(xvan+365,yvan+107,1.5);
   glPopMatrix();

//chaka2
  glPushMatrix();
  glColor3f(0.961, 0.961, 0.961);
  glTranslatef(xvan+383,yvan+109.7,0);
  glRotatef(180,xvan+0,yvan+0,0);
  glutWireTorus(0.5, 3, 4, 30);
  glPopMatrix();

     glPushMatrix();
   glColor3f(0.000, 0.000, 0.000);
   drawFilledCircle(xvan+383,yvan+109.5,1.5);
   glPopMatrix();



glFlush();
glutSwapBuffers();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'r':
        xboat1+=0.8;
        xboat2-=0.8;
        sun+=0.4;
        cld-=0.4;
        break;
    case 'l':
        xboat1-=0.8;
        xboat2+=0.8;
        sun-=0.4;
        cld+=0.4;
        break;
    case 'u':
        yboat1+=0.8;
        yboat2-=0.8;
        break;
    case 'd':
        yboat1-=0.8;
        yboat2+=0.8;
        break;
    case '1':
        xvan+=1;
        xcar-=1;
        break;
    case '2':
        xvan-=1;
        xcar+=1;
        break;
    case '3':
        yvan+=1;
        ycar-=1;
        break;
    case '4':
        yvan-=1;
        ycar+=1;
        break;


    case 's':
        flagScale=true;
        break;
    case 'e':
        flagScale=false;
        break;


    case 27:	// Escape key
        exit(1);
    }
    glutPostRedisplay();
}

void animate()
{
//sun
	if (flagScale == true)
	{
		sun+= 0.01;
		if(sun > 285)
			sun = -125;
	}
	if (flagScale == false)
	{
		sun = 0;
	}


//cloud
    if (flagScale == true)
	{
		cld-= 0.015;
		if(cld < -390)
			cld = 390;
	}
	if (flagScale == false)
	{
		cld = 0;
	}
	glutPostRedisplay();


//boat1
    if (flagScale == true)
	{
		xboat1 += 0.04;
		if(xboat1 > 400)
			xboat1 = -80;
	}
	if (flagScale == false)
	{
		xboat1 = 0;
	}
	glutPostRedisplay();


//boat2
    if (flagScale == true)
	{
		xboat2 -= 0.05;
		if(xboat2 < -360)
			xboat2 = 150;
	}
	if (flagScale == false)
	{
		xboat2 = 0;
	}
	glutPostRedisplay();


//van
    if (flagScale == true)
	{
		xvan -= 0.1;
		if(xvan < -390)
			xvan = 330;

	}
	if (flagScale == false)
	{
		xvan = 0;
	}
	glutPostRedisplay();



	    if (flagScale == true)
	{
		yvan -= 0.013;
		if(yvan < -89.5)
			yvan = 4.1;
	}
	if (flagScale == false)
	{
		yvan = 0;
	}
	glutPostRedisplay();



//car
    if (flagScale == true)
	{
		xcar += 0.1;
		if(xcar > 335)
			xcar = -100;

	}
	if (flagScale == false)
	{
		xcar = 0;
	}
	glutPostRedisplay();



	    if (flagScale == true)
	{
		ycar += 0.013;
		if(ycar > 44.5)
			ycar = -12.1;
	}
	if (flagScale == false)
	{
		ycar = 0;
	}
	glutPostRedisplay();


//bird
    if (flagScale == true)
	{
		xbird += 0.05;
		if(xbird > 110)
			xbird = -300;
	}
	if (flagScale == false)
	{
		xbird = 0;
	}
	glutPostRedisplay();


}




int main (int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowPosition(100,100);
glutInitWindowSize(windowWidth, windowHeight);
glutCreateWindow("Katha");

glutKeyboardFunc(myKeyboardFunc);
glutIdleFunc(animate);

glutDisplayFunc(display);
glutMainLoop();
return 0;
}
