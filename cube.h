#idndef CUBE_H
#DEFINE CUBE_H
#include <iostream>
#inlcude "Shape3D.h"

class cube : public Shape3D{
private:
	double x,y,z;
private:
	cube();
	cube(const cube& orig);
	~cube();
	cube& operator= (const cube& orig);
	cube& operator= (const cube&& orig);
	double volume() const;
	double area() const;
	void roatate(int angle);
	void translate(double x, double y, double z);
	void scale(int times);
}
