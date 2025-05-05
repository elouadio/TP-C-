#include <iostream>
#include <list>
#include <array>
#include <random>
#include "Particule.h"

int main() {
    // Initialisation du générateur de nombres aléatoires
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist_position(-10.0, 10.0);  // Pour les positions dans l'intervalle [-10, 10]
    std::uniform_real_distribution<double> dist_vitesse(-5.0, 5.0);    // Pour les vitesses dans l'intervalle [-5, 5]
    std::uniform_real_distribution<double> dist_force(-1.0, 1.0);      // Pour les forces dans l'intervalle [-1, 1]
    std::uniform_real_distribution<double> dist_masse(1e-27, 1e-24);    // Pour les masses (en kg)
    std::uniform_int_distribution<int> dist_id(1, 1000);               // Identifiant unique aléatoire entre 1 et 1000
    std::uniform_int_distribution<int> dist_categorie(0, 2);           // Categorie (0=electron, 1=proton, 2=neutron)

    // Collection de particules (utilisation de list au lieu de vector)
    std::list<Particule> particleList;

    // Générer 100 particules avec des valeurs aléatoires
    for (int i = 0; i < 100; ++i) {
        std::array<double, 3> position = {dist_position(mt), dist_position(mt), dist_position(mt)};
        std::array<double, 3> vitesse = {dist_vitesse(mt), dist_vitesse(mt), dist_vitesse(mt)};
        std::array<double, 3> force = {dist_force(mt), dist_force(mt), dist_force(mt)};
        
        // Masse et catégorie aléatoires
        double masse = dist_masse(mt);
        int categorie = dist_categorie(mt);
        
        // Créer une particule avec un ID unique et des valeurs aléatoires
        Particule p(dist_id(mt), (categorie == 0 ? "electron" : (categorie == 1 ? "proton" : "neutron")), masse, position, vitesse, force);

        // Utilisation de insert pour ajouter au début (inversion de l'ordre d'insertion)
        particleList.insert(particleList.begin(), p);
    }

    // Afficher les 10 premières particules avec un itérateur explicite
    std::cout << "Affichage des 10 premières particules générées avec un itérateur explicite:\n";
    int count = 0;
    for (auto it = particleList.begin(); it != particleList.end(); ++it) {
        it->print_particule();  // Utilisation de l'itérateur pour accéder à chaque particule
        count++;
        if (count == 10) break; // Afficher seulement les 10 premières particules
    }

    return 0;
}
