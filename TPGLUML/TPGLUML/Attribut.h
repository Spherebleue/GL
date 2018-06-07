/*************************************************************************
Attribut  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Attribut> (fichier Attribut.h) ------------
#ifndef ATTRIBUT_H_INCLUDED
#define ATTRIBUT_H_INCLUDED
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>


class Attribut
{
//----------------------------------------------------------------- PUBLIC

// Role de la classe <Attribut>
// 
//
//------------------------------------------------------------------------


public:
	//-------------------------------------------------------Fonction amies
    friend ostream& operator<<(ostream&, const Attribut &); 

	virtual ostream& output(ostream &) const = 0;
	//----------------------------------------------------Méthodes publiques 

	virtual Attribut * copieAttribut() = 0;
	// Mode d'emploi :
	// Une fonction virtuelle qui a pour but de faire une copie en profondeur d'un pointeur d'Attribut

//-------------------------------------------- Constructeurs - destructeur
    Attribut ( const Attribut & uneAttribut );
    // Mode d'emploi :
    // Fait une copie en profondeur d'un objet Attribut

    Attribut ();
    // Mode d'emploi :
    // Un constructeur par défaut

	Attribut(string);
	// Mode d'emploi :
	// Un constructeur

	


    virtual ~Attribut ( );
    // Mode d'emploi :
    // Destructeur de Attribut

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string nom;

};

#endif