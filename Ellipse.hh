#ifndef ELLIPSE_HH_
#define ELLIPSE_HH_
#include "2Dshape.hh"
#include <iostream>

class ELLIPSE: public 2Dshape {
private:
   double x,y,a,b;            // (x,y) is the upper point, a is the major radius and b is the minor radius.
public:
   Ellipse(double x, double y, double a, double b): x(x),y(y),a(a),b(b) {}
   double area() const;
   double perimeter() const;
   void drawEllipse(int color) const ; // draw an ellipse in the 2D coordinate.
   void moveleft(int n) ;     // move the model n units to the left.
   void moveright(int n) ;     // move the model n units to the right.
}

#endif
