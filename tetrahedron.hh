#ifndef TETRAHEDRON_HH_ 
#define	TETRAHEDRON_HH_
#include "3Dshape.hh"
#include <iostream>
using namespace std;

class Tetrahedron : public 3Dshape {
private:
	double x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4;
public:
	Tetrahedron(double x1, double y1, double z1, double x2, double y2, double z2,
					double x3, double y3, double z3, double x4, double y4, double z4)
				: x1(x1), x2(x2), x3(x3), x4(x4), y1(y1), y2(y2), y3(y3), y4(y4), z1(z1), z2(z2), z3(z3) {}
	Tetrahedron(const Tetrahedron& orig);
	~Tetrahedron();
	Tetrahedron& operator =(const Tetrahedron& orig);
	Tetrahedron& operator =(const Tetrahedron&& orig);
	double area() const;
	double volume() const;
	void drawTetrahedron(int color) const;
	void rotate(double ang) const;
	void scale(int n);
	void translate(double x, double y, double z);
};

#endif
