#include "univers.h"
#include "simulate.h"
#include <iostream>
#include <cmath>

int main() {
    Univers u(3);  // 3D
    int n = std::pow(2, 5);
    u.initialiserCube(n);  

    //u.afficher();  // Affiche les positions initiales

    //u.avancer(0.1, 1.0);  // Avance les particules

    //std::cout << "\n--- Après évolution ---\n";
    //u.afficher();  // Affiche les nouvelles positions

    return 0;
}
