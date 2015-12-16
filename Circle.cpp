#include<iostream>
#include<fstream>
#include<istream>
#include<cmath>
#define PI 3.141592653
//#include"2Dshape.hh"
#include"Circle.hh"
using namespace std;
//Constructor
Circle::Circle(double x0, double y0, double z0, double r) : x0(x0), y0(y0), z0(z0), r(r){
	double degree = 360 / (200 * r);
	double rad = degree / 180 * PI;
	size = 200 * r + 1;
	x = new double[(int)size];
	y = new double[(int)size];
	z = new double[(int)size];
	x[0] = x0;
	y[0] = y0;
	x[1] = x0;
	y[1] = x0 + r;
	z[0] = z[1] = z0;
	for (int i = 2; i < size; i++) {
		x[i] = r*sin((i - 1)*rad) + x0;
		y[i] = r*cos((i - 1)*rad) + y0;
		z[i] = z0;
	}
}
Circle::Circle(const Circle& orig) {
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
Circle::~Circle() {
	delete[] x;
	delete[] y;
	delete[] z;
}
Circle& Circle::operator=(const Circle& orig) {
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
Circle::Circle(Circle &&orig) : x0(orig.x0), y0(orig.y0), z0(orig.z0), r(orig.r),size(orig.size) {
	orig.x = nullptr;
	orig.y = nullptr;
	orig.z = nullptr;
}
//Draw a circle
void Circle::draw() const {
	ofstream fout("circle.stl");
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
	fout << "endsolid OpenSCAD_Model" << endl;
}
//calculate the Area of this Circle
double Circle::area() const {
	return PI*r*r;
}
//calculate the perimeter of this Circle
double Circle::perimeter() const {
	return 2 * PI*r;
}
//Zoom the Circle
void Circle::zoom(double times, Circle& orig) {
	r = orig.r*times;
	double degree = 360 / (200 * r);
	double rad = degree / 180 * PI;
	size = 200 * r + 1;
	x = new double[(int)size];
	y = new double[(int)size];
	z = new double[(int)size];
	x[0] = x0;
	y[0] = y0;
	x[1] = x0;
	y[1] = x0 + r;
	z[0] = z[1] = z0;
	for (int i = 2; i < size; i++) {
		x[i] = r*sin((i - 1)*rad) + x0;
		y[i] = r*cos((i - 1)*rad) + y0;
		z[i] = z0;
	}
	orig.r = r;
}
void Circle::move(double n, char direction, Circle& orig) {
	if (direction == 'L') {
		orig.x[0] -= n;
	}
	else if (direction == 'R') {
		orig.x[0] += n;
	}
	else if (direction == 'up') {
		orig.y[0] += n;
	}
	else if (direction == 'down') {
		orig.y[0] += n;
	}
}
int main() {
	Circle a(0, 0, 0, 10);
	a.zoom(2, a);
	a.move(10, 'L', a);
	a.draw();
	cout << "The perimeter of this Circle is " << a.perimeter() << endl;
	cout << "The suface area of this Circle is " << a.area() << endl;
	return 0;
}
