/*************************************************************************
Numerique  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Numerique> (fichier Numerique.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Numerique.h"

//------------------------------------------------------------- Constantes
//#define MAP ;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
ostream&  Numerique::output(ostream&strm) const
{
	return strm << *this << std::endl;

}

double Numerique::getValeur()
{
	return valeur;
}


Numerique * Numerique::copieAttribut()
//creer un pointeur sur l'attribut
{
	return new Numerique(*this);
}

ostream& operator<<(ostream &strm,const Numerique &Num)
//Pour afficher
{
	strm << "Numérique (nom :  inconnu, valeur :" << Num.valeur << ")"; //TODO : a corriger
	return strm;
}


//-------------------------------------------- Constructeurs - destructeur

Numerique::Numerique ( const Numerique & unNumerique )

// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Numerique>" << endl;
		#endif
			nom = unNumerique.nom;
			valeur = unNumerique.valeur;

	} //----- Fin de Numerique (constructeur de copie)



Numerique::Numerique ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Numerique>" << endl;
		#endif

	} //----- Fin de Numerique

Numerique::Numerique ( string nomT, double valeurT) : Attribut(nomT), valeur (valeurT)
// Algorithme :
// Un constructeur
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Numerique>" << endl;
		#endif
	} //----- Fin de Numerique


Numerique::~Numerique ( )
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Numerique>" << endl;
		#endif

	} //----- Fin de ~Numerique
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
