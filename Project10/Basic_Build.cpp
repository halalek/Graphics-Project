#include "Basic_Build.h"

#include <windows.h>		// Header File For Windows
#include <GL.h>				// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <gl/glut.h>			// Header File For The GLut32 Library
#include <fstream>
#include <math.h>

#include<camera.h>
//include lib file
//#include<Model_3DS.h>
//#include<3DTexture.h>

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glut32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"GLAUX.LIB")

#include <glaux.h>		// Header File For The Glaux Library
#include"Model_3DS.h"

//#include"gltexture.h"
#include "3DTexture.h"
#include"texture.h"
int ssaa = 0, ssbb = 0;
int first = 0;
int stone,stone1,stone2;
using namespace std;
int  ard, bul, roof, interfaceeright, door1, door2, aard,door30;
Model_3DS A4, A5, A3, m, A6, A7, bad, A8, A9, A10, m1, A12, bad1,A13,A14,A15,A17,A19;
int saa1_1=0,saa1_2=0,saa1_3=0,saa1_4=0,saa2_1=0,saa2_2=0,saa2_3=0,saa2_4=0,saa3_1=0,saa3_2=0,saa3_3=0,saa3_4=0;
int Basic_Build::Initbuild()									// All Setup For OpenGL Goes Here
{
	//glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	//glClearColor(0.0f, 0.0f, 1.0f, 0.3f);				// Black Background
	//glClearDepth(1.0f);									// Depth Buffer Setup
	//glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	//glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	ard = LoadTexture((char*)"image//124.bmp", 255);
	stone = LoadTexture((char*)"image//stone.bmp", 255);
	stone1 = LoadTexture((char*)"image//stone1.bmp", 255);
	stone2 = LoadTexture((char*)"image//stone2.bmp", 255);
	bul = LoadTexture((char*)"image//4.bmp", 255);
	roof = LoadTexture((char*)"image//ro.bmp", 255);
	interfaceeright = LoadTexture((char*)"image//interfaceright.bmp", 255);
	aard = LoadTexture((char*)"image//th.bmp", 255);
	door1 = LoadTexture((char*)"image//door1.bmp", 255);
	door30 = LoadTexture((char*)"image//door30.bmp", 255);
	door2 = LoadTexture((char*)"image//door2.bmp", 255);
	bad.Load((char*)"image//Bed Sanderlend Dantone home N261019.3ds");
	bad.Materials[2].tex.Load((char*)"image//Be1.bmp");
	bad.Materials[1].tex.Load((char*)"image//Be2.bmp");
	bad.Materials[0].tex.Load((char*)"image//Be3.bmp");
	bad.Materials[3].tex.Load((char*)"image//Be4.bmp");
	bad.Materials[4].tex.Load((char*)"image//Be5.bmp");
	bad.Materials[5].tex.Load((char*)"image//Be6.bmp");
	A10.Load((char*)"image//Sofa1 N220519.3ds");
	A10.Materials[0].tex.Load((char*)"image//red.bmp");
	A10.Materials[1].tex.Load((char*)"image//124.bmp");
	A10.Materials[2].tex.Load((char*)"image//red.bmp");
	A12.Load((char*)"image//Sofa2 N220519.3ds");
	A12.Materials[0].tex.Load((char*)"image//tot.bmp");
	A12.Materials[1].tex.Load((char*)"image//1243.bmp");
	A12.Materials[2].tex.Load((char*)"image//tot.bmp");
	A4.Load((char*)"image//Sofa N220519.3ds");
	A4.Materials[0].tex.Load((char*)"image//leat sml.bmp");
	A4.Materials[1].tex.Load((char*)"image//text_flw.bmp");
	A4.Materials[2].tex.Load((char*)"image//124.bmp");
	A5.Load((char*)"image//Wood_Table.3ds");
	A5.Materials[0].tex.Load((char*)"image//Reflexion.bmp");
	A5.Materials[1].tex.Load((char*)"image//Be2.bmp");
	m.Load((char*)"image//Dining_Table.3ds");
	m.Materials[0].tex.Load((char*)"image//Pi1.bmp");
	m.Materials[1].tex.Load((char*)"image//4.bmp");
	m.Materials[2].tex.Load((char*)"image//124.bmp");
	m.Materials[3].tex.Load((char*)"image//ar1.bmp");
	m.Materials[5].tex.Load((char*)"image//Be1.bmp");
	A7.Load((char*)"image//R1.3ds");
	A7.Materials[0].tex.Load((char*)"image//4.bmp");

	A8.Load((char*)"image//Lamp LA MURRINA Rolls N010920.3ds");
	A8.Materials[0].tex.Load((char*)"image//Be3.bmp");
	A8.Materials[1].tex.Load((char*)"image//124.bmp");
	A8.Materials[2].tex.Load((char*)"image//ar1.bmp");
	A9.Load((char*)"image//Vase flowers Lily Pink N230118.3DS");
	A9.Materials[0].tex.Load((char*)"image//leat sml.bmp");
	A9.Materials[1].tex.Load((char*)"image//L1.bmp");
	A9.Materials[2].tex.Load((char*)"image//leat sml.bmp");
	A9.Materials[4].tex.Load((char*)"image//nono.bmp");
	A9.Materials[5].tex.Load((char*)"image//L1.bmp");
	A9.Materials[6].tex.Load((char*)"image//lily pin.bmp");
	A9.Materials[7].tex.Load((char*)"image//lily pin.bmp");
	A3.Load((char*)"image//Clock N210912.3ds");
	A3.Materials[0].tex.Load((char*)"image//clo.bmp");
	A6.Load((char*)"image//Piano Celviano N111014.3ds");
	A6.Materials[0].tex.Load((char*)"image//124.bmp");
	A6.Materials[1].tex.Load((char*)"image//124.bmp");
	A15.Load((char*)"image//B2925-3d.3DS");
	A15.Materials[0].tex.Load((char*)"image//Wire weave wh.bmp");
	A15.Materials[1].tex.Load((char*)"image//ar1.bmp");
	A13.Load((char*)"image//Toilet bowl.3DS");
	A13.Materials[0].tex.Load((char*)"image//Wire weave wh.bmp");
	A13.Materials[1].tex.Load((char*)"image//ar1.bmp");
	A13.Materials[2].tex.Load((char*)"image//ar1.bmp");
	A14.Load((char*)"image//Wash-basin.3ds");
	A14.Materials[0].tex.Load((char*)"image//ar1.bmp");
	A14.Materials[1].tex.Load((char*)"image//Wire weave wh.bmp");
	A14.Materials[2].tex.Load((char*)"image//ar1.bmp");
	A17.Load((char*)"image//Shower Massage N130315.3DS");
	A17.Materials[0].tex.Load((char*)"image//ar1.bmp");
	A19.Load((char*)"image//Bucket 4.3DS");
	A19.Materials[0].tex.Load((char*)"image//Arch41_043_leaf.bmp");
	A19.Materials[1].tex.Load((char*)"image//nono.bmp");
	A19.Materials[2].tex.Load((char*)"image//Arch41_043_leaf.bmp");
	A19.Materials[3].tex.Load((char*)"image//nono.bmp");
	A19.Materials[4].tex.Load((char*)"image//Arch41_043_leaf.bmp");
	A19.Materials[5].tex.Load((char*)"image//door1.bmp");
	return true;										// Initialization Went OK
}

