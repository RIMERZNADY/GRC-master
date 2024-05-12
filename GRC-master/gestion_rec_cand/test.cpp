#include <iostream>
#include <string>
using namespace std;

class Recruteur {
private:
    int id;
    string nom;
    string prenom;
    string email;
    string password;

public:
    Recruteur(int id, const string& nom, const string& prenom, const string& email, const string& password);
    bool authentifier(const string& email, const string& password) const;
};

Recruteur::Recruteur(int id, const string& nom, const string& prenom, const string& email, const string& password)
    : id(id), nom(nom), prenom(prenom), email(email), password(password) {}

bool Recruteur::authentifier(const string& email, const string& password) const {
    return (this->email == email && this->password == password);
}

class Candidat {
private:
    int id;
    string nom;
    string prenom;
    string email;
    string password;

public:
    Candidat(int id, const string& nom, const string& prenom, const string& email, const string& password);
    bool authentifier(const string& email, const string& password) const;
};

Candidat::Candidat(int id, const string& nom, const string& prenom, const string& email, const string& password)
    : id(id), nom(nom), prenom(prenom), email(email), password(password) {}

bool Candidat::authentifier(const string& email, const string& password) const {
    return (this->email == email && this->password == password);
}

int test() {
    int choix;
    string email, password;
    Recruteur recrut(1, "nom1", "prenom1", "recruteur@email.com", "recrut123");
    Candidat condidat1(12, "Znady", "Rime", "rime@email.com", "rime123");

    while (true)
    {
        cout << "\t************************************" << endl;
        cout << "\t- Gestion recruteur/candidat -" << endl;
        cout << "\t************************************" << endl;
        cout << "\tBienvenue ! Veuillez selectionner votre role :" << endl;
        cout << "\t1. Recruteur" << endl;
        cout << "\t2. Candidat" << endl;
        cout << "\t3. Visiteur" << endl;
        cout << "\t0. Quitter Programme" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        if (choix == 0) {
            break;
        }
        else if (choix == 1) {
            cout << "Entrez votre email : ";
            cin >> email;
            cout << "Entrez votre mot de passe : ";
            cin >> password;
            if (recrut.authentifier(email, password)) {
                cout << "Authentification réussie en tant que recruteur !" << endl;
                while (true) {
                    cout << "\t1. Gerer les offres d'emploi" << endl;
                    cout << "\t2. Gerer les demmandes d'emploi" << endl;
                    cout << "\t3. Poser Les criteres" << endl;
                    cout << "\t0. Quitter" << endl;
                    cout << "Votre choix : ";
                    cin >> choix;
                    if (choix == 1) {
                        cout << "\t1. Consulter les offres d'emploi" << endl;
                        cout << "\t2. Ajouter un offre d'emploi" << endl;
                        cout << "\t3. Modifier un offre d'emploi" << endl;
                        cout << "\t4. Supprimer un offre d'emploi" << endl;
                        cout << "\t0. Quitter" << endl;
                        cout << "Votre choix : ";
                        cin >> choix;
                        if (choix == 0) {
                            break;
                        }
                    }
                    if (choix == 2) {
                        cout << "\t1. Consulter les Demmandes d'emploi" << endl;
                        cout << "\t2. Aprouver un Demmande d'emploi" << endl;
                        cout << "\t3. Refuser un Demmande d'emploi" << endl;
                        cout << "\t0. Quitter" << endl;
                        cout << "Votre choix : ";
                        cin >> choix;
                        if (choix == 0) {
                            break;
                        }
                    }
                    if (choix == 3) {
                        cout << "\t1. Consulter les Criteres" << endl;
                        cout << "\t2. Ajouter un Critere" << endl;
                        cout << "\t3. Modifier un Critere" << endl;
                        cout << "\t4. Supprimer un Critere" << endl;
                        cout << "\t0. Quitter" << endl;
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
            if (condidat1.authentifier(email, password)) {
                cout << "Authentification réussie en tant que candidat !" << endl;
                while (true) {
                    cout << "\t1. Gerer profil" << endl;
                    cout << "\t2. Consulter offres d'emploi" << endl;
                    cout << "\t0. Quitter" << endl;
                    cout << "Votre choix : ";
                    cin >> choix;
                    if (choix == 0) {
                        break;
                    }
                }
                if (choix == 1) {
                    cout << "\t1. Modifier profil" << endl;
                    cout << "\t2. Consulter profil" << endl;
                    cout << "\t3. Supprimer profil" << endl;
                    cout << "\t0. Quitter" << endl;
                    cout << "Votre choix : ";
                    cin >> choix;
                    if (choix == 0) {
                        break;
                    }
                }
                if (choix == 2) {
                    cout << "\t1. Afficher touts les offres" << endl;
                    cout << "\t2. Postuler a une offre" << endl;
                    cout << "\t0. Quitter" << endl;
                    cout << "Votre choix : ";
                    cin >> choix;
                    if (choix == 0) {
                        break;
                    }
                }
            }
            else {
                cout << "Email ou mot de passe incorrect. Veuillez réessayer." << endl;
            }
        }
        if (choix == 3) {
            while (true) {
                cout << "Bienvenue a l'application: " << endl;
                cout << "\t1. Consulter les offres d'emploi" << endl;
                cout << "\t2. S'inscrire comme un condidat" << endl;
                cout << "\t0. Quitter" << endl;
                cout << "Votre choix : ";
                cin >> choix;
                if (choix == 0) {
                    break;
                }
            }
        }
    }

    return 0;
}
