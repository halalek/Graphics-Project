#pragma once

#include"Model_3DS.h"
class node
{
public:int x; int y; int z;
};

class Street
{
public:
	void street(int road, node s[], int vertical);
		void street1(int number, int texture);
		void square(Model_3DS square);
		void grass(Model_3DS h, Model_3DS h1,int r);
		void grassnumber(Model_3DS h, int n);
		void car(Model_3DS h, int n);
		void bus(Model_3DS h, int n);
		void model();
		void mainstreet(int c, int g, int t, int l);
		void bus2(Model_3DS h, int n);
		void car1(Model_3DS h, int n);
		void carcontrol(Model_3DS h, int n);
		void move_up();
		void move_down();
		void move_right();
		void move_left();
		void Carnumber(int a, int a1);
		void Keyboard(bool	keys[]);
		void light(Model_3DS h, int n);
		void traffic(Model_3DS h, int n, Model_3DS ch);
		void lightfrontright(Model_3DS h, int n, int x, int y, int z);
		void lightfrontleft(Model_3DS h, int n, int x, int y, int z);
		void lightbasic(Model_3DS h);
		void lightbackleft(Model_3DS h, int n, int x, int y, int z); 
		void lightbackRight(Model_3DS h, int n, int x, int y, int z);
};

