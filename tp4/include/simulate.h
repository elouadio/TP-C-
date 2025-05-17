#ifndef SIMULATE_H
#define SIMULATE_H

#include "univers.h"
#include "vecteur.h"
#include <vector>

/**
 * @brief Calcule la force de Lennard-Jones entre deux particules
 * 
 * @param p1 Particule 1
 * @param p2 Particule 2
 * @param epsilon Paramètre epsilon de Lennard-Jones
 * @param sigma Paramètre sigma de Lennard-Jones
 * @return Vecteur représentant la force appliquée sur p1 par p2
 */
Vecteur compute_LJ_force(const Particule& p1, const Particule& p2, double epsilon, double sigma);

/**
 * @brief Calcule les forces pour toutes les particules dans l'univers
 * 
 * @param univers L'univers contenant les particules et le maillage
 * @return Un vecteur contenant les forces appliquées sur chaque particule
 */
std::vector<Vecteur> compute_forces(const Univers& univers);

/**
 * @brief Exécute la simulation en utilisant l'algorithme de Störmer-Verlet
 * 
 * @param univers L'univers contenant les particules
 * @param tmax Le temps maximum de simulation
 * @param dt Le pas de temps de la simulation
 */
void simulate(Univers& univers, double tmax, double dt);

#endif // SIMULATE_H
