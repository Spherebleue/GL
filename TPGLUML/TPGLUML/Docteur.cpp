/*************************************************************************
                           Docteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Docteur> (fichier Docteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Docteur.h"

//------------------------------------------------------------- Constantes
#define MAP ;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur
Docteur::Docteur ( const Docteur & unDocteur )
// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Docteur>" << endl;
		#endif


	} //----- Fin de Docteur (constructeur de copie)


Docteur::Docteur ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Docteur>" << endl;
		#endif

	} //----- Fin de Docteur


Docteur::~Docteur ()
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Docteur>" << endl;
		#endif


	} //----- Fin de ~Docteur
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
