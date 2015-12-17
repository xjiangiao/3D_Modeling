#include<iostream>
#include<fstream>
#include<istream>
#include<cmath>
#define PI 3.141592653
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
void Triangle::rotate(double degree, Triangle& orig) {
	double x2tmp = orig.x2;
	double y2tmp = orig.y2;
	double x3tmp = orig.x3;
	double y3tmp = orig.y3;
	double rad = degree / 180 * PI;
	x2tmp = (orig.x2 - orig.x1)*cos(rad) + (orig.y2 - orig.y1)*sin(rad) + orig.x1;
	x3tmp = (orig.x3 - orig.x1)*cos(rad) + (orig.y3 - orig.y1)*sin(rad) + orig.x1;
	y2tmp = (orig.y2 - orig.y1)*cos(rad) - (orig.x2 - orig.x1)*sin(rad) + orig.y1;
	y3tmp = (orig.y3 - orig.y1)*cos(rad) - (orig.x3 - orig.x1)*sin(rad) + orig.y1;
	orig.x2 = x2tmp;
	orig.x3 = x3tmp;
	orig.y2 = y2tmp;
	orig.y3 = y3tmp;
}
void Triangle::move(double n, char direction, Triangle& orig){
    if(direction == 'L'){
        orig.x1 -= n;
        orig.x2 -= n;
        orig.x3 -= n;
    }
    else if(direction == 'R'){
        orig.x1 += n;
        orig.x2 += n;
        orig.x3 += n;
    }
    else if(direction == 'U'){
        orig.y1 += n;
        orig.y2 += n;
        orig.y3 += n;
    }
    else if( direction == 'D'){
        orig.y1 -= n;
        orig.y2 -= n;
        orig.y3 -= n;
    }
}
void Triangle::zoom(double times, Triangle& orig){
    orig.x1 *= times;
    orig.x2 *= times;
    orig.x3 *= times;
    orig.y1 *= times;
    orig.y2 *= times;
    orig.y3 *= times;
}
double Triangle::perimeter() const{   //calculate perimeter of triangle
    double len1 = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));    //use pythagorean theorem to find length of each side
    double len2 = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    double len3 = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    return len1+len2+len3;
}
double Triangle::area() const{    //Use Heron's formula to calulate area
    double len1 = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));    //use pythagorean theorem to find length of each side
    double len2 = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    double len3 = sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
    double halfPerimeter =  0.5*(len1+len2+len3);
    return sqrt(halfPerimeter*(halfPerimeter-len1)*(halfPerimeter-len2)*(halfPerimeter-len3));  //Heron's formula
}
int main(){
	Triangle a(0.0,0.0,0.0,10.0,0.0,0.0,0.0,10.0,0.0);
	a.rotate(90,a);
	a.draw();
	a.zoom(2,a);
	a.move(10,'L', a);
	cout << "The perimeter of this triangle is " << a.perimeter() << endl;
	cout << "The area of this triangle is " << a.area() << endl;
	//system("pause");
	return 0;
}
