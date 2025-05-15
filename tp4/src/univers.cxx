#include "univers.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

/**
 * Constructeur de la classe Univers
 */
Univers::Univers(int dim, const std::vector<double>& Ld, double r_cut, double eps, double sig)
    : dimension(dim), longueurs(Ld), rcut(r_cut), epsilon(eps), sigma(sig) {}

/**
 * Initialisation du cube de particules
 * Cette méthode crée un cube de particules espacées de manière régulière
 */
void Univers::initialiserCube(int n) {
    particules.clear();
    double masse = 1.0;
    Vecteur vitesse(0.01, 0.01, 0.01);
    Vecteur force(0.0, 0.0, 0.0);
    int id = 0;

    double step_x = (dimension >= 1) ? longueurs[0] / (n - 1) : 0.0;
    double step_y = (dimension >= 2) ? longueurs[1] / (n - 1) : 0.0;
    double step_z = (dimension == 3) ? longueurs[2] / (n - 1) : 0.0;

    // Création des particules dans un cube régulier
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (dimension >= 2 ? n : 1); ++j) {
            for (int k = 0; k < (dimension == 3 ? n : 1); ++k) {
                Vecteur pos(i * step_x, j * step_y, k * step_z);
                particules.emplace_back(id++, "particule", masse, pos, vitesse, force);
            }
        }
    }
    
    // Initialiser le maillage après avoir ajouté les particules
    initialiserMaillage(); 
}

/**
 * Initialisation du maillage tensoriel
 * Cette méthode segmente l'espace en cellules de taille rcut
 */
void Univers::initialiserMaillage() {
    // Calcul du nombre de cellules par dimension
    ncd_x = std::ceil(longueurs[0] / rcut);
    ncd_y = (dimension >= 2) ? std::ceil(longueurs[1] / rcut) : 1;
    ncd_z = (dimension == 3) ? std::ceil(longueurs[2] / rcut) : 1;

    // Allocation de la grille
    grille.clear();
    grille.resize(ncd_x, std::vector<std::vector<Cellule>>(ncd_y, std::vector<Cellule>(ncd_z)));

    // Ajout des particules dans les cellules correspondantes
    for (auto& p : particules) {
        int x = std::min(static_cast<int>(p.getPosition().getX() / rcut), ncd_x - 1);
        int y = (dimension >= 2) ? std::min(static_cast<int>(p.getPosition().getY() / rcut), ncd_y - 1) : 0;
        int z = (dimension == 3) ? std::min(static_cast<int>(p.getPosition().getZ() / rcut), ncd_z - 1) : 0;

        grille[x][y][z].particules.push_back(&p);
    }

    cout << "Maillage initialisé avec succès (" << ncd_x << ", " << ncd_y << ", " << ncd_z << ")" << endl;
}

/**
 * Affichage des particules par cellule
 */
void Univers::afficher() const {
    for (int x = 0; x < ncd_x; ++x) {
        for (int y = 0; y < ncd_y; ++y) {
            for (int z = 0; z < ncd_z; ++z) {
                if (!grille[x][y][z].particules.empty()) {
                    cout << "Cellule (" << x << ", " << y << ", " << z << ") contient : ";
                    for (const auto* p : grille[x][y][z].particules) {
                        cout << "[" << p->getId() << "] ";
                    }
                    cout << endl;
                }
            }
        }
    }
}

/**
 *  Lecture seule (const Univers)
 */
const std::vector<Particule>& Univers::getParticules() const {
    return particules;
}

/**
 *  Lecture/écriture (Univers normal, non-const)
 */
std::vector<Particule>& Univers::getParticules() {
    return particules;
}

/**
 * Accesseurs pour les attributs privés
 */
int Univers::getDimension() const {
    return dimension;
}

double Univers::getRcut() const {
    return rcut;
}

const std::vector<double>& Univers::getLongueurs() const {
    return longueurs;
}

double Univers::getEpsilon() const {
    return epsilon;
}

double Univers::getSigma() const {
    return sigma;
}

/**
 * 🔹 Nouvel accesseur pour récupérer la grille
 */
const std::vector<std::vector<std::vector<Cellule>>>& Univers::getGrille() const {
    return grille;
}

/**
 * 🔹 Getters pour les dimensions du maillage
 */
int Univers::getNcdX() const {
    return ncd_x;
}

int Univers::getNcdY() const {
    return ncd_y;
}

int Univers::getNcdZ() const {
    return ncd_z;
}
/**
 * 🔹 Mise à jour du maillage après le déplacement des particules
 */
void Univers::mettreAJourMaillage() {
    // 🔹 1. On vide toutes les cellules
    for (auto& plan : grille) {
        for (auto& ligne : plan) {
            for (auto& cellule : ligne) {
                cellule.particules.clear();
            }
        }
    }

    // Calcul du nombre de cellules par dimension
    ncd_x = std::ceil(longueurs[0] / rcut);
    ncd_y = (dimension >= 2) ? std::ceil(longueurs[1] / rcut) : 1;
    ncd_z = (dimension == 3) ? std::ceil(longueurs[2] / rcut) : 1;

    // 🔹 2. On réattribue chaque particule dans la bonne cellule
    for (auto& p : particules) {
        double posX = p.getPosition().getX();
        double posY = p.getPosition().getY();
        double posZ = p.getPosition().getZ();

        // 🔹 Vérification : On ignore les particules hors de l'univers
        if (posX < 0 || posX >= longueurs[0] ||
            (dimension >= 2 && (posY < 0 || posY >= longueurs[1])) ||
            (dimension == 3 && (posZ < 0 || posZ >= longueurs[2]))) {
            std::cerr << " Particule " << p.getId() 
                      << " hors de l'univers. Non insérée dans le maillage."
                      << " Position : (" << posX << ", " << posY << ", " << posZ << ")" << std::endl;
            continue; // On ne l'ajoute pas
        }

        // 🔹 Calcul des indices dans la grille
        int x = std::min(static_cast<int>(posX / rcut), ncd_x - 1);
        int y = (dimension >= 2) ? std::min(static_cast<int>(posY / rcut), ncd_y - 1) : 0;
        int z = (dimension == 3) ? std::min(static_cast<int>(posZ / rcut), ncd_z - 1) : 0;

        // 🔹 On replace la particule dans la cellule correcte
        grille[x][y][z].particules.push_back(&p);
    }

    std::cout << "✅ Maillage mis à jour. Les particules hors de l'univers ont été ignorées." << std::endl;
}

double Univers::getLongueur(int index) const {
    return longueurs[index];
}
