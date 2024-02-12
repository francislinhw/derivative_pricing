// Mesh.hpp
#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

// Function to create a mesh array of doubles
std::vector<double> createMesh(double start, double end, double h) {
    std::vector<double> mesh;
    for (double value = start; value <= end; value += h) {
        mesh.push_back(value);
    }
    return mesh;
}

#endif