Basic_Build::Basic_Build()
{

}
void room2_1(bool door11)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, bul);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-44, 165, 400);
	glTexCoord2d(0, 1);
	glVertex3d(-283, 165, 400);
	glTexCoord2d(1, 1);
	glVertex3d(-283, 291, 400);
	glTexCoord2d(1, 0);
	glVertex3d(-44, 291, 400);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();
	if (door11 == true && saa2_1 < 51)
	{
		saa2_1 += 9;
	}
	else if (door11 == false && saa2_1 > 0)
		saa2_1 -= 9;
	glPushMatrix();
	glTranslated(0, 0, -saa2_1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, door30);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-44, 165, 700);
	glTexCoord2d(1, 0);
	glVertex3d(-44, 165, 770);
	glTexCoord2d(1, 1);
	glVertex3d(-44, 240, 770);
	glTexCoord2d(0, 1);
	glVertex3d(-44, 240, 700);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3d(-44, 165, 400);
	glVertex3d(-44, 291, 400);
	glVertex3d(-44, 291, 700);
	glVertex3d(-44, 165, 700);
	glVertex3d(-44, 291, 770);
	glVertex3d(-44, 165, 770);
	glVertex3d(-44, 165, 943);
	glVertex3d(-44, 291, 943);
	glVertex3d(-44, 240, 770);
	glVertex3d(-44, 291, 770);
	glVertex3d(-44, 291, 700);
	glVertex3d(-44, 240, 700);
	glEnd();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A10.scale = 1.5;
	A10.rot.y = 90;
	A10.pos.x = -180;
	A10.pos.y = 200;
	A10.pos.z = 700;
	A10.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A7.scale = 20;
	A7.rot.y = 5;
	A7.pos.x = -130;
	A7.pos.y = 170;
	A7.pos.z = 800;
	A7.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A9.scale = 0.3;
	A9.rot.y = 5;
	A9.pos.x = -130;
	A9.pos.y = 201;
	A9.pos.z = 800;
	A9.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void room2_2(bool door11)
{

	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3d(-44, 165, 1);
	glVertex3d(-44, 291, 1);
	glVertex3d(-44, 291, 255);
	glVertex3d(-44, 165, 255);
	glVertex3d(-44, 291, 320);
	glVertex3d(-44, 165, 320);
	glVertex3d(-44, 165, 400);
	glVertex3d(-44, 291, 400);
	glVertex3d(-44, 240, 320);
	glVertex3d(-44, 291, 320);
	glVertex3d(-44, 291, 255);
	glVertex3d(-44, 240, 255);
	glEnd();

	glPopMatrix();

	if (door11 == true && saa2_2 < 51)
	{
		saa2_2 += 9;
	}
	else if (door11 == false && saa2_2> 0)
		saa2_2 -= 9;

	glPushMatrix();
	glTranslated(0, 0, -saa2_2);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, door30);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-44, 165, 255);
	glTexCoord2d(1, 0);
	glVertex3d(-44, 165, 320);
	glTexCoord2d(1, 1);
	glVertex3d(-44, 240, 320);
	glTexCoord2d(0, 1);
	glVertex3d(-44, 240, 255);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();
	glPushMatrix();
	A15.scale = 1;
	A15.rot.y = -90;
	A15.pos.x = -244;
	A15.pos.y = 160;
	A15.pos.z = 100;
	A15.Draw();
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A13.scale = 0.07;
	A13.rot.y = 90;
	A13.pos.x = -100;
	A13.pos.y = 165;
	A13.pos.z = 100;
	A13.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	A14.scale = 0.085;
	A14.rot.y = 0;
	A14.pos.x = -175;
	A14.pos.y = 199;
	A14.pos.z = 60;
	A14.Draw();
	glPopMatrix();
	glPushMatrix();
	A17.scale = 1;
	A17.rot.y = 0;
	A17.pos.x = -270;
	A17.pos.y = 240;
	A17.pos.z = 200;
	A17.Draw();
	glPopMatrix();
}
void room2_4(bool door11)
{
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3d(55, 165, 1);
	glVertex3d(55, 291, 1);
	glVertex3d(55, 291, 255);
	glVertex3d(55, 165, 255);
	glVertex3d(55, 291, 320);
	glVertex3d(55, 165, 320);
	glVertex3d(55, 165, 400);
	glVertex3d(55, 291, 400);
	glVertex3d(55, 240, 320);
	glVertex3d(55, 291, 320);
	glVertex3d(55, 291, 255);
	glVertex3d(55, 240, 255);
	glEnd();
	
	if (door11 == true && saa2_4< 51)
	{
		saa2_4 += 9;
	}
	else if (door11 == false && saa2_4 > 0)
		saa2_4 -= 9;
	glPushMatrix();
	glTranslated(0, 0, -saa2_4);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, door30);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(55, 165, 255);
	glTexCoord2d(1, 0);
	glVertex3d(55, 165, 320);
	glTexCoord2d(1, 1);
	glVertex3d(55, 240, 320);
	glTexCoord2d(0, 1);
	glVertex3d(55, 240, 255);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	bad.scale = 0.15;
	bad.rot.y = 0;
	bad.pos.x = 170;
	bad.pos.y = 200;
	bad.pos.z = 200;
	bad.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A8.scale = 1.3;
	A8.rot.y = 0;
	A8.pos.x = 100;
	A8.pos.y = 225;
	A8.pos.z = 70;
	A8.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A5.scale = 90;
	A5.rot.y = 0;
	A5.pos.x = 100;
	A5.pos.y = 169;
	A5.pos.z = 70;
	A5.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void room2_3(bool  door11)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, bul);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(55, 160, 400);
	glTexCoord2d(0, 1);
	glVertex3d(279, 160, 400);
	glTexCoord2d(1, 1);
	glVertex3d(279, 290, 400);
	glTexCoord2d(1, 0);
	glVertex3d(55, 290, 400);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3d(55, 165, 400);
	glVertex3d(55, 291, 400);
	glVertex3d(55, 291, 700);
	glVertex3d(55, 165, 700);
	glVertex3d(55, 291, 770);
	glVertex3d(55, 165, 770);
	glVertex3d(55, 165, 943);
	glVertex3d(55, 291, 943);
	glVertex3d(55, 240, 770);
	glVertex3d(55, 291, 770);
	glVertex3d(55, 291, 700);
	glVertex3d(55, 240, 700);
	glEnd();
	if (door11 == true && saa2_3 < 51)
	{
		saa2_3 += 9;
	}
	else if (door11 == false && saa2_3 > 0)
		saa2_3 -= 9;
	glPushMatrix();
	glTranslated(0, 0, -saa2_3);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, door30);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(55, 165, 700);
	glTexCoord2d(1, 0);
	glVertex3d(55, 165, 770);
	glTexCoord2d(1, 1);
	glVertex3d(55, 240, 770);
	glTexCoord2d(0, 1);
	glVertex3d(55, 240, 700);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A3.scale = 1;
	A3.rot.y = 9;
	A3.pos.x = 150;
	A3.pos.y = 170;
	A3.pos.z = 500;
	A3.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A6.scale = 3;
	A6.rot.y = 90;
	A6.pos.x = 250;
	A6.pos.y = 191;
	A6.pos.z = 600;
	A6.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	m.scale = 400;
	m.rot.y = 5;
	m.pos.x = 170;
	m.pos.y = 168;
	m.pos.z = 700;
	m.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void room1_1(bool  door11)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, bul);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-44, 2, 400);
	glTexCoord2d(0, 1);
	glVertex3d(-283, 2, 400);
	glTexCoord2d(1, 1);
	glVertex3d(-283, 150, 400);
	glTexCoord2d(1, 0);
	glVertex3d(-44, 150, 400);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3d(-44, 1, 400);
	glVertex3d(-44, 150, 400);
	glVertex3d(-44, 150, 700);
	glVertex3d(-44, 1, 700);
	glVertex3d(-44, 150, 770);
	glVertex3d(-44, 1, 770);
	glVertex3d(-44, 1, 943);
	glVertex3d(-44, 150, 943);
	glVertex3d(-44, 120, 770);
	glVertex3d(-44, 150, 770);
	glVertex3d(-44, 150, 700);
	glVertex3d(-44, 120, 700);
	glEnd();

	if (door11 == true && saa1_1< 51)
	{
		saa1_1 += 9;
	}
	else if (door11 == false && saa1_1> 0)
		saa1_1 -= 9;
	glPushMatrix();
	glTranslated(0, 0, -saa1_1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, door30);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-44, 1, 700);
	glTexCoord2d(1, 0);
	glVertex3d(-44, 1, 770);
	glTexCoord2d(1, 1);
	glVertex3d(-44, 120, 770);
	glTexCoord2d(0, 1);
	glVertex3d(-44, 120, 700);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A4.scale = 1.5;
	A4.rot.y = 90;
	A4.pos.x = -180;
	A4.pos.y = 40;
	A4.pos.z = 700;
	A4.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A7.scale = 20;
	A7.rot.y = 5;
	A7.pos.x = -130;
	A7.pos.y = 10;
	A7.pos.z = 800;
	A7.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A9.scale = 0.3;
	A9.rot.y = 5;
	A9.pos.x = -130;
	A9.pos.y = 39;
	A9.pos.z = 800;
	A9.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void room1_2(bool  door11)
{
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3d(-44, 8, 1);
	glVertex3d(-44, 150, 1);
	glVertex3d(-44, 150, 255);
	glVertex3d(-44, 8, 255);
	glVertex3d(-44, 150, 320);
	glVertex3d(-44, 8, 320);
	glVertex3d(-44, 8, 400);
	glVertex3d(-44, 150, 400);
	glVertex3d(-44, 120, 320);
	glVertex3d(-44, 150, 320);
	glVertex3d(-44, 150, 255);
	glVertex3d(-44, 120, 255);
	glEnd();
	glPopMatrix();

	if (door11 == true && saa1_2< 51)
	{
		saa1_2 += 9;
	}
	else if (door11 == false && saa1_2 > 0)
		saa1_2 -= 9;
	glPushMatrix();
	glTranslated(0, 0, -saa1_2);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, door30);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-44, 8, 255);
	glTexCoord2d(1, 0);
	glVertex3d(-44, 8, 320);
	glTexCoord2d(1, 1);
	glVertex3d(-44, 120, 320);
	glTexCoord2d(0, 1);
	glVertex3d(-44, 120, 255);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();
	glPushMatrix();
	A15.scale = 1;
	A15.rot.y = -90;
	A15.pos.x = -244;
	A15.pos.y = -4;
	A15.pos.z = 100;
	A15.Draw();
	glPopMatrix();
	glPushMatrix();
	A13.scale = 0.07;
	A13.rot.y = 90;
	A13.pos.x = -100;
	A13.pos.y = 15;
	A13.pos.z = 100;
	A13.Draw();
	glPopMatrix();
	glPushMatrix();
	A14.scale = 0.085;
	A14.rot.y = 0;
	A14.pos.x = -175;
	A14.pos.y = 49;
	A14.pos.z = 60;
	A14.Draw();
	glPopMatrix();
	glPushMatrix();
	A17.scale = 1;
	A17.rot.y = 0;
	A17.pos.x = -270;
	A17.pos.y = 79;
	A17.pos.z = 200;
	A17.Draw();
	glPopMatrix();
}
void room1_3(bool  door11)
{
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, bul);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(55, 8, 400);
	glTexCoord2d(0, 1);
	glVertex3d(279, 8, 400);
	glTexCoord2d(1, 1);
	glVertex3d(279, 150, 400);
	glTexCoord2d(1, 0);
	glVertex3d(55, 150, 400);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3d(55, 8, 400);
	glVertex3d(55, 150, 400);
	glVertex3d(55, 150, 700);
	glVertex3d(55, 8, 700);
	glVertex3d(55, 150, 770);
	glVertex3d(55, 8, 770);
	glVertex3d(55, 8, 943);
	glVertex3d(55, 150, 943);
	glVertex3d(55, 120, 770);
	glVertex3d(55, 150, 770);
	glVertex3d(55, 150, 700);
	glVertex3d(55, 120, 700);

	glEnd();

	if (door11 == true && saa1_3< 51)
	{
		saa1_3 += 9;
	}
	else if (door11 == false && saa1_3 > 0)
		saa1_3 -= 9;
	glPushMatrix();
	glTranslated(0, 0, -saa1_3);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, door30);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(55, 8, 700);
	glTexCoord2d(1, 0);
	glVertex3d(55, 8, 770);
	glTexCoord2d(1, 1);
	glVertex3d(55, 120, 770);
	glTexCoord2d(0, 1);
	glVertex3d(55, 120, 700);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
	A3.scale = 1;
	A3.rot.y = 9;
	A3.pos.x = 150;
	A3.pos.y = 9;
	A3.pos.z = 500;
	A3.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A6.scale = 3;
	A6.rot.y = 90;
	A6.pos.x = 250;
	A6.pos.y = 9;
	A6.pos.z = 600;
	A6.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	m.scale = 400;
	m.rot.y = 5;
	m.pos.x = 170;
	m.pos.y = 10;
	m.pos.z = 700;
	m.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}
