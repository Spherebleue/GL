/*************************************************************************
Utilisateur  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Utilisateur> (fichier Utilisateur.h) ------------
#if ! defined ( Utilisateur_H )
#define Utilisateur_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

// Role de la classe <Utilisateur>
// 
//
//------------------------------------------------------------------------

class Utilisateur
{

//-------------------------------------------------------Fonction amies
public:

//----------------------------------------------------------------- PUBLIC
	friend ostream& operator<<(ostream&, const Utilisateur &);

//-------------------------------------------- Constructeurs - destructeur

	Utilisateur();
    // Mode d'emploi :
    // Un constructeur par défaut

    Utilisateur ( const Utilisateur & unUtilisateur);
    // Mode d'emploi :
    // Fait une copie en profondeur d'un objet Utilisateur


	Utilisateur(string, string, string, string);
	// Mode d'emploi :
	// Un constructeur


    virtual ~Utilisateur( );
    // Mode d'emploi :
    // Destructeur de Utilisateur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string nom;
	string prenom;
	string motDePasse;
	string adresse;

};

#endif

