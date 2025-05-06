#ifndef PARTICULE_H
#define PARTICULE_H

#include <string>
#include <array>

class Particule {
private:
    int id;
    std::string categorie;
    double masse;
    std::array<double, 3> position;  // x, y, z
    std::array<double, 3> vitesse;   // vx, vy, vz
    std::array<double, 3> force;     // fx, fy, fz

public:
    // Constructeur
    Particule(int identifiant,
              const std::string& cat,
              double m,
              const std::array<double, 3>& pos,
              const std::array<double, 3>& vit,
              const std::array<double, 3>& frc);

    // Accesseurs
    int getId() const;
    std::string getCategorie() const;
    double getMasse() const;
    std::array<double, 3> getPosition() const;
    std::array<double, 3> getVitesse() const;
    std::array<double, 3> getForce() const;

    // Mutateurs
    void setPosition(const std::array<double, 3>& pos);
    void setVitesse(const std::array<double, 3>& vit);
    void setForce(const std::array<double, 3>& frc);
    void print_particule() const;

};

#endif
