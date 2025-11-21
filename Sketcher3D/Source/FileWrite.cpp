// FileWrite.cpp
#include "FileWrite.h"
#include <fstream>
#include <iostream>

bool FileWrite::writePoints(const std::string& filename,
    const std::vector<Point>& points) {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return false;
    }

    for (const auto& p : points) {
        out << p.x << " " << p.y << " " << p.z << "\n";
    }

    return true;
}
