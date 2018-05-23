/*************************************************************************
                           Attribut  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Attribut> (fichier Attribut.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>

//------------------------------------------------------ Include personnel
#include "Attribut.h"

//------------------------------------------------------------- Constantes
//#define MAP ;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Attribut * Attribut::copieAttribut()
//creer un pointeur sur l'attribut
{
	return new Attribut(*this);
}

ostream& operator<<(std::ostream &strm, const Attribut &At)
//Pour afficher
{
	strm << " Nom : " << At.nom << " ";
	return strm;
}
	

//-------------------------------------------- Constructeurs - destructeur

Attribut::Attribut ( const Attribut & unAttribut )
// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Attribut>" << endl;
		#endif
		nom = unAttribut.nom;

	} //----- Fin de Attribut (constructeur de copie)


Attribut::Attribut ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Attribut>" << endl;
		#endif

	} //----- Fin de Attribut

Attribut::Attribut (string nomT) : nom (nomT)
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Attribut>" << endl;
		#endif

	} //----- Fin de Attribut

Attribut::~Attribut ( )
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Attribut>" << endl;
		#endif

	} //----- Fin de ~Attribut


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
