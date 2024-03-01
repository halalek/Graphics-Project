#include "Building.h"
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




int build1; int  build2;
int build3; int  build4;
int build5; int  build6;
int  down,UP;
Model_3DS buildoffice;
Model_3DS buildoffice1;
Model_3DS buildoffice2;
Model_3DS g;
void Building::BUild(Model_3DS b)
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1,1, 1);
	glScalef(3, 3, 3);
	glRotatef(90, 0, 1, 0);
	b.pos.x = -300;
	b.pos.y = 5;
	b.pos.z = 300;
	b.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void Building:: BUild2(Model_3DS b)
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(0.4, 0.4, 0.4);
	//glRotatef(90, 0, 1, 0);
	b.pos.x =2700;
	b.pos.y = 5;
	b.pos.z = 500;
	b.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


}

void Building::BUild3(Model_3DS b)
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(0.1, 0.1, 0.1);
	//glRotatef(90, 0, 1, 0);
	b.pos.x = -12000;
	b.pos.y = 10;
	b.pos.z = 8000;
	b.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Building::BUildright(int x,int y,int z,int tex)
{
	//BUildBasic(tex);//0 0 0
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTranslatef(x, y, z);//800 0 0
	BUildBasic(tex);//BUildright(800,0,build2)
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	/*glPushMatrix();
	glTranslatef(0, 0, -200);// 0 0-200
	BUildBasic(build2);//BUildright(0,0,-200,build2)
	glPopMatrix();

	glPushMatrix();
	glTranslatef(800, 0, -200);// 800 0-200
	BUildBasic(build3);
	glPopMatrix();//BUildright(800,0,-200,build3)

	glPushMatrix();
	glTranslatef(800, 0, -400);// 800 0 -400
	BUildBasic(build4);//BUildright(800,0,-400,build4)
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -400);// 0 0 -400
	BUildBasic(build4);//BUildright(0,0,-400,build4)
	glPopMatrix();

	glPushMatrix();
	glTranslatef(400, 0, -300);// 400 0 -300
	BUildBasic(build3);//BUildright(400,0,-300,build3)
	glPopMatrix();*/
}
void Building::BUildleft(int x, int y, int z, int tex)
{
	//BUildBasic(tex);//0 0 0
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTranslatef(x, y, z);//800 0 0
	BUildBasic(tex);//BUildright(800,0,build2)
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Building::BUildleftDraw(int b,int tex, int tex1)
{
	if (b==2)
	{
		BUild3(buildoffice2);
		glPushMatrix();
		glTranslatef(-1800, 0, 0);
		BUild2(buildoffice1);
		glPopMatrix();
	}
	if(b==4){
		BUild3(buildoffice2);
		glPushMatrix();
		glTranslatef(-1800, 0, 0);
		BUild2(buildoffice1);
		glPopMatrix();
		BUildleft(-1000, 0, -80,tex);// build5
		BUildleft(-1000, 0, -300,tex1);//build6
	}
	if (b==6) {
		BUild3(buildoffice2);
		glPushMatrix();
		glTranslatef(-1800, 0, 0);
		BUild2(buildoffice1);
		glPopMatrix();
		BUildleft(-1000, 0, -80, tex);//5
		BUildleft(-1000, 0, -300, tex1);//6
		BUildleft(-1300, 0, -400, tex);//5
		BUildleft(-1600, 0, -400, tex1);//6
	}
}
void Building::BUildRhitDraw(int b ,int tex, int tex1,int tex2)
{
	if(b==2)
	{
		BUild(buildoffice);
		BUild2(buildoffice1);
	}
	if (b==4)
	{
		BUild(buildoffice);
		BUild2(buildoffice1);
		BUildright(0, 0, 0, tex);
		BUildright(800, 0, 0, tex);//2
	}
	if (b==6)
	{
		BUild(buildoffice);
		BUild2(buildoffice1);
		BUildright(0, 0, 0, tex);
		BUildright(800, 0, 0, tex);//2
		BUildright(0, 0, -200, tex);//2
		BUildright(800, 0, -200,tex1);//3
	}
	if (b==9)
	{
		BUild(buildoffice);
		BUild2(buildoffice1);
		BUildright(0, 0, 0, tex);
		BUildright(800, 0, 0, tex);//2
		BUildright(0, 0, -200, tex);//2
		BUildright(800, 0, -200, tex1);//3
		BUildright(800, 0, -400, tex2);//4
		BUildright(0, 0, -400, tex2);//4
		BUildright(400, 0, -300, tex1);//3
	}
}
void Building::BUildBasic(int b)
{
	//glClearColor(1.0f, 1.0f, 1.0f, 0.3f);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);  
	glBindTexture(GL_TEXTURE_2D, b);
	glBegin(GL_QUADS);

	glTexCoord2d(0, 0);glVertex3d(560, 5, 950);
	glTexCoord2d(1, 0);glVertex3d(420, 5, 950);
	glTexCoord2d(1, 1);glVertex3d(420, 400, 950);
	glTexCoord2d(0, 1);glVertex3d(560, 400, 950);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

	//Back
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, b);
	glBegin(GL_QUADS);
	
	glTexCoord2d(0, 0);glVertex3d(560, 5, 850);
	glTexCoord2d(1, 0);glVertex3d(420, 5, 850);
	glTexCoord2d(1, 1);glVertex3d(420, 400, 850);
	glTexCoord2d(0, 1);glVertex3d(560, 400, 850);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

	//Right
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, b);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(560, 5, 850);
	glTexCoord2d(1, 0);glVertex3d(560, 5, 950);
	glTexCoord2d(1, 1);glVertex3d(560, 400, 950);
	glTexCoord2d(0, 1);glVertex3d(560, 400, 850);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

	//Left
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, b);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);glVertex3d(420, 5, 850);
    glTexCoord2d(1, 0);glVertex3d(420, 5, 950);
	glTexCoord2d(1, 1);glVertex3d(420, 400, 950);
	glTexCoord2d(0, 1);glVertex3d(420, 400, 850);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();


	glPushMatrix();//fffffffffffffffffffffffffffffff
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, UP);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(420, 400, 850);
	glTexCoord2d(1, 0); glVertex3d(420, 400, 950);
	glTexCoord2d(1, 1); glVertex3d(560, 400, 950);
	glTexCoord2d(0, 1); glVertex3d(560, 400, 850);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();

	glPushMatrix();//bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
	glEnable(GL_TEXTURE_2D);
	
	glBindTexture(GL_TEXTURE_2D, down);
	
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(420, 5, 850);
	glTexCoord2d(1, 0); glVertex3d(420, 5, 950);
	glTexCoord2d(1, 1); glVertex3d(560, 5, 950);
	glTexCoord2d(0, 1); glVertex3d(560, 5, 850);
	glEnd();
	
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


