#pragma once
#include <iostream>
#include <vector>
using namespace std;

class OffreEmploi {
private:
    static int dernierId;
    int idOffre;
    int idRecrut;
    vector<string> critere;

public:
    // Constructor
    OffreEmploi(int id=0);

    // Getter for job criteria
    vector<string> getCritere() const;
    int getIdOffre() const;
    void setIdOffre(int id);
    int getIdRecrut() const;
    void setIdRecrut(int id);
    // Add a job criterion
    void ajouterCritere(const string& critere);

    // Remove a job criterion
    void supprimerCritere(const string& critere);

    // vider les critere
    void viderCritere();
    void afficher() const;
};


