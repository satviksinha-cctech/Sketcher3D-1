#pragma once
#include "Shape3D.h"

class Cylinder : public Shape3D {
private:
    Point center;   // center of base
    double radius;
    double height;
    int circleSteps;
    int heightSteps;

public:
    Cylinder(const Point& baseCenter, double radius, double height,
        int circleSteps = 36, int heightSteps = 10);

    std::vector<Point> getCoordinates() const override;
};