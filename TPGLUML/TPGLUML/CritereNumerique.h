/*************************************************************************
CritereNumerique  -  description
-------------------
d�but                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <CritereNumerique> (fichier CritereNumerique.h) ------------
#define CritereNumerique_H
//--------------------------------------------------- Interfaces utilis�es

#include "Critere.h"
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

// Role de la classe <CritereNumerique>
// 
//
//------------------------------------------------------------------------


class CritereNumerique : public Critere
{
	//----------------------------------------------------------------- PUBLIC

	
public:

	//-------------------------------------------------------Fonction amies
	friend ostream& operator<<(ostream&, const CritereNumerique &); 

	//------------------------------------------------------ M�thodes publiques
	CritereNumerique * copieCritere();
	// Mode d'emploi :
	// Une fonction qui a pour but de faire une copie en profondeur d'un pointeur de CritereNumerique

	double getEcartType();
	// Mode d'emploi :
	// Une accesseur pour l'attribut "ecartType"
	double getMoyenne();
	// Mode d'emploi :
	// Une accesseur pour l'attribut "getMoyenne"


	//-------------------------------------------- Constructeurs - destructeur
	CritereNumerique(const CritereNumerique & uneCritereNumerique);
	// Mode d'emploi :
	// Fait une copie en profondeur d'un objet CritereNumerique.

	CritereNumerique();
	// Mode d'emploi :
	// Un constructeur par d�faut

	CritereNumerique(string, bool, double, double);
	// Mode d'emploi :
	// Un constructeur
	

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