void room1_4(bool door11)
{
	
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3d(55, 8, 1);
	glVertex3d(55, 150, 1);
	glVertex3d(55, 150, 255);
	glVertex3d(55, 8, 255);
	glVertex3d(55, 150, 320);
	glVertex3d(55, 8, 320);
	glVertex3d(55, 8, 400);
	glVertex3d(55, 150, 400);
	glVertex3d(55, 120, 320);
	glVertex3d(55, 150, 320);
	glVertex3d(55, 150, 255);
	glVertex3d(55, 120, 255);
	glEnd();
	glPopMatrix();
	if (door11 == true && saa1_4< 51)
	{
		saa1_4 += 9;
	}
	else if (door11 == false && saa1_4 > 0)
		saa1_4 -= 9;
		glPushMatrix();
		glTranslated(0, 0, -saa1_4);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, door30);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(55, 8, 255);
		glTexCoord2d(1, 0);
		glVertex3d(55, 8, 320);
		glTexCoord2d(1, 1);
		glVertex3d(55, 120, 320);
		glTexCoord2d(0, 1);
		glVertex3d(55, 120, 255);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
	A5.scale = 90;
	A5.rot.y = 0;
	A5.pos.x = 100;
	A5.pos.y = 9;
	A5.pos.z = 70;
	A5.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	bad.scale = 0.15;
	bad.rot.y = 0;
	bad.pos.x = 200;
	bad.pos.y = 40;
	bad.pos.z = 200;
	bad.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	A8.scale = 1.3;
	A8.rot.y = 0;
	A8.pos.x = 100;
	A8.pos.y = 68;
	A8.pos.z = 70;
	A8.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void room3_1(bool door11)
{

glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, bul);
glBegin(GL_QUADS);
glTexCoord2d(0, 0);
glVertex3d(-44, 300, 400);
glTexCoord2d(0, 1);
glVertex3d(-283, 300, 400);
glTexCoord2d(1, 1);
glVertex3d(-283, 440, 400);
glTexCoord2d(1, 0);
glVertex3d(-44, 440, 400);
glEnd();
glDisable(GL_TEXTURE_2D);
glDisable(GL_BLEND);
glPopMatrix();
glColor3f(0.5f, 0.5f, 0.5f);
glBegin(GL_QUADS);
glVertex3d(-44, 300, 400);
glVertex3d(-44, 435, 400);
glVertex3d(-44, 435, 700);
glVertex3d(-44, 300, 700);
glVertex3d(-44, 435, 770);
glVertex3d(-44, 300, 770);
glVertex3d(-44, 300, 943);
glVertex3d(-44, 435, 943);
glVertex3d(-44, 403, 770);
glVertex3d(-44, 435, 770);
glVertex3d(-44, 435, 700);
glVertex3d(-44, 403, 700);
glEnd();

