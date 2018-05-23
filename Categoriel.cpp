/*************************************************************************
                           Categoriel  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Categoriel> (fichier Categoriel.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>
//------------------------------------------------------ Include personnel
#include "Categoriel.h"

//------------------------------------------------------------- Constantes
//#define MAP ;
//----------------------------------------------------------------- PUBLIC

string Categoriel::getValeur()
{
	return valeur;
}
//----------------------------------------------------- Méthodes publiques

ostream& operator<<(ostream &strm, const Categoriel &categoriel)
//Pour afficher
{

	cout << "v" << categoriel.nom << "w  : " << categoriel.valeur;
	//strm << "Nom : " << Cat.nom << ", valeur : " << Cat.valeur;
	return strm;
}
//-------------------------------------------- Constructeurs - destructeur

Categoriel::Categoriel ( const Categoriel & unCategoriel )
// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Categoriel>" << endl;
		#endif
			nom = unCategoriel.nom;
			valeur = unCategoriel.valeur;


	} //----- Fin de Categoriel (constructeur de copie)


Categoriel::Categoriel ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Categoriel>" << endl;
		#endif

	} //----- Fin de Categoriel

Categoriel::Categoriel (string nomT , string valeurT) : Attribut(nomT), valeur(valeurT)
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Categoriel>" << endl;
		#endif

	} //----- Fin de Categoriel

Categoriel::~Categoriel ( )
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Categoriel>" << endl;
		#endif


	} //----- Fin de ~Categoriel


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées