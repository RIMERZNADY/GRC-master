#pragma once
#include "Personne.h"
#include "Profil.h"

class Candidate : public Personne {
private:
    static int dernierId;
    string domaineEtudes;
    string experienceProfessionnelle;
    Profil profil;

public:
    // Constructeur
    Candidate(int id = 0, string nom = "", string prenom = "", string email = "", string password = "",
        string domaineEtudes = "", string experienceProfessionnelle = "");

    // Getters
    string getDomaineEtudes() const;
    string getExperienceProfessionnelle() const;
    Profil getProfil() const;

    // Setters
    void setDomaineEtudes(const string& domaineEtudes);
    void setExperienceProfessionnelle(const string& experienceProfessionnelle);
    void setProfil(Profil p);

    // Afficher
    void afficher();

    // Méthode pour récupérer le dernier ID
    static int getDernierId();
};
