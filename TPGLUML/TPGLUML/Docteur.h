/*************************************************************************
Docteur.h  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Docteur> (fichier Docteur.h) ------------
#if ! defined ( Docteur_H )
#define Docteur_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "Utilisateur.h"

// Role de la classe <Docteur>
// 
//
//------------------------------------------------------------------------

class Docteur : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

public:
	//-------------------------------------------------------Fonction amies
	friend ostream& operator<<(ostream&, const Docteur &);

//-------------------------------------------- Constructeurs - destructeur
    Docteur ( const Docteur & unDocteur);
    // Mode d'emploi :
    // Fait une copie en profondeur d'un objet Docteur.

	Docteur();
    // Mode d'emploi :
    // Un constructeur par défaut

	Docteur(string, string, string, string);
	// Mode d'emploi :
	// Un constructeur

    virtual ~Docteur( );
    // Mode d'emploi :
    // Destructeur de Docteur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	
};

#endif

