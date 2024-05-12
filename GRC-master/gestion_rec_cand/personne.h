#pragma once
#include <iostream>
using namespace std;

class Personne {
protected:
    int id;
    string nom;
    string prenom;
    string email;
    string password;

public:
    Personne(int = 0, string = "", string = "", string = "", string = "");
    bool authentification(string email, string password);
    virtual void afficher() = 0;

    // Getters
    int getId() const;
    string getNom() const;
    string getPrenom() const;
    string getEmail() const;
    string getPassword() const;

    // Setters
    void setId(int id);
    void setNom(string nom);
    void setPrenom(string prenom);
    void setEmail(string email);
    void setPassword(string password);
};
