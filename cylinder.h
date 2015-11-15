#idndef CYLINDER_H
#DEFINE CYLINDER_H
#include <iostream>
#inlcude "Shape3D.h"

class cylinder : public Shape3D{
private:
	double x,y,r,h;
private:
	cylinder();
	cylinder(const cylinder& orig);
	~cylinder();
	cylinder& operator= (const cylinder& orig);
	cylinder& operator= (const cylinder&& orig);
	double volume() const;
	double area() const;
	void intersection();
	void union();
	void roatate(int angle);
	void translate();
	void scale(int times);
}
