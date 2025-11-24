#include "ShapesAPI.h"
#include "Cuboid.h"
#include "Sphere.h"
#include "Cylinder.h"
#include "Cone.h"
#include "Pyramid.h"

    GEOMETRY3D_API Shape3D* CreateCuboid(double ox, double oy, double oz,
        double L, double B, double H) {
        return new Cuboid(Point(ox, oy, oz), L, B, H);
    }

    GEOMETRY3D_API Shape3D* CreateSphere(double cx, double cy, double cz,
        double radius, int thetaSteps, int phiSteps) {
        return new Sphere(Point(cx, cy, cz), radius, thetaSteps, phiSteps);
    }

    GEOMETRY3D_API Shape3D* CreateCylinder(double bx, double by, double bz,
        double radius, double height,
        int circleSteps, int heightSteps) {
        return new Cylinder(Point(bx, by, bz), radius, height, circleSteps, heightSteps);
    }

    GEOMETRY3D_API Shape3D* CreateCone(double bx, double by, double bz,
        double radius, double height,
        int circleSteps, int heightSteps) {
        return new Cone(Point(bx, by, bz), radius, height, circleSteps, heightSteps);
    }

    GEOMETRY3D_API Shape3D* CreatePyramid(double bx, double by, double bz,
        double baseLength, double baseBreadth,
        double height)
    {
        return new Pyramid(Point(bx, by, bz), baseLength, baseBreadth, height);
    }
