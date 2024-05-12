#ifndef VISITEUR_H
#define VISITEUR_H

#include <iostream>
#include <vector>
#include "Offre.h" // Inclure la définition de la classe Offre
#include "Inscription.h" // Inclure la définition de la classe Inscription

class Visiteur {
private:
    int idV;
    Inscription inscription;

public:
    void consulterOffres(std::vector<Offre>& offres);
};

#endif // VISITEUR_H
