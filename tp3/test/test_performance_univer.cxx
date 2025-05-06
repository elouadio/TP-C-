#include "univers.h"
#include "simulate.h"
#include <iostream>
#include <cmath>
#include <chrono>  // Inclure chrono pour mesurer le temps

int main() {
    for (int k = 3; k <= 7; ++k) {
        int n = std::pow(2, k);  // Calculer 2^k
        int nb_particules = std::pow(n, 3);  // Calculer (2^k)^3 pour la taille du cube de particules
        Univers u(3);  // Univers 3D

        std::cout << "Test avec " << nb_particules << " particules (taille du cube: " << n << ")\n";

        // Initialiser les particules dans un cube de dimension (2^k)^3
        
        auto start = std::chrono::high_resolution_clock::now();
        u.initialiserCube(n);

        auto end = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double> duration = end - start;

        std::cout << "Temps de simulation pour " << nb_particules << " particules : " << duration.count() << " secondes\n";
    }

    return 0;
}
