#include "Skybox.h"
#include <windows.h>		// Header File For Windows
#include <GL.h>				// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
//#include <gl/glut.h>			// Header File For The GLut32 Library
#include <fstream>
#include <math.h>
#include "texture.h"
#include<camera.h>
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
/*
void Skybox::skybox22(int q, int q1, int q2, int q3, int q4, int q5)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q);//SKYFRONT
	glBegin(GL_QUADS);

	
	glTexCoord2d(1, 0); glVertex3d(-1500, 0, 0);
	glTexCoord2d(1, 1); glVertex3d(-1500, 1200, 0);
	glTexCoord2d(0, 1); glVertex3d(1500, 1200, 0);
	glTexCoord2d(0, 0); glVertex3d(1500, 0, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q1);//SKYBACK
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0); glVertex3d(-1500, 0, 1800);// glVertex3d(-1500, 0, 1800);
	glTexCoord2d(1, 1); glVertex3d(-1500, 1200, 1800);//glVertex3d(-1500, 1200, 1800);
	glTexCoord2d(0, 1); glVertex3d(1500, 1200, 1800);//glVertex3d(1500, 1200, 1800);
	glTexCoord2d(0, 0); glVertex3d(1500, 0, 1800);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q2);// SKYLEFT
	glPushMatrix();
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 1); glVertex3d(1500, 1200, 0);
	glTexCoord2d(0, 0); glVertex3d(1500, 0, 0);
	glTexCoord2d(1, 0); glVertex3d(1500, 0, 1800);
	glTexCoord2d(1, 1); glVertex3d(1500, 1200, 1800);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q3);//SKYRIGHT
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(-1500, 0, 0);
	glTexCoord2d(1, 0); glVertex3d(-1500, 0, 1800);
	glTexCoord2d(1, 1); glVertex3d(-1500, 1200, 1800);
	glTexCoord2d(0, 1); glVertex3d(-1500, 1200, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q4);//SKYUP
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(1500, 1200, 0);
	glTexCoord2d(1, 0); glVertex3d(-1500, 1200, 0);
	glTexCoord2d(1, 1); glVertex3d(-1500, 1200, 1800);
	glTexCoord2d(0, 1); glVertex3d(1500, 1200, 1800);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q5);//cc
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(1500, 0, 1800);
	glTexCoord2d(1, 0); glVertex3d(-1500, 0, 1800);
	glTexCoord2d(1, 1); glVertex3d(-1500, 0, 0);
	glTexCoord2d(0, 1); glVertex3d(1500, 0, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}*/
void Skybox ::skybox22(int q, int q1, int q2, int q3, int q4, int q5)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q);//SKYFRONT
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0); glVertex3d(1500, 0, 0);
	glTexCoord2d(1, 0); glVertex3d(-1500, 0, 0);
	glTexCoord2d(1, 1); glVertex3d(-1500, 1200, 0);
	glTexCoord2d(0, 1); glVertex3d(1500, 1200, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q1);//SKYBACK
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(1500, 0, 1800);
	glTexCoord2d(1, 0); glVertex3d(-1500, 0, 1800);// glVertex3d(-1500, 0, 1800);
	glTexCoord2d(1, 1); glVertex3d(-1500, 1200, 1800);//glVertex3d(-1500, 1200, 1800);
	glTexCoord2d(0,1); glVertex3d(1500, 1200, 1800);//glVertex3d(1500, 1200, 1800);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q2);// SKYLEFT
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(1500, 0, 0);
	glTexCoord2d(1, 0); glVertex3d(1500, 0, 1800);
	glTexCoord2d(1, 1); glVertex3d(1500, 1200, 1800);
	glTexCoord2d(0, 1); glVertex3d(1500, 1200, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q3);//SKYRIGHT
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(-1500, 0, 0);
	glTexCoord2d(1, 0); glVertex3d(-1500, 0, 1800);
	glTexCoord2d(1, 1); glVertex3d(-1500, 1200, 1800);
	glTexCoord2d(0, 1); glVertex3d(-1500, 1200, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q4);//SKYUP
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(1500, 1200, 0);
	glTexCoord2d(1, 0); glVertex3d(-1500, 1200, 0);
	glTexCoord2d(1, 1); glVertex3d(-1500, 1200, 1800);
	glTexCoord2d(0, 1); glVertex3d(1500, 1200, 1800);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q5);//cc
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(1500, 0, 1800);
	glTexCoord2d(1, 0); glVertex3d(-1500, 0, 1800);
	glTexCoord2d(1, 1); glVertex3d(-1500, 0, 0);
	glTexCoord2d(0, 1); glVertex3d(1500, 0, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}