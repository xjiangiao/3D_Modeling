#ifndef CIRCLE_HH_
#define CIRCLE_HH_
//#include "2Dshape.hh"
#include <iostream>

class Circle {
private:
   double x0,y0,z0, r;

public:
	Circle(double x0, double y0, double z0, double r) : x0(x0), y0(y0), z0(z0), r(r) {};
   double area() const;
   double perimeter() const;
   void draw() const ; // draw a circle in the 2D coordinate.
   void moveleft(int n) ;     // move the model n units to the left.
   void moveright(int n) ;     // move the model n units to the right.
};

#endif
