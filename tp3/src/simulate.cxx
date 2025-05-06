#include "simulate.h"
#include <iostream>
#include <cmath>
#include <vector>

// Définir le pas de temps (dt)
const double dt = 0.01;

// Gravité universelle (force de p2 sur p1)
Vecteur compute_gravity(const Particule& p1, const Particule& p2) {
    Vecteur force(0, 0, 0);
    Vecteur r = p2.getPosition() - p1.getPosition();
    double r2 = r.norme2();

    if (r2 == 0.0) return force;  // Évite division par zéro

    double r_norm = std::sqrt(r2);
    double f_mag = (p1.getMasse() * p2.getMasse()) / (r2 * r_norm);  // F = m1*m2 / r^3
    force = r * f_mag;
    return force;
}

// Calcul de toutes les forces
std::vector<Vecteur> compute_forces(const std::vector<Particule>& particules) {
    size_t n = particules.size();
    std::vector<Vecteur> forces(n, Vecteur(0, 0, 0));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i != j) {
                Vecteur f = compute_gravity(particules[i], particules[j]);
                forces[i] = forces[i] + f;
            }
        }
    }
    return forces;
}

// Simulation complète avec intégrateur de Verlet
void simulate(std::vector<Particule>& particules, double tmax) {
    double t = 0.0;
    std::vector<Vecteur> forces = compute_forces(particules);

    while (t < tmax) {
        t += dt;

        // Étape 1 : mise à jour des positions
        for (size_t i = 0; i < particules.size(); ++i) {
            Vecteur pos = particules[i].getPosition();
            Vecteur vit = particules[i].getVitesse();
            Vecteur f = forces[i];
            double m = particules[i].getMasse();

            pos = pos + vit * dt + (f * (0.5 * dt * dt / m));
            particules[i].setPosition(pos);
        }

        // Étape 2 : recalcul des forces
        std::vector<Vecteur> new_forces = compute_forces(particules);

        // Étape 3 : mise à jour des vitesses
        for (size_t i = 0; i < particules.size(); ++i) {
            Vecteur vit = particules[i].getVitesse();
            double m = particules[i].getMasse();

            Vecteur avg_force = (forces[i] + new_forces[i]) * 0.5;
            vit = vit + avg_force * (dt / m);
            particules[i].setVitesse(vit);
        }

        // Mise à jour pour prochaine itération
        forces = new_forces;

        // Affichage
        std::cout << "Temps: " << t << " s\n";
        for (const auto& p : particules) {
            p.print_particule();
        }
        std::cout << "-----------------------------\n";
    }
}
