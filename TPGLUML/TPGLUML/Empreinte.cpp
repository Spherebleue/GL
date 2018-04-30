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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Empreinte::ajouterAttribut(Attribut * attribut, int position)
{
	attributs[position] = attribut->copieAttribut();
}


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

Empreinte::Empreinte (string ID, int nombreAttributs)
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Empreinte>" << endl;
		#endif

		this->ID =ID;
		attributs = new Attribut * [nombreAttributs];
	} //----- Fin de Empreinte



Empreinte::~Empreinte ( )
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Empreinte>" << endl;
		#endif

		delete attributs;
	} //----- Fin de ~Empreinte
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
