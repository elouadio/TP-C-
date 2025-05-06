#include "particule.h"
#include <iostream>
#include <iomanip>  // Pour un affichage formaté

// Constructeur
Particule::Particule(int identifiant,
                     const std::string& cat,
                     double m,
                     const std::array<double, 3>& pos,
                     const std::array<double, 3>& vit,
                     const std::array<double, 3>& frc)
    : id(identifiant), categorie(cat), masse(m), position(pos), vitesse(vit), force(frc) {}

// Accesseurs
int Particule::getId() const { return id; }
std::string Particule::getCategorie() const { return categorie; }
double Particule::getMasse() const { return masse; }
std::array<double, 3> Particule::getPosition() const { return position; }
std::array<double, 3> Particule::getVitesse() const { return vitesse; }
std::array<double, 3> Particule::getForce() const { return force; }

// Mutateurs
void Particule::setPosition(const std::array<double, 3>& pos) { position = pos; }
void Particule::setVitesse(const std::array<double, 3>& vit) { vitesse = vit; }
void Particule::setForce(const std::array<double, 3>& frc) { force = frc; }

void Particule::print_particule() const {
    std::cout << std::fixed << std::setprecision(3)  // Format de sortie
              << "Particule ID: " << id 
              << " | Categorie: " << categorie 
              << " | Masse: " << masse << " kg"
              << " | Position: (" << position[0] << ", "
              << position[1] << ", " << position[2] << ")"
              << " | Vitesse: (" << vitesse[0] << ", "
              << vitesse[1] << ", " << vitesse[2] << ")"
              << " | Force: (" << force[0] << ", "
              << force[1] << ", " << force[2] << ")"
              << std::endl;
}
