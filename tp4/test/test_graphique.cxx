#include "univers.h"
#include "simulate.h"
#include "vecteur.h"
#include <iostream>
#include <vector>
#include <thread> // Pour std::this_thread::sleep_for
#include <chrono> // Pour std::chrono::milliseconds
#include <cassert>
#include <cmath>  // Pour pow

using namespace std;

/**
 * 🔹 Fonction d'affichage des positions
 */
void afficherPositions(const std::vector<Particule>& particules) {
    system("clear"); // Nettoie l'écran (pour un affichage dynamique)
    cout << "=== Positions des particules ===" << endl;
    for (const auto& p : particules) {
        Vecteur pos = p.getPosition();
        cout << "ID: " << p.getId() << " | Position: (" 
             << pos.getX() << ", " << pos.getY() << ")" << endl;
    }
    cout << "---------------------------------------" << endl;
}

/**
 * 🔹 Fonction principale de test
 */
int main() {
    // === Paramètres de l'univers ===
    std::vector<double> longueurs = {250.0, 40.0};  // Univers 2D : longueur X, Y
    double epsilon = 5.0;
    double sigma = 1.0;
    double rcut = 2.5 * sigma;
    double espace = pow(2, 1.0 / 6.0); // 🔹 2^(1/6)

    // === Création de l'univers ===
    Univers univers(2, longueurs, rcut, epsilon, sigma);

    // === Initialisation du carré (40x40 particules) ===
    cout << "=== Initialisation du carré ===" << endl;
    int id = 0;

    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j < 40; ++j) {
            Vecteur pos(i * espace + 5, j * espace , 0.0); // Position en haut
            Vecteur vitesse(0.0, 10.0, 0.0);                   // Vitesse vers le bas
            Vecteur force(0.0, 0.0, 0.0);

            univers.getParticules().emplace_back(id++, "carre", 1.0, pos, vitesse, force);
        }
    }

    // === Initialisation du rectangle (160x40 particules) ===
    cout << "=== Initialisation du rectangle ===" << endl;

    for (int i = 0; i < 160; ++i) {
        for (int j = 0; j < 40; ++j) {
            Vecteur pos(i * espace + 5, j * espace, 0.0); // Position en bas
            Vecteur vitesse(0.0, 0.0, 0.0);              // Statique
            Vecteur force(0.0, 0.0, 0.0);

            univers.getParticules().emplace_back(id++, "rectangle", 1.0, pos, vitesse, force);
        }
    }

    
    // 🔹 Initialiser le maillage
    univers.initialiserMaillage();
    cout << " maillage mzn" << endl;


    // === Vérifications ===
    assert(univers.getParticules().size() == 8000); // 1600 + 6400
    cout << " Le nombre de particules est correct (8000)" << endl;

    // === Affichage des particules ===
    afficherPositions(univers.getParticules());
    cout << " Les particules sont correctement initialisées." << endl;

    // === Simulation de test ===
    double tmax = 0;

    simulate(univers, tmax);

    cout << "\n=== Simulation terminée. ===" << endl;

    return 0;
}