if (door11 == true && saa3_1< 51)
{
	saa3_1 += 9;
}
else if (door11 == false && saa3_1 > 0)
saa3_1 -= 9;
glPushMatrix();
glTranslated(0, 0, -saa3_1);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, door30);
glBegin(GL_QUADS);
glTexCoord2d(0, 0);
glVertex3d(-44, 300, 700);
glTexCoord2d(1, 0);
glVertex3d(-44, 300, 770);
glTexCoord2d(1, 1);
glVertex3d(-44, 403, 770);
glTexCoord2d(0, 1);
glVertex3d(-44, 403, 700);
glEnd();
glDisable(GL_TEXTURE_2D);
glDisable(GL_BLEND);
glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
A12.scale = 1.5;
A12.rot.y = 90;
A12.pos.x = -180;
A12.pos.y = 330;
A12.pos.z = 700;
A12.Draw();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
A7.scale = 20;
A7.rot.y = 5;
A7.pos.x = -130;
A7.pos.y = 300;
A7.pos.z = 800;
A7.Draw();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
A9.scale = 0.3;
A9.rot.y = 5;
A9.pos.x = -130;
A9.pos.y = 327;
A9.pos.z = 800;
A9.Draw();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
}
void room3_2(bool door11)
{
	
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3d(-44, 300, 1);
	glVertex3d(-44, 435, 1);
	glVertex3d(-44, 435, 255);
	glVertex3d(-44, 300, 255);
	glVertex3d(-44, 435, 320);
	glVertex3d(-44, 300, 320);
	glVertex3d(-44, 300, 400);
	glVertex3d(-44, 435, 400);
	glVertex3d(-44, 403, 320);
	glVertex3d(-44, 435, 320);
	glVertex3d(-44, 435, 255);
	glVertex3d(-44, 403, 255);
	glEnd();
	if (door11 == true && saa3_2< 51)
	{
		saa3_2 += 9;
	}
	else if (door11 == false && saa3_2 > 0)
		saa3_2 -= 9;
glPushMatrix();
glTranslated(0, 0, -saa3_2);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, door30);
glBegin(GL_QUADS);
glTexCoord2d(0, 0);
glVertex3d(-44, 300, 255);
glTexCoord2d(1, 0);
glVertex3d(-44, 300, 320);
glTexCoord2d(1, 1);
glVertex3d(-44, 403, 320);
glTexCoord2d(0, 1);
glVertex3d(-44, 403, 255);
glEnd();
glDisable(GL_TEXTURE_2D);
glDisable(GL_BLEND);
glPopMatrix();
glPushMatrix();
A15.scale = 1;
A15.rot.y = -90;
A15.pos.x = -244;
A15.pos.y = 280;
A15.pos.z = 100;
A15.Draw();
glPopMatrix();
glPushMatrix();
A14.scale = 0.085;
A14.rot.y = 0;
A14.pos.x = -175;
A14.pos.y = 337;
A14.pos.z = 60;
A14.Draw();
glPopMatrix();
glPushMatrix();
A17.scale = 1;
A17.rot.y = 0;
A17.pos.x = -270;
A17.pos.y = 360;
A17.pos.z = 200;
A17.Draw();
glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
A13.scale = 0.07;
A13.rot.y = 90;
A13.pos.x = -100;
A13.pos.y = 290;
A13.pos.z = 100;
A13.Draw();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
}
void room3_3(bool door11)
{
	
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, bul);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(55, 300, 400);
	glTexCoord2d(0, 1);
	glVertex3d(279, 300, 400);
	glTexCoord2d(1, 1);
	glVertex3d(279, 440, 400);
	glTexCoord2d(1, 0);
	glVertex3d(55, 440, 400);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glPopMatrix();
