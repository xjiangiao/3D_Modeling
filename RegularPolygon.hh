#ifndef REGPOLYGON_HH_
#define REGPOLYGON_HH_
#include "2Dshape.hh"
#include <iostream>

class RegPolygon: public 2Dshape {
private:
   double x,y,a,b,n;            // (x,y) is the left upper point, n is the number of sides, b is the apothem and a is the side length.
public:
   RegPolygon(double x, double y, double a, double b, int n): x(x),y(y),a(a),b(b), n(n) {}
   double area() const;
   double perimeter() const;
   void drawPolygon(int color) const ; // draw an ellipse in the 2D coordinate.
   void moveleft(int n) ;     // move the model n units to the left.
   void moveright(int n) ;     // move the model n units to the right.
}

#endif

