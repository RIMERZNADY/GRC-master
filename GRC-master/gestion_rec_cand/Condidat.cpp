#include "Condidat.h"

int Candidate::dernierId = 0;
// Constructeur
Candidate::Candidate(int id, string nom, string prenom, string email, string password,
    string domaineEtudes, string experienceProfessionnelle)
    : Personne(id, nom, prenom, email, password), domaineEtudes(domaineEtudes),
    experienceProfessionnelle(experienceProfessionnelle) {
    if (id == 0) { // Si l'ID n'est pas spécifié, auto-incrémente
        dernierId++;
        this->id = dernierId;
    }
    else { // Si l'ID est spécifié, met à jour le dernier ID si nécessaire
        dernierId = max(dernierId, id);
    }
    
}

// Getters
string Candidate::getDomaineEtudes() const {
    return domaineEtudes;
}

string Candidate::getExperienceProfessionnelle() const {
    return experienceProfessionnelle;
}

Profil Candidate::getProfil() const {
    return profil;
}

// Setters
void Candidate::setDomaineEtudes(const string& domaineEtudes) {
    this->domaineEtudes = domaineEtudes;
}

void Candidate::setExperienceProfessionnelle(const string& experienceProfessionnelle) {
    this->experienceProfessionnelle = experienceProfessionnelle;
}

void Candidate::setProfil(Profil p) {
    profil = p;
}

void Candidate::afficher() {
    cout << "ID: " << getId() << ", Nom: " << getNom() << ", Prénom: " << getPrenom() << ", Email: " << getEmail() << endl;
    cout << "Domaine d'études: " << domaineEtudes << ", Expérience professionnelle: " << experienceProfessionnelle << endl;
    cout << "Profil: " << profil.getType() << endl;
}

int Candidate::getDernierId() {
    return dernierId;
}