glColor3f(0.5, 0.5, 0.5);
glBegin(GL_QUADS);
glVertex3d(55, 300, 400);
glVertex3d(55, 435, 400);
glVertex3d(55, 435, 700);
glVertex3d(55, 300, 700);
glVertex3d(55, 435, 770);
glVertex3d(55, 300, 770);
glVertex3d(55, 300, 943);
glVertex3d(55, 435, 943);
glVertex3d(55, 403, 770);
glVertex3d(55, 435, 770);
glVertex3d(55, 435, 700);
glVertex3d(55, 403, 700);

glEnd();

	if (door11 == true && saa3_3< 51)
	{
		saa3_3 += 9;
	}
	else if (door11 == false && saa3_3 > 0)
		saa3_3 -= 9;
		glPushMatrix();
		glTranslated(0, 0, -saa3_3);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, door30);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0);
		glVertex3d(55, 300, 700);
		glTexCoord2d(1, 0);
		glVertex3d(55, 300, 770);
		glTexCoord2d(1, 1);
		glVertex3d(55, 403, 770);
		glTexCoord2d(0, 1);
		glVertex3d(55, 403, 700);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
		glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
m.scale = 400;
m.rot.y = 5;
m.pos.x = 170;
m.pos.y = 300;
m.pos.z = 700;
m.Draw();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
A3.scale = 1;
A3.rot.y = 9;
A3.pos.x = 150;
A3.pos.y = 300;
A3.pos.z = 500;
A3.Draw();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
A6.scale = 3;
A6.rot.y = 90;
A6.pos.x = 250;
A6.pos.y = 332;
A6.pos.z = 600;
A6.Draw();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
}
void room3_4(bool door11)
{
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex3d(55, 300, 1);
	glVertex3d(55, 435, 1);
	glVertex3d(55, 435, 255);
	glVertex3d(55, 300, 255);
	glVertex3d(55, 435, 320);
	glVertex3d(55, 300, 320);
	glVertex3d(55, 300, 400);
	glVertex3d(55, 435, 400);
	glVertex3d(55, 403, 320);
	glVertex3d(55, 435, 320);
	glVertex3d(55, 435, 255);
	glVertex3d(55, 403, 255);
	glEnd();
	if (door11 == true && saa3_4< 50)
	{
		saa3_4 += 9;
	}
	else if (door11 == false && saa3_4 > 0)
		saa3_4 -= 9;
glPushMatrix();
glTranslated(0, 0, -saa3_4);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, door30);
glBegin(GL_QUADS);
glTexCoord2d(0, 0);
glVertex3d(55, 300, 255);
glTexCoord2d(1, 0);
glVertex3d(55, 300, 320);
glTexCoord2d(1, 1);
glVertex3d(55, 403, 320);
glTexCoord2d(0, 1);
glVertex3d(55, 403, 255);
glEnd();
glDisable(GL_TEXTURE_2D);
glDisable(GL_BLEND);
glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
bad.scale = 0.15;
bad.rot.y = 0;
bad.pos.x = 170;
bad.pos.y = 330;
bad.pos.z = 200;
bad.Draw();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
A8.scale = 1.3;
A8.rot.y = 0;
A8.pos.x = 100;
A8.pos.y = 355;
A8.pos.z = 70;
A8.Draw();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
glPushMatrix();
A5.scale = 90;
A5.rot.y = 0;
A5.pos.x = 100;
A5.pos.y = 300;
A5.pos.z = 70;
A5.Draw();
glPopMatrix();
}
void flatsecond(int num_room,bool door11)
{
	glColor3f(1, 1, 1);
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, bul);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(280, 160, 950);
glTexCoord2d(1, 0); glVertex3d(280, 160, 1);
glTexCoord2d(1, 1); glVertex3d(280, 290, 1);
glTexCoord2d(0, 1); glVertex3d(280, 290, 950);
glEnd();
glDisable(GL_TEXTURE_2D);
glDisable(GL_BLEND);
glPopMatrix();
//Ê«ÃÂ… Ì”«—Ì

