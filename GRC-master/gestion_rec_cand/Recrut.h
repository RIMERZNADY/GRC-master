#pragma once
#include "Personne.h"
#include "OffreEmploi.h"
#include "Profil.h";
#include <vector>
class Personne;
class Profile;
class Recrut : public Personne {
private:
    std::string nomEntreprise;
    std::string secteurActivite;
    std::vector<OffreEmploi> offres;
    Profil profil;

public:
    // Constructeur
    Recrut(int id = 0, std::string nom = "", std::string prenom = "", std::string email = "", std::string password = "",
        std::string nomEntreprise = "", std::string secteurActivite = "");

    // Getters
    std::string getNomEntreprise() const;
    std::string getSecteurActivite() const;
    Profil getProfil() const;
    std::vector<OffreEmploi> getOffres() const;

    // Setters
    void setNomEntreprise(std::string nomEntreprise);
    void setSecteurActivite(std::string secteurActivite);
    void setProfil(Profil&);

    // Méthodes pour gérer les offres d'emploi
    void ajouterOffre(const OffreEmploi& offre);
    void supprimerOffre(int idOffre);
    void afficherOffres() const;

    // afficher:
    void afficher() override;
};

