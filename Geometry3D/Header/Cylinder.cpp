// Cylinder.cpp
#include "Cylinder.h"
#include <vector>
#include <cmath>



Cylinder::Cylinder(const Point& baseCenter, double radius, double height,
    int circleSteps, int heightSteps)
    : center(baseCenter), radius(radius),
    height(height), circleSteps(circleSteps),
    heightSteps(heightSteps) {
}

std::vector<Point> Cylinder::getCoordinates() const {
    std::vector<Point> pts;

    // Side surface: circles along height
    for (int k = 0; k <= heightSteps; ++k) {
        double z = center.z + (height * k / heightSteps);

        for (int i = 0; i <= circleSteps; ++i) {
            double theta = 2.0 * M_PI * i / circleSteps;
            double x = center.x + radius * std::cos(theta);
            double y = center.y + radius * std::sin(theta);
            pts.emplace_back(x, y, z);
        }
    }

    return pts;
}
