/*************************************************************************
Categoriel  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
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
Categoriel *Categoriel::copieAttribut()
//creer un pointeur sur l'attribut
{
	return new Categoriel(*this);
}

string Categoriel::getValeur()
{
	return valeur;
}
//----------------------------------------------------- Méthodes publiques

ostream& operator<<(ostream &strm, const Categoriel &Cat)
//Pour afficher
{

	
	strm << "Nom : " << Cat.nom << ", valeur : " << Cat.valeur;
	return strm;
}

ostream& Categoriel::output(ostream&strm) const
{
	return strm << *this << std::endl;

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