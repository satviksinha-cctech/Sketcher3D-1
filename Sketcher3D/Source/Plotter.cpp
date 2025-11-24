// Plotter.cpp
#include "Plotter.h"
#include <fstream>
#include <cstdlib>

bool fileExists(const std::string& path) {
    std::ifstream f(path);
    return f.good();
}

void Plotter::plot3D(const std::string& dataFile,
    const std::string& title) {
    if (!fileExists(dataFile)) {
        return;
    }

    const std::string scriptFile = "plot_shape.gp";

    std::ofstream gp(scriptFile);
    if (!gp) return;

    gp << "set title '" << title << "'\n";
    gp << "set xlabel 'X'\n";
    gp << "set ylabel 'Y'\n";
    gp << "set zlabel 'Z'\n";
    gp << "set grid\n";
    gp << "set view 60, 30\n";
    gp << "splot '" << dataFile << "' with lines\n";
    gp << "pause -1\n";  
    gp.close();

    std::string cmd = "gnuplot " + scriptFile;
    std::system(cmd.c_str());
}
