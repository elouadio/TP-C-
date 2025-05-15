#include "univers.h"
#include "simulate.h"
#include "vecteur.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>  // Pour pow
#include <cassert>

using namespace std;

/**
 * 🔹 Sauvegarde des positions finales dans un fichier CSV
 */
void sauvegarderPositions(const std::vector<Particule>& particules, const std::string& filename, double longueurX, double longueurY) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier " << filename << endl;
        return;
    }

    // En-tête CSV
    file << "ID,Type,X,Y,Z,OutOfBounds\n";

    for (const auto& p : particules) {
        Vecteur pos = p.getPosition();
        
        // Vérification des bornes
        bool out_of_bounds = (pos.getX() < 0 || pos.getX() > longueurX ||
                              pos.getY() < 0 || pos.getY() > longueurY);

        file << p.getId() << "," 
             << p.getCategorie() << ","   // C'était "Categorie" dans le CSV
             << pos.getX() << "," 
             << pos.getY() << "," 
             << pos.getZ() << ","
             << (out_of_bounds ? "True" : "False") << "\n";
    }

    file.close();
    cout << "✅ Positions finales enregistrées dans " << filename << endl;
}



/**
 * 🔹 Initialisation des particules dans l'univers
 */
void initialiserParticules(Univers& univers) {
    double espace = pow(2, 1.0 / 10000.0); // 🔹 2^(1/6)
    int id = 0;

    // === Initialisation du carré (40x40 particules) ===
    cout << "=== Initialisation du carré ===" << endl;
    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j < 40; ++j) {
            double x = i * espace +80;
            double y = j * espace + 35 ;
            Vecteur pos(x, y , 0.0); // Position en haut
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

    // === Vérification du nombre total de particules ===
    assert(univers.getParticules().size() == 8000); // 1600 + 6400
    cout << " Le nombre de particules est correct (8000)" << endl;
}

/**
 * 🔹 Affichage des positions
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
 * 🔹 Fonction principale
 */
int main() {
    // === Paramètres de l'univers ===
    vector<double> longueurs = {250.0, 40.0};  // Univers 2D : longueur X, Y
    double epsilon = 5.0;
    double sigma = 1.0;
    double rcut = 2.5 * sigma;

    // === Création de l'univers ===
    Univers univers(2, longueurs, rcut, epsilon, sigma);

    // === Initialisation des particules ===
    initialiserParticules(univers);

    //  Initialiser le maillage
    univers.initialiserMaillage();
    cout << " Maillage initialisé." << endl;

    // === Affichage des particules ===
    afficherPositions(univers.getParticules());
    cout << " Les particules sont correctement initialisées." << endl;

    // === Simulation de test ===
    double tmax = 19.5;
    simulate(univers, tmax);

    //  Sauvegarde des positions finales
    sauvegarderPositions(univers.getParticules(), "positions_finales.csv", 250.0, 100.0);


    cout << "\n=== Simulation terminée. ===" << endl;

    return 0;
}
