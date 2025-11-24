#pragma once
#include <string>

class Plotter {
public:
    // Generates a gnuplot script and runs it using system()
    static void plot3D(const std::string& dataFile,
        const std::string& title = "3D Shape");
};