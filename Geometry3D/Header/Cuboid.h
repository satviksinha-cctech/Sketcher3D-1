#pragma once
#include "Shape3D.h"

class Cuboid : public Shape3D {
private:
    Point origin;   
    double L;       
    double B;       
    double H;       

public:
    Cuboid(const Point& origin, double L, double B, double H);

    std::vector<Point> getCoordinates() const override;
};