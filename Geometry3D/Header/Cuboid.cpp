#include "Cuboid.h"

Cuboid::Cuboid(const std::string& name,
    double length,
    double breadth,
    double height)
    : Shape(name),
    mLength(length),
    mBreadth(breadth),
    mHeight(height)
{
}

const std::vector<Point> Cuboid::getCoordinates() const
{
    std::vector<Point> pts;

    double L = mLength;
    double B = mBreadth;
    double H = mHeight;

    Point p000(0, 0, 0);
    Point p100(L, 0, 0);
    Point p110(L, B, 0);
    Point p010(0, B, 0);

    Point p001(0, 0, H);
    Point p101(L, 0, H);
    Point p111(L, B, H);
    Point p011(0, B, H);

    // Base rectangle
    pts.push_back(p000); pts.push_back(p100);
    pts.push_back(p110); pts.push_back(p010);
    pts.push_back(p000);

    // Top rectangle
    pts.push_back(p001); pts.push_back(p101);
    pts.push_back(p111); pts.push_back(p011);
    pts.push_back(p001);

    // Vertical edges
    pts.push_back(p000); pts.push_back(p001);
    pts.push_back(p100); pts.push_back(p101);
    pts.push_back(p110); pts.push_back(p111);
    pts.push_back(p010); pts.push_back(p011);

    return pts;
}

void Cuboid::save(std::ostream& os) const
{
    os << "Cuboid: " << getName() << "\n"
        << "Length: " << mLength << "\n"
        << "Breadth: " << mBreadth << "\n"
        << "Height: " << mHeight << "\n\n";
}

void Cuboid::saveForGnu(std::ostream& os) const
{
    const auto pts = getCoordinates();
    for (const auto& p : pts)
        os << p.getX() << " " << p.getY() << " " << p.getZ() << "\n";

    os << "\n";
}
