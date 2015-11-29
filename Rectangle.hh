#ifndef RECTANGLE_HH_
#define RECTANGLE_HH_
#include "2Dshape.hh"
#include <iostream>

class Rectangle: public 2Dshape {
private:
   double x,y,w,h;            // (x,y) is the left upper point of the rectangle, w is width and h is height.
public:
   Rectangle(double x, double y, double w, double h): x(x),y(y),w(w),h(h) {}
   double area() const;
   double perimeter() const;
   void drawRectangle(int color) const ; // draw a rectangle in the 2D coordinate.
   void moveleft(int n) ;     // move the model n units to the left.
   void moveright(int n) ;     // move the model n units to the right.
}

#endif

