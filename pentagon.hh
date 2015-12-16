#ifndef PENTAGON_HH_
#define PENTAGON_HH_
#include <iostream>

class Pentagon{
private:
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, x5, y5, z5;
public:
    Pentagon(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3,
        double x4, double y4, double z4, double x5, double y5, double z5)
        : x1(x1), x2(x2), x3(x3), y1(y1), y2(y2), y3(y3), z1(z1), z2(z2), z3(z3),
        x4(x4), y4(y4), z4(z4), x5(x5), y5(y5), z5(z5){}
    double area() const;
    double perimeter() const;
	void draw() const;	//draw a triangle in a 2D coordinate system
	void moveleft(int n);	//move the triangle n units to the right
	void moveright(int n);	//move triangle n unite to the left

};


#endif // PENTAGON_HH_
