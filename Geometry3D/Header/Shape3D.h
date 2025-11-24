#pragma once
#include <vector>
#include "Point.h"

const double M_PI = 3.14159265358979323846;

class Shape3D {
public:
    virtual ~Shape3D() {}

    virtual std::vector<Point> getCoordinates() const = 0;
};