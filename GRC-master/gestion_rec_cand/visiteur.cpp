#include "Visiteur.h"

void Visiteur::consulterOffres(std::vector<Offre>& offres) {
    // Afficher la liste des offres disponibles
    std::cout << "Liste des offres disponibles : " << std::endl;
    for (const Offre& offre : offres) {
        std::cout << "ID : " << offre.getId() << " - " << offre.getDescription() << std::endl;
    }

    // Demander à l'utilisateur de saisir l'ID de l'offre à consulter
    int idOffre;
    std::cout << "Veuillez saisir l'ID de l'offre que vous souhaitez consulter : ";
    std::cin >> idOffre;

    // Rechercher l'offre dans la liste des offres
    bool trouve = false;
    for (const Offre& offre : offres) {
        if (offre.getId() == idOffre) {
            // Afficher les détails de l'offre si elle est trouvée
            std::cout << "Détails de l'offre : " << std::endl;
            std::cout << "Titre : " << offre.getTitre() << std::endl;
            std::cout << "Description : " << offre.getDescription() << std::endl;
            std::cout << "Critères : ";
            for (const std::string& critere : offre.getCriteres()) {
                std::cout << critere << ", ";
            }
            std::cout << std::endl;
            trouve = true;
            break;
        }
    }

    // Afficher un message si l'offre n'est pas trouvée
    if (!trouve) {
        std::cout << "L'offre avec l'ID " << idOffre << " n'a pas été trouvée." << std::endl;
    }
}
