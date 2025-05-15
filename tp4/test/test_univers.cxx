#include "univers.h"
#include <iostream>
#include <cassert>
#include <cmath>    

int main() {
    std::vector<double> longueurs = {10.0, 10.0, 10.0};
    Univers univers(3, longueurs, 2.0, 1.0, 1.0);

    // 🔹 Initialiser le cube de particules
    univers.initialiserCube(10);

    //  Test 1 : Vérification du nombre de particules
    size_t expected_particles = 10 * 10 * 10;
    assert(univers.getParticules().size() == expected_particles);
    std::cout << "Test 1 réussi : Nombre de particules correctement initialisé." << std::endl;

    // Test 2 : Vérification du maillage
    const auto& grille = univers.getGrille();
    size_t ncd_x = std::ceil(longueurs[0] / 2.0);
    size_t ncd_y = std::ceil(longueurs[1] / 2.0);
    size_t ncd_z = std::ceil(longueurs[2] / 2.0);

    assert(grille.size() == ncd_x);
    assert(grille[0].size() == ncd_y);
    assert(grille[0][0].size() == ncd_z);
    std::cout << "Test 2 réussi : Grille correctement dimensionnée." << std::endl;

    // 🔹 Afficher le contenu de la grille
    univers.afficher();

    std::cout << "\n Tous les tests sont passés avec succès." << std::endl;

    return 0;
}
