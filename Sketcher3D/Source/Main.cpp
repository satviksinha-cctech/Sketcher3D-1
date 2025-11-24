//#include<iostream>
//using namespace std;
//
//int main() {
//	cout << "Hello, this is my program";
//	return 0;
//}

// Main.cpp
//#include <iostream>
//#include "Geometry3D.h"
//#include "FileWrite.h"
//#include "Plotter.h"
//#include "ShapesAPI.h"
//
//
//int main() {
//    // Example: create a cuboid via DLL
//    Shape3D* shape = CreateCuboid(0.0, 0.0, 0.0, 4.0, 3.0, 2.0);
//    if (!shape) {
//        std::cerr << "Failed to create shape\n";
//        return 1;
//    }
//
//    auto points = shape->getCoordinates();
//
//    // Choose a file name per shape type
//    std::string filename = "cuboid.dat";
//    if (!FileWrite::writePoints(filename, points)) {
//        std::cerr << "Failed to write data file\n";
//        delete shape;
//        return 1;
//    }
//
//    // Plot it
//    Plotter::plot3D(filename, "Cuboid");
//
//    delete shape;
//    return 0;
//}
#include <iostream>
#include <vector>
#include <string>

#include "ShapesAPI.h"   // DLL factories
#include "FileWrite.h"  // writes .dat
#include "Plotter.h"    // calls gnuplot

int main() {
    std::vector<Shape3D*> shapes;

    // Create multiple shapes via DLL
    shapes.push_back(CreateCuboid(0, 0, 0, 4, 3, 2));
    shapes.push_back(CreateSphere(0, 0, 0, 2.0, 36, 18));
    shapes.push_back(CreateCylinder(0, 0, 0, 2.0, 5.0, 36, 10));
    shapes.push_back(CreateCone(0, 0, 0, 2.0, 4.0, 36, 10));
    shapes.push_back(CreatePyramid(0, 0, 0, 4, 4, 3));


    int count = 1;

    for (auto shape : shapes) {
        if (!shape) {
            std::cerr << "Shape creation failed!\n";
            continue;
        }

        // Generate file name (shape1.dat, shape2.dat, ...)
        std::string filename = "shape" + std::to_string(count) + ".dat";

        // Get coordinates from the DLL object
        auto points = shape->getCoordinates();

        // Write .dat file
        if (!FileWrite::writePoints(filename, points)) {
            std::cerr << "Failed to write " << filename << "\n";
            delete shape;
            count++;
            continue;
        }

        // Plot it with gnuplot
        Plotter::plot3D(filename, "Shape " + std::to_string(count));

        // Free heap-allocated DLL object
        delete shape;

        count++;
    }

    std::cout << "All shapes plotted.\n";
    return 0;
}
