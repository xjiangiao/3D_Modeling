#include<iostream>
#include<fstream>
#include<istream>
#include"cube.h"
#include<cmath>
#define PI 3.141592653
using namespace std;
//Constructor
cube::cube(double x0, double y0, double z0, double w, double l, double h) : x0(x0), y0(y0), z0(z0), w(w), l(l), h(h) {
	x = new double[8];
	y = new double[8];
	z = new double[8];
	for (int i = 0; i < 4; i++) {
		x[i] = x0 + (i % 2)*w;
		z[i] = z0;
		if (i == 2 || i == 3) {
			y[i] = y0 + l;
		}
		else y[i] = y0;
	}
	for (int i = 4; i < 8; i++) {
		x[i] = x0 + (i % 2)*w;
		z[i] = z0 + h;
		if (i == 4 || i == 5) {
			y[i] = y0 + l;
		}
		else y[i] = y0;
	}
}
//Destrcutor
cube::~cube() {
	delete[] x;
	delete[] y;
	delete[] z;
}
cube::cube(const cube& orig) {
	x = new double[8];
	y = new double[8];
	z = new double[8];
	for (int i = 0; i < 8; i++) {
		x[i] = orig.x[i];
		y[i] = orig.y[i];
		z[i] = orig.z[i];
	}
}
cube& cube::operator=(const cube& orig) {
	delete[] x;
	delete[] y;
	delete[] z;
	x = new double[8];
	y = new double[8];
	z = new double[8];
	for (int i = 0; i < 8; i++) {
		x[i] = orig.x[i];
		y[i] = orig.y[i];
		z[i] = orig.z[i];
	}
	return *this;
}
cube::cube(cube &&orig) : x0(x0), y0(y0), z0(z0), w(w), l(l), h(h) {
	x = nullptr;
	y = nullptr;
	z = nullptr;
}
//draw cube
void cube::draw() const {
	ofstream fout("cube.stl");
	fout << "solid OpenSCAD_Model" << endl;
	for (int i = 1; i < 7; i++) {
			fout << "  facet normal 0 0 0" << endl;
			fout << "    outer loop" << endl;
			fout << "      vertex " << x[i] << " " << y[i] << " " << z[i] << endl;
			fout << "      vertex " << x[i - 1] << " " << y[i - 1] << " " << z[i - 1] << endl;
			fout << "      vertex " << x[i + 1] << " " << y[i + 1] << " " << z[i + 1] << endl;
			fout << "    endloop" << endl;
			fout << "  endfacet" << endl;
	}
	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x[1] << " " << y[1] << " " << z[1] << endl;
	fout << "      vertex " << x[3] << " " << y[3] << " " << z[3] << endl;
	fout << "      vertex " << x[5] << " " << y[5] << " " << z[5] << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x[5] << " " << y[5] << " " << z[5] << endl;
	fout << "      vertex " << x[7] << " " << y[7] << " " << z[7] << endl;
	fout << "      vertex " << x[1] << " " << y[1] << " " << z[1] << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x[0] << " " << y[0] << " " << z[0] << endl;
	fout << "      vertex " << x[2] << " " << y[2] << " " << z[2] << endl;
	fout << "      vertex " << x[4] << " " << y[4] << " " << z[4]<< endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x[4] << " " << y[4] << " " << z[4] << endl;
	fout << "      vertex " << x[6] << " " << y[6] << " " << z[6] << endl;
	fout << "      vertex " << x[0] << " " << y[0] << " " << z[0] << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x[6] << " " << y[6] << " " << z[6] << endl;
	fout << "      vertex " << x[7] << " " << y[7] << " " << z[7] << endl;
	fout << "      vertex " << x[0] << " " << y[0] << " " << z[0] << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x[1] << " " << y[1] << " " << z[1] << endl;
	fout << "      vertex " << x[7] << " " << y[7] << " " << z[7] << endl;
	fout << "      vertex " << x[0] << " " << y[0] << " " << z[0] << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	fout << "endsolid OpenSCAD_Model" << endl;
}
//rotate cube by different axle
void cube::rotate(double angle, char axle, cube& orig) {
	double rad = angle / 180 * PI;
	double* xtmp = new double[8];
	double* ytmp = new double[8];
	double* ztmp = new double[8];
	for (int i = 0; i < 8; i++) {
		xtmp[i] = orig.x[i];
		ytmp[i] = orig.y[i];
		ztmp[i] = orig.z[i];
	}
	if (axle == 'x') {
		for (int i = 0; i < 8; i++) {
			ytmp[i] = orig.y[i] * cos(rad) - orig.z[i] * sin(rad);
			ztmp[i] = orig.y[i] * sin(rad) + orig.z[i] * cos(rad);
//			orig.x[i] = xtmp[i];
			orig.y[i] = ytmp[i];
			orig.z[i] = ztmp[i];
		}
	}
	else if (axle == 'y') {
		for (int i = 0; i < 8; i++) {
			xtmp[i] = orig.z[i] * cos(rad) - orig.x[i] * sin(rad);
			ztmp[i] = orig.z[i] * sin(rad) + orig.x[i] * cos(rad);
			orig.x[i] = xtmp[i];
	//		orig.y[i] = ytmp[i];
			orig.z[i] = ztmp[i];
		}
	}
	else if (axle == 'z') {
		for (int i = 0; i < 8; i++) {
			xtmp[i] = orig.x[i] * cos(rad) - orig.y[i] * sin(rad);
			ytmp[i] = orig.x[i] * sin(rad) + orig.y[i] * cos(rad);
			orig.x[i] = xtmp[i];
			orig.y[i] = ytmp[i];
		//	orig.z[i] = ztmp[i];
		}
	}
}
double cube::volume() const {
	return w*h*l;
}
double cube::area() const {
	return w*l*2+w*h*2+h*l*2;
}
int main() {
	cube a(0, 0, 0, 10, 10, 10);
//	a.draw();
	a.rotate(45, 'x', a);
	a.draw();
	cout << "The Volume of this cube is " << a.volume() << endl;
	cout << "The suface area of this cube is " << a.area() << endl;
	system("pause");
	return 0;
}
