#include<iostream>
#include<fstream>
#include<istream>
//#include"2Dshape.hh"
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
	fout << "      vertex " << x2 << " " << y2 << " " << z2 << endl;
	fout << "      vertex " << x1 << " " << y1 << " " << z1 << endl;
	fout << "      vertex " << x4 << " " << y4 << " " << z4 << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	fout << "endsolid OpenSCAD_Model" << endl;
}
int main() {
	Rectangle a(0, 10, 10, 
		       10, 0, 10, 
		       10, 10, 10,
		        0, 0, 10);
	a.draw();
	system("pause");
	return 0;
}
