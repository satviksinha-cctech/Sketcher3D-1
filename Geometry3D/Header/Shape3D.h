#pragma once
#include <vector>
#include "Point.h"

class Shape3D {
public:
    virtual ~Shape3D() {}

    // Returns a list of 3D points that describe the shape (wireframe or surface sample)
    virtual std::vector<Point> getCoordinates() const = 0;
};