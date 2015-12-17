#include<iostream>
#include<fstream>
#include<istream>
#include<cmath>
#define PI 3.141592653
#include"cylinder.h"
using namespace std;
//Constructor
cylinder::cylinder(double x0, double y0, double z0, double r, double h) :x0(x0), y0(y0), z0(z0), r(r), h(h) {
	double degree = 360 / (200 * r);
	double rad = degree / 180 * PI;
	size = 200 * r + 1;
	x = new double[size];
	y = new double[size];
	z = new double[size];
	o = new double[size];
	p = new double[size];
	q = new double[size];
	x[0] = x0;
	y[0] = y0;
	z[0] = z0;
	o[0] = x0 ;
	p[0] = y0;
	q[0] = z0 + h;
	for (int i = 1; i < size; i++) {
		x[i] = r*sin((i - 1)*rad) + x0;
		y[i] = r*cos((i - 1)*rad) + y0;
		z[i] = z0;
		o[i] = r*sin((i - 1)*rad) + x0;
		p[i] = r*cos((i - 1)*rad) + y0;
		q[i] = z0 + h;
	}
}
cylinder::cylinder(const cylinder& orig) {
	size = orig.size;
	x = new double[size];
	y = new double[size];
	z = new double[size];
	for (int i = 0; i < size; i++) {
		x[i] = orig.x[i];
		y[i] = orig.y[i];
		z[i] = orig.z[i];
		o[i] = orig.o[i];
		p[i] = orig.p[i];
		q[i] = orig.q[i];
	}
}
cylinder::~cylinder() {
	delete[] x;
	delete[] y;
	delete[] z;
	delete[] o;
	delete[] p;
	delete[] q;
}
cylinder& cylinder::operator=(const cylinder& orig) {
	delete[] x;
	delete[] y;
	delete[] z;
	delete[] o;
	delete[] p;
	delete[] q;
	size = orig.size;
	x = new double[(int)size];
	y = new double[(int)size];
	z = new double[(int)size];
	for (int i = 0; i < size; i++) {
		x[i] = orig.x[i];
		y[i] = orig.y[i];
		z[i] = orig.z[i];
		o[i] = orig.o[i];
		p[i] = orig.p[i];
		q[i] = orig.q[i];
	}
	return *this;
}
cylinder::cylinder(cylinder &&orig) : x0(orig.x0), y0(orig.y0), z0(orig.z0), r(orig.r), size(orig.size), h(orig.h) {
	orig.x = nullptr;
	orig.y = nullptr;
	orig.z = nullptr;
	orig.o = nullptr;
	orig.p = nullptr;
	orig.q = nullptr;
}
void cylinder::draw() const {
	ofstream fout("cylinder.stl");
	fout << "solid OpenSCAD_Model" << endl;
	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x[0] << " " << y[0] << " " << z[0] << endl;
	fout << "      vertex " << x[1] << " " << y[1] << " " << z[1] << endl;
	fout << "      vertex " << x[2] << " " << y[2] << " " << z[2] << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	for (int i = 3; i < size; i++) {
		if (i < size - 2) {
			fout << "  facet normal 0 0 0" << endl;
			fout << "    outer loop" << endl;
			fout << "      vertex " << x[i - 1] << " " << y[i - 1] << " " << z[i - 1] << endl;
			fout << "      vertex " << x[0] << " " << y[0] << " " << z[0] << endl;
			fout << "      vertex " << x[i] << " " << y[i] << " " << z[i] << endl;
			fout << "    endloop" << endl;
			fout << "  endfacet" << endl;
		}
		else {
			fout << "  facet normal 0 0 0" << endl;
			fout << "    outer loop" << endl;
			fout << "      vertex " << x[i] << " " << y[i] << " " << z[i] << endl;
			fout << "      vertex " << x[0] << " " << y[0] << " " << z[0] << endl;
			fout << "      vertex " << x[1] << " " << y[1] << " " << z[1] << endl;
			fout << "    endloop" << endl;
			fout << "  endfacet" << endl;
		}
	}

	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << o[0] << " " << o[0] << " " << o[0] << endl;
	fout << "      vertex " << p[1] << " " << p[1] << " " << p[1] << endl;
	fout << "      vertex " << q[2] << " " << q[2] << " " << q[2] << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	for (int i = 3; i < size; i++) {
		if (i < size - 2) {
			fout << "  facet normal 0 0 0" << endl;
			fout << "    outer loop" << endl;
			fout << "      vertex " << o[i - 1] << " " << p[i - 1] << " " << q[i - 1] << endl;
			fout << "      vertex " << o[0] << " " << p[0] << " " << q[0] << endl;
			fout << "      vertex " << o[i] << " " << p[i] << " " << q[i] << endl;
			fout << "    endloop" << endl;
			fout << "  endfacet" << endl;
		}
		else {
			fout << "  facet normal 0 0 0" << endl;
			fout << "    outer loop" << endl;
			fout << "      vertex " << o[i] << " " << p[i] << " " << q[i] << endl;
			fout << "      vertex " << o[0] << " " << p[0] << " " << q[0] << endl;
			fout << "      vertex " << o[1] << " " << p[1] << " " << q[1] << endl;
			fout << "    endloop" << endl;
			fout << "  endfacet" << endl;
		}
	}

	for (int i = 2; i < size; i++) {
		fout << "  facet normal 0 0 0" << endl;
		fout << "    outer loop" << endl;
		fout << "      vertex " << o[i-1] << " " << p[i-1] << " " << q[i-1] << endl;
		fout << "      vertex " << o[i] << " " << p[i] << " " << q[i] << endl;
		fout << "      vertex " << x[i-1] << " " << y[i-1] << " " << z[i-1] << endl;
		fout << "    endloop" << endl;
		fout << "  endfacet" << endl;

		fout << "  facet normal 0 0 0" << endl;
		fout << "    outer loop" << endl;
		fout << "      vertex " << x[i - 1] << " " << y[i - 1] << " " << z[i - 1] << endl;
		fout << "      vertex " << x[i] << " " << y[i] << " " << z[i] << endl;
		fout << "      vertex " << o[i] << " " << p[i] << " " << q[i] << endl;
		fout << "    endloop" << endl;
		fout << "  endfacet" << endl;
	}
	fout << "endsolid OpenSCAD_Model" << endl;
}
double cylinder::area() const {
	return 2 * PI*r*r + 2 * PI*r*h;
}
double cylinder::volume() const {
	return PI*r*r*h;
}/*
int main() {
	cylinder a(0, 0, 10, 10, 50);
//	a.zoom(2, a);
//	a.move(100, 'R', a);
	a.draw();
	cout << "The volume of this cylinder is " << a.volume() << endl;
	cout << "The suface area of this cylinder is " << a.area() << endl;
	return 0;
}*/