void Building::girl(Model_3DS v)
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(12,12,12);
	//glRotatef(90, 0, 1, 0);
	v.pos.x = -50;
	v.pos.y = 2;
	v.pos.z = 100;
	v.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}
float x=80, z=100;
bool s = false;
void Building::girlmove(Model_3DS v)
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(12, 12, 12);
	v.pos.x = x;
	v.pos.y = 2;
	v.pos.z = z;
	v.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	if (s == false)
	{

		z+=0.3;
	}

	if (z>=160)
	{

		 x = 80, z = 100;
		 s = false;
	}
	//if (stop == true && point2 < 1900)
	//{
	//	point2 += xx;
	//	//xx = -xx;
	//}

}
float x2=90, y2 =-100 ;
void Building::girlmove1(Model_3DS v)
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glScalef(12, 12, 12);
	glRotatef(270,0,1,0);
	v.pos.x = x2;
	v.pos.y = 2;
	v.pos.z = y2;
	v.Draw();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	if (s == false)
	{

		y2 += 0.3;
	}

	if (y2 >= 130)
	{

		x2 = 90; y2 = -100;
		s = false;
	}
	//if (stop == true && point2 < 1900)
	//{
	//	point2 += xx;
	//	//xx = -xx;
	//}

}
void Building::girlnumber(Model_3DS v)
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1, 1, 1);
	glTranslatef(50,0,0);
	girl(g);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}
