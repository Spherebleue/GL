/*************************************************************************
Administrateur  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Administrateur> (fichier Administrateur.h) ------------
#if ! defined ( Administrateur_H )
#define Administrateur_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "Utilisateur.h"

class Administrateur : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC

//------------------------------------------------------------------------
// Role de la classe <Administrateur>
// Cette classe herite de la classe Utilisateur. Un Administrateur pourra
// modifier le fichier contenant la base de données pour les maladies
//------------------------------------------------------------------------
//-------------------------------------------------------Fonction amies
public:
	friend ostream& operator<<(ostream&, const Administrateur &);

//-------------------------------------------- Constructeurs - destructeur
    Administrateur ( const Administrateur & unAdministrateur); 
    // Mode d'emploi :
    // Fait une copie en profondeur d'un objet Administrateur

	Administrateur();
    // Mode d'emploi :
    // Un constructeur par défaut

	Administrateur(string, string, string, string);
	// Mode d'emploi :
	// Un constructeur

    virtual ~Administrateur( );
    // Mode d'emploi :
    // Destructeur de Administateur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	
};
#endif

