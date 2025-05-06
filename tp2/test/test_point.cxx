#include <iostream>
#include "Particule.h"

int main() {
    std::array<double, 3> pos = {0.0, 0.0, 0.0};
    std::array<double, 3> vit = {1.0, 1.0, 1.0};
    std::array<double, 3> frc = {0.0, 0.0, 0.0};

    Particule p1= Particule(1, "electron", 9.11e-31, pos, vit, frc);

    p1.print_particule();

    return 0;
}
