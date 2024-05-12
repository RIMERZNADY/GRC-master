#include "Profil.h"

// Constructeur
Profil::Profil(int id, string type) : id(id), type(type) {}

// Getters
int Profil::getId() const {
    return id;
}

string Profil::getType() const {
    return type;
}

// Setters
void Profil::setId(int id) {
    this->id = id;
}

void Profil::setType(string type) {
    this->type = type;
}
