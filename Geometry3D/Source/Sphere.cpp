// Sphere.cpp
#include "Sphere.h"
#include <vector>
#include <cmath>


Sphere::Sphere(const Point& center, double radius,
    int thetaSteps, int phiSteps)
    : center(center), radius(radius),
    thetaSteps(thetaSteps), phiSteps(phiSteps) {
}

std::vector<Point> Sphere::getCoordinates() const {
    std::vector<Point> pts;
    pts.reserve(thetaSteps * phiSteps);

    
    for (int i = 0; i <= phiSteps; ++i) {
        double phi = M_PI * i / phiSteps; 

        for (int j = 0; j <= thetaSteps; ++j) {
            double theta = 2.0 * M_PI * j / thetaSteps; 

            double x = center.x + radius * std::sin(phi) * std::cos(theta);
            double y = center.y + radius * std::sin(phi) * std::sin(theta);
            double z = center.z + radius * std::cos(phi);

            pts.emplace_back(x, y, z);
        }
    }

    return pts;
}
