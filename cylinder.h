#ifndef CYLINDER_H
#define CYLINDER_H
#include "Shape3D.h"
#include <iostream>
class cylinder:public shape3D{
private:
	double x0,y0,z0,r,h;
	int size;
	double *x, *y, *z, *o, *p, *q;
public:
	cylinder(double x0,double y0,double z0,double r, double h);
	cylinder(const cylinder& orig);
	~cylinder();
	cylinder& operator= (const cylinder& orig);
	cylinder(cylinder &&orig);
	void draw() const;
	double volume() const;
	double area() const;
//	void intersection();
//	void union();
//	void roatate(int angle);
	void translate();
	void scale(int times);
};
#endif
