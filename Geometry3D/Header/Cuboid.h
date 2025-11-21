#pragma once
#include "Shape3D.h"

class Cuboid : public Shape3D {
private:
    Point origin;   // one corner
    double L;       // length (x direction)
    double B;       // breadth (y direction)
    double H;       // height (z direction)

public:
    Cuboid(const Point& origin, double L, double B, double H);

    std::vector<Point> getCoordinates() const override;
};