#include <iostream>
#include <fstream>
#include <istream>
//#include "2DShape.hh"
#include "pentagon.hh"
using namespace std;

void Pentagon::draw() const{
	ofstream fout("pentagon.stl");
	fout << "solid OpenSCAD_Model" << '\n';
	fout << "	facet normal 0 0 0" << '\n';
	fout << "		outer loop" << '\n';
	fout << "			vertex " << x1 << " " << y1 << " " << z1 << '\n';
	fout << "			vertex " << x2 << " " << y2 << " " << z2 << '\n';
	fout << "			vertex " << x3 << " " << y3 << " " << z3 << '\n';
	fout << "			vertex " << x4 << " " << y4 << " " << z4 << '\n';
	fout << "			vertex " << x5 << " " << y5 << " " << z5 << '\n';
	fout << " 		endloop" << '\n';
	fout << "	endfacet" << '\n';
	fout << "endsolid OpenSCAD_Model" << '\n';
}

int main(){
	Pentagon a(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	a.draw();
	system("pause");
	return 0;
}
