#pragma once
#include <string>
#include <vector>
#include "Point.h"

class FileWrite {
public:
    static bool writePoints(const std::string& filename,
        const std::vector<Point>& points);
};