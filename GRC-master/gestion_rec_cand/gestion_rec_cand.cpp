#include <iostream>
#include <string>
#include "Condidat.h"
#include "Recrut.h"
#include "DemandeEmploi.h"
#include "OffreEmploi.h"
#include "Profil.h"
using namespace std;


int main() {
    int choix;
    string email, password;
    bool authentifier = false;

    // Vecteur de candidats
    vector<Candidate> candidats;

    // Vecteur de recruteurs
    vector<Recrut> recruteurs;

    // Vecteur d'offres d'emploi
    vector<OffreEmploi> offresEmploi;

    // Vecteur de demande emploi
    vector<DemandeEmploi> demandesEmploi;

    // Exemple d'ajout d'éléments aux vecteurs
    candidats.push_back(Candidate(101, "Rime", "Znady", "rime@email.com", "rime123", "Informatique", "5 ans d'expérience"));
    recruteurs.push_back(Recrut(201,"recrut1", "prenom1", "recrut1@email.com", "recrut123", "Entreprise A", "Informatique"));

    OffreEmploi offreEmploi(201);

    // Ajout de critères à l'offre d'emploi
    offreEmploi.ajouterCritere("Expérience de travail");
    offreEmploi.ajouterCritere("Maîtrise du C++");
    offreEmploi.ajouterCritere("Bonne communication");
    offresEmploi.push_back(offreEmploi);

    recruteurs[0].ajouterOffre(offreEmploi);
    
    DemandeEmploi demande(101, 2);
    
    while (true)
    {
        cout << "\t#####################################" << endl;
        cout << "\t- Gestion recruteur/candidat -" << endl;
        cout << "\t#####################################" << endl;
        cout << "\tBienvenue ! QUI ETES VOUS:" << endl;
        cout << "\t1. Recruteur" << endl;
        cout << "\t2. Candidat" << endl;
        cout << "\t3. Visiteur" << endl;
        cout << "\t0. Exit" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        if (choix == 0) {
            authentifier = false;
            break;
        }
        else if (choix == 1) { // Recruteur
            cout << "Entrez votre email : ";
            cin >> email;
            cout << "Entrez votre mot de passe : ";
            cin >> password;
            int indexRecruteur = -1;
            for (int i = 0; i < recruteurs.size(); ++i) {
                if (recruteurs[i].authentification(email, password)) {
                    authentifier = true;
                    indexRecruteur = i; 
                    break; 
                }
            }
            if (authentifier) {
                cout << "Authentification réussie en tant que recruteur !" << endl;
                while (true) {
                    cout << "#######################################" << endl;
                    cout << "Bienvenue a votre espace recruteur" << endl;
                    cout << "\t1. Gerer les offres d'emploi" << endl;
                    cout << "\t2. Gerer les demmandes d'emploi" << endl;
                    cout << "\t0. Exit" << endl;
                    cout << "Votre choix : ";
                    cin >> choix;
                    if (choix == 0) {
                        break;
                    }
                    if (choix == 1) {
                       while (true) {

                            cout << "\t1. Consulter les offres d'emploi" << endl;
                            cout << "\t2. Ajouter une offre d'emploi" << endl;
                            cout << "\t3. Modifier une offre d'emploi" << endl;
                            cout << "\t4. Supprimer une offre d'emploi" << endl;
                            cout << "\t0. Exit" << endl;
                            cout << "Votre choix : ";
                            cin >> choix;
                            if (choix == 0) {
                                break;
                            }
                            if (choix == 1) {
                                cout << "\t\t\tafficher les offres: " << endl;
                                for (auto& offre : recruteurs[indexRecruteur].getOffres()) {
                                    offre.afficher();
                                }
                            }
                            if (choix == 2) {
                                int nbr;
                                string valeur;
                                cout << "ajouter une offre d'emploie: " << endl;
                                OffreEmploi offre(recruteurs[indexRecruteur].getId());
                                cout << "combien des critere vous voullez ajouter?: ";
                                cin >> nbr;
                                for (int i = 0; i < nbr; i++) {
                                    cout << "saisire le critere numero " << i << ": ";
                                    cin >> valeur;
                                    offre.ajouterCritere(valeur);
                                }
                                recruteurs[indexRecruteur].ajouterOffre(offre);
                            }
                            if (choix == 3) {
                                int id;
                                cout << "sasir le numero de l'offre: ";
                                cin >> id;
                                for (auto& offre : recruteurs[indexRecruteur].getOffres()) {
                                    if (offre.getIdOffre() == id) {
                                        offre.viderCritere();
                                        int nbr;
                                        string valeur;
                                        cout << "ajouter un offre d'emploie: " << endl;
                                        OffreEmploi offre(recruteurs[indexRecruteur].getId());
                                        cout << "combien des critere vous voullez ajouter?: ";
                                        cin >> nbr;
                                        for (int i = 0; i < nbr; i++) {
                                            cout << "saisire le critere numero " << i << ": ";
                                            cin >> valeur;
                                            offre.ajouterCritere(valeur);
                                        }
                                        break;
                                    }
                                }
                            }
                            if (choix == 4) {
                                int id;
                                cout << "sasir le numero d' offre: ";
                                cin >> id;
                                recruteurs[indexRecruteur].supprimerOffre(id);
                                cout << "offre est bien supprimer" << endl;
                            }
                       }
                    }
                    if (choix == 2) {
                        while (true) {
                            cout << "\t1. Consulter les demmandes d'emploi" << endl;
                            cout << "\t2. Gerer une demmande d'emploi" << endl;
                            cout << "\t0. Exit" << endl;
                            cout << "Votre choix : ";
                            cin >> choix;
                            if (choix == 0) {
                                break;
                            }
                            if (choix == 1) {
                                cout << endl << "consulter les demmandes d'emploi" << endl;
                                for (auto& offre : recruteurs[indexRecruteur].getOffres()) {
                                    cout << "les demmande pour l'offre: " << offre.getIdOffre() << endl;
                                    for (auto& demande : demandesEmploi) {
                                        if (demande.getIdOffre() == offre.getIdOffre() ) {
                                            auto condidat = demande.getCondidat();
                                            condidat.afficher();
                                        }
                                    }
                                }   
                            }
                            if (choix == 2) {
                                int idoffre, idcondidat, decission;
                                cout << "saisir le numero d'offre: ";
                                cin >> idoffre;
                                cout << "saisir le numero de condidat: ";
                                cin >> idcondidat;
                                for (auto& demande : demandesEmploi) {
                                    if (demande.getIdOffre() == idoffre && demande.getIdCondidat() == idcondidat ) {
                                        cout << "votre decission? (1 pour approuver, 0 pour refuser): ";
                                        cin >> decission;
                                        demande.setStatus(decission == 1);
                                        break;
                                    }
                                }

                            }
                        }
                    }
                    if (choix == 3) {
                        cout << "\t1. Consulter les Criteres" << endl;
                        cout << "\t2. Ajouter un Critere" << endl;
                        cout << "\t3. Modifier un Critere" << endl;
                        cout << "\t4. Supprimer un Critere" << endl;
                        cout << "\t0. Exit" << endl;
                        cout << "Votre choix : ";
                        cin >> choix;
                        if (choix == 0) {
                            break;
                        }
                    }

                }
            }
            else {
                cout << "Email ou mot de passe incorrect. Veuillez réessayer." << endl;
            }
        }
        else if (choix == 2) {
            cout << "Entrez votre email : ";
            cin >> email;
            cout << "Entrez votre mot de passe : ";
            cin >> password;
            int indexCandidat = -1;
            for (size_t i = 0; i < candidats.size(); ++i) {
                if (candidats[i].authentification(email, password)) {
                    authentifier = true;
                    indexCandidat = i;
                    break;
                }
            }
            if (authentifier) {
                cout << "Authentification réussie en tant que candidat !" << endl;
                while (true) {
                    cout << "#######################################" << endl;
                    cout << "Bienvenue a votre espace candidat" << endl;
                    cout << "\t1. Gerer profil" << endl;
                    cout << "\t2. Consulter offres d'emploi" << endl;
                    cout << "\t0. Quitter" << endl;
                    cout << "Votre choix : ";
                    cin >> choix;
                    if (choix == 0) {
                        authentifier = false;
                        break;
                    }
                    if (choix == 1) {
                        while (true && authentifier) {

                            cout << "\t1. Consulter profil" << endl;
                            cout << "\t2. Modifier profil" << endl;
                            cout << "\t3. Supprimer profil" << endl;
                            cout << "\t0. Quitter" << endl;
                            cout << "Votre choix : ";
                            cin >> choix;
                            if (choix == 0) {
                                break;
                            }
                            if (choix == 1) {
                                candidats[indexCandidat].afficher();
                            }
                            if (choix == 2) {
                                string nom, prenom, email, password, domain, experience;
                                cout << "modifier votre Profil: " << endl;
                                cout << "modifier votre nom: ";
                                cin >> nom;
                                candidats[indexCandidat].setNom(nom);
                                cout << "modifier votre prenom: ";
                                cin >> prenom;
                                candidats[indexCandidat].setPrenom(prenom);
                                cout << "modifier votre email: ";
                                cin >> email;
                                candidats[indexCandidat].setEmail(email);
                                cout << "modifier votre motdepass: ";
                                cin >> password;
                                candidats[indexCandidat].setPassword(password);
                                cout << "modifier votre domain: ";
                                cin >> domain;
                                candidats[indexCandidat].setDomaineEtudes(domain);
                                cout << "modifier votre experience: ";
                                cin >> experience;
                                candidats[indexCandidat].setExperienceProfessionnelle(experience);
                            }
                            if (choix == 3) {
                                authentifier = false;
                                break;
                            }
                        }
                    }
                    if (choix == 2) {
                        while (true) {

                            cout << "\t1. Afficher touts les offres" << endl;
                            cout << "\t2. Postuler a une offre" << endl;
                            cout << "\t3. Consulter mes demandes d'emploi" << endl;
                            cout << "\t0. Quitter" << endl;
                            cout << "Votre choix : ";
                            cin >> choix;
                            if (choix == 0) {
                                break;
                            }
                            if (choix == 1) {
                                cout << endl << "liste des offre emploi: " << endl;
                                for (auto& recrut : recruteurs) {
                                    cout << "offre de recruteur: " << recrut.getNom() << " numero: " << recrut.getId() << endl;
                                    cout << "##########" << endl;
                                    recrut.afficherOffres();
                                    cout << "##########" << endl;
                                }
                            }
                            if (choix == 2) {
                                int id;
                                cout << "saisir le numero d'offre d'emploi: ";
                                cin >> id;
                                DemandeEmploi  d(candidats[indexCandidat].getId(), id);
                                d.setCondidat(candidats[indexCandidat]);
                                demandesEmploi.push_back(d);
                            }
                            if (choix == 3) {
                                cout << endl << "mes demande d'emploi: " << endl;
                                for (auto& demande : demandesEmploi) {
                                    demande.afficher();
                                }
                            }
                        }
                    }
                }
            }
            else {
                cout << "Email ou mot de passe incorrect. Veuillez réessayer." << endl;
            }
        }
        if (choix == 3) {
            cout << "Bienvenue a l'application: " << endl;
            while (true) {
                cout << "#######################################" << endl;
                cout << "\t1. Consulter les offres d'emploi" << endl;
                cout << "\t2. S'inscrire comme un condidat" << endl;
                cout << "\t0. Quitter" << endl;
                cout << "Votre choix : ";
                cin >> choix;
                if (choix == 0) {
                    break;
                }
                if (choix == 1) {
                    cout << endl << "liste des offre emploie: " << endl;
                    for (auto& recrut : recruteurs) {
                        cout << "offre de recruteur: " << recrut.getNom() << " numero: " << recrut.getId() << endl;
                        cout << "##########" << endl;
                        recrut.afficherOffres();
                        cout << "##########" << endl;
                    }
                }
                if (choix == 2) {
                    cout << "S'inscrire :" << endl;
                    string nom, prenom, email, password, domain, experience;
                    cout << "saisir votre nom: ";
                    cin >> nom;
                    cout << "saisir votre prenom: ";
                    cin >> prenom;
                    cout << "saisir votre email: ";
                    cin >> email;
                    cout << "saisir votre motdepass: ";
                    cin >> password;
                    cout << "saisir votre domain: ";
                    cin >> domain;
                    cout << "saisir votre experience: ";
                    cin >> experience;
                    Candidate condidat(0, nom, prenom, email, password, domain, experience);
                    candidats.push_back(condidat);
                    cout << "compte cree vous pouvez vous authentifier en tant que candidat" << endl;

                }
            }
        }
    }

    return 0;
}
