#pragma once
#include"Model_3DS.h"
class Building
{
//public: void skybox22(int q, int q1, int q2, int q3, int q4, int q5);
public:
	void BUildright(int x, int y, int z,int tex);
	void BUild(Model_3DS b);
	void BUild2(Model_3DS b);
	void BUild3(Model_3DS b);
	void BUildBasic(int a);
	void mainbuild(int a,int a1,int a2, int Enter);
	void modelbuild();
	void BUildRhitDraw(int b, int tex,int tex1, int tex2);
	void BUildleftDraw(int b, int tex, int tex1);
	void BUildleft(int x, int y, int z, int tex);
	void girl(Model_3DS b);
	void girlnumber(Model_3DS v);
	void girlmove(Model_3DS v);
	void girlmove1(Model_3DS v);
};

