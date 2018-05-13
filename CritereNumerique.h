
#define CritereNumerique_H
//--------------------------------------------------- Interfaces utilisées

#include "Critere.h"
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>


class CritereNumerique : public Critere
{
	//----------------------------------------------------------------- PUBLIC
	//-------------------------------------------------------Fonction amies
public:

	//-------------------------------------------- Constructeurs - destructeur
	CritereNumerique(const CritereNumerique & uneCritereNumerique);
	// Mode d'emploi :
	// Fait une copie en profondeur de l'objet donne en parametre, et
	// l ajoute au CritereNumerique.

	CritereNumerique();
	// Mode d'emploi :
	// Un constructeur par défaut, se contenant de creer la premiere cellule

	CritereNumerique(string, bool, double, double);
	// Mode d'emploi :
	// Un constructeur pour créer un CritereNumerique

	void afficher();
	CritereNumerique * copieCritere();


	virtual ~CritereNumerique();
	// Mode d'emploi :
	// Destructeur de CritereNumerique

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

	double ecartType;
	double moyenne;


};



#pragma once
