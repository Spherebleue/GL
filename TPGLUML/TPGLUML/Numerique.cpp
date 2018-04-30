/*************************************************************************
                           Numerique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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

std::ostream& operator<<(std::ostream &strm, const Numerique &Num)
//Pour afficher
{
	return strm << Num.nom << ";" <<Num.valeur;
}
//-------------------------------------------- Constructeurs - destructeur

Numerique::Numerique ( const Numerique & unNumerique )

// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Numerique>" << endl;
		#endif

	} //----- Fin de Numerique (constructeur de copie)



Numerique::Numerique ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Numerique>" << endl;
		#endif

	} //----- Fin de Numerique

Numerique::Numerique ( string nom, int valeur)
// Algorithme :
// Un constructeur
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Numerique>" << endl;
		#endif
		this->valeur=valeur;
		this->nom=nom;

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
