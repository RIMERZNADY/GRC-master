// Recruteur.cpp
#include "Recruteur.h"

void Recruteur::publierOffre(const std::string& titre, const std::string& description, const std::vector<std::string>& criteres) {
    // Cr�er une nouvelle instance d'Offre avec les informations fournies
    Offre nouvelleOffre;
    nouvelleOffre.setTitre(titre);
    nouvelleOffre.setDescription(description);
    nouvelleOffre.setCriteres(criteres);

    // Ajouter la nouvelle offre � une liste d'offres disponibles
    offresDisponibles.push_back(nouvelleOffre);
}
