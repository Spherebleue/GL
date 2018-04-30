/*************************************************************************
                           Administrateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Administrateur> (fichier Administrateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Administrateur.h"


//------------------------------------------------------------- Constantes
//#define MAP ;


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
Administrateur::Administrateur ( const Administrateur & unAdministrateur )
// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Administrateur>" << endl;
		#endif


	} //----- Fin de Administrateur (constructeur de copie)


Administrateur::Administrateur ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Administrateur>" << endl;
		#endif

	} //----- Fin de Administrateur


Administrateur::~Administrateur ( )
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Administrateur>" << endl;
		#endif


	} //----- Fin de ~Administrateur
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
