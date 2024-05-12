#include "Recrut.h"
using namespace std;
// Constructeur
Recrut::Recrut(int id, string nom, string prenom, string email, string password,
    string nomEntreprise, string secteurActivite)
    : Personne(id, nom, prenom, email, password), nomEntreprise(nomEntreprise),
    secteurActivite(secteurActivite) {}

// Getters
string Recrut::getNomEntreprise() const {
    return nomEntreprise;
}

string Recrut::getSecteurActivite() const {
    return secteurActivite;
}

Profil Recrut::getProfil() const {
    return profil;
}

std::vector<OffreEmploi> Recrut::getOffres() const {
    return offres;
}

// Setters
void Recrut::setNomEntreprise(string nomEntreprise) {
    this->nomEntreprise = nomEntreprise;
}

void Recrut::setSecteurActivite(string secteurActivite) {
    this->secteurActivite = secteurActivite;
}

void Recrut::setProfil(Profil& p) {
    profil = p;
}

// Ajouter une offre d'emploi
void Recrut::ajouterOffre(const OffreEmploi& offre) {
    offres.push_back(offre);
}

// Supprimer une offre d'emploi
void Recrut::supprimerOffre(int idOffre) {
    // Recherche de l'offre dans le vecteur
    for (auto it = offres.begin(); it != offres.end(); ++it) {
        if (it->getIdOffre() == idOffre) {
            offres.erase(it);
            break;
        }
    }
}

// Afficher les offres d'emploi
void Recrut::afficherOffres() const {
    cout << "Offres d'emploi pour " << nomEntreprise << ":" << endl;
    for (auto& offre : offres) {
        offre.afficher();
    }
}


void Recrut::afficher() {
    std::cout << "ID: " << getId() << ", Nom: " << getNom() << ", Prénom: " << getPrenom() << ", Email: " << getEmail() << std::endl;
    std::cout << "Nom de l'entreprise: " << nomEntreprise << ", Secteur d'activité: " << secteurActivite << std::endl;
    std::cout << "Profil: " << profil.getType() << std::endl;
}