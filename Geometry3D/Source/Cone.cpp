// Cone.cpp
#include "Cone.h"
#include <vector>
#include <cmath>



Cone::Cone(const Point& baseCenter, double radius, double height,
    int circleSteps, int heightSteps)
    : baseCenter(baseCenter), radius(radius),
    height(height), circleSteps(circleSteps),
    heightSteps(heightSteps) {
}

std::vector<Point> Cone::getCoordinates() const {
    std::vector<Point> pts;

    // Apex above base center
    Point apex(baseCenter.x, baseCenter.y, baseCenter.z + height);

    for (int k = 0; k <= heightSteps; ++k) {
        double t = static_cast<double>(k) / heightSteps;
        double currentRadius = radius * (1.0 - t);
        double currentZ = baseCenter.z + height * t;

        for (int i = 0; i <= circleSteps; ++i) {
            double theta = 2.0 * M_PI * i / circleSteps;
            double x = baseCenter.x + currentRadius * std::cos(theta);
            double y = baseCenter.y + currentRadius * std::sin(theta);
            pts.emplace_back(x, y, currentZ);
        }
    }

    
    for (int i = 0; i <= circleSteps; ++i) {
        double theta = 2.0 * M_PI * i / circleSteps;
        double x = baseCenter.x + radius * std::cos(theta);
        double y = baseCenter.y + radius * std::sin(theta);
        pts.emplace_back(x, y, baseCenter.z);
        pts.push_back(apex);
    }

    return pts;
}
