#include "DemandeEmploi.h"
#include <iostream>

// Constructeur
DemandeEmploi::DemandeEmploi(int idCondidat, int idOffre)
    : idCondidat(idCondidat), idOffre(idOffre), status(false) {}

// Getters
int DemandeEmploi::getIdCondidat() const {
    return idCondidat;
}

int DemandeEmploi::getIdOffre() const {
    return idOffre;
}

bool DemandeEmploi::getStatus() const {
    return status;
}

// Setters
void DemandeEmploi::setIdCondidat(int idCondidat) {
    this->idCondidat = idCondidat;
}

void DemandeEmploi::setIdOffre(int idOffre) {
    this->idOffre = idOffre;
}

void DemandeEmploi::setStatus(bool status) {
    this->status = status;
}

// Afficher les détails de la demande d'emploi
void DemandeEmploi::afficher() const {
    std::cout << "ID Candidat: " << idCondidat << ", ID Offre: " << idOffre << ", Status: " << (status ? "Acceptée" : "En attente") << std::endl;
}

Candidate DemandeEmploi::getCondidat() const {
    return condidat;
}

void DemandeEmploi::setCondidat(Candidate& c) {
    condidat = c;
}