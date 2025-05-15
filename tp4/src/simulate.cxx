#include "simulate.h"
#include "univers.h"
#include <iostream>
#include <cmath>
#include <vector>

const double dt = 0.005;

using namespace std;

/**
 * Calcul de la force de Lennard-Jones
 */
Vecteur compute_LJ_force(const Particule& p1, const Particule& p2, double epsilon, double sigma) {
    Vecteur force(0, 0, 0);
    Vecteur r_ij = p2.getPosition() - p1.getPosition();
    double r2 = r_ij.norme2();

    if (r2 == 0.0) return force; // Évite la division par zéro

    double r = sqrt(r2);
    double sr6 = pow(sigma / r, 6);
    double coeff = (24 * epsilon / r2) * sr6 * (1 - 2 * sr6);
    force = r_ij * coeff;

    return force;
}

/**
 * Mise à jour des forces avec le maillage
 */
std::vector<Vecteur> compute_forces(const Univers& univers) {
    const auto& grille = univers.getGrille();
    const double epsilon = univers.getEpsilon();
    const double sigma = univers.getSigma();

    size_t n = univers.getParticules().size();
    std::vector<Vecteur> forces(n, Vecteur(0, 0, 0));

    for (int x = 0; x < univers.getNcdX(); ++x) {
        for (int y = 0; y < univers.getNcdY(); ++y) {
            for (int z = 0; z < univers.getNcdZ(); ++z) {
                
                auto& current_cell = grille[x][y][z].particules;

                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        for (int dz = -1; dz <= 1; ++dz) {
                            int nx = x + dx;
                            int ny = y + dy;
                            int nz = z + dz;

                            if (nx >= 0 && nx < univers.getNcdX() &&
                                ny >= 0 && ny < univers.getNcdY() &&
                                nz >= 0 && nz < univers.getNcdZ()) {

                                auto& neighbor_cell = grille[nx][ny][nz].particules;

                                for (auto* p1 : current_cell) {
                                    for (auto* p2 : neighbor_cell) {
                                        if (p1 != p2) {
                                            Vecteur f = compute_LJ_force(*p1, *p2, epsilon, sigma);
                                            forces[p1->getId()] = forces[p1->getId()] + f;
                                            forces[p2->getId()] = forces[p2->getId()] - f;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return forces;
}

/**
 * Simulation avec Störmer-Verlet en utilisant le maillage
 * Les particules évoluent librement sans contrainte.
 */
void simulate(Univers& univers, double tmax) {
    double t = 0.0;
    auto& particules = univers.getParticules();
    std::vector<Vecteur> forces = compute_forces(univers);

    while (t < tmax) {
        t += dt;

        // 🔹 Mise à jour des positions
        cout << "➡️ Mise à jour des positions à t = " << t << endl;
        for (auto& p : particules) {
            Vecteur pos = p.getPosition();
            Vecteur vit = p.getVitesse();
            Vecteur f = forces[p.getId()];
            double m = p.getMasse();

            // Calcul de la nouvelle position
            pos = pos + vit * dt + (f * (0.5 * dt * dt / m));

            // 🔸 Aucune contrainte, les particules sortent si nécessaire
            p.setPosition(pos);
            p.setVitesse(vit);

            cout << "Particule " << p.getId() << " : (" 
                 << pos.getX() << ", " 
                 << pos.getY() << ", " 
                 << pos.getZ() << ")\n";
        }

        // 🔹 Mise à jour du maillage
        univers.mettreAJourMaillage();

        // 🔹 Recalcul des forces
        forces = compute_forces(univers);

        // 🔹 Mise à jour des vitesses
        for (auto& p : particules) {
            Vecteur vit = p.getVitesse();
            double m = p.getMasse();
            Vecteur avg_force = forces[p.getId()];
            vit = vit + avg_force * (dt / m);
            p.setVitesse(vit);
        }

        cout << "-----------------------------\n";
    }
}
