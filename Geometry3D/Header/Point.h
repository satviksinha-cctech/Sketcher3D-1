#pragma once
#include <iostream>

class Point {
public:
    double x;
    double y;
    double z;

    Point();
    Point(double x, double y, double z);
};

inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << p.x << " " << p.y << " " << p.z;
    return os;
}
