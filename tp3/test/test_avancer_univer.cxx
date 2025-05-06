#include "univers.h"
#include "simulate.h"

int main() {
    Univers u(3);
    u.initialiserCube(2);  // Crée 5^3 = 125 particules

    u.avancer(0.01, 0.1);  // Avance la simulation de 0 à 0.1 sec avec dt = 0.01

    return 0;
}
