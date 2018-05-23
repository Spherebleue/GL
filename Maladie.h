
#define Maladie_H
//--------------------------------------------------- Interfaces utilis�es

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
	// Un constructeur par d�faut, se contenant de creer la premiere cellule

	Maladie(string, int);
	// Mode d'emploi :
	// Un constructeur pour cr�er une Maladie

	void ajouterCritere(Critere * , int);
	//Mode d'emploi :
	// Une methode qui perme d'ajouter un crit�re � la position indiquee par le int
	void afficherContenu();



	virtual ~Maladie();
	// Mode d'emploi :
	// Destructeur de Maladie

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	string nom;
	Critere ** listeCritere;
	int nombreCritere;


};
