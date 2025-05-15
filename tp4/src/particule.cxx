#include "particule.h"
#include <iostream>
#include <iomanip>
#include "vecteur.h"

using namespace std;

// Constructeur
Particule::Particule(int identifiant,
                     const string& cat,
                     double m,
                     const Vecteur& pos,
                     const Vecteur& vit,
                     const Vecteur& frc)
    : id(identifiant), categorie(cat), masse(m),
      position(pos), vitesse(vit), force(frc) {}

// Accesseurs
int Particule::getId() const { return id; }
string Particule::getCategorie() const { return categorie; }
double Particule::getMasse() const { return masse; }
Vecteur Particule::getPosition() const { return position; }
Vecteur Particule::getVitesse() const { return vitesse; }
Vecteur Particule::getForce() const { return force; }

// Mutateurs
void Particule::setPosition(const Vecteur& pos) { position = pos; }
void Particule::setVitesse(const Vecteur& vit) { vitesse = vit; }
void Particule::setForce(const Vecteur& frc) { force = frc; }
void Particule::setId(int newId) {
    id = newId;
}
// Affichage
void Particule::print_particule() const {
    cout << fixed << setprecision(3)
         << "Particule ID: " << id
         << " | Categorie: " << categorie
         << " | Masse: " << masse << " kg"
         << " | Position: "; position.afficher();
    cout << " | Vitesse: "; vitesse.afficher();
    cout << " | Force: "; force.afficher();
    cout << endl;
}
