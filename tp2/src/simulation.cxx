#include "simulation.h"
#include <iostream>
#include <cmath>

// Définir le pas de temps
const double dt = 0.01;

// Calcul de la force gravitationnelle de p2 sur p1
std::array<double, 3> compute_gravity(const Particule& p1, const Particule& p2) {
    std::array<double, 3> force = {0.0, 0.0, 0.0};
    std::array<double, 3> pos1 = p1.getPosition();
    std::array<double, 3> pos2 = p2.getPosition();
    double dx = pos2[0] - pos1[0];
    double dy = pos2[1] - pos1[1];
    double dz = pos2[2] - pos1[2];
    double r2 = dx * dx + dy * dy + dz * dz;

    if (r2 == 0.0) return force;  // Éviter division par zéro

    double r = std::sqrt(r2);
    double f_mag = (p1.getMasse() * p2.getMasse()) / (r2 * r);  // F = m1 * m2 / r^3

    force[0] = f_mag * dx;
    force[1] = f_mag * dy;
    force[2] = f_mag * dz;

    return force;
}

// Calcul des forces totales exercées sur chaque particule
std::vector<std::array<double, 3>> compute_forces(const std::vector<Particule>& particules) {
    size_t n = particules.size();
    std::vector<std::array<double, 3>> forces(n, {0.0, 0.0, 0.0});

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i != j) {
                std::array<double, 3> f = compute_gravity(particules[i], particules[j]);
                forces[i][0] += f[0];
                forces[i][1] += f[1];
                forces[i][2] += f[2];
            }
        }
    }
    return forces;
}

// Simulation utilisant l'intégrateur de Störmer-Verlet
void simulate(std::vector<Particule>& particules, double tmax) {
    double t = 0.0;
    std::vector<std::array<double, 3>> forces = compute_forces(particules);

    while (t < tmax) {
        t += dt;

        // Étape 1 : mise à jour des positions
        for (size_t i = 0; i < particules.size(); ++i) {
            std::array<double, 3> pos = particules[i].getPosition();
            std::array<double, 3> vit = particules[i].getVitesse();
            std::array<double, 3> force = forces[i];
            double m = particules[i].getMasse();

            for (int d = 0; d < 3; ++d) {
                pos[d] += dt * (vit[d] + 0.5 * force[d] / m * dt);
            }
            particules[i].setPosition(pos);
        }

        // Étape 2 : recalcul des nouvelles forces
        std::vector<std::array<double, 3>> new_forces = compute_forces(particules);

        // Étape 3 : mise à jour des vitesses
        for (size_t i = 0; i < particules.size(); ++i) {
            std::array<double, 3> vit = particules[i].getVitesse();
            double m = particules[i].getMasse();

            for (int d = 0; d < 3; ++d) {
                vit[d] += 0.5 * dt * (forces[i][d] + new_forces[i][d]) / m;
            }
            particules[i].setVitesse(vit);
        }

        // Mise à jour des forces pour la prochaine itération
        forces = new_forces;

        // Affichage
        std::cout << "Temps: " << t << " s\n";
        for (const auto& p : particules) {
            p.print_particule();
        }
        std::cout << "-----------------------------\n";
    }
}
