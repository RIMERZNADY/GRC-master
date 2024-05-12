#include "Personne.h"

// Constructeur
Personne::Personne(int id, string nom, string prenom, string email, string password)
    : id(id), nom(nom), prenom(prenom), email(email), password(password) {}

// Méthode d'authentification
bool Personne::authentification(string email, string password) {
    return (this->email == email && this->password == password);
}

// Getters
int Personne::getId() const {
    return id;
}

string Personne::getNom() const {
    return nom;
}

string Personne::getPrenom() const {
    return prenom;
}

string Personne::getEmail() const {
    return email;
}

string Personne::getPassword() const {
    return password;
}

// Setters
void Personne::setId(int id) {
    this->id = id;
}

void Personne::setNom(string nom) {
    this->nom = nom;
}

void Personne::setPrenom(string prenom) {
    this->prenom = prenom;
}

void Personne::setEmail(string email) {
    this->email = email;
}

void Personne::setPassword(string password) {
    this->password = password;
}
