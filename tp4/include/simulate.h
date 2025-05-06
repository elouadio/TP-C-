#ifndef SIMULATE_H
#define SIMULATE_H

#include <vector>
#include "particule.h"
#include "vecteur.h"

void simulate(std::vector<Particule>& particules,
              double tmax,
              double rcut,
              double epsilon,
              double sigma);

#endif
