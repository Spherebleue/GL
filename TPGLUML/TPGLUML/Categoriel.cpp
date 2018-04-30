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

std::ostream& operator<<(std::ostream &strm, const Categoriel &Cat)
//Pour afficher
{
	return strm << "Categoriel ( nom : " << Cat.nom << " valeur : " << Cat.valeur<<")"<<endl;
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

Categoriel::Categoriel (string nom , string valeur)
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Categoriel>" << endl;
		#endif
		this->nom = nom;
		this->valeur=valeur;

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