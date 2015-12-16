#ifndef BEZIER_HH_
#define BEZIER_HH_
#include "2Dshape.hh"
#include <iostream>
class bezier: public 2Dshape.hh{
private:
	double x,y,z;
public:
    bezier();
	bezier(const bezier& orig);
	~bezier();
	cube& operator= (const bezier& orig);
	cube& operator= (const bezier&& orig);
}
