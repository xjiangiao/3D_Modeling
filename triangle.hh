#ifndef TRIANGLE_HH_
#define TRIANGLE_HH_
#include "Shape2D.h"
#include <iostream>
class Triangle :public shape2D{
private:
    double x1, x2, x3, y1, y2, y3, z1, z2, z3;
public:
    Triangle(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
        : x1(x1), x2(x2), x3(x3), y1(y1), y2(y2), y3(y3), z1(z1), z2(z2), z3(z3){}
    double area() const;
    double perimeter() const;
    	void zoom(double times, Triangle& orig);	
	void draw() const;	//draw a triangle in a 2D coordinate system
	void rotate(double degree, Triangle& orig);
	void move(double n, char direction, Triangle& orig);	//move rectangle n units up, down, left, or right
};

#endif

