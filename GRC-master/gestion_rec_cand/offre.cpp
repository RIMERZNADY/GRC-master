#include "offre.h"

const std::vector<std::string>& Offre::getCriteres() const {
    return criteres;
}

int Offre::getId() const {
    return idOffre;
}

const std::string& Offre::getTitre() const {
    return titre;
}

const std::string& Offre::getDescription() const {
    return description;
}

Offre Offre::ajouterOffre(int idOffre, const std::string& titre, const std::string& description, const std::vector<std::string>& criteres) {
    Offre nouvelleOffre;
    nouvelleOffre.setId(idOffre);
    nouvelleOffre.setTitre(titre);
    nouvelleOffre.setDescription(description);
    nouvelleOffre.setCriteres(criteres);
    return nouvelleOffre;
}

void Offre::setId(int id) {
    idOffre = id;
}

void Offre::setTitre(const std::string& titre) {
    this->titre = titre;
}

void Offre::setDescription(const std::string& description) {
    this->description = description;
}

void Offre::setCriteres(const std::vector<std::string>& criteres) {
    this->criteres = criteres;
}

bool Offre::supprimerOffre(std::vector<Offre>& offres, int idOffre) {
    for (auto it = offres.begin(); it != offres.end(); ++it) {
        if (it->getId() == idOffre) {
            offres.erase(it);
            return true;
        }
    }
    return false;
}

bool Offre::modifierOffre(std::vector<Offre>& offres, int idOffre, const std::string& nouveauTitre, const std::string& nouvelleDescription, const std::vector<std::string>& nouveauxCriteres) {
    for (auto& offre : offres) {
        if (offre.getId() == idOffre) {
            offre.setTitre(nouveauTitre);
            offre.setDescription(nouvelleDescription);
            offre.setCriteres(nouveauxCriteres);
            return true;
        }
    }
    return false;
}
