// Cuboid.cpp
#include "Cuboid.h"
#include <vector>

Cuboid::Cuboid(const Point& origin, double L, double B, double H)
    : origin(origin), L(L), B(B), H(H) {
}

std::vector<Point> Cuboid::getCoordinates() const {
    std::vector<Point> pts;
    pts.reserve(50);

    // 8 vertices
    Point v0(origin.x, origin.y, origin.z);
    Point v1(origin.x + L, origin.y, origin.z);
    Point v2(origin.x + L, origin.y + B, origin.z);
    Point v3(origin.x, origin.y + B, origin.z);
    Point v4(origin.x, origin.y, origin.z + H);
    Point v5(origin.x + L, origin.y, origin.z + H);
    Point v6(origin.x + L, origin.y + B, origin.z + H);
    Point v7(origin.x, origin.y + B, origin.z + H);

    // Bottom rectangle
    pts.push_back(v0);
    pts.push_back(v1);
    pts.push_back(v2);
    pts.push_back(v3);
    pts.push_back(v0);

    // Vertical edges (some may retrace)
    pts.push_back(v4);
    pts.push_back(v5);
    pts.push_back(v1);
    pts.push_back(v5);
    pts.push_back(v6);
    pts.push_back(v2);
    pts.push_back(v6);
    pts.push_back(v7);
    pts.push_back(v3);
    pts.push_back(v7);
    pts.push_back(v4);

    // Top rectangle (closing the loop)
    pts.push_back(v5);
    pts.push_back(v6);
    pts.push_back(v7);
    pts.push_back(v4);

    return pts;
}
