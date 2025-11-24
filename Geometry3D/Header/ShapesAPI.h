#pragma once
#include "Export.h"
#include "Shape3D.h"
#include "Point.h"

    GEOMETRY3D_API Shape3D* CreateCuboid(double ox, double oy, double oz,
        double L, double B, double H);

    GEOMETRY3D_API Shape3D* CreateSphere(double cx, double cy, double cz,
        double radius,
        int thetaSteps, int phiSteps);

    GEOMETRY3D_API Shape3D* CreateCylinder(double bx, double by, double bz,
        double radius, double height,
        int circleSteps, int heightSteps);

    GEOMETRY3D_API Shape3D* CreateCone(double bx, double by, double bz,
        double radius, double height,
        int circleSteps, int heightSteps);

    GEOMETRY3D_API Shape3D* CreatePyramid(double bx, double by, double bz,
        double baseLength, double baseBreadth,
        double height);