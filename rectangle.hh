#ifndef RECTANGLE_HH_
#define RECTANGLE_HH_
#include "2Dshape.hh"
#include <iostream>

class Rectangle : public 2Dshape {
private:
	double x,y,z;
public:
	Rectangle(double x, double y, dobule z) : x(x), y(y), z(z){}
	double area() const;
	double perimeter() const;
	void drawCircle(int color) const;	//draw a circle in a 2D coordinate system
	void moveleft(int n);	//move the rectangle n units to the right
	void moveright(int n);	//move rectangle n unite to the left
};

#endif
