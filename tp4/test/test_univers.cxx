#include "univers.h"
#include <iostream>

int main() {
    // Création d’un univers 3D avec :
    // - Longueurs caractéristiques : 1.0 x 1.0 x 1.0
    // - Rayon de coupure : 0.5
    // - Constantes physiques : epsilon = 1.0, sigma = 1.0
    Univers u(3, {1.0, 1.0, 1.0}, 0.5, 1.0, 1.0);

    // Initialisation d’un cube 2x2x2 (8 particules)
    u.initialiserCube(3);

    std::cout << "\n=== État initial de l'univers ===\n";
    u.afficher();

    // Simulation avec dt = 0.01, tmax = 0.1
    u.avancer(0.01, 0.1);

    std::cout << "\n=== État final de l'univers ===\n";
    u.afficher();

    return 0;
}
