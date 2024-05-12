#ifndef OFFRE_H
#define OFFRE_H

#include <vector>
#include <string>

class Offre {
private:
    std::vector<std::string> criteres;
    int idOffre;
    std::string titre;
    std::string description;

public:
    const std::vector<std::string>& getCriteres() const;
    int getId() const;
    const std::string& getTitre() const;
    const std::string& getDescription() const;

    static Offre ajouterOffre(int idOffre, const std::string& titre, const std::string& description, const std::vector<std::string>& criteres);
    static bool supprimerOffre(std::vector<Offre>& offres, int idOffre);
    static bool modifierOffre(std::vector<Offre>& offres, int idOffre, const std::string& nouveauTitre, const std::string& nouvelleDescription, const std::vector<std::string>& nouveauxCriteres);

    void setId(int id);
    void setTitre(const std::string& titre);
    void setDescription(const std::string& description);
    void setCriteres(const std::vector<std::string>& criteres);
};

#endif // OFFRE_H