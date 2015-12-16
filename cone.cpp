#include<iostream>
#include<fstream>
#include<istream>
#include<cmath>
#define PI 3.141592653
#include"cone.h"
using namespace std;
//Constructor
Cone::Cone(double x0, double y0, double z0, double r,double h) : x0(x0), y0(y0), z0(z0), r(r), h(h){
	double degree = 360 / (200 * r);
	double rad = degree / 180 * PI;
	size = 200 * r + 2;
	x = new double[(int)size];
	y = new double[(int)size];
	z = new double[(int)size];
	x[0] = x0;
	y[0] = y0;
	x[1] = x0;
	y[1] = x0 + r;
	z[0] = z[1] = z0;
	for (int i = 2; i < size; i++) {
		if (i == size - 1) {
			x[i] = x0;
			y[i] = y0;
			z[i] = h;
		}
		else {
			x[i] = r*sin((i - 1)*rad) + x0;
			y[i] = r*cos((i - 1)*rad) + y0;
			z[i] = z0;
		}
	}
}
Cone::Cone(const Cone& orig) {
	size = orig.size;
	x = new double[(int)size];
	y = new double[(int)size];
	z = new double[(int)size];
	for (int i = 0; i < size; i++) {
		x[i] = orig.x[i];
		y[i] = orig.y[i];
		z[i] = orig.z[i];
	}
}
//Destructor
Cone::~Cone() {
	delete[] x;
	delete[] y;
	delete[] z;
}
Cone& Cone::operator=(const Cone& orig) {
	delete[] x;
	delete[] y;
	delete[] z;
	size=orig.size;
	x = new double[(int)size];
	y = new double[(int)size];
	z = new double[(int)size];
	for (int i = 0; i < size; i++) {
		x[i] = orig.x[i];
		y[i] = orig.y[i];
		z[i] = orig.z[i];
	}
	return *this;
}
Cone::Cone(Cone &&orig) : x0(orig.x0), y0(orig.y0), z0(orig.z0), r(orig.r),size(orig.size) {
	orig.x = nullptr;
	orig.y = nullptr;
	orig.z = nullptr;
}
//Draw a Cone
void Cone::draw() const {
	ofstream fout("Cone.stl");
	fout << "solid OpenSCAD_Model" << endl;
	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x[0] << " " << y[0] << " " << z[0] << endl;
	fout << "      vertex " << x[1] << " " << y[1] << " " << z[1] << endl;
	fout << "      vertex " << x[2] << " " << y[2] << " " << z[2] << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	for (int i = 3; i < size; i++) {
		if (i < size-2 ) {
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
	for (int j = 2; j < size - 1; j++) {
		fout << "  facet normal 0 0 0" << endl;
		fout << "    outer loop" << endl;
		fout << "      vertex " << x[j-1] << " " << y[j-1] << " " << z[j-1] << endl;
		fout << "      vertex " << x[j] << " " << y[j] << " " << z[j] << endl;
		fout << "      vertex " << x[int(200 * r )+ 1] << " " << y[int(size - 1)] << " " << z[int(size - 1)] << endl;
		fout << "    endloop" << endl;
		fout << "  endfacet" << endl;
	}
	fout << "endsolid OpenSCAD_Model" << endl;
}
//calculate the Area of this Cone
double Cone::area() const {
	return (h*h + 2 * r*r)*PI; 
}
//calculate the perimeter of this Cone
double Cone::volume() const {
	return (1/3) * PI * r  *r;
}
//Zoom the Cone
void Cone::zoom(double times, Cone& orig) {
	r = orig.r*times;
	double degree = 360 / (200 * r);
	double rad = degree / 180 * PI;
	size = 200 * r + 2;
	x = new double[(int)size];
	y = new double[(int)size];
	z = new double[(int)size];
	x[0] = x0;
	y[0] = y0;
	x[1] = x0;
	y[1] = x0 + r;
	z[0] = z[1] = z0;
	for (int i = 2; i < size; i++) {
		if (i == size - 1) {
			x[i] = x0;
			y[i] = y0;
			z[i] = h;
		}
		else {
			x[i] = r*sin((i - 1)*rad) + x0;
			y[i] = r*cos((i - 1)*rad) + y0;
			z[i] = z0;
		}
	}
	orig.r = r;
	orig.h = h*times;
}
int main() {
	Cone a(0, 0, 0, 50,100);
	a.zoom(2, a);
	a.draw();
	cout << "The volume of this Cone is " << a.volume() << endl;
	cout << "The suface area of this Cone is " << a.area() << endl;
	return 0;
}
