/*************************************************************************
CritereCategoriel  -  description
-------------------
d�but                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <CritereCategoriel> (fichier CritereCategoriel.h) ------------
#define CritereCategoriel_H
//--------------------------------------------------- Interfaces utilis�es

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "Critere.h"

// Role de la classe <CritereCategoriel>
// 
//
//------------------------------------------------------------------------

class CritereCategoriel : public Critere
{
	//----------------------------------------------------------------- PUBLIC

	
public:
	//-------------------------------------------------------Fonction amies
	friend ostream& operator<<(ostream&, const CritereCategoriel &); 

	//-----------------------------------------------------M�thodes publiques
	CritereCategoriel * copieCritere();
	// Mode d'emploi :
	// Une fonction qui a pour but de faire une copie en profondeur d'un pointeur de CritereCategoriel

	string getCategorie();
	// Mode d'emploi :
	// Une accesseur pour l'attribut "categorie"

	//-------------------------------------------- Constructeurs - destructeur
	CritereCategoriel(const CritereCategoriel & uneCritereCategoriel);
	// Mode d'emploi :
	// Fait une copie en profondeur d'un objet CritereCategoriel

	CritereCategoriel();
	// Mode d'emploi :
	// Un constructeur par d�faut

	CritereCategoriel(string, bool, string);
	// Mode d'emploi :
	// Un constructeur




	virtual ~CritereCategoriel();
	// Mode d'emploi :
	// Destructeur de CritereCategoriel

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	string categorie;

};



#pragma once
