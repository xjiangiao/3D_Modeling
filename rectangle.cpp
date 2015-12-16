#include<iostream>
#include<fstream>
#include<istream>
#include<cmath>
#define PI 3.141592653
#include"rectangle.hh"
using namespace std;

void Rectangle::draw() const {
	ofstream fout("rectangle.stl");
	fout << "solid OpenSCAD_Model" << endl;
	fout << "  facet normal -0 0 1" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x1 << " " << y1 << " " << z1 << endl;
	fout << "      vertex " << x2 << " " << y2 << " " << z2 << endl;
	fout << "      vertex " << x3 << " " << y3 << " " << z3 << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	fout << "  facet normal 0 0 1" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x3 << " " << y3 << " " << z3 << endl;
	fout << "      vertex " << x4 << " " << y4 << " " << z4 << endl;
	fout << "      vertex " << x1 << " " << y1 << " " << z1 << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	fout << "endsolid OpenSCAD_Model" << endl;
}

void Rectangle::rotate(double degree, Rectangle& orig) {
	double x2tmp = orig.x2;
	double y2tmp = orig.y2;
	double x3tmp = orig.x3;
	double y3tmp = orig.y3;
	double x4tmp = orig.x4;
	double y4tmp = orig.y4;
	double rad = degree / 180 * PI;
	x2tmp = (orig.x2 - orig.x1)*cos(rad) + (orig.y2 - orig.y1)*sin(rad) + orig.x1;
	x3tmp = (orig.x3 - orig.x1)*cos(rad) + (orig.y3 - orig.y1)*sin(rad) + orig.x1;
	x4tmp = (orig.x4 - orig.x1)*cos(rad) + (orig.y4 - orig.y1)*sin(rad) + orig.x1;
	y2tmp = (orig.y2 - orig.y1)*cos(rad) - (orig.x2 - orig.x1)*sin(rad) + orig.y1;
	y3tmp = (orig.y3 - orig.y1)*cos(rad) - (orig.x3 - orig.x1)*sin(rad) + orig.y1;
	y4tmp = (orig.y4 - orig.y1)*cos(rad) - (orig.x4 - orig.x1)*sin(rad) + orig.y1;
	orig.x2 = x2tmp;
	orig.x3 = x3tmp;
	orig.x4 = x4tmp;
	orig.y2 = y2tmp;
	orig.y3 = y3tmp;
	orig.y4 = y4tmp;
}
//Calculate the area of this rectangle
double Rectangle::area() const {
	double xtmp = abs(x1 - x2);
	double ytmp = abs(y1 - y2);
	return xtmp*ytmp;
}
//Calculate the perimeter of this rectangle
double Rectangle::perimeter() const {
	double xtmp = abs(x1 - x2);
	double ytmp = abs(y1 - y2);
	return 2*(xtmp+ytmp);
}
//Move the rectangle
void Rectangle::move(double n, char direction, Rectangle& orig) {
		if (direction == 'L') {
			orig.x1 -= n;
			orig.x2 -= n;
			orig.x3 -= n;
			orig.x4 -= n;
		}
		else if (direction == 'R') {
			orig.x1 += n;
			orig.x2 += n;
			orig.x3 += n;
			orig.x4 += n;
		}
		else if (direction == 'up') {
			orig.y1 += n;
			orig.y2 += n;
			orig.y3 += n;
			orig.y4 += n;
		}
		else if (direction == 'down') {
			orig.y1 -= n;
			orig.y2 -= n;
			orig.y3 -= n;
			orig.y4 -= n;
		}
}
//zoom this rectangle
void Rectangle::zoom(double times, Rectangle& orig) {
	orig.x2 = times*orig.x2;
	orig.x3 = times*orig.x3;
	orig.x4 = times*orig.x4;
	orig.y2 = times*orig.y2;
	orig.y3 = times*orig.y3;
	orig.y4 = times*orig.y4;
}
int main() {
	Rectangle a(0, 20, 10, 10, 0, 10, 10, 20, 10, 0, 0, 10);
	Rectangle b(0, 0, 10, 10, 0, 10, 10, 20, 10, 0, 20, 10);
	a.zoom(2, a);
	b.move(10, 'L', a);
	b.rotate(45,b);
	b.draw();
	cout << "The perimeter of this rectangle is " << a.perimeter() << endl;
	cout << "The suface area of this rectangle is " << a.area() << endl;
	system("pause");
	return 0;
}