glPushMatrix();

glEnable(GL_BLEND);
glColor3f(1, 1, 1);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, interfaceeright);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(280, 160, 950);
glTexCoord2d(1, 0); glVertex3d(60, 160, 950);
glTexCoord2d(1, 1);  glVertex3d(60, 290, 950);
glTexCoord2d(0, 1); glVertex3d(280, 290, 950);
glEnd();
glDisable(GL_TEXTURE_2D);

///////////////////
glPopMatrix();
//Ê«ÃÂ… Ì„Ì‰Ì
glPushMatrix();

glEnable(GL_BLEND);
glColor3f(1, 1, 1);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, interfaceeright);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(-60, 1, 950);
glTexCoord2d(1, 0); glVertex3d(-280, 1, 950);
glTexCoord2d(1, 1);  glVertex3d(-280, 160, 950);
glTexCoord2d(0, 1); glVertex3d(-60, 160, 950);
glEnd();
glDisable(GL_TEXTURE_2D);

///////////////////
glPopMatrix();
//Ê«ÃÂ… »‰’ » ÿ«»ﬁ 2
glPushMatrix();

glEnable(GL_BLEND);
glColor3f(1, 1, 1);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, interfaceeright);

glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(60, 160, 950);
glTexCoord2d(1, 0); glVertex3d(-60, 160, 950);
glTexCoord2d(1, 1);  glVertex3d(-60, 290, 950);
glTexCoord2d(0, 1); glVertex3d(60, 290, 950);
//////////////////////////////

glEnd();
glDisable(GL_TEXTURE_2D);

glPopMatrix();
//Ì”«—Ì
glColor3f(1, 1, 1);
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, bul);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(-280, 160, 1);
glTexCoord2d(1, 0); glVertex3d(-280, 160, 950);
glTexCoord2d(1, 1); glVertex3d(-280, 290, 950);
glTexCoord2d(0, 1); glVertex3d(-280, 290, 1);
glEnd();
glDisable(GL_TEXTURE_2D);
glDisable(GL_BLEND);
glPopMatrix();
//Ãœ«— Œ·›Ì
glColor3f(1, 1, 1);
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, bul);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(280, 160, 10);
glTexCoord2d(1, 0); glVertex3d(-280, 160, 10);
glTexCoord2d(1, 1); glVertex3d(-280, 290, 10);
glTexCoord2d(0, 1); glVertex3d(280, 290, 10);
glEnd();
glDisable(GL_TEXTURE_2D);
glDisable(GL_BLEND);
glPopMatrix();
glPushMatrix();
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glColor4f(1, 1, 1, 0.8);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, aard);
glBegin(GL_QUADS);
glTexCoord2d(0, 0);
glVertex3d(275, 150, 0);
glTexCoord2d(1, 0);
glVertex3d(275, 150, 900);
glTexCoord2d(1, 1);
glVertex3d(-275, 150, 900);
glTexCoord2d(0, 1);
glVertex3d(-275, 150, 0);
glEnd();
glDisable(GL_TEXTURE_2D);
glDisable(GL_BLEND);
glPopMatrix();
//”Ã«œ… ÿ«»ﬁ  «‰Ì
glColor3f(1, 1, 1);
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, ard);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(275, 165, 900);
glTexCoord2d(5, 0); glVertex3d(-275, 165, 900);
glTexCoord2d(5, 5); glVertex3d(-275, 165, 1);
glTexCoord2d(0, 5); glVertex3d(275, 165, 1);
glEnd();
glPushMatrix();
glDisable(GL_TEXTURE_2D);
glDisable(GL_BLEND);
glPopMatrix();

glEnable(GL_BLEND);
glColor3f(1, 1, 1);

glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, interfaceeright);

glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(-60, 160, 950);
glTexCoord2d(1, 0); glVertex3d(-280, 160, 950);
glTexCoord2d(1, 1);  glVertex3d(-280, 290, 950);
glTexCoord2d(0, 1); glVertex3d(-60, 290, 950);
glEnd();
glDisable(GL_TEXTURE_2D);
glPopMatrix();

