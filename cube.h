#ifndef CUBE_H_
#define CUBE_H_
#include <iostream>
class cube{
private:
	double x0,y0,z0,w,l,h;
	double* x, * y, * z;
public:
	cube(double x0, double y0, double z0, double w, double l, double h);
	cube(const cube& orig);
	cube& operator =(const cube& orig);
	~cube();
	cube(cube&& orig);
	void draw() const;
	double volume() const;
	double area() const;
	void rotate(double angle, char axle, cube& orig);
//	void translate(double x, double y, double z);
	void zoom(double times, cube& org);
};
#endif
