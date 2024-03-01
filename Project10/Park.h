#pragma once
#include"Model_3DS.h"
#include<string.h>
class Park
{
private :
	Model_3DS tree1;
	Model_3DS tree2;
	Model_3DS chair;
	Model_3DS toy1;
	Model_3DS toy2;
	Model_3DS toy3;
	Model_3DS kish;
	Model_3DS gb;
	Model_3DS man;
	
	int texTree1;

public : 
	void initPark();
	void drawTree1();
	void drawTree2(int n);
	void drawToy(int a);
	void drawChair(int n);
	void drawTree(int n);
	void drawPeople(int n);
	void drawRubbish();
	void drawKish(int a);
	//void drawMTree(int n);
//public: void skybox22(int q, int q1, int q2, int q3, int q4, int q5);
};

