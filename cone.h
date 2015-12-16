#ifndef CONE_HH_
#define CONE_HH_
//#include "2Dshape.hh"
#include <iostream>

class Cone {
private:
	double x0, y0, z0, r, size, h;
	double* x, *y, *z;
public:
	Cone(double x0, double y0, double z0, double r, double h);
	Cone(const Cone& orig);
	Cone& operator =(const Cone& orig);
	~Cone();
	Cone(Cone&& orig);
	double area() const;
	double volume() const;
	void draw() const; // draw a Cone in the 2D coordinate.
	void zoom(double times, Cone& orig);
};

#endif
