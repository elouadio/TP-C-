#ifndef SIMULATE_H
#define SIMULATE_H

#include "univers.h"
#include "vecteur.h"
#include "particule.h"
#include <vector>

/**
 * Calcul de la force de Lennard-Jones
 * @param p1 : Particule 1
 * @param p2 : Particule 2
 * @param epsilon : Propriété du potentiel de Lennard-Jones
 * @param sigma : Propriété du potentiel de Lennard-Jones
 * @return La force de Lennard-Jones appliquée
 */
Vecteur compute_LJ_force(const Particule& p1, const Particule& p2, double epsilon, double sigma);

/**
 * Calcul des forces dans l'Univers
 * @param univers : L'univers contenant les particules et le maillage
 * @return Un vecteur contenant les forces appliquées sur chaque particule
 */
std::vector<Vecteur> compute_forces(const Univers& univers);

/**
 * Simulation du déplacement des particules dans l'univers
 * en utilisant l'algorithme de Störmer-Verlet.
 * @param univers : L'univers à simuler
 * @param tmax : Temps maximal de la simulation
 */
void simulate(Univers& univers, double tmax);

#endif // SIMULATE_H
