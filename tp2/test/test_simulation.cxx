#include "particule.h"
#include "simulation.h"
#include <vector>
#include <array>

int main() {
    // Définir les paramètres communs
    double t_end = 468.5;

    // Création des particules avec : ID, catégorie, masse, position, vitesse, force initiale (0)
    Particule soleil(0, "Soleil", 1.0,
                     {0.0, 0.0, 0.0},
                     {0.0, 0.0, 0.0},
                     {0.0, 0.0, 0.0});

    Particule terre(1, "Terre", 3.0e-6,
                    {0.0, 1.0, 0.0},
                    {-1.0, 0.0, 0.0},
                    {0.0, 0.0, 0.0});

    Particule jupiter(2, "Jupiter", 9.55e-4,
                      {0.0, 5.36, 0.0},
                      {-0.425, 0.0, 0.0},
                      {0.0, 0.0, 0.0});

    Particule haley(3, "Haley", 1.0e-14,
                    {34.75, 0.0, 0.0},
                    {0.0, 0.0296, 0.0},
                    {0.0, 0.0, 0.0});

    // Créer un vecteur de particules
    std::vector<Particule> systeme = {soleil, terre, jupiter, haley};

    // Lancer la simulation
    simulate(systeme, t_end);

    return 0;
}
