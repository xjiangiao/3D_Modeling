#include<iostream>
#include<fstream>
#include<istream>
#include<cmath>
#define PI 3.141592653
#include"Tetrahedron.h"
using namespace std;

void Tetrahedron::draw() const {
	ofstream fout("Tetrahedron.stl");
	fout << "solid OpenSCAD_Model" << endl;
	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x1 << " " << y1 << " " << z1 << endl;
	fout << "      vertex " << x2 << " " << y2 << " " << z2 << endl;
	fout << "      vertex " << x3 << " " << y3 << " " << z3 << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;

	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x4 << " " << y4 << " " << z4 << endl;
	fout << "      vertex " << x2 << " " << y2 << " " << z2 << endl;
	fout << "      vertex " << x3 << " " << y3 << " " << z3 << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;

	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x1 << " " << y1 << " " << z1 << endl;
	fout << "      vertex " << x2 << " " << y2 << " " << z2 << endl;
	fout << "      vertex " << x4 << " " << y4 << " " << z4 << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;

	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x3 << " " << y3 << " " << z3 << endl;
	fout << "      vertex " << x4 << " " << y4 << " " << z4 << endl;
	fout << "      vertex " << x1 << " " << y1 << " " << z1 << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	fout << "endsolid OpenSCAD_Model" << endl;
}
//Ratate this Tetrahedron
void Tetrahedron::rotate(double degree, char axle, Tetrahedron& orig) {
	double x1tmp = orig.x1;
	double y1tmp = orig.y1;
	double z1tmp = orig.z1;
	double x2tmp = orig.x2;
	double y2tmp = orig.y2;
	double z2tmp = orig.z2;
	double x3tmp = orig.x3;
	double y3tmp = orig.y3;
	double z3tmp = orig.z3;
	double x4tmp = orig.x4;
	double y4tmp = orig.y4;
	double z4tmp = orig.z4;
	double rad = degree / 180 * PI;
	if (axle == 'x') {
		y1tmp = orig.y1*cos(rad) - orig.z1*sin(rad);
		y2tmp = orig.y2*cos(rad) - orig.z2*sin(rad);
		y3tmp = orig.y3*cos(rad) - orig.z3*sin(rad);
		y4tmp = orig.y4*cos(rad) - orig.z4*sin(rad);
		z1tmp = orig.y1*sin(rad) + orig.z1*cos(rad);
		z2tmp = orig.y2*sin(rad) + orig.z2*cos(rad);
		z3tmp = orig.y3*sin(rad) + orig.z3*cos(rad);
		z4tmp = orig.y4*sin(rad) + orig.z4*cos(rad);
		orig.y1 = y1tmp;
		orig.y2 = y2tmp;
		orig.y3 = y3tmp;
		orig.y4 = y4tmp;
		orig.z1 = z1tmp;
		orig.z2 = z2tmp;
		orig.z3 = z3tmp;
		orig.z4 = z4tmp;
	}
	else if (axle == 'y') {
		x1tmp = orig.z1*cos(rad) - orig.x1*sin(rad);
		x2tmp = orig.z2*cos(rad) - orig.x2*sin(rad);
		x3tmp = orig.z3*cos(rad) - orig.x3*sin(rad);
		x4tmp = orig.z4*cos(rad) - orig.x4*sin(rad);
		z1tmp = orig.z1*sin(rad) + orig.x1*cos(rad);
		z2tmp = orig.z2*sin(rad) + orig.x2*cos(rad);
		z3tmp = orig.z3*sin(rad) + orig.x3*cos(rad);
		z4tmp = orig.z4*sin(rad) + orig.x4*cos(rad);
		orig.x1 = x1tmp;
		orig.x2 = x2tmp;
		orig.x3 = x3tmp;
		orig.x4 = x4tmp;
		orig.z1 = x1tmp;
		orig.z2 = x2tmp; 
		orig.z3 = x3tmp;
		orig.z4 = z4tmp;

	}
	else if (axle == 'z') {
		x1tmp = orig.x1*cos(rad) - orig.y1*sin(rad);
		x2tmp = orig.x2*cos(rad) - orig.y2*sin(rad);
		x3tmp = orig.x3*cos(rad) - orig.y3*sin(rad);
		x4tmp = orig.x4*cos(rad) - orig.y4*sin(rad);
		y1tmp = orig.x1*sin(rad) + orig.y1*cos(rad);
		y2tmp = orig.x2*sin(rad) + orig.y2*cos(rad);
		y3tmp = orig.x3*sin(rad) + orig.y3*cos(rad);
		y4tmp = orig.x4*sin(rad) + orig.y4*cos(rad);
		orig.x1 = x1tmp;
		orig.x2 = x2tmp;
		orig.x3 = x3tmp;
		orig.x4 = x4tmp;
		orig.y1 = y1tmp;
		orig.y2 = y2tmp;
		orig.y3 = y3tmp;
		orig.y4 = y4tmp;
	}
}
double Tetrahedron::area() const {
	//face 1 area:
	double len1 = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1));    //use pythagorean theorem to find length of each side
	double len2 = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3) + (z2 - z3)*(z2 - z3));
	double len3 = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1) + (z3 - z1)*(z3 - z1));
	double halfPerimeter1 = 0.5*(len1 + len2 + len3);
	double area1 = sqrt(halfPerimeter1*(halfPerimeter1 - len1)*(halfPerimeter1 - len2)*(halfPerimeter1 - len3));  //Heron's formula
																												  //face 2
	double len4 = sqrt((x2 - x4)*(x2 - x4) + (y2 - y4)*(y2 - y4)+ (z2 - z4)*(z2 - z4));    //use pythagorean theorem to find length of each side
	double len5 = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3)+ (z2 - z3)*(z2 - z3));
	double len6 = sqrt((x3 - x4)*(x3 - x4) + (y3 - y4)*(y3 - y4)+ (z3 - z4)*(z3 - z4));
	double halfPerimeter2 = 0.5*(len4 + len5 + len6);
	double area2 = sqrt(halfPerimeter2*(halfPerimeter2 - len4)*(halfPerimeter2 - len5)*(halfPerimeter2 - len6));
	//face 3
	double len7 = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)+ (z2 - z1)*(z2 - z1));    //use pythagorean theorem to find length of each side
	double len8 = sqrt((x2 - x4)*(x2 - x4) + (y2 - y4)*(y2 - y4)+ (z2 - z4)*(z2 - z4));
	double len9 = sqrt((x4 - x1)*(x4 - x1) + (y4 - y1)*(y4 - y1)+ (z4 - z1)*(z4 - z1));
	double halfPerimeter3 = 0.5*(len7 + len8 + len9);
	double area3 = sqrt(halfPerimeter3*(halfPerimeter3 - len7)*(halfPerimeter3 - len8)*(halfPerimeter3 - len9));
	//face 4
	double len10 = sqrt((x3 - x4)*(x3 - x4) + (y3 - y3)*(y3 - y4)+ (z3 - z4)*(z3 - z4));    //use pythagorean theorem to find length of each side
	double len11 = sqrt((x4 - x1)*(x4 - x1) + (y4 - y1)*(y4 - y1)+ (z4 - z1)*(z4 - z1));
	double len12 = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1)+ (z3 - z1)*(z3 - z1));
	double halfPerimeter4 = 0.5*(len10 + len11 + len12);
	double area4 = sqrt(halfPerimeter4*(halfPerimeter4 - len10)*(halfPerimeter4 - len11)*(halfPerimeter4 - len12));
	//final surface area
	return area1 + area2 + area3 + area4;
}
//zoom this Tetrahedron
void Tetrahedron::zoom(double times, Tetrahedron& orig) {
	orig.x1 = times*orig.x1;
	orig.x2 = times*orig.x2;
	orig.x3 = times*orig.x3;
	orig.x4 = times*orig.x4;
	orig.y1 = times*orig.y1;
	orig.y2 = times*orig.y2;
	orig.y3 = times*orig.y3;
	orig.y4 = times*orig.y4;
	orig.z1 = times*orig.z1;
	orig.z2 = times*orig.z2;
	orig.z3 = times*orig.z3;
	orig.z4 = times*orig.z4;
}
/*
int main() {
	Tetrahedron a(0, 20, 10, 10, 0, 10, 10, 20, 10, 10, 10, 20);

	a.zoom(2, a);
//	b.move(10, 'L', a);
    a.rotate(45, 'x', a);
	a.draw();
	cout << "The perimeter of this rectangle is " << a.perimeter() << endl;
	cout << "The suface area of this rectangle is " << a.area() << endl;
	//	system("pause");
	return 0;
}*/
