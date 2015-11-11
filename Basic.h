#ifndef BASIC_H
#define BAISC_H

#include <iostream>
using namespace std;
class Vector3D {
private:
	double x,y,z;
public:
	Vector3D(double x=0.0,double y=0.0 ,double z=0.0):x(x),y(y),z(z){}
	Vector3D operator+(const Vevctor3D &lhs, const Vector3D &rhs) const{
		return Vector3D(lhs.x+rhs.x,lhs.y+rhs.y,lhs.z+rhs.z)
	}
	Vector3D operator-(const Vevctor3D &lhs, const Vector3D &rhs) const{
		return Vector3D(lhs.x-rhs.x,lhs.y-rhs.y,lhs.z-rhs.z)
	}
	Vector3D operator*(double s) const{
		return Vector3D(x*s,y*s,z*s)
	}
};
#endif
