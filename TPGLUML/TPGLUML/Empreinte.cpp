/*************************************************************************
                           Empreinte  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Empreinte.h"


//------------------------------------------------------------- Constantes
//#define MAP ;
unsigned int MAXLENGTH = 25;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
Empreinte::Empreinte ( const Empreinte & unEmpreinte )
// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Empreinte>" << endl;
		#endif


	} //----- Fin de Empreinte (constructeur de copie)


Empreinte::Empreinte ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Empreinte>" << endl;
		#endif

	} //----- Fin de Empreinte


Empreinte::~Empreinte ( )
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Empreinte>" << endl;
		#endif


	} //----- Fin de ~Empreinte
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