void Building::modelbuild()
{
	
	build1 = LoadTexture((char *)"h//building2.bmp", 255);
	build2 = LoadTexture((char *)"h//building1.bmp", 255);
	

	
	build3 = LoadTexture((char *)"h//building10.bmp", 255);
		
	
	
	build4 = LoadTexture((char *)"h//building5.bmp", 255);
		
	build5 = LoadTexture((char *)"h//buildingg.bmp", 255);
	build6 = LoadTexture((char *)"h//building9.bmp", 255);

	
	down = LoadTexture((char *)"h//T (5).bmp", 255);
	
	UP = LoadTexture((char *)"h//T (4).bmp", 255);
	

	g = Model_3DS();
	g.Load((char *)"h//human_man_1.2.3ds");
	g.Materials[0].tex.Load((char *)"h//T (6).bmp");//3//5/7/8/13/19
	g.Materials[1].tex.Load((char *)"s//nono.bmp");//3//5/7/8/13/19
	g.Materials[2].tex.Load((char *)"h//18FABRIC.bmp");
	g.Materials[3].tex.Load((char *)"h//T (4).bmp");
	g.Materials[4].tex.Load((char *)"h//0.bmp");
	g.Materials[5].tex.Load((char *)"h//T (2).bmp");
	g.Materials[6].tex.Load((char *)"h//18FABRIC.bmp");


	buildoffice = Model_3DS();
	buildoffice.Load((char *)"h//Building N250814.3DS");
	buildoffice.Materials[0].tex.Load((char *)"h//T (1).bmp");//3//5/7/8/13/19
    buildoffice.Materials[1].tex.Load((char *)"h//T (4).bmp");//3//5/7/8/13/19
	buildoffice.Materials[2].tex.Load((char *)"h//T (4).bmp");
	buildoffice.Materials[3].tex.Load((char *)"h//5 (2).bmp");
	buildoffice.Materials[4].tex.Load((char *)"h//T (1).bmp");
	buildoffice.Materials[5].tex.Load((char *)"h//7(3).bmp");
	buildoffice.Materials[6].tex.Load((char *)"h//7(3).bmp");
	buildoffice.Materials[7].tex.Load((char *)"h//T (5).bmp");
	buildoffice.Materials[8].tex.Load((char *)"h//18FABRIC.bmp");
	buildoffice.Materials[9].tex.Load((char *)"h//T (4).bmp");
	buildoffice.Materials[10].tex.Load((char *)"h//T (4).bmp");
	buildoffice.Materials[11].tex.Load((char *)"h//7(1).bmp");
	buildoffice.Materials[12].tex.Load((char *)"h//7(1).bmp");
	buildoffice.Materials[13].tex.Load((char *)"h//7(7).bmp");
	buildoffice.Materials[14].tex.Load((char *)"h//7(7).bmp");
	buildoffice.Materials[15].tex.Load((char *)"h//7(3).bmp");



	
		buildoffice1 = Model_3DS();
		buildoffice1.Load((char *)"h//Building N140812.3DS");
		buildoffice1.Materials[0].tex.Load((char *)"h//T (4).bmp");
		buildoffice1.Materials[1].tex.Load((char *)"h//5 (2).bmp");
		buildoffice1.Materials[2].tex.Load((char *)"h//5 (2).bmp");
		buildoffice1.Materials[3].tex.Load((char *)"h//BUILD.bmp");
		buildoffice1.Materials[4].tex.Load((char *)"h//5 (2).bmp");
		buildoffice1.Materials[5].tex.Load((char *)"h//T (4).bmp");
		buildoffice1.Materials[6].tex.Load((char *)"h//7(1).bmp");
		buildoffice1.Materials[7].tex.Load((char *)"h//18FABRIC.bmp");
		buildoffice1.Materials[8].tex.Load((char *)"h//5 (2).bmp");
		buildoffice1.Materials[9].tex.Load((char *)"h//18FABRIC.bmp");
		buildoffice1.Materials[10].tex.Load((char *)"h//BUILD.bmp");
		buildoffice1.Materials[11].tex.Load((char *)"h//BUILD.bmp");
		buildoffice1.Materials[12].tex.Load((char *)"h//5 (2).bmp");
		buildoffice1.Materials[13].tex.Load((char *)"h//BUILD.bmp");
		buildoffice1.Materials[14].tex.Load((char *)"h//T (4).bmp");
		buildoffice1.Materials[15].tex.Load((char *)"h//18FABRIC.bmp");
		buildoffice1.Materials[16].tex.Load((char *)"h//18FABRIC.bmp");
		buildoffice1.Materials[17].tex.Load((char *)"h//18FABRIC.bmp");


		buildoffice2 = Model_3DS();
		buildoffice2.Load((char *)"h//building.3DS");
		buildoffice2.Materials[0].tex.Load((char *)"h//7(3).bmp");
		buildoffice2.Materials[1].tex.Load((char *)"h//18FABRIC.bmp");
		buildoffice2.Materials[2].tex.Load((char *)"h//T (2).bmp");
		buildoffice2.Materials[3].tex.Load((char *)"h//T (4).bmp");
		buildoffice2.Materials[4].tex.Load((char *)"h//T (1).bmp");
		buildoffice2.Materials[5].tex.Load((char *)"h//T (4).bmp");
		buildoffice2.Materials[6].tex.Load((char *)"h//18FABRIC.bmp");
		buildoffice2.Materials[7].tex.Load((char *)"h//T (2).bmp");
		buildoffice2.Materials[8].tex.Load((char *)"h//5 (2).bmp");
		buildoffice2.Materials[9].tex.Load((char *)"h//T (4).bmp");
		buildoffice2.Materials[10].tex.Load((char *)"h//5 (2).bmp");
		buildoffice2.Materials[11].tex.Load((char *)"h//5 (2).bmp");
		buildoffice2.Materials[12].tex.Load((char *)"h//T (4).bmp");

}
void Building::mainbuild(int text,int r,int l,int Enter)
{
	
	girl(g);
	girlnumber(g);
	girlmove(g);
	girlmove1(g);
	if(text==1)
	{
		BUildRhitDraw(r, build2, build2, build2);
		BUildleftDraw(l, build2, build2);
	}
	if (text==2)
	{
		BUildRhitDraw(r, build1, build1, build1);
		BUildleftDraw(l, build1, build1);
	}
	if (text==3)
	{
		BUildRhitDraw(r, build4, build4, build4);
		BUildleftDraw(l, build4, build4);
	}
	if (text==4)
	{
		BUildRhitDraw(r, build3, build3, build3);
		BUildleftDraw(l, build3, build3);
	}
	if (text==5)
	{
		BUildRhitDraw(r, build5, build5, build5);
		BUildleftDraw(l, build5, build5);
	}
	
	if (text==0&&Enter==0)
	{
		BUildRhitDraw(9, build2, build3, build4);//9
		BUildleftDraw(6, build5, build6);
	}
	//BUildright(0,0,0,0);
	//BUildright(800, 0,0, build2);
	//BUildright(0, 0, -200, build2);
	//BUildright(800, 0, -200, build3);
	//BUildright(800, 0, -400, build4);
	//BUildright(0, 0, -400, build4);
	//BUild(buildoffice);
	//	BUild2(buildoffice1);
	//	BUildright(0, 0, 0, 0);
	//	BUildright(800, 0, 0, build2);
	//	BUildright(0, 0, -200, build2);
	//	BUildright(800, 0, -200, build3);
	//BUild();
	//BUild2();

}