/*************************************************************************
Maladie  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Maladie> (fichier Maladie.h) ------------
#define Maladie_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "Critere.h"

// Role de la classe <Maladie>
// Cette classe définit une maladie, qui possède des critères qui seront définis
// dans la méthode initMaladies() de GestionRisques
//------------------------------------------------------------------------

class Maladie
{
	//----------------------------------------------------------------- PUBLIC
	
public:

	//-----------------------------------------------------------------Méthodes publiques
	void ajouterCritere(Critere *, int);
	//Mode d'emploi :
	// Une methode qui permet d'ajouter un pointeur de Critère à la position indiquee par le int

	void afficherContenu(); // A VIRER 

	

	string getNom();
	// Mode d'emploi :
	// Une accesseur pour l'attribut "nom"
	Critere** getListeCritere();
	// Mode d'emploi :
	// Une accesseur pour l'attribut "listeCritere"

	//-------------------------------------------- Constructeurs - destructeur
	Maladie(const Maladie & uneMaladie);
	// Mode d'emploi :
	// Fait une copie en profondeur d'un objet Maladie

	Maladie();
	// Mode d'emploi :
	// Un constructeur par défaut

	Maladie(string);
	// Mode d'emploi :
	// Un constructeur

	virtual ~Maladie();
	// Mode d'emploi :
	// Destructeur de Maladie

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	string nom;
	Critere ** listeCritere;


};
