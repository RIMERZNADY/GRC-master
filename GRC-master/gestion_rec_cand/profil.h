#pragma once
#include <iostream>
using namespace std;
class Profil
{
private:
	int id;
	string type;
public:
	Profil(int=0, string="");
	//getters:
	int getId() const;
	string getType() const;

	//setters:
	void setId(int);
	void setType(string);
};


