
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
#include "Skybox.h"
#include "Street.h"
#include "Park.h"
#include "Building.h"
#include "Basic_Build.h"
#include<iostream>
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glut32.lib")
#pragma comment(lib,"glu32.lib")
#pragma comment(lib,"GLAUX.LIB")
#pragma comment(lib, "Winmm.lib")
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Context
HWND		hWnd = NULL;		// Holds Our Windowmahmoud.s Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = TRUE; 	// Fullscreen Flag Set To Fullscreen Mode By Default
#define PI 3.141592
LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc
//******************************************
// ============= Members Definition =========
int textureID_flower;
//==========================================

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	//gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 10000.0f);
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height,15, 10000.0f);//5.5
	glFrustum(0, 0, 0, 0, 0., 0);
	glOrtho(0, 0, 0, 0, 0, 0);
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

int boll = 0;
int c, c2, cc, right2, lleft, top,J, leftll, oo, m3, a22, hl, ass, ass1;;
int SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, SKYDOWN;

//Model_3DS square;
//Model_3DS h;
//Model_3DS h1;

float Light_Ambient1[] = { 1, 1, 1, 1 };
float Light_Diffuse1[] = { 1, 1, 1, 1 };
float Light_Specular1[] = { 1, 1, 1, 1 };
float Light_Position1[] = { 0, 70, 800, 1 };
float Light_Spot_direction[] = { 0, 0, 800 };
float Light_CutOff = 5;
float Light_Ambient[] = { 1, 1, 1, 1 };
float Light_Diffuse[] = { 1, 1, 1, 1 };
float Light_Specular[] = { 1, 1, 1, 1 };
float Light_Position[] = { 0, 90, 800, 1 };
float Cone_Ambient[] = { 1, 1, 1, 1 };
float Cone_Diffuse[] = { 1, 1, 1, 1 };
float Cone_Specular[] = { 1, 1, 1, 1 };
//GLUquadric *quadric;
Skybox SS = Skybox();
Building build = Building();//—«„«
Basic_Build basicbuild = Basic_Build();//€Ìœ«¡Ê‰Ê—
Street st = Street();//Â·«
Park park = Park();//œ·«·
bool  door_build = false, door11 = false;
bool a1 = true;
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 1.0f, 0.3f);				// Black Background
	glClearDepth(1.0f);			
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);		
	
	//glEnable(GL_TEXTURE_2D);
	c = LoadTexture((char*)"s//front1.bmp", 255);
	c2 = LoadTexture((char*)"s//top.bmp", 255);
	cc = LoadTexture((char*)"s//nono.bmp", 255);
	
	right2 = LoadTexture((char*)"s//right1.bmp", 255);
	lleft = LoadTexture((char*)"s//left1.bmp", 255);
	top = LoadTexture((char*)"s//topp2.bmp", 255);

	SKYFRONT = LoadTexture((char*)"s//front.bmp", 255);
	SKYBACK = LoadTexture((char*)"s//back.bmp", 255);
	SKYLEFT = LoadTexture((char*)"s//left.bmp", 255);
	SKYRIGHT = LoadTexture((char*)"s//right.bmp", 255);
	SKYUP = LoadTexture((char*)"s//up.bmp", 255);
	SKYDOWN = LoadTexture((char*)"s//down.bmp", 255);

	a22= LoadTexture((char*)"image//AA2.bmp", 255);
	m3 = LoadTexture((char*)"image//171.bmp", 255);
	ass1 = LoadTexture((char*)"image//ass1.bmp", 255);
	hl = LoadTexture((char*)"image//hll.bmp", 255);
	ass = LoadTexture((char*)"image//ass.bmp", 255);
	oo = LoadTexture((char*)"image//o.bmp", 255);
	leftll = LoadTexture((char*)"image//AA2.bmp", 255);

	glPushMatrix();
	st.model();
	basicbuild.Initbuild();
	park.initPark();
	build.modelbuild();
	glPopMatrix();
	st.model();
	return true;										// Initialization Went OK
}

