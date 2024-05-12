#include "offreemploi.h"

// Initialize static variable
int OffreEmploi::dernierId = 0;

// Constructor
OffreEmploi::OffreEmploi(int idRecrut) {
    // Increment and assign the ID
    dernierId++;
    idOffre = dernierId;
    this->idRecrut = idRecrut;
}

// Getter for job criteria
vector<string> OffreEmploi::getCritere() const {
    return critere;
}

// Add a job criterion
void OffreEmploi::ajouterCritere(const string& critere) {
    this->critere.push_back(critere);
}

void OffreEmploi::afficher() const{
    auto lescritere = OffreEmploi::getCritere();
    cout << "##### OFFRE D'EMPLOI #####"<< endl;
    cout << "Offre numero: " << idOffre << endl;
    cout << "Offre par recruteur numero: " << idRecrut << endl;
    cout << "Les critere d'offres: " << endl;
    for (auto& crit : lescritere) {
        cout << "#: " << crit << endl;
    }
    cout << "##########################" << endl;

}
// Remove a job criterion
void OffreEmploi::supprimerCritere(const string& critere) {
    // Find the criterion in the vector
    for (auto it = this->critere.begin(); it != this->critere.end(); ++it) {
        if (*it == critere) {
            this->critere.erase(it);
            break;
        }
    }
}

void OffreEmploi::viderCritere() {
    critere.clear();
}

int OffreEmploi::getIdRecrut() const {
    return idRecrut;
}
void OffreEmploi::setIdRecrut(int id) {
    idRecrut = id;
}

int OffreEmploi::getIdOffre() const {
    return idOffre;
}
void OffreEmploi::setIdOffre(int id) {
    idOffre = id;
}