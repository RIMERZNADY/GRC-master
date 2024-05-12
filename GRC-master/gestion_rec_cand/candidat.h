#pragma once
#ifndef CANDIDAT_H
#define CANDIDAT_H

#include <string>
#include "Personne.h" 

class Candidat : public Personne {
private:
    int IdC;
    std::string nom;
    std::string prenom;
    std::string diplome;
    std::string specialite;
    std::string experience;
    int code_postal;

public:
    // ------------------------------------Constructeur par défaut-------------------------------------------------------
    Candidat();

    // -----------------------------------Constructeur avec paramètres---------------------------------------------------
    Candidat(int idC, const std::string& nom, const std::string& prenom, const std::string& diplome, const std::string& specialite, const std::string& experience, int codePostal);

    // -----------------------------------Méthode d'authentification------------------------------------------------------
    bool authentification(std::string email, std::string password) override;

    
    void postulerOffre(const std::string& nom, const std::string& prenom, const std::string& diplome, const std::string& specialite, const std::string& experience, int codePostal, int idOffre);

    
    std::string getNom() const { return nom; }
    std::string getPrenom() const { return prenom; }
    std::string getDiplome() const { return diplome; }
    std::string getSpecialite() const { return specialite; }
    std::string getExperience() const { return experience; }
    int getCodePostal() const { return code_postal; }

   
    void setNom(const std::string& nom) { this->nom = nom; }
    void setPrenom(const std::string& prenom) { this->prenom = prenom; }
    void setDiplome(const std::string& diplome) { this->diplome = diplome; }
    void setSpecialite(const std::string& specialite) { this->specialite = specialite; }
    void setExperience(const std::string& experience) { this->experience = experience; }
    void setCodePostal(int codePostal) { this->code_postal = codePostal; }
};

#endif // CANDIDAT_H
