#pragma once
#include "Shape3D.h"

class Pyramid : public Shape3D {
private:
    Point baseCenter;
    double baseLength;
    double baseBreadth;
    double height;

public:
    Pyramid(const Point& baseCenter, double baseLength, double baseBreadth, double height);

    std::vector<Point> getCoordinates() const override;
};