/*************************************************************************
Critere  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Critere> (fichier Critere.h) ------------
#ifndef CRITERE_H_INCLUDED
#define CRITERE_H_INCLUDED

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

// Role de la classe <Critere>
// 
//
//------------------------------------------------------------------------
class Critere
{
	//----------------------------------------------------------------- PUBLIC

	
public:
	//-------------------------------------------------------Fonction amies
  	
	friend ostream& operator<<(ostream&, const Critere &); 

	//--------------------------------------------------------- Méthodes publiques


	string getNom();
	// Mode d'emploi :
	// Une accesseur pour l'attribut "nomAttribut"

	bool getUtile();
	// Mode d'emploi :
	// Une accesseur pour l'attribut "utile"



	virtual Critere * copieCritere() = 0;
	// Mode d'emploi :
	// Une fonction virtuelle qui a pour but de faire une copie en profondeur d'un pointeur de Critere

	//-------------------------------------------- Constructeurs - destructeur
	Critere(const Critere & uneCritere);
	// Mode d'emploi :
	// Fait une copie en profondeur d'un objet Critere

	Critere();
	// Mode d'emploi :
	// Un constructeur par défaut

	Critere(string, bool);
	// Mode d'emploi :
	// Un constructeur



	virtual ~Critere();
	// Mode d'emploi :
	// Destructeur de Critere

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	string nomAttribut;
	bool utile;


};

#endif

