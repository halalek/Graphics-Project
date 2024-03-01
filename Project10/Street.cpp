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


Model_3DS Square;
Model_3DS h;
Model_3DS h1;
Model_3DS cars;
Model_3DS cars1;
Model_3DS bus1;
Model_3DS Bus2;
Model_3DS lightt;
Model_3DS traff;
Model_3DS traff1;
int road; int help;

void Street::street(int road,node s[],int vertical)
{
	
	
	
if (vertical ==1) {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, road);
		glBegin(GL_POLYGON);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(s[0].x, s[0].y, s[0].z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(s[1].x, s[1].y, s[1].z);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(s[2].x, s[2].y, s[2].z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(s[3].x, s[3].y, s[3].z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
	
	if (vertical ==0) {
		glPushMatrix();
		glColor3f(1, 1, 1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, road);
		glBegin(GL_POLYGON);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(s[0].x, s[0].y, s[0].z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(s[1].x, s[1].y, s[1].z);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(s[2].x, s[2].y, s[2].z);
		glTexCoord2f(0.0f,0.0f); glVertex3f(s[3].x, s[3].y, s[3].z);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
//	glDisable(GL_TEXTURE_2D);
	
}




node build1[] = { { 1500,1,1200 },{-1500, 1, 1200}, {-1500, 1, 1350}, {1500, 1, 1350 } };
node build2[] = { { 1500,1,1400 },{-1500, 1, 1400}, {-1500, 1, 1550}, {1500, 1, 1550 } };
//node build3[] = { {0,1,1550 },{-50,1, 1550}, {-50, 1, 1800}, {0, 1, 1800 } };
 node build3[] = { {-70,1,1550 },{70,1, 1550}, {70, 1, 1800}, {-70, 1, 1800 } };
//node build4[] = { {70,1,1550 },{20, 1, 1550}, {20, 1, 1800}, {70, 1, 1800 } };

void Street::street1(int number,int texture)
{
	if (number == 1)
	{
		street(texture,build1,0);
	}

	if (number == 2)
	{
		street(texture, build1,0);
		street(texture, build2,0);
	}

	if (number == 3)
	{
		street(texture, build1,0);
		street(texture, build2,0);
		street(texture, build3,1);
	}
}

void Street::square(Model_3DS square)
{

	float angle = 0;
	float x = 10, y = 1360, r = 200;

	//Circle();
	glBegin(GL_POLYGON);
	for (float i = 2000.0f; i < 2100; i += 0.1f)
	{
		glColor3f(0.12, 0.12, 0.13);
		glVertex3f(x+(sin(i)*r),2 , y + (cos(i)*r));
	}
	glEnd();

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	glScalef(0.1, 0.1, 0.1);
	square.pos.x = 100;
	square.pos.y = 30;
	square.pos.z = 13700;
	square.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}
bool color = false;
void Street::grassnumber(Model_3DS h,int n)
{

	//if (color == false) { color=true; h.Materials[19].tex.Load((char *)"h//1 (3).bmp");}
	//if (color ==false) { color=false; h.Materials[19].tex.Load((char *)"h//0.bmp");}
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(0.1, 0.1, 0.1);
	h.pos.x = n;
	h.pos.y = 10;
	h.pos.z = 13800;//6900
	h.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();



}
void Street::grass(Model_3DS h, Model_3DS h1,int r)
{

	if (r == 2) {
	grassnumber(h, 2500); 
	grassnumber(h, -2500);
	}
	if (r == 4) {
		grassnumber(h, 2500);
		grassnumber(h, -2500);
		grassnumber(h1, 4500);
		grassnumber(h1, -4500);
	}
	if (r == 6) {
		grassnumber(h, 2500);
		grassnumber(h, -2500);
		grassnumber(h1, 4500);
		grassnumber(h1, -4500);
		grassnumber(h, 6500);
		grassnumber(h, -6500);
	}
	if (r == 8) {
		grassnumber(h, 2500);
		grassnumber(h, -2500);
		grassnumber(h1, 4500);
		grassnumber(h1, -4500);
		grassnumber(h, 6500);
		grassnumber(h, -6500);
		grassnumber(h1, 8500);
		grassnumber(h1, -8500);
	}
	if (r == 10) {
		grassnumber(h, 2500);
		grassnumber(h, -2500);
		grassnumber(h1, 4500);
		grassnumber(h1, -4500);
		grassnumber(h, 6500);
		grassnumber(h, -6500);
		grassnumber(h1, 8500);
		grassnumber(h1, -8500);
		grassnumber(h, 10500);
		grassnumber(h, -10500);
	}
	if (r == 12) {
		grassnumber(h, 2500);
		grassnumber(h, -2500);
		grassnumber(h1, 4500);
		grassnumber(h1, -4500);
		grassnumber(h, 6500);
		grassnumber(h, -6500);
		grassnumber(h1, 8500);
		grassnumber(h1, -8500);
		grassnumber(h, 10500);
		grassnumber(h, -10500);
		grassnumber(h1, 13500);
		grassnumber(h1, -13500);
	}
	



}
GLfloat  zRotated =0;
float point1 =-1510 ,point2=-1200;
float yy = 6, xx = 6;
bool stop = false;
int a = 90;
void Street::car(Model_3DS h, int n)
{
	glPushMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1, 1, 1);
	
	glRotated(a, 0, 1,0);
	h.pos.x =point1;//-1510
	h.pos.y = 22;
	h.pos.z = point2;//-1100
	h.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	if (stop == false)
	{
		point2 += yy;
	}


	/*if (point2 >= -8.00)
	{
		point1 -= xx;
		xx = +xx;
		stop = false;

	}*/

	if (point2 >=-70&&stop==false)
	{
		
		point2 -= xx;
		xx = +xx;
		stop = true;
		glPushMatrix();
		a = 0;
		point1 = -30;//-1510
		point2 = 1600;
		/*h.pos.x = -30;//-1510
		h.pos.y = 30;
		h.pos.z =1600;//-1100
		h.Draw();*/
		
		glPopMatrix();
	}
	if (stop == true && point2<1900)
	{
		point2 += xx;
		//xx = -xx;
	}
	if (point2 >= 1900)
	{
		a = 90;
		point1 = -1510, point2 = -1100;
		stop =false;
		//xx = -xx;
	}

	glEnd();
	glPopMatrix();
}
float point7 = -1, point8 = -87;
float yy3 = 0.3, xx3 =0.3;
bool stop3 = false, stop31 = false;
int a2 = 180;
void Street::car1(Model_3DS h, int n)
{
	
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(20, 20, 20);
	glRotatef(a2,0,1,0);
	h.pos.x = point7;//pomnt7 -77
	h.pos.y = -0.05;
	h.pos.z =point8;//point8  5
	h.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
	if (stop3 == false && point8 < -80)
	{
		point8 += yy3;
	}


	if (stop31 == true)
	{
		if (point8 >= -80 && stop3 == false)
		{

			point7 -= xx3;
			xx3 = +xx3;
			stop3 = true;
			glPushMatrix();
			a2 = 90;
			point7 = -76;
			point8 = 5;

		}
	}
		if (stop3 == true&& point8<100)
		{
			point8 += xx3;
			//xx3 = -xx3;
		}

		if (point8 >= 100)
		{
			a2 = 180;
			point7 = -1; point8 = -87;
			stop3 = false;
			 
			//xx3 = -xx3;
		}
	
	glEnd();
	glPopMatrix();


}
float point9=-72, point10 =-50 ;
void Street::carcontrol(Model_3DS h, int n)
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glColor3f(0, 0.5, 0.5);
	glScalef(20, 20, 20);
	glRotatef(90, 0, 1, 0);
	h.pos.x = point9;//pomnt7 -77
	h.pos.y = -0.05;
	h.pos.z = point10;//point8  5
	h.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}
void Street::move_up()
{
	//if (point9 < 90)
		point9 += 0.5;
}

void Street::move_down()
{
	//if (point9 > -90)
		point9 -=0.5;
}

void Street:: move_left()
{
	//if (point10 > -90)
		point10 -=0.5;
}

void Street::move_right()
{
	//if (point10 < 90)
		point10 += 0.5;
}

void Street::Keyboard(bool	keys[])
{
	if (keys[GLUT_KEY_LEFT])
		move_left();
	if (keys[GLUT_KEY_RIGHT])
		move_right();
	if (keys[GLUT_KEY_UP])
		move_up();;
	if (keys[GLUT_KEY_DOWN])
		move_down();
}
float point3 = 1540, point4 = -1700;
float yy1 = 10, xx1 = 10;
bool stop1 = false;

void Street::bus(Model_3DS h, int n)
{
	glColor3f(1,1,1);
	glPushMatrix();
glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glRotatef(90,1,0,0);
	glRotatef(90, 0, 0,1);
	glScalef(0.8,0.8,0.8);
	h.pos.x = point3;//1240
	h.pos.y = point4;//-1200
	h.pos.z = -25;
	h.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glDisable(GL_COLOR);
	if (stop1 == false)
	{
		point4 += yy1;
	}

	if (point4 >= -110 && point4 <= -70)
	{

		point3 -= xx1;
		//xx1 = +xx1;
		//stop = true;
	}
	if (point4 >-30 && point4 <= 5)
	{

		point3 += xx1;
		//xx1 = -xx1;
		//stop = true;
	}

	if ( point4>=2000)
	{

		
		point3 = 1540; point4 = -1700;
	}
	glEnd();

}
float point5 = -30, point6 = 74;
float yy2 = 0.5, xx2 = 0.5;
bool stop2 = false;
void Street::bus2(Model_3DS h, int n)
{
	glColor3f(0.95, 0,0);
	glPushMatrix();
	glDisable(GL_LIGHTING);
glEnable(GL_TEXTURE_2D);
	//glRotatef(90, 1, 0, 0);
	//glRotatef(90, 0, 0, 1);
	glScalef(20, 20, 20);
	h.pos.x = point5;//50
	h.pos.y = 2.5;//-1200
	h.pos.z = point6;//-3
	h.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glDisable(GL_COLOR);
	
	if (point5 == 30)
	{
		stop31 = true;
		traff1.Materials[5].tex.Load((char *)"h//T (4).bmp");
		traff1.Materials[6].tex.Load((char *)"h//T (4).bmp");
		traff1.Materials[7].tex.Load((char *)"h//green.bmp");
		//traff.Materials[7].tex.Load((char *)"h//T (4).bmp");
		
	}
	if (stop2 == false)
	{
		point5+= yy2;
		//traff.Materials[7].tex.Load((char *)"h//green.bmp");
		
	}
	if (point5>=80)
	{
		point5 = -30, point6 = 74;
		stop31 = false;
		traff1.Materials[5].tex.Load((char *)"h//T (4).bmp");
		traff1.Materials[6].tex.Load((char *)"h//1 (3).bmp");
		traff1.Materials[7].tex.Load((char *)"h//T (4).bmp");
		//traff.Materials[7].tex.Load((char *)"h//green.bmp");

	}
	glEnd();

	
}
void Street::lightfrontright(Model_3DS h, int n,int x,int y,int z)
{
	float count = 0;
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(3, 3, 3);
	glRotatef(10, 1, 1, 1);
	h.pos.x = x;//20
	h.pos.y = y;//60
	h.pos.z = z;//520
	h.Draw();
	for (int i = 1; i < n; i++)
	{
		h.pos.x = x + (80*i);
		h.pos.y = y - (7.5*i);//-30
		h.pos.z = z + (10*i);
		h.Draw();
	}
	glDisable(GL_TEXTURE_2D);	
	glPopMatrix();
	glEnd();
}

void Street::lightfrontleft(Model_3DS h, int n, int x, int y, int z)
{

	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(3, 3, 3);
	glRotatef(10, 1, 1, 1);
	h.pos.x = x;//-120
	h.pos.y = y;//70
	h.pos.z = z;//510
	h.Draw();
	for (int i = 0; i < n; i++)
	{
		h.pos.x = x - (80*i);
		h.pos.y = y + (8*i);//-30
		h.pos.z = z - (10*i);
		h.Draw();

	}
	glDisable(GL_TEXTURE_2D);	
	glPopMatrix();
	glEnd();
}

void Street::lightbackleft(Model_3DS h, int n, int x, int y, int z)
{

	glDisable(GL_LIGHTING);
	for (int i = 0; i < n; i++)
	{glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(3, 3, 3);
	glRotatef(180, 0, 1, 0);
		h.pos.x = x + (80 * i);//80
		h.pos.y = y ;//10
		h.pos.z = z ;//-390
		h.Draw();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
	
	glEnd();
}

void Street::lightbackRight(Model_3DS h, int n, int x, int y, int z)
{

	glDisable(GL_LIGHTING);
	for (int i = 0; i < n; i++)
	{
		glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glColor3f(1, 1, 1);
		glScalef(3, 3, 3);
		glRotatef(180, 0, 1, 0);
		h.pos.x = x - (80 * i);//-100
		h.pos.y = y;//10
		h.pos.z = z;//-390
		h.Draw();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	glEnd();
}

void Street::lightbasic(Model_3DS h)
{
	float count = 0;//front
	glDisable(GL_LIGHTING);
	glPushMatrix();
    glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(3, 3, 3);
	glRotatef(90, 0, 1, 0);
	h.pos.x = -550;
	h.pos.y = 10;//-30
	h.pos.z = 30;
	h.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(3, 3, 3);
	glRotatef(90, 0, 1, 0);
	h.pos.x = -580;
	h.pos.y = 10;//-30
	h.pos.z = 30;
	h.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(3, 3, 3);
	glRotatef(250, 0, 1, 0);
	h.pos.x = 550;
	h.pos.y = 10;//-30
	h.pos.z = -170;
	h.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(3, 3, 3);
	glRotatef(250, 0, 1, 0);
	h.pos.x = 520;
	h.pos.y = 10;//-30
	h.pos.z = -160;
	h.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void Street::traffic(Model_3DS h, int n,Model_3DS ch)
{
	
	/*glPushMatrix();//liiiiiii
	glColor3f(1, 1, 1);
	//glScalef(0.51, 0.51, 0.51);
	glScalef(0.01, 0.01, 0.01);
	h.pos.x = 8000;//-1500
	h.pos.y =0;//600
	h.pos.z = 160000;//20500
	h.Draw();
	glPopMatrix();*/
	glPushMatrix();//liiiiiii
    glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	//glScalef(0.51, 0.51, 0.51);
	glScalef(30, 30,30);
	ch.pos.x = 3;//-1500
	ch.pos.y =0;//600
	ch.pos.z = 52;//20500
	ch.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();//liiiiiii
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glRotatef(90,0,1,0);
	glScalef(30, 30, 30);
	h.pos.x = -39;//-1500
	h.pos.y = 0;//600
	h.pos.z = 8;//20500
	h.Draw();
	glDisable(GL_TEXTURE_2D);	
	glPopMatrix();

	glPushMatrix();//liiiiiii
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glRotatef(90, 0, 1, 0);
	glScalef(30, 30, 30);
	h.pos.x = -47;//-1500
	h.pos.y = 0;//600
	h.pos.z = 8;//20500
	h.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();//liiiiiii
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glRotatef(240, 0, 1, 0);
	glScalef(30, 30, 30);
	h.pos.x =43;//-1500
	h.pos.y = 0;//600
	h.pos.z = -17;//20500
	h.Draw();
	glDisable(GL_TEXTURE_2D);	
	glPopMatrix();

	glPushMatrix();//liiiiiii
		glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glRotatef(240, 0, 1, 0);
	glScalef(30, 30, 30);
	h.pos.x = 48;//-1500 50
	h.pos.y = 0;//600
	h.pos.z =-21;//20500
	h.Draw();
	glDisable(GL_TEXTURE_2D);	
	glPopMatrix();

	glEnd();
	/*glDisable(GL_LIGHTING);
	glPushMatrix();
	glColor3f(1, 1, 1);
	glScalef(3, 3, 3);
	glRotatef(250, 0, 1, 0);
	h.pos.x = 520;
	h.pos.y = 10;//-30
	h.pos.z = -160;
	h.Draw();
	glPopMatrix();*/
/*	h.pos.x = 100;
	h.pos.y = 55;//-30
	h.pos.z = 530;
	h.Draw();

	h.pos.x = 180;
	h.pos.y = 50;//-30
	h.pos.z = 540;
	h.Draw();

	h.pos.x = 260;
	h.pos.y = 45;//-30
	h.pos.z = 550;
	h.Draw();

	h.pos.x = 320;
	h.pos.y = 40;//-30
	h.pos.z = 560;
	h.Draw();
	glPopMatrix();
	glEnd();



	glPushMatrix();//left
	glColor3f(1, 1, 1);
	glScalef(3, 3, 3);
	glRotatef(10, 1, 1, 1);
	h.pos.x = -120;
	h.pos.y = 70;//-30
	h.pos.z = 510;
	h.Draw();

	h.pos.x = -200;
	h.pos.y = 80;//-30
	h.pos.z = 500;
	h.Draw();

	h.pos.x = -280;
	h.pos.y = 90;//-30
	h.pos.z = 490;
	h.Draw();

	h.pos.x = -360;
	h.pos.y = 100;//-30
	h.pos.z = 480;
	h.Draw();

	h.pos.x = -440;
	h.pos.y = 110;//-30
	h.pos.z = 470;
	h.Draw();
	glPopMatrix();
	glEnd();*/


}
void Street::model()
{
	
	lightt = Model_3DS();
	lightt.Load((char *)"h//Light Pole.3ds");
	lightt.Materials[0].tex.Load((char *)"h//Light-Polee.bmp");
	
	/*traff.Load((char *)"h//t.3ds");
	traff.Materials[0].tex.Load((char *)"h//18FABRIC.bmp");
	traff.Materials[1].tex.Load((char *)"h//1 (3).bmp");
	traff.Materials[2].tex.Load((char *)"h//1 (3).bmp");
	traff.Materials[3].tex.Load((char *)"h//18FABRIC.bmp");
	traff.Materials[4].tex.Load((char *)"h//18FABRIC.bmp");*/

	//traff.Load((char *)"h//Traffic light N210817.3DS");
	
	traff = Model_3DS();
	traff.Load((char *)"h//traffic light 2.3ds");
	traff.Materials[0].tex.Load((char *)"h//18FABRIC.bmp");
	traff.Materials[1].tex.Load((char *)"h//18FABRIC.bmp");
	traff.Materials[2].tex.Load((char *)"h//T (2).bmp");
	traff.Materials[5].tex.Load((char *)"h//T (4).bmp");
	traff.Materials[6].tex.Load((char *)"h//1 (3).bmp");
	traff.Materials[7].tex.Load((char *)"h//green.bmp");
	traff.Materials[8].tex.Load((char *)"h//18FABRIC.bmp");

	traff1 = Model_3DS();
	traff1.Load((char *)"h//traffic light 2.3ds");
	traff1.Materials[0].tex.Load((char *)"h//18FABRIC.bmp");
	traff1.Materials[1].tex.Load((char *)"h//18FABRIC.bmp");
	traff1.Materials[2].tex.Load((char *)"h//T (2).bmp");
	traff1.Materials[5].tex.Load((char *)"h//T (4).bmp");
	traff1.Materials[6].tex.Load((char *)"h//1 (3).bmp");
	traff1.Materials[7].tex.Load((char *)"h//T (4).bmp");
	traff1.Materials[8].tex.Load((char *)"h//18FABRIC.bmp");
	
	
	
	bus1 = Model_3DS();
	bus1.Load((char *)"h//Taxi.3ds");
	//1 2 3 4 5 6 7 8 9 10 20 24 23 26
	//bus1.Materials[2].tex.Load((char *)"h//4_5.bmp");
	//bus1.Materials[1].tex.Load((char *)"h//4_6.bmp");
	bus1.Materials[0].tex.Load((char *)"h//4_3.bmp");
	
	
	
	Bus2 = Model_3DS();
	Bus2.Load((char *)"h//Bus18.3DS");
	//1 2 3 4 5 6 7 8 9 10 20 24 23 26
	//bus1.Materials[2].tex.Load((char *)"h//4_5.bmp");
	//bus1.Materials[1].tex.Load((char *)"h//4_6.bmp");
	Bus2.Materials[0].tex.Load((char *)"h//18FABRIC.bmp");
	Bus2.Materials[1].tex.Load((char *)"h//1811.bmp");
	Bus2.Materials[2].tex.Load((char *)"h//1811.bmp");
	Bus2.Materials[3].tex.Load((char *)"h//187.bmp");
	Bus2.Materials[4].tex.Load((char *)"h//185.bmp");
	Bus2.Materials[5].tex.Load((char *)"h//188.bmp");
	Bus2.Materials[6].tex.Load((char *)"h//189.bmp");
	Bus2.Materials[7].tex.Load((char *)"h//1815.bmp");
	Bus2.Materials[8].tex.Load((char *)"h//1818.bmp");
	Bus2.Materials[9].tex.Load((char *)"h//1816.bmp");
	Bus2.Materials[10].tex.Load((char *)"h//1817.bmp");
	Bus2.Materials[11].tex.Load((char *)"h//1820.bmp");
	Bus2.Materials[12].tex.Load((char *)"h//1812.bmp");
	Bus2.Materials[13].tex.Load((char *)"h//1813.bmp");
	Bus2.Materials[14].tex.Load((char *)"h//1819.bmp");
	Bus2.Materials[15].tex.Load((char *)"h//1827.bmp");
	Bus2.Materials[16].tex.Load((char *)"h//1810.bmp");
	Bus2.Materials[17].tex.Load((char *)"h//1814.bmp");
	Bus2.Materials[18].tex.Load((char *)"h//1823.bmp");
	Bus2.Materials[19].tex.Load((char *)"h//1824.bmp");
	Bus2.Materials[20].tex.Load((char *)"h//1825.bmp");
	Bus2.Materials[21].tex.Load((char *)"h//1826.bmp");
	Bus2.Materials[22].tex.Load((char *)"h//18FABRIC.bmp");
	Bus2.Materials[23].tex.Load((char *)"h//18FABRIC.bmp");
	Bus2.Materials[24].tex.Load((char *)"h//18FABRIC.bmp"); 
	Bus2.Materials[25].tex.Load((char *)"h//18FABRIC.bmp");
	//Bus2.Materials[26].tex.Load((char *)"h//18FABRIC.bmp");
	//Bus2.Materials[27].tex.Load((char *)"h//18FABRIC.bmp");
	
	
	
	cars = Model_3DS();
	cars.Load((char *)"h//Car.3ds");
	cars.Materials[0].tex.Load((char *)"h//7(1).bmp");//0color//1insert
	cars.Materials[3].tex.Load((char *)"h//18FABRIC.bmp");//0color//1insert
	
	cars1 = Model_3DS();
	cars1.Load((char *)"h//c.3ds");
	cars1.Materials[0].tex.Load((char *)"h//18FABRIC.bmp");//0color//1insert
	cars1.Materials[2].tex.Load((char *)"h//0.bmp");//0color//1insert
	cars1.Materials[3].tex.Load((char *)"h//18FABRIC.bmp");//0color//1insert
	cars1.Materials[4].tex.Load((char *)"h//18FABRIC.bmp");//0color//1insert
	cars1.Materials[5].tex.Load((char *)"h//5 (2).bmp");//0color//1insert
	cars1.Materials[6].tex.Load((char *)"h//18FABRIC.bmp");//0color//1insert
	cars1.Materials[7].tex.Load((char *)"h//18FABRIC.bmp");//0color//1insert
	//cars1.Materials[8].tex.Load((char *)"h//18FABRIC.bmp");//0color//1insert

	
	

	h = Model_3DS();
	h.Load((char *)"h//plants.3ds");
	h.Materials[19].tex.Load((char *)"h//1 (3).bmp");//3//5/7/8/13/19
	h.Materials[13].tex.Load((char *)"h//7(4).bmp");//3//5/7/8/13/19
	h.Materials[3].tex.Load((char *)"h//7(4).bmp");
	h.Materials[5].tex.Load((char *)"h//7(4).bmp");
	h.Materials[7].tex.Load((char *)"h//7(7).bmp");
	h.Materials[8].tex.Load((char *)"h//7(7).bmp");


	h1 = Model_3DS();
	h1.Load((char *)"h//plants.3ds");
	h1.Materials[19].tex.Load((char *)"h//0.bmp");//3//5/7/8/13/19
	h1.Materials[13].tex.Load((char *)"h//7(4).bmp");//3//5/7/8/13/19
	h1.Materials[3].tex.Load((char *)"h//7(4).bmp");
	h1.Materials[5].tex.Load((char *)"h//7(4).bmp");
	h1.Materials[7].tex.Load((char *)"h//7(7).bmp");
	h1.Materials[8].tex.Load((char *)"h//7(7).bmp");


	Square = Model_3DS();
	Square.Load((char *)"h//1.3ds");//7;5/3/1/10
	Square.Materials[10].tex.Load((char *)"h//7(3).bmp");
	Square.Materials[7].tex.Load((char *)"h//7(5).bmp");
	Square.Materials[5].tex.Load((char *)"h//7(3).bmp");
	Square.Materials[3].tex.Load((char *)"h//7(7).bmp");
	Square.Materials[1].tex.Load((char *)"h//7(3).bmp");
	road = LoadTexture((char *)"h//r2.bmp", 255);
	
	
}
void Street::Carnumber(int a,int a1)
{
	if(a==1)
	{
		bus(bus1, 0);
	}
	if (a == 2)
	{
		bus(bus1, 0);
		bus2(Bus2, 0);
	}

	if (a == 3)
	{
		bus(bus1, 0);
		bus2(Bus2, 0);
		car1(cars1, 0);
	}
	if (a == 4)
	{
		bus(bus1, 0);
		bus2(Bus2, 0);
		car1(cars1, 0);
		car(cars, 0);
	}
	if (a1 == 1)
	{
		carcontrol(cars1, 0);
	}
}
void Street::mainstreet(int c,int g,int t,int l)
{
	glPushMatrix();
	int aq; bool q = false;
	street1(3, road);
	square(Square);
	grass(h, h1, g);//12
	Carnumber(c-1, 1);//4
	traffic(traff, t,traff1);//5
	if(l==1)
	{
		lightbackleft(lightt, 5, 80, 10, -390);
		lightfrontleft(lightt, 5, -120, 70, 510);
	}
	if (l == 2) {
		lightbackRight(lightt, 5, -100, 10, -390);
		lightfrontright(lightt, 5, 20, 60, 520);
	}
	if (l == 3) {
		lightbackleft(lightt, 5, 80, 10, -390);
		lightfrontleft(lightt, 5, -120, 70, 510);
		lightbackRight(lightt, 5, -100, 10, -390);
		lightfrontright(lightt, 5, 20, 60, 520);
		lightbasic(lightt);
	}
	
	if (q == true)
	{
		q = true;
		cout << "hhhhhhhh";
		cin >> aq;
	}
	glPopMatrix();
}
/*void d()
{
#include <iostream>
#include <json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>

	std::ifstream people_file("people.json", std::ifstream::binary);


	cout << people; //This will print the entire json object.

	//The following lines will let you access the indexed objects.
	cout << people["Anna"]; //Prints the value for "Anna"
	cout << people["ben"]; //Prints the value for "Ben"
	cout << people["Anna"]["profession"]; //Prints the value corresponding to "profession" in the json for "Anna"

	cout << people["profession"];
}*/
/*void Street::street1()
{
	
	
	
		glBegin(GL_QUADS);
		glColor3f(1, 0, 1);
		glVertex3f(build1[0].x, build1[0].y, build1[0].z);
		glVertex3f(build1[1].x, build1[1].y, build1[1].z);
		glVertex3f(build1[2].x, build1[2].y, build1[2].z);
		glVertex3f(build1[3].x, build1[3].y, build1[3].z);
		glEnd();
	
		   glBegin(GL_QUADS);
			glColor3f(1, 0, 1);
			glVertex3f(1500, 0, 1200);
			glVertex3f(-1500, 0, 1200);
			glVertex3f(-1500, 0, 1350);
			glVertex3f(1500, 0, 1350);
			glEnd();
		
	//build2= { { 1500,0,1400 },{-1500, 0, 1400}, {-1500, 0, 1550}, {1500, 0, 1550 } };
		glBegin(GL_QUADS);
		glColor3f(1, 0, 1);
		glVertex3f(build2[0].x, build2[0].y, build2[0].z);
		glVertex3f(build2[1].x, build2[1].y, build2[1].z);
		glVertex3f(build2[2].x, build2[2].y, build2[2].z);
		glVertex3f(build2[3].x, build2[3].y, build2[3].z);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(1, 0, 1);
		glVertex3f(1500, 0, 1400);
		glVertex3f(-1500, 0, 1400);
		glVertex3f(-1500, 0, 1550);
		glVertex3f(1500, 0, 1550);
		glEnd();
	
		

	glBegin(GL_QUADS);
	glColor3f(1, 0, 1);
	glVertex3f(0, 0, 1500);
	glVertex3f(-50, 0, 1500);
	glVertex3f(-50, 0, 1800);
	glVertex3f(0, 0, 1800);
	glEnd();
		glBegin(GL_QUADS);
		glColor3f(1, 0, 1);
		glVertex3f(build3[0].x, build3[0].y, build3[0].z);
		glVertex3f(build3[1].x, build3[1].y, build3[1].z);
		glVertex3f(build3[2].x, build3[2].y, build3[2].z);
		glVertex3f(build3[3].x, build3[3].y, build3[3].z);
		glEnd();

		
	glBegin(GL_QUADS);
	glColor3f(1, 0,1);
	glVertex3f(70, 0, 1500);
	glVertex3f(20, 0, 1500);
	glVertex3f(20, 0, 1800);
	glVertex3f(70, 0, 1800);
	glEnd();

		glBegin(GL_QUADS);
		glColor3f(1, 0, 1);
		glVertex3f(build4[0].x, build4[0].y, build4[0].z);
		glVertex3f(build4[1].x, build4[1].y, build4[1].z);
		glVertex3f(build4[2].x, build4[2].y, build4[2].z);
		glVertex3f(build4[3].x, build4[3].y, build4[3].z);
		glEnd();

}*/