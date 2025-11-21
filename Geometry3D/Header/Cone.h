#pragma once
#include "Shape3D.h"

class Cone : public Shape3D {
private:
    Point baseCenter;
    double radius;
    double height;
    int circleSteps;
    int heightSteps;

public:
    Cone(const Point& baseCenter, double radius, double height,
        int circleSteps = 36, int heightSteps = 10);

    std::vector<Point> getCoordinates() const override;
};