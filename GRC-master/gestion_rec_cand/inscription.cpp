#include "Inscription.h"

Candidat Inscription::sInscrire() {
    // Demandez à l'utilisateur de saisir les informations pour créer un nouveau candidat
    int idC;
    std::string nom, prenom, diplome, specialite, experience;
    int codePostal;

    std::cout << "ID Candidat : ";
    std::cin >> idC;
    std::cout << "Nom : ";
    std::cin >> nom;
    std::cout << "Prenom : ";
    std::cin >> prenom;
    std::cout << "Diplome : ";
    std::cin >> diplome;
    std::cout << "Specialite : ";
    std::cin >> specialite;
    std::cout << "Experience : ";
    std::cin >> experience;
    std::cout << "Code Postal : ";
    std::cin >> codePostal;

    // Créer et retourner un nouvel objet Candidat avec les informations saisies
    return Candidat(idC, nom, prenom, diplome, specialite, experience, codePostal);
}
