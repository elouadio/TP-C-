#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <array>
#include <random>
#include "Particule.h"

int main() {
    // Initialisation du générateur de nombres aléatoires
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist_position(-10.0, 10.0);
    std::uniform_real_distribution<double> dist_vitesse(-5.0, 5.0);
    std::uniform_real_distribution<double> dist_force(-1.0, 1.0);
    std::uniform_real_distribution<double> dist_masse(1e-27, 1e-24);
    std::uniform_int_distribution<int> dist_id(1, 1000);
    std::uniform_int_distribution<int> dist_categorie(0, 2);

    // Test des performances pour différentes tailles
    for (int num_particles = 64; num_particles <= 2048; num_particles *= 2) {
        std::cout << "Test pour " << num_particles << " particules:" << std::endl;

        // Créer un vector et une liste de particules
        std::vector<Particule> particleVector;
        std::list<Particule> particleList;

        // Mesurer le temps pour insérer dans un vector avec insert
        auto start = std::chrono::steady_clock::now();
        for (int i = 0; i < num_particles; ++i) {
            std::array<double, 3> position = {dist_position(mt), dist_position(mt), dist_position(mt)};
            std::array<double, 3> vitesse = {dist_vitesse(mt), dist_vitesse(mt), dist_vitesse(mt)};
            std::array<double, 3> force = {dist_force(mt), dist_force(mt), dist_force(mt)};
            double masse = dist_masse(mt);
            int categorie = dist_categorie(mt);

            // Créer une particule
            Particule p(dist_id(mt), (categorie == 0 ? "electron" : (categorie == 1 ? "proton" : "neutron")), masse, position, vitesse, force);

            // Insérer la particule dans le vector (avant le dernier élément)
            particleVector.insert(particleVector.begin(), p);
        }
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Temps d'insertion dans std::vector avec insert: " << elapsed_seconds.count() << "s\n";

        // Mesurer le temps pour insérer dans une list avec insert
        start = std::chrono::steady_clock::now();
        for (int i = 0; i < num_particles; ++i) {
            std::array<double, 3> position = {dist_position(mt), dist_position(mt), dist_position(mt)};
            std::array<double, 3> vitesse = {dist_vitesse(mt), dist_vitesse(mt), dist_vitesse(mt)};
            std::array<double, 3> force = {dist_force(mt), dist_force(mt), dist_force(mt)};
            double masse = dist_masse(mt);
            int categorie = dist_categorie(mt);

            // Créer une particule
            Particule p(dist_id(mt), (categorie == 0 ? "electron" : (categorie == 1 ? "proton" : "neutron")), masse, position, vitesse, force);

            // Insérer la particule au début de la liste (avant le premier élément)
            particleList.insert(particleList.begin(), p);
        }
        end = std::chrono::steady_clock::now();
        elapsed_seconds = end - start;
        std::cout << "Temps d'insertion dans std::list avec insert: " << elapsed_seconds.count() << "s\n";

        std::cout << "--------------------------------------\n";
    }

    return 0;
}
