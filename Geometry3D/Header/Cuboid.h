#pragma once
#include "pch.h"
#include "Shape.h"
#include "Point.h"
#include <vector>

class GEOMETRY3D_API Cuboid : public Shape
{
private:
    double mLength;
    double mBreadth;
    double mHeight;

public:
    Cuboid(const std::string& name,
        double length,
        double breadth,
        double height);

    const std::vector<Point> getCoordinates() const override;
    void save(std::ostream& os) const override;
    void saveForGnu(std::ostream& os) const override;
};
