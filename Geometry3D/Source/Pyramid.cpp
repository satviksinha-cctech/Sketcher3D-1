// Pyramid.cpp
#include "Pyramid.h"
#include <vector>

Pyramid::Pyramid(const Point& baseCenter, double baseLength,
    double baseBreadth, double height)
    : baseCenter(baseCenter),
    baseLength(baseLength),
    baseBreadth(baseBreadth),
    height(height) {
}

std::vector<Point> Pyramid::getCoordinates() const {
    std::vector<Point> pts;

    double hl = baseLength / 2.0;
    double hb = baseBreadth / 2.0;

    // Base corners
    Point bl(baseCenter.x - hl, baseCenter.y - hb, baseCenter.z);
    Point br(baseCenter.x + hl, baseCenter.y - hb, baseCenter.z);
    Point tr(baseCenter.x + hl, baseCenter.y + hb, baseCenter.z);
    Point tl(baseCenter.x - hl, baseCenter.y + hb, baseCenter.z);

    // Apex
    Point apex(baseCenter.x, baseCenter.y, baseCenter.z + height);

    // Base square
    pts.push_back(bl);
    pts.push_back(br);
    pts.push_back(tr);
    pts.push_back(tl);
    pts.push_back(bl);

    // Sides
    pts.push_back(apex);  // bl -> apex
    pts.push_back(br);
    pts.push_back(apex);  // br -> apex
    pts.push_back(tr);
    pts.push_back(apex);  // tr -> apex
    pts.push_back(tl);
    pts.push_back(apex);  // tl -> apex
    pts.push_back(bl);

    return pts;
}