float mousee, mouses;
Camera MyCamera;
int above = 0;
bool open = false;
int mouseX = 0, mouseY = 0;
bool isClicked = false, isRClicked = false, mousemoved = false;
void mouse(int mouseX, int mouseY, bool isClicked, bool isRClicked)
{
	if (mousemoved)
	{
		mousee = (mouseX - 320) * 20 / 640;
		MyCamera.MoveRight(mousee);

		mouses = (mouseY - 320) * 20 / 640;
		if (mouses <= 1750)
		{
			MyCamera.MoveForward(mouses);
		}
		mouseX = 0;
		mouseY = 0;
	}
	if (isClicked)
	{
		MyCamera.MoveUpward(5);
	}
	if (isRClicked)
	{
		MyCamera.MoveUpward(-5);
	}

}
int saz = 0, sbz = 0;
float angle = 0;
float i = 1750;
float j = 0;
float y = 50;
float k = 0;
float e = 1;
float a, b;
float mh = 90;
int doo = 1;
float mou, mouu;

bool light=false;
bool night =false;
bool sound = true;
bool sound1 = true;
void key(int a)
{

	if (keys[VK_DOWN]) {
		if (i < 1750)
		{
			MyCamera.MoveForward(-10*a);
			i += 10;
		}

	}

	if (keys[VK_UP])
	{

		MyCamera.MoveForward(10*a);
		i -= 10;

	}
	if (keys['D'])			MyCamera.RotateY(-1*a);
	if (keys['A'])		    MyCamera.RotateY(1*a);
	if (keys['Z'])        MyCamera.MoveUpward(-1*a);
	if (keys['Q'])      MyCamera.MoveUpward(1*a);
	if (keys[VK_LEFT]) {
		MyCamera.MoveRight(-2*a);
		j -= 1;
	}
	if (keys[VK_RIGHT])
	{
		MyCamera.MoveRight(2*a);
		j += 1;
	}
	if (keys['W'])		 MyCamera.RotateX(1*a);

	if (keys['S']) MyCamera.RotateX(-1*a);

	if (keys['N'])
	{
		if (night == false)
		{
			boll = 1;
			Light_Ambient[0] = 0.3;
			Light_Ambient[1] = 0.3;
			Light_Ambient[2] = 0.3;
			night = true;
		}
		else
		{ 
			boll = 0;
			Light_Ambient[0] = 1;
			Light_Ambient[1] = 1;
			Light_Ambient[2] = 1;
			night = false;
		}


	}

	if (keys['L'])
	{
		if (light ==false)
		{
			light = true;
			Light_Ambient[0] = 0.3;
			Light_Ambient[1] = 0.3;
			Light_Ambient[2] = 0.3;
		}
		else
		{
			light = false;
			Light_Ambient[0] = 1;
			Light_Ambient[1] = 1;
			Light_Ambient[2] = 1;
		}


	}
	if (keys['P'])
	{
		PlaySound("s3.wav", NULL, SND_FILENAME | SND_ASYNC |SND_LOOP);
		//sound = false;

	}

	if (keys['O']) {
		PlaySound("s.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}

	if (keys['I']) {
		PlaySound("s1.wav", NULL, SND_FILENAME | SND_ASYNC);
	}

	if (keys['1'])
	{
		above = 1;

	}
	if (keys['0'])
	{
		above = 0;

	}


	if (keys['X'])
		door_build = !door_build;

	if (keys['V'])
		open = !open;

	if (keys['B'])
	{
		door11 = !door11;

	}

	if (keys['2'])
	{
		above = 2;

	}
	if (keys['M'])
	{
		a1=!a1;

	}


	
	st.Keyboard(keys);
}

void skybox2(int q,int q1,int q2,int q3,int q4,int q5)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q);//SKYFRONT
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(1500, 0, 0);
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
	glTexCoord2d(1, 0); glVertex3d(-1500, 0, 1800);
	glTexCoord2d(1, 1); glVertex3d(-1500, 1200, 1800);
	glTexCoord2d(0, 1); glVertex3d(1500, 1200, 1800);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,q2);// SKYLEFT
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
	glBindTexture(GL_TEXTURE_2D,q3);//SKYRIGHT
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
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, q5);//cc
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(1500, 0, 1800);
	glTexCoord2d(40, 0); glVertex3d(-1500, 0, 1800);
	glTexCoord2d(40, 40); glVertex3d(-1500, 0, 0);
	glTexCoord2d(0, 40); glVertex3d(1500, 0, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
int saa = 0, sbb = 0;
int s = 0;
void Elevator()
{
	glPushMatrix();
	glTranslatef(0, s, 0);
	glColor3f(1, 1, 1);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, hl);
	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3d(30, 10, 150);
	glTexCoord2f(10, 0); glVertex3d(-30, 10, 150);
	glTexCoord2f(10, 1); glVertex3d(-30, 10, 50);
	glTexCoord2f(0, 1); glVertex3d(30, 10, 50);
	glDisable(GL_TEXTURE_2D);

	glEnd();
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.5);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(30, 10, 50);
	glTexCoord2d(1, 0);
	glVertex3d(30, 10, 150);
	glTexCoord2d(1, 1);
	glVertex3d(30, 137, 150);
	glTexCoord2d(0, 1);
	glVertex3d(30, 137, 50);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//The Front
	glColor3f(1, 1, 1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.5);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(30, 10, 50);
	glTexCoord2d(1, 0);
	glVertex3d(-30, 10, 50);
	glTexCoord2d(1, 1);
	glVertex3d(-30, 137, 50);
	glTexCoord2d(0, 1);
	glVertex3d(30, 137, 50);
	glEnd();
	glDisable(GL_TEXTURE_2D);


	//Back

	glColor3f(1, 1, 1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 1, 1, 0.8);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m3);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-30, 10, 150);
	glTexCoord2d(1, 0);
	glVertex3d(-30, 10, 50);
	glTexCoord2d(1, 1);
	glVertex3d(-30, 137, 50);
	glTexCoord2d(0, 1);
	glVertex3d(-30, 137, 150);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);


	if (open == true && saz < 30)
	{
		saz += 2;
		sbz += 2;
	}
	else if (open == false && saz > 0)
	{
		saz -= 2;
		sbz -= 2;
	}
	glPushMatrix();
	glTranslated(sbz, 0, 0);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ass);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(30, 137, 150);
	glTexCoord2d(1, 0);
	glVertex3d(0, 137, 150);
	glTexCoord2d(1, 1);
	glVertex3d(0, 10, 150);
	glTexCoord2d(0, 1);
	glVertex3d(30, 10, 150);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
	glPushMatrix();
	glTranslated(-saz, 0, 0);
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ass1);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0, 137, 150);
	glTexCoord2d(1, 0);
	glVertex3d(-30, 137, 150);
	glTexCoord2d(1, 1);
	glVertex3d(-30, 10, 150);
	glTexCoord2d(0, 1);
	glVertex3d(0, 10, 150);
	glEnd();


	glDisable(GL_TEXTURE_2D);


	glPopMatrix();


	if (above == 1 && s < 160)
	{

		s += 2;
		MyCamera.MoveUpward(+2);
	}
	else if (above == 1 && s > 160)
	{
		s -= 2;
		MyCamera.MoveUpward(-2);
	}
	if (above == 2 && s < 290)
	{

		s += 2;
		MyCamera.MoveUpward(+2);
	}
	if (above == 0 && s > 10)
	{
		s -= 2;
		MyCamera.MoveUpward(-2);
	}


	glPopMatrix();
}



