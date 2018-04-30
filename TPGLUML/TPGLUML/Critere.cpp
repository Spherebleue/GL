/*************************************************************************
Critere  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Critere> (fichier Critere.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>


//------------------------------------------------------ Include personnel

#include "Critere.h"

//------------------------------------------------------------- Constantes
//#define MAP ;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Critere::afficher()
{
	cout << "Nom : " << nomAttribut.c_str() << ", utilite : " << utile << ", ecart-type : " << ecartType << ", moyenne " << moyenne<< endl;
}

Critere * Critere::copieCritere()
{
	return new Critere(*this);
}

//-------------------------------------------- Constructeurs - destructeur
Critere::Critere(const Critere & unCritere)
// Algorithme :
// Un constructeur de copie.
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Critere>" << endl;
#endif
	nomAttribut = unCritere.nomAttribut;
	utile = unCritere.utile;
	ecartType = unCritere.ecartType;
	moyenne = unCritere.moyenne;


} //----- Fin de Critere (constructeur de copie)



Critere::Critere()
// Algorithme :
// Un constructeur par défaut.
{
#ifdef MAP
	cout << "Appel au constructeur de <Critere>" << endl;
#endif

} //----- Fin de Critere

Critere::Critere(string nomAttributT, bool utileT, double ecartTypeT, double moyenneT)
// Algorithme :
// Un constructeur avec tous les attributs
{
#ifdef MAP
	cout << "Appel au constructeur de <Critere>" << endl;
#endif
	nomAttribut = nomAttributT;
	utile = utileT;
	ecartType = ecartTypeT;
	moyenne = moyenneT;


} //----- Fin de Critere




Critere::~Critere()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Critere>" << endl;
#endif


} //----- Fin de ~Critere
  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées