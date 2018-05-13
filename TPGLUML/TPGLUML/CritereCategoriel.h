
#define CritereCategoriel_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "Critere.h"

class CritereCategoriel : public Critere
{
	//----------------------------------------------------------------- PUBLIC
	//-------------------------------------------------------Fonction amies
public:

	friend ostream& operator<<(ostream&, const CritereCategoriel &); 

	//-------------------------------------------- Constructeurs - destructeur
	CritereCategoriel(const CritereCategoriel & uneCritereCategoriel);
	// Mode d'emploi :
	// Fait une copie en profondeur de l'objet donne en parametre, et
	// l ajoute au CritereCategoriel.

	CritereCategoriel();
	// Mode d'emploi :
	// Un constructeur par défaut, se contenant de creer la premiere cellule

	CritereCategoriel(string, bool, string);
	// Mode d'emploi :
	// Un constructeur pour créer un CritereCategoriel

	void afficher();

	CritereCategoriel * copieCritere();


	virtual ~CritereCategoriel();
	// Mode d'emploi :
	// Destructeur de CritereCategoriel

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	string categorie;

};



#pragma once
