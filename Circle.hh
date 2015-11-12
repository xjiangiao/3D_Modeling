#ifndef CIRCLE_HH_
#define CIRCLE_HH_
#include "2Dshape.hh"
#include <iostream>

class Circle: public 2Dshape {
private:
   double x,y,r;
public:
   Circle(double x, double y, double r): x(x),y(y),r(r) {}
   double area() const;
   double perimeter() const;
   void drawCircle(int color) const ; // draw a circle in the 2D coordinate.
   void moveleft(int n) ;     // move the model n units to the left.
   void moveright(int n) ;     // move the model n units to the right.
}

#endif


