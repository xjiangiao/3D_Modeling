#ifndef SHAPE3d_HH_
#define SHAPE3d_HH_
class shape3D {
private:
public:
	virtual double area() const = 0;
	virtual double volume() const = 0;
};

#endif
