#include <iostream>
#include <vector>
#include "univers.h"
#include "simulate.h"
#include "vecteur.h"
#include "particule.h"

using namespace std;

int main() {
    // 🔹 Paramètres de l'univers
    int dimension = 3;
    std::vector<double> longueurs = {10.0, 10.0, 10.0};
    double rcut = 2.5;
    double epsilon = 1.0;
    double sigma = 1.0;

    // 🔹 Création de l'univers
    Univers univers(dimension, longueurs, rcut, epsilon, sigma);

    // 🔹 Initialisation d'un cube de particules (5x5x5)
    cout << "=== Initialisation du cube de particules ===" << endl;
    univers.initialiserCube(5);
    univers.afficher();

    // 🔹 Simulation pendant 1 seconde
    cout << "\n=== Début de la simulation ===" << endl;
    double tmax = 1.0;  // 1 seconde de simulation
    simulate(univers, tmax);

    // 🔹 Afficher l'état final
    cout << "\n=== État final des particules ===" << endl;
    univers.afficher();

    return 0;
}