int v;

void DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();


	MyCamera.Render();
	gluLookAt(0, 50, 1795, 0, 0, 0, 0, 1, 0);
//	mouse(mouseX, mouseY, isClicked, isRClicked);
	key(12);//speed camera
	glPushMatrix();
	
	glPopMatrix();
	mousemoved = true;
	
	//dd();
	//glColor3f(1, 1, 1);
	//buld();
	
	glEnable(GL_LIGHT_MODEL_LOCAL_VIEWER);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, Light_Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light_Diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Light_Specular);
	glLightfv(GL_LIGHT0, GL_POSITION, Light_Position);
	float Cone_Shininess = 90;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Cone_Ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Cone_Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Cone_Specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, Cone_Shininess);
	glEnable(GL_COLOR_MATERIAL);
	



	if (boll == 0)

	{
		//skybox2(SKYFRONT,SKYBACK,SKYLEFT,SKYRIGHT,SKYUP,cc);
		SS.skybox22(SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, cc);
	
	}
	else
		SS.skybox22(c, c, lleft, right2, top, cc);
		//skybox2(c,c,lleft,right2,top, cc);
	
	bool a4 = false;
	if (a4 == false)
	{
		cout << " Enter 1 to change settings  ";
		cout << "\n";
		cout << " Enter 2 to display the project  ";
		cin >> v;
		if (v==1)
		{
			a1=false;
			a4=true;
		}
		if (v==2)
		{
			a1=true;
			a4=true;
		}
	}
	
	if(a1==false)
	{
		string line; int i = 0;
		int AraayInter[14];
		ifstream myfile("Inputs.txt");
		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{

				cout << line << '\n';
				AraayInter[i] = stoi(line);
				i++;
			}
			myfile.close();

		}

		else { cout << "Unable to open file"; }

		park.drawTree(AraayInter[0]);
		park.drawChair(AraayInter[2]);
		park.drawToy(AraayInter[1]);
		park.drawKish(AraayInter[4]);
		park.drawPeople(AraayInter[3]);
		if (AraayInter[5] != 0)
		{
			Elevator();
		}
		st.mainstreet(AraayInter[8], AraayInter[9], AraayInter[12], AraayInter[13]);
		basicbuild.basic_Build(AraayInter[5], AraayInter[6],door_build, door11);
		build.mainbuild(AraayInter[7], AraayInter[11], AraayInter[10], 1);
	}
	if(a1==true)
	{
		glPushMatrix();
		Elevator();
		glPopMatrix();


		glPushMatrix();
		park.drawTree(8);
		park.drawChair(14);
		park.drawToy(3);
		park.drawKish(3);
		park.drawRubbish();
		park.drawPeople(6);
		glPopMatrix();

		glPushMatrix();
		st.mainstreet(5,12,5,3);
		glPopMatrix();

		glPushMatrix();
		build.mainbuild(0,0,0,0);
		glPopMatrix();

		


		glPushMatrix();
		basicbuild.basic_Build(3, 4, door_build, door11);
		glPopMatrix();

	}

	SwapBuffers(hDC);
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "NeHe GL", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	static PAINTSTRUCT ps;

	switch (uMsg)									// Check For Windows Messages
	{
	case WM_PAINT:
		DrawGLScene();
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		return 0;

	case WM_TIMER:
		DrawGLScene();
		return 0;

	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
		switch (wParam)							// Check System Calls
		{
		case SC_SCREENSAVE:					// Screensaver Trying To Start?
		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
			return 0;							// Prevent From Happening
		}
		break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	case WM_MOUSEMOVE:
	{
		mouseX = (int)LOWORD(lParam);
		mouseY = (int)HIWORD(lParam);
		mousemoved = true;
		isClicked = (LOWORD(wParam) & MK_LBUTTON) ? true : false;
		isRClicked = (LOWORD(wParam) & MK_RBUTTON) ? true : false;
		break;
	}
	case WM_LBUTTONUP:
	{
		isClicked = false;
		break;
	}
	case WM_RBUTTONUP:
	{
		isRClicked = false;
		break;
	}
	case WM_LBUTTONDOWN:
	{
		isClicked = true;
		break;
	}
	case WM_RBUTTONDOWN:
	{
		isRClicked = true;
		break;
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

	// Ask The User Which Screen Mode They Prefer
	//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}
	char a[] = "PROJECT GHRAPHICS";
	// Create Our OpenGL Window
	if (!CreateGLWindow(a, 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}


	//Set drawing timer to 20 frame per second
	UINT timer = SetTimer(hWnd, 0, 50, (TIMERPROC)NULL);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;

}
int main(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow) {
	return WinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

}

/*int main(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int nCmdShow) {
	// Enter the infinitely event-processing loop

	return WinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
}*/
