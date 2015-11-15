#ifndef 2DSHAPE_HH_
#define 2DSHAPE_HH_
#include <iostream>
#include “basic.h”

class 2Dshape {
public:
   virtual double area() const=0;   // calculate the area of 2D model.
   virtual double perimeter() const=0; // calculate the perimeter of 2D model.

#endif

