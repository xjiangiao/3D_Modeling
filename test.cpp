 #include<iostream>
#include"Shape2D.h"
#include"cube.h"
#include"cone.h"
#include"Circle.hh"
#include"cone.h"
#include"cylinder.h"
#include"rectangle.hh"
#include"Sphere.h"
#include"Tetrahedron.h"
#include"triangle.hh"
using namespace std;
int main() {
	Circle a(0, 0, 10, 10);
//	a.zoom(2, a);
	a.draw();
	cout << "The perimeter of this Circle is " << a.perimeter() << endl;
	cout << "The suface area of this Circle is " << a.area() << endl;

	cylinder b(0, 0, 10, 10, 50);
	//	b.zoom(2, a);
	//	b.move(100, 'R', a);
	b.draw();
	cout << "The volume of this cylinder is " << b.volume() << endl;
	cout << "The suface area of this cylinder is " << b.area() << endl;

	Cone c(0, 0, 0, 50, 100);
	c.zoom(2, c);
	c.draw();
	cout << "The volume of this Cone is " << c.volume() << endl;
	cout << "The suface area of this Cone is " << c.area() << endl;

	Tetrahedron d(0, 0, 0, 10, 0, 0, 0, 10, 0, 0, 0, 10);
//	d.zoom(2, d);
	//	b.move(10, 'L', a);
	//d.rotate(45, 'x', d);
	d.draw();
    cout << "The volume of this Tetrahedron is " << d.volume() << endl;
	cout << "The suface area of this Tetrahedron is " << d.area() << endl;

	Rectangle e(0, 0, 10, 10, 0, 10, 10, 20, 10, 0, 20, 10);
//	e.zoom(2, e);
//	e.move(10, 'L', e);
//	e.rotate(45, e);
	e.draw();
	cout << "The perimeter of this Rectangle is " << e.perimeter() << endl;
	cout << "The area of this Rectangle is " << e.area() << endl;

	Triangle f(0, 0, 0, 50, 0, 0, 0, 30, 0);
//	f.rotate(90, f);
	f.draw();
	cout << "The perimeter of this triangle is " << f.perimeter() << endl;
	cout << "The area of this triangle is " << f.area() << endl;

	cube g(0, 0, 0, 10, 10, 10);
//	a.draw();
	g.rotate(45, 'x', g);
	g.zoom(5, g);
	g.draw();
	cout << "The Volume of this cube is " << g.volume() << endl;
	cout << "The suface area of this cube is " << g.area() << endl;
	system("pause");
	return 0;
}
