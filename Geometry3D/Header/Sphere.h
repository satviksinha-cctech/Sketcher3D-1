#pragma once
#include "Shape3D.h"

class Sphere : public Shape3D {
private:
    Point center;
    double radius;
    int thetaSteps;  // around horizontal
    int phiSteps;    // from top to bottom

public:
    Sphere(const Point& center, double radius,
        int thetaSteps = 36, int phiSteps = 18);

    std::vector<Point> getCoordinates() const override;
};