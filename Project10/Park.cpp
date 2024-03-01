#include "Park.h"
#include "Street.h"
#include <windows.h>		// Header File For Windows
#include <GL.h>				// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <gl/glut.h>			// Header File For The GLut32 Library
#include <fstream>
#include <math.h>
#include "texture.h"
#include<camera.h>
#include<iostream>
//include lib file
//#include<Model_3DS.h>
//#include<3DTexture.h>
#include <glaux.h>		// Header File For The Glaux Library
#include"Model_3DS.h"
#include "3DTexture.h"
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glut32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"GLAUX.LIB")
using namespace std;

Model_3DS wm;

void Park::initPark() {

	//first type of tree
	tree1 = Model_3DS();
	tree1.Load((char *)"d//tree1.3ds");
	tree1.Materials[0].tex.Load((char *)"d//b.bmp");
	tree1.Materials[1].tex.Load((char *)"d//bark.bmp");

	//second type of tree
	tree2 = Model_3DS();
	tree2.Load((char *)"d//tree2.3ds");
	tree2.Materials[0].tex.Load((char *)"d//bark.bmp");
	tree2.Materials[1].tex.Load((char *)"d//green.bmp");
	tree2.Materials[2].tex.Load((char *)"d//green.bmp");
	tree2.Materials[3].tex.Load((char *)"d//green.bmp");
	tree2.Materials[4].tex.Load((char *)"d//green.bmp");
	tree2.Materials[5].tex.Load((char *)"d//green.bmp");
	tree2.Materials[6].tex.Load((char *)"d//green.bmp");
	tree2.Materials[7].tex.Load((char *)"d//green.bmp");
	tree2.Materials[8].tex.Load((char *)"d//green.bmp");
	tree2.Materials[9].tex.Load((char *)"d//green.bmp");
	tree2.Materials[10].tex.Load((char *)"d//green.bmp");

	//chair
	chair = Model_3DS();
	chair.Load((char *)"d//chair.3ds");
	chair.Materials[0].tex.Load((char *)"d//bark.bmp");
	chair.Materials[1].tex.Load((char *)"d//bark.bmp");
	
	//first type of toy
	toy1 = Model_3DS();
	toy1.Load((char *)"d//toy1.3ds");
	toy1.Materials[0].tex.Load((char *)"d//metal.bmp");
	toy1.Materials[1].tex.Load((char *)"d//metal.bmp");

	//second type of toy
	toy2 = Model_3DS();
	toy2.Load((char *)"d//toy2.3ds");
	toy2.Materials[0].tex.Load((char *)"d//toy4.bmp");
	toy2.Materials[1].tex.Load((char *)"d//toy4.bmp");
	toy2.Materials[2].tex.Load((char *)"d//toy4.bmp");
	toy2.Materials[3].tex.Load((char *)"d//toy4.bmp");
	toy2.Materials[4].tex.Load((char *)"d//toy4.bmp");
	toy2.Materials[5].tex.Load((char *)"d//toy4.bmp");
	
	//third type of toy
	toy3 = Model_3DS();
	toy3.Load((char *)"d//toy3.3ds");
	toy3.Materials[0].tex.Load((char *)"d//toy4.bmp");
	toy3.Materials[1].tex.Load((char *)"d//toy4.bmp");
	toy3.Materials[2].tex.Load((char *)"d//toy4.bmp");
	toy3.Materials[3].tex.Load((char *)"d//toy4.bmp");
	toy3.Materials[4].tex.Load((char *)"d//toy4.bmp");
	toy3.Materials[5].tex.Load((char *)"d//toy3.bmp");
	toy3.Materials[6].tex.Load((char *)"d//toy3.bmp");
	toy3.Materials[7].tex.Load((char *)"d//toy3.bmp");
	toy3.Materials[8].tex.Load((char *)"d//toy3.bmp");
	toy3.Materials[9].tex.Load((char *)"d//toy3.bmp");
	toy3.Materials[10].tex.Load((char *)"d//toy3.bmp");

	//kiosk
	kish = Model_3DS();
	kish.Load((char *)"d//kish.3ds");
	kish.Materials[0].tex.Load((char *)"d//kish2.bmp");
	kish.Materials[1].tex.Load((char *)"d//kish2.bmp");
	
	//rubbish
	gb = Model_3DS();
	gb.Load((char *)"d//gb.3ds");
	gb.Materials[0].tex.Load((char *)"d//gb.bmp");
	gb.Materials[1].tex.Load((char *)"d//gb.bmp");
	
	//man 1
	man = Model_3DS();
	man.Load((char *)"d//man1.3ds");
	man.Materials[0].tex.Load((char *)"d//man11.bmp");
	man.Materials[1].tex.Load((char *)"d//man11.bmp");
	man.Materials[2].tex.Load((char *)"d//man111.bmp");
	man.Materials[3].tex.Load((char *)"d//man111.bmp");
	man.Materials[4].tex.Load((char *)"d//man111.bmp");
	man.Materials[5].tex.Load((char *)"d//man111.bmp");
	
	
}

