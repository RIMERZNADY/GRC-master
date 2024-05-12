#pragma once
#include "Condidat.h"
class Candidate;
class DemandeEmploi
{
private:
	int idCondidat;
	Candidate condidat;
	int idOffre;
	bool status;
public:
	DemandeEmploi(int idCondidat = 0, int idOffre = 0);
	// getters:
	int getIdCondidat() const;
	int getIdOffre() const;
	bool getStatus() const;
	Candidate getCondidat() const;

	// setters:
	void setIdCondidat(int);
	void setIdOffre(int);
	void setStatus(bool);
	void setCondidat(Candidate&);
	void afficher() const;
};

