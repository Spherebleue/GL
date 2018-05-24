
#define CritereNumerique_H
//--------------------------------------------------- Interfaces utilis�es

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

	friend ostream& operator<<(ostream&, const CritereNumerique &); 

	//-------------------------------------------- Constructeurs - destructeur
	CritereNumerique(const CritereNumerique & uneCritereNumerique);
	// Mode d'emploi :
	// Fait une copie en profondeur de l'objet donne en parametre, et
	// l ajoute au CritereNumerique.

	CritereNumerique();
	// Mode d'emploi :
	// Un constructeur par d�faut, se contenant de creer la premiere cellule

	CritereNumerique(string, bool, double, double);
	// Mode d'emploi :
	// Un constructeur pour cr�er un CritereNumerique

	
	CritereNumerique * copieCritere();


	virtual ~CritereNumerique();
	// Mode d'emploi :
	// Destructeur de CritereNumerique

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

	double ecartType;
	double moyenne;


};



#pragma once
