/*************************************************************************
                           Utilisateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Utilisateur> (fichier Utilisateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Utilisateur.h"


//------------------------------------------------------------- Constantes
//#define MAP ;


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
Utilisateur::Utilisateur ( const Utilisateur & unUtilisateur )
// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Utilisateur>" << endl;
		#endif


	} //----- Fin de Utilisateur (constructeur de copie)


Utilisateur::Utilisateur ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Utilisateur>" << endl;
		#endif

	} //----- Fin de Utilisateur


Utilisateur::~Utilisateur ( )
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Utilisateur>" << endl;
		#endif


	} //----- Fin de ~Utilisateur
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
