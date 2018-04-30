
#define Critere_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

class Critere
{
	//----------------------------------------------------------------- PUBLIC
	//-------------------------------------------------------Fonction amies
public:

	//-------------------------------------------- Constructeurs - destructeur
	Critere(const Critere & uneCritere);
	// Mode d'emploi :
	// Fait une copie en profondeur de l'objet donne en parametre, et
	// l ajoute au Critere.

	Critere();
	// Mode d'emploi :
	// Un constructeur par défaut, se contenant de creer la premiere cellule

	Critere(string, bool, double, double);
	// Mode d'emploi :
	// Un constructeur pour créer un Critere

	void afficher();
	Critere * copieCritere();


	virtual ~Critere();
	// Mode d'emploi :
	// Destructeur de Critere

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	string nomAttribut;
	bool utile;
	double ecartType;
	double moyenne;


};



