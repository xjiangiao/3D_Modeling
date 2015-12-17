#ifndef CIRCLE_HH_
#define CIRCLE_HH_
#include "Shape2D.h"
#include <iostream>

class Circle : public shape2D{
private:
	double x0, y0, z0, r, size;
	double* x,* y,* z;
public:
	Circle(double x0, double y0, double z0, double r);
	Circle(const Circle& orig);
	Circle& operator =(const Circle& orig);
	~Circle();
	Circle(Circle&& orig);
   double area() const;
   double perimeter() const;
   void draw() const ; // draw a circle in the 2D coordinate.
   void zoom(double times, Circle& orig);
   void move(double n, char direction, Circle& orig);     // move the model n units to the right.
};

#endif
