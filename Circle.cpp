#include<iostream>
#include<fstream>
#include<istream>
#include<cmath>
#include"Circle.hh"
#define PI 3.141592653
using namespace std;
void Circle::draw() const {
	double degree = 360 / (200 * r);
	double rad = degree / 180 * PI;
	ofstream fout("circle.stl");
	fout << "solid OpenSCAD_Model" << endl;
	double size = 200 * r + 1;
	double* x = new double[(int)size];
	double* y = new double[(int)size];
	double* z = new double[(int)size];
	x[0] = x0;
	y[0] = y0;
	x[1] = x0;
	y[1] = x0 + r;
	x[2] = r*sin(rad) + x0;
	y[2] = r*cos(rad) + y0;
	z[0] = z[1] = z[2] = z0;

	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x[0] << " " << y[0] << " " << z[0] << endl;
	fout << "      vertex " << x[1] << " " << y[1] << " " << z[1] << endl;
	fout << "      vertex " << x[2] << " " << y[2] << " " << z[2] << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;

	for (int i = 3; i <= 200 * r; i++) {
		x[i] = r*sin((i - 1)*rad) + x0;
		y[i] = r*cos((i - 1)*rad) + y0;
		z[i] = z0;
		if (i != 200 * r) {
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
	delete[] x;
	delete[] y;
	delete[] z;
}

double Circle:: area() const {
	return 2 * PI*r;
};
int main() {
	Circle a(10, 10, 10, 100);
	a.draw();
	cout <<"The area of this Circle is "<< a.area();
	return 0;
}
