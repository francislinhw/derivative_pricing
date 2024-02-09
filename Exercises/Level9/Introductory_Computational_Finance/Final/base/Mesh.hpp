// Mesh.hpp
#include <vector>
#ifndef MESH_HPP
#define MESH_HPP

// Function to create a mesh array of doubles
std::vector<double> createMesh(double start, double end, double h) {
    std::vector<double> mesh;
    for (double value = start; value <= end; value += h) {
        mesh.push_back(value);
    }
    return mesh;
}

#endif