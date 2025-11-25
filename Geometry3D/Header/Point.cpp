#include "pch.h"
#include "Point.h"
#include <iostream>
#include <cmath>

Point::Point() : mX(0), mY(0), mZ(0) {}

Point::Point(double x, double y, double z)
	: mX(x), mY(y), mZ(z) {
}

double Point::distance(const Point& other) const
{
	return std::sqrt((mX - other.mX) * (mX - other.mX) +
		(mY - other.mY) * (mY - other.mY) +
		(mZ - other.mZ) * (mZ - other.mZ));
}
double Point::getX() const { return mX; }
double Point::getY() const { return mY; }
double Point::getZ() const { return mZ; }

void Point::setX(const double x) { mX = x; }
void Point::setY(const double y) { mY = y; }
void Point::setZ(const double z) { mZ = z; }


std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << p.getX() << " " << p.getY() << " " << p.getZ() << "\n";
	return out;
}