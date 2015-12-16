#include <iostream>
#include <fstream>
#include <istream>
#include "tetrahedron.hh"
using namespace std;

void Tetrahedron::draw() const {
	ofstream fout("tetrahedron.stl");
	fout << "solid OpenSCAD_Model" << '\n';
	fout << "	facet normal 0 0 0" << '\n';
	fout << "		outer loop" << '\n';
	fout << "			vertex " << x1 << " " << y1 << " " << z1 << '\n';
	fout << "			vertex " << x2 << " " << y2 << " " << z2 << '\n';
	fout << "			vertex " << x3 << " " << y3 << " " << z3 << '\n';
	fout << " 		endloop" << '\n';
	fout << "	endfacet" << '\n';
	fout << "	facet normal 0 0 0" << '\n';
	fout << "		outer loop" << '\n';
	fout << "			vertex " << x4 << " " << y4 << " " << z4 << '\n';
	fout << "			vertex " << x3 << " " << y3 << " " << z3 << '\n';
	fout << "			vertex " << x2 << " " << y2 << " " << z2 << '\n';
	fout << " 		endloop" << '\n';
	fout << "	endfacet" << '\n';
	fout << "	facet normal 0 0 0" << '\n';
	fout << "		outer loop" << '\n';
	fout << "			vertex " << x3 << " " << y3 << " " << z3 << '\n';
	fout << "			vertex " << x4 << " " << y4 << " " << z4 << '\n';
	fout << "			vertex " << x1 << " " << y1 << " " << z1 << '\n';
	fout << " 		endloop" << '\n';
	fout << "	endfacet" << '\n';
	fout << "	facet normal 0 0 0" << '\n';
	fout << "		outer loop" << '\n';
	fout << "			vertex " << x2 << " " << y2 << " " << z2 << '\n';
	fout << "			vertex " << x1 << " " << y1 << " " << z1 << '\n';
	fout << "			vertex " << x4 << " " << y4 << " " << z4 << '\n';
	fout << " 		endloop" << '\n';
	fout << "	endfacet" << '\n';

	fout << "endsolid OpenSCAD_Model" << '\n';
}

int main(){
	Tetrahedron a(5.0, 5.0, 5.0,
					5.0, 0.0, 0.0,
						0.0, 5.0, 0.0,
							0.0,0.0,5.0);
	a.draw();
	system("pause");
	return 0;
}
