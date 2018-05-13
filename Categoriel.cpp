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

//------------------------------------------------------ Include personnel
#include "Categoriel.h"

//------------------------------------------------------------- Constantes
//#define MAP ;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

ostream& operator<<(ostream &strm, const Categoriel &Cat)
//Pour afficher
{
	strm << "Categoriel ( nom : " << Cat.nom << ", valeur : " << Cat.valeur << ")";
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