void Park::drawPeople(int n) {
	
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glScalef(20, 20, 20);
	man.rot.y = 180;
	man.pos.x = 58;
	man.pos.y = 0;
	man.pos.z = 84;
	man.Draw();
	glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(20, 20, 20);
		man.rot.y = 180;
		man.pos.x = -57;
		man.pos.y = 0;
		man.pos.z = 84;
		man.Draw();
		glPopMatrix();

		if (n >=3) {
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(1, 1, 1);
			glScalef(20, 20, 20);
			man.rot.y = 180;
			man.pos.x = -20;
			man.pos.y = 0;
			man.pos.z = 82;
			man.Draw();
			glPopMatrix();
		}
		if (n >=4) {
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(1, 1, 1);
			glScalef(20, 20, 20);
			man.rot.y = 180;
			man.pos.x = 20;
			man.pos.y = 0;
			man.pos.z = 82;
			man.Draw();
			glPopMatrix();
		}
		if (n >=5)
		{
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(1, 1, 1);
			glScalef(20, 20, 20);
			man.pos.x = -10;
			man.pos.y = 0;
			man.pos.z = 55;
			man.Draw();
			glPopMatrix();
		}
		if (n==6)
		{
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(1, 1, 1);
			glScalef(20, 20, 20);
			man.pos.x = 10;
			man.pos.y = 0;
			man.pos.z = 55;
			man.Draw();
			glPopMatrix();
		}
}

void Park::drawRubbish() {
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glScalef(5, 5, 5);
	gb.pos.x = 225;
	gb.pos.y = 0;
	gb.pos.z = 330;
	gb.Draw();
	glPopMatrix();

	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glScalef(5, 5, 5);
	gb.pos.x = -220;
	gb.pos.y = 0;
	gb.pos.z = 330;
	gb.Draw();
	glPopMatrix();

}

void Park::drawTree1() {
	int x = 36000;

	for (int i = 0; i < 12; i++) {
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.04, 0.04, 0.04);
		tree1.pos.x = x;
		tree1.pos.y =-500;
		tree1.pos.z = 44500;
		tree1.Draw();
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.04, 0.04, 0.04);
		tree1.pos.x = -x;
		tree1.pos.y = -500;
		tree1.pos.z = 44500;
		tree1.Draw();
		glPopMatrix();

		
		x = x - 3000;
	}

}



void Park::drawTree2(int n) {
	int x = 100;
	for (int i =0; i<n; i++) {
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(0.5, 0.5, 0.5);
		glScalef(10, 20, 10);
		tree2.pos.x = x;
		tree2.pos.y = 0;
		tree2.pos.z = 170;
		tree2.Draw();
		glPopMatrix();

		x = x - 28;
	}
}

