/*************************************************************************
Categoriel  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Categoriel> (fichier Categoriel.h) ------------
#if ! defined ( Categoriel_H )
#define Categoriel_H
//--------------------------------------------------- Interfaces utilisées
#include "Attribut.h"
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

// Role de la classe <Categoriel>
// 
//
//------------------------------------------------------------------------

class Categoriel : public Attribut
{
//----------------------------------------------------------------- PUBLIC


//------------------------------------------------------------------------


public:

	//-------------------------------------------------------Fonction amies
    friend ostream& operator<<(ostream&, const Categoriel &); 
	ostream & output(ostream&) const;

	//-------------------------------------------------Méthodes publiques
	Categoriel * copieAttribut();
	// Mode d'emploi :
	// Une fonction qui a pour but de faire une copie en profondeur d'un pointeur de Categoriel

	string getValeur();
	// Mode d'emploi :
	// Une accesseur pour l'attribut "valeur"

//-------------------------------------------- Constructeurs - destructeur
    Categoriel ( const Categoriel & uneCategoriel );
    // Mode d'emploi :
    // Fait une copie en profondeur d'un objet Categoriel

    Categoriel ();
    // Mode d'emploi :
    // Un constructeur par défaut

    Categoriel (string nom , string valeur);
    // Mode d'emploi :
    // Un constructeur



    virtual ~Categoriel ( );
    // Mode d'emploi :
    // Destructeur de Categoriel

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Categoriels protégés
	string valeur;

};

#endif 