if(num_room==1)
{
	room2_3(door11);
}
if(num_room==2)
{
	room2_3(door11);
	room2_4(door11);
}
if (num_room == 3)
{
	room2_3(door11);
	room2_4(door11);
	room2_1(door11);
}
if (num_room == 4)
{
	room2_3(door11);
	room2_4(door11);
	room2_1(door11);
	room2_2(door11);
}

 }
void flatfirst(int num_room, bool door_build, bool door11)
{
	glPushMatrix();
	A19.scale = 6;
	A19.rot.y = 0;
	A19.pos.x = -100;
	A19.pos.y = 1;
	A19.pos.z = 990;
	A19.Draw();
	glPopMatrix();
	glPushMatrix();
	A19.scale = 6;
	A19.rot.y = 0;
	A19.pos.x = 100;
	A19.pos.y = 1;
	A19.pos.z = 990;
	A19.Draw();
	glPopMatrix();
	//„› «ÕÊ Õ—› g
	if (door_build == true  && ssaa < 35)
	{
		ssaa += 2;
		ssbb += 2;
	}
	else if (door_build == false && ssaa > 0 && ssbb > 0)
	{
		ssaa -= 2;
		ssbb -= 2;
	}
		glPushMatrix();
		glTranslated(ssbb, 0, 0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, door1);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3d(60, 0.5, 957);
		glTexCoord2d(1, 0); glVertex3d(0, 0.5, 957);
		glTexCoord2d(1, 1);  glVertex3d(0, 130, 957);
		glTexCoord2d(0, 1); glVertex3d(60, 130, 957);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslated(-ssaa, 0, 0);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, door2);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3d(0, 0.5, 957);
		glTexCoord2d(1, 0); glVertex3d(-60, 0.5, 957);
		glTexCoord2d(1, 1);  glVertex3d(-60, 130, 957);
		glTexCoord2d(0, 1); glVertex3d(0, 130, 957);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, ard);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(280, 8, 950);
glTexCoord2d(5, 0); glVertex3d(-280, 8, 950);
glTexCoord2d(5, 5); glVertex3d(-280, 8, 1);
glTexCoord2d(0, 5); glVertex3d(280, 8, 1);
glEnd();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
//Ì„Ì‰
glColor3f(1, 1, 1);
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, bul);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(280, 1, 950);
glTexCoord2d(1, 0); glVertex3d(280, 1, 1);
glTexCoord2d(1, 1); glVertex3d(280, 160, 1);
glTexCoord2d(0, 1); glVertex3d(280, 160, 950);
glEnd();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
//ÕÌÿ Ì”«—Ì
glPushMatrix();

glEnable(GL_BLEND);
glColor3f(1, 1, 1);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, interfaceeright);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(280, 1, 950);
glTexCoord2d(1, 0); glVertex3d(60, 1, 950);
glTexCoord2d(1, 1);  glVertex3d(60, 160, 950);
glTexCoord2d(0, 1); glVertex3d(280, 160, 950);
glEnd();
glDisable(GL_TEXTURE_2D);

///////////////////
glPopMatrix();
//Ê«ÃÂ… Ì„Ì‰Ì
glPushMatrix();

glEnable(GL_BLEND);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, interfaceeright);
glColor3f(1, 1, 1);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(-60, 1, 950);
glTexCoord2d(1, 0); glVertex3d(-280, 1, 950);
glTexCoord2d(1, 1);  glVertex3d(-280, 160, 950);
glTexCoord2d(0, 1); glVertex3d(-60, 160, 950);
glEnd();
glDisable(GL_TEXTURE_2D);
///////////////////
glPopMatrix();
glPushMatrix();

glEnable(GL_BLEND);
glColor3f(1, 1, 1);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, interfaceeright);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(60, 130, 950);
glTexCoord2d(1, 0); glVertex3d(-60, 130, 950);
glTexCoord2d(1, 1);  glVertex3d(-60, 160, 950);
glTexCoord2d(0, 1); glVertex3d(60, 160, 950);
//////////////////////////////

glEnd();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
//Ì”«—Ì » ÿ«»ﬁ «Ê·
glColor3f(1, 1, 1);
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, bul);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(-280, 1, 1);
glTexCoord2d(1, 0); glVertex3d(-280, 1, 950);
glTexCoord2d(1, 1); glVertex3d(-280, 160, 950);
glTexCoord2d(0, 1); glVertex3d(-280, 160, 1);
glEnd();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
//Ãœ«— Œ·›Ì
glColor3f(1, 1, 1);
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, bul);
glBegin(GL_QUADS);

glTexCoord2d(0, 0); glVertex3d(280, 2, 10);
glTexCoord2d(1, 0); glVertex3d(-280, 2, 10);
glTexCoord2d(1, 1); glVertex3d(-280, 160, 10);
glTexCoord2d(0, 1); glVertex3d(280, 160, 10);

glEnd();
glDisable(GL_TEXTURE_2D);
glPopMatrix();

if (num_room == 1)
{
	room1_3(door11);
}
if (num_room == 2)
{
	room1_3(door11);
	room1_4(door11);

}
if (num_room == 3)
{
	room1_3(door11);
	room1_4(door11);
	room1_1(door11);
}
if (num_room == 4)
{
	room1_3(door11);
	room1_4(door11);
	room1_1(door11);
	room1_2(door11);
}

}

