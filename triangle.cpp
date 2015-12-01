#include<iostream>
#include<fstream>
#include<istream>
//#include"2Dshape.hh"
#include"triangle.hh"
using namespace std;

void Triangle::draw() const{
	ofstream fout("triangle.stl");
	fout << "solid OpenSCAD_Model" << endl;
	fout << "  facet normal 0 0 0" << endl;
	fout << "    outer loop" << endl;
	fout << "      vertex " << x1 << " " << y1 << " " << z1 << endl;
	fout << "      vertex " << x2 << " " << y2 << " " << z2 << endl;
	fout << "      vertex " << x3 << " " << y3 << " " << z3 << endl;
	fout << "    endloop" << endl;
	fout << "  endfacet" << endl;
	fout << "endsolid OpenSCAD_Model" << endl;
}
int main(){
	Triangle a(0.0,0.0,0.0,10.0,0.0,0.0,0,10.0,0.0);
	a.draw();
	system("pause");
	return 0;
}
