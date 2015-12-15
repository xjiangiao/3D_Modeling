#ifndef RECTANGLE_HH_
#define RECTANGLE_HH_
//#include "2Dshape.hh"
#include <iostream>

class Rectangle {
private:
	double x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4;
public:
	Rectangle(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double x4, 
		double y4, double z4) : x1(x1), x2(x2), x3(x3), x4(x4), y1(y1), y2(y2), y3(y3), y4(y4), z1(z1), z2(z2), z3(z3), z4(z4){}
	double area() const;
	double perimeter() const;
	void draw() const;	//draw a circle in a 2D coordinate system
	void rotate(double degree, Triangle& orig);
//	void moveleft(int n);	//move the rectangle n units to the right
//	void moveright(int n);	//move rectangle n unite to the left
};

#endif