void Park::drawKish(int a) {

	if (a==1) {
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.5, 0.5, 0.5);
		kish.rot.y = 180;
		kish.pos.x = 2350;
		kish.pos.y = 0;
		kish.pos.z = 3300;
		kish.Draw();
		glPopMatrix();
	}

	if (a==2) {
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.5, 0.5, 0.5);
		kish.rot.y = 180;
		kish.pos.x = -2300;
		kish.pos.y = 0;
		kish.pos.z = 3300;
		kish.Draw();
		glPopMatrix();
	}

	if (a==3) {
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.5, 0.5, 0.5);
		kish.rot.y = 180;
		kish.pos.x = 2350;
		kish.pos.y = 0;
		kish.pos.z = 3300;
		kish.Draw();
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.5, 0.5, 0.5);
		kish.rot.y = 180;
		kish.pos.x = -2300;
		kish.pos.y = 0;
		kish.pos.z = 3300;
		kish.Draw();
		glPopMatrix();
	}
}


void Park::drawChair(int n) {
	int x = 3505;

	for (int i = 0; i < n+1; i++) {
		if (x != 5) {
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(1,1,1);
			glScalef(0.3, 0.3, 0.3);
			chair.rot.y = 90;
			chair.pos.x = x;
			chair.pos.y = 0;
			chair.pos.z = 6300;
			chair.Draw();
			glPopMatrix();
		}
		x = x - 500;
	}
}

void Park::drawToy(int a7) {
	int z = 340;
	for (int i = 0; i < 5; i++) {
		if (a7==1) {
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(1, 0, 0);
			glScalef(5, 10, 5);
			toy1.rot.y = -180;
			toy1.pos.x = 255;
			toy1.pos.y = 4;
			toy1.pos.z = z;
			toy1.Draw();
			glPopMatrix();
		}

		if (a7==2) {
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(1, 0, 1);
			glScalef(5, 10, 5);
			toy1.pos.x = -250;
			toy1.pos.y = 4;
			toy1.pos.z = z;
			toy1.Draw();
			glPopMatrix();
		}
		if (a7==3) {
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(1, 0, 0);
			glScalef(5, 10, 5);
			toy1.rot.y = -180;
			toy1.pos.x = 255;
			toy1.pos.y = 4;
			toy1.pos.z = z;
			toy1.Draw();
			glPopMatrix();


			glPushMatrix();
			glDisable(GL_LIGHTING);
			glColor3f(1, 0, 1);
			glScalef(5, 10, 5);
			toy1.pos.x = -250;
			toy1.pos.y = 4;
			toy1.pos.z = z;
			toy1.Draw();
			glPopMatrix();

		}
		
		z = z - 5;
	}
	if (a7==1) {
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.3, 0.3, 0.3);
		toy2.pos.x = 4800;
		toy2.pos.y = 70;
		toy2.pos.z = 5700;
		toy2.Draw();
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.5, 0.5, 0.5);
		toy3.pos.x = 2700;
		toy3.pos.y = 0;
		toy3.pos.z = 3300;
		toy3.Draw();
		glPopMatrix();
	}

	if (a7==2) {
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.3, 0.3, 0.3);
		toy2.pos.x = -4800;
		toy2.pos.y = 70;
		toy2.pos.z = 5700;
		toy2.Draw();
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.5, 0.5, 0.5);
		toy3.pos.x = -2700;
		toy3.pos.y = 0;
		toy3.pos.z = 3300;
		toy3.Draw();
		glPopMatrix();
	}

	if (a7==3) {
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.3, 0.3, 0.3);
		toy2.pos.x = 4800;
		toy2.pos.y = 70;
		toy2.pos.z = 5700;
		toy2.Draw();
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.5, 0.5, 0.5);
		toy3.pos.x = 2700;
		toy3.pos.y = 0;
		toy3.pos.z = 3300;
		toy3.Draw();
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.3, 0.3, 0.3);
		toy2.pos.x = -4800;
		toy2.pos.y = 70;
		toy2.pos.z = 5700;
		toy2.Draw();
		glPopMatrix();

		glPushMatrix();
		glDisable(GL_LIGHTING);
		glColor3f(1, 1, 1);
		glScalef(0.5, 0.5, 0.5);
		toy3.pos.x = -2700;
		toy3.pos.y = 0;
		toy3.pos.z = 3300;
		toy3.Draw();
		glPopMatrix();
	}
}


void Park::drawTree(int n) {
	drawTree1();
	drawTree2(n);
}