#ifndef SPHERE_HH_
#define SPHERE_HH_
#include "3Dshape.hh"
#include <iostream>

class Sphere : public 3Dshape {
private:
	double x,y,z,r;
public:
	Sphere(double x, double y, double z, double r): x(x), y(y), z(z), r(r){}
	double area() const;
	double volume() const;
	void drawSphere(int color) const;
	void rotate(double ang) const;
	void scale(int n);
	void move(double x, double y, double z);
};

#endif