void flattherd(int num_room, bool door11){
//«—÷Ì… ÿ 3
	glColor3f(1, 1, 1);
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, bul);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(280, 290, 0);
glTexCoord2d(1, 0); glVertex3d(280, 290, 950);
glTexCoord2d(1, 1); glVertex3d(-280, 290, 950);
glTexCoord2d(0, 1); glVertex3d(-280, 290, 0);
glEnd();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
//Ì„Ì‰
glColor3f(1, 1, 1);
glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, bul);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(280, 290, 950);
glTexCoord2d(1, 0); glVertex3d(280, 290, 1);
glTexCoord2d(1, 1); glVertex3d(280, 440, 1);
glTexCoord2d(0, 1); glVertex3d(280, 440, 950);
glEnd();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
glPushMatrix();
glEnable(GL_BLEND);
glColor3f(1, 1, 1);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, interfaceeright);	
glBegin(GL_QUADS);
glTexCoord2d(0, 0);
glVertex3d(-60, 440, 950);
glTexCoord2d(1, 0);
glVertex3d(-280, 440, 950);
glTexCoord2d(1, 1);
glVertex3d(-280, 290, 950);
glTexCoord2d(0, 1);
glVertex3d(-60, 290, 950);
glEnd();
glDisable(GL_TEXTURE_2D);
glPopMatrix();
//Ê«ÃÂ… Ì”«—Ì
glPushMatrix();

glEnable(GL_BLEND);
glColor3f(1, 1, 1);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, interfaceeright);

glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(280, 290, 950);
glTexCoord2d(1, 0); glVertex3d(60, 290, 950);
glTexCoord2d(1, 1);  glVertex3d(60, 440, 950);
glTexCoord2d(0, 1); glVertex3d(280, 440, 950);
glEnd();
glDisable(GL_TEXTURE_2D);
//glDisable(GL_BLEND);

///////////////////
glPopMatrix();
//Ê«ÃÂ… »‰’
glPushMatrix();

glEnable(GL_BLEND);
//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glColor3f(1, 1, 1);
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, interfaceeright);

glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(60, 290, 950);

glTexCoord2d(1, 0); glVertex3d(-60, 290, 950);
glTexCoord2d(1, 1);  glVertex3d(-60, 440, 950);
glTexCoord2d(0, 1); glVertex3d(60, 440, 950);
//////////////////////////////

glEnd();
glDisable(GL_TEXTURE_2D);
//glDisable(GL_BLEND);

glPopMatrix();
//Ì”«—Ì » ÿ«»ﬁ  «· 
glColor3f(1, 1, 1);
glPushMatrix();
glEnable(GL_TEXTURE_2D);

glBindTexture(GL_TEXTURE_2D, bul);

glBegin(GL_QUADS);

glTexCoord2d(0, 0); glVertex3d(-280, 290, 1);
glTexCoord2d(1, 0); glVertex3d(-280, 290, 950);
glTexCoord2d(1, 1); glVertex3d(-280, 440, 950);
glTexCoord2d(0, 1); glVertex3d(-280, 440, 1);
glEnd();
glPopMatrix();
//Ãœ«— Œ·›Ì

glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, bul);
glBegin(GL_QUADS);

glTexCoord2d(0, 0); glVertex3d(280, 290, 10);
glTexCoord2d(1, 0); glVertex3d(-280, 290, 10);
glTexCoord2d(1, 1); glVertex3d(-280, 440, 10);
glTexCoord2d(0, 1); glVertex3d(280, 440, 10);

glEnd();
glDisable(GL_TEXTURE_2D);
//glDisable(GL_BLEND);
glPopMatrix();
//”Ã«œ… ÿ«»ﬁ  «· 

glPushMatrix();
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, ard);
glBegin(GL_QUADS);
glTexCoord2d(0, 0); glVertex3d(275, 300, 900);
glTexCoord2d(5, 0); glVertex3d(-275, 300, 900);
glTexCoord2d(5, 5); glVertex3d(-275, 300, 1);
glTexCoord2d(0, 5); glVertex3d(275, 300, 1);
glEnd();
glDisable(GL_TEXTURE_2D);
//glDisable(GL_BLEND);
glPopMatrix();
if(num_room==1)
{
	room3_3( door11);
}
if(num_room==2)
{
	room3_3(door11);
	room3_4(door11);

}
if(num_room==3)
{
	room3_3(door11);
	room3_4(door11);
	room3_1(door11);
}
if(num_room==4)
{
	room3_3(door11);
	room3_4(door11);
	room3_1(door11);
	room3_2(door11);
}

}
void   Basic_Build::basic_Build(int number, int num_room ,bool door_build,bool door11)

{
	
	glDisable(GL_LIGHTING);
		if (number == 1)
		{
			flatfirst(num_room,  door_build,  door11);
			
			
			glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, roof);
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0); glVertex3d(280, 165, 0);
			glTexCoord2d(5, 0); glVertex3d(280, 165, 950);
			glTexCoord2d(5, 5); glVertex3d(-285, 165, 950);
			glTexCoord2d(0, 5); glVertex3d(-285, 165, 0);
			glEnd();
			glPopMatrix();
		}
		if (number == 2)
		{
			flatfirst(num_room,door_build, door11);
			flatsecond(num_room, door11);
			
			glPushMatrix();
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, roof);
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0); glVertex3d(280, 291, 0);
			glTexCoord2d(5, 0); glVertex3d(280, 291, 950);
			glTexCoord2d(5, 5); glVertex3d(-285, 291, 950);
			glTexCoord2d(0, 5); glVertex3d(-285, 291, 0);
			glEnd();
			glPopMatrix();
			
		}
		if (number == 3)
		{
			flatfirst(num_room ,door_build, door11);
			flatsecond(num_room,door11);
			flattherd(num_room,door11);
			glPushMatrix();
			
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, roof);
			glBegin(GL_QUADS);
			glTexCoord2d(0, 0); glVertex3d(280, 440, 0);
			glTexCoord2d(5, 0); glVertex3d(280, 440, 950);
			glTexCoord2d(5, 5); glVertex3d(-285, 440, 950);
			glTexCoord2d(0, 5); glVertex3d(-285, 440, 0);
			glEnd();
			glPopMatrix();
		}

		
}