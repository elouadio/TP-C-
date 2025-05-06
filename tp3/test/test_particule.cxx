#include "particule.h"
#include "vecteur.h"

int main() {
    Vecteur pos(1.0, 2.0, 3.0);
    Vecteur vit(0.1, 0.2, 0.3);
    Vecteur frc(5.0, 0.0, -2.0);

    Particule p(1, "proton", 1.67e-27, pos, vit, frc);
    p.print_particule();

    return 0;
}
