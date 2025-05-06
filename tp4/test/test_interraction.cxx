#include "particule.h"
#include "vecteur.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

// Potentiel de Lennard-Jones
double lennard_jones(double r, double epsilon = 1.0, double sigma = 1.0) {
    double sr6 = pow(sigma / r, 6);
    return 4 * epsilon * (sr6 * sr6 - sr6);
}

int main() {
    // Fichier de sortie
    ofstream file("lennard_jones.dat");
    if (!file) {
        cerr << "Erreur lors de l'ouverture du fichier !" << endl;
        return 1;
    }

    file << "# r U(r)\n";

    // On fait varier la position d'une deuxième particule le long de l'axe x
    for (double r = 0.8; r <= 3.0; r += 0.01) {
        // Particule fixe à l'origine
        Particule p1(1, "typeA", 1.0, Vecteur(0.0, 0.0, 0.0), Vecteur(0.0, 0.0, 0.0), Vecteur(0.0, 0.0, 0.0));
        // Particule mobile à distance r sur l'axe x
        Particule p2(2, "typeB", 1.0, Vecteur(r, 0.0, 0.0), Vecteur(0.0, 0.0, 0.0), Vecteur(0.0, 0.0, 0.0));

        // Calcul de la distance inter-particules
        double distance = (p2.getPosition() - p1.getPosition()).norme2();

        // Calcul du potentiel
        double U = lennard_jones(distance);

        // Sauvegarde dans le fichier
        file << fixed << setprecision(5) << r << " " << U << "\n";
    }

    file.close();
    cout << "Fichier 'lennard_jones.dat' généré avec succès." << endl;
    return 0;
}
