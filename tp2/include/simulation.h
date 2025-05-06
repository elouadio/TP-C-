#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <array>
#include "particule.h"

// Calcule la force gravitationnelle exercée par p2 sur p1
std::array<double, 3> compute_gravity(const Particule& p1, const Particule& p2);

// Calcule les forces totales exercées sur chaque particule
std::vector<std::array<double, 3>> compute_forces(const std::vector<Particule>& particules);

// Lance la simulation avec un pas de temps dt jusqu'à tmax
void simulate(std::vector<Particule>& particules, double tmax);

#endif // SIMULATION_H
