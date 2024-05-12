// Recruteur.h
#ifndef RECRUTEUR_H
#define RECRUTEUR_H

#include <vector>
#include "Offre.h"

class Recruteur {
private:
    std::vector<Offre> offresDisponibles;

public:
    void publierOffre(const std::string& titre, const std::string& description, const std::vector<std::string>& criteres);
};

#endif // RECRUTEUR_H
