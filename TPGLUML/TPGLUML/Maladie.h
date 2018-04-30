
#define Maladie_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "Critere.h"

class Maladie
{
	//----------------------------------------------------------------- PUBLIC
	//-------------------------------------------------------Fonction amies
public:

	//-------------------------------------------- Constructeurs - destructeur
	Maladie(const Maladie & uneMaladie);
	// Mode d'emploi :
	// Fait une copie en profondeur de l'objet donne en parametre, et
	// l ajoute au Maladie.

	Maladie();
	// Mode d'emploi :
	// Un constructeur par défaut, se contenant de creer la premiere cellule

	Maladie(string, int);
	// Mode d'emploi :
	// Un constructeur pour créer une Maladie

	void ajouterCritere(Critere * , int);
	//Mode d'emploi :
	// Une methode qui perme d'ajouter un critère à la position indiquee par le int
	void afficherContenu();



	virtual ~Maladie();
	// Mode d'emploi :
	// Destructeur de Maladie

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	string nom;
	Critere ** listeCritere;
	int nombreCritere;


};
