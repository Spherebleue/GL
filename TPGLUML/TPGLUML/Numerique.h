/*************************************************************************
Numerique  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Numerique> (fichier Numerique.h) ------------
#if ! defined ( Numerique_H )
#define Numerique_H

//--------------------------------------------------- Interfaces utilisées

#include "Attribut.h"
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

// Role de la classe <Numerique>
// 
//
//------------------------------------------------------------------------

class Numerique : public Attribut
{
//----------------------------------------------------------------- PUBLIC

public:

//-------------------------------------------------------Fonction amies
	friend ostream& operator<<(ostream&, const Numerique &);
	 ostream & output(ostream&) const;
 //----------------------------------------------Méthodes publiques
	 Numerique * copieAttribut();
	 // Mode d'emploi :
	 // Une fonction qui a pour but de faire une copie en profondeur d'un pointeur de Numerique


	double getValeur();
	 // Mode d'emploi :
	// Une accesseur pour l'attribut "valeur"

//-------------------------------------------- Constructeurs - destructeur
    Numerique ( const Numerique & uneNumerique );
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre, et
    // l ajoute au Numerique.

    Numerique ();
    // Mode d'emploi :
    // Un constructeur par défaut, se contenant de creer la premiere cellule

    Numerique ( string nom,double valeur);
    // Mode d'emploi :
    // Un constructeure


    virtual ~Numerique ( );
    // Mode d'emploi :
    // Destructeur de Numerique

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Numeriques protégés
	double valeur;

};

#endif
