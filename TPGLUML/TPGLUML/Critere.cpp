/*************************************************************************
Critere  -  description
-------------------
d�but                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- R�alisation de la classe <Critere> (fichier Critere.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <cstring>
#include <string>


//------------------------------------------------------ Include personnel

#include "Critere.h"

//------------------------------------------------------------- Constantes
//#define MAP ;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

/*void Critere::afficher()
{
	cout << "Nom : " << nomAttribut.c_str() << ", utilite : " << utile ;
}*/

ostream& operator<<(ostream &strm, const Critere &At)
//Pour afficher
{
	strm << "Nom : " << At.nomAttribut << ", utilite : " << At.utile ;
	return strm;
}


bool Critere::getUtile()
{
	return utile;
}


string Critere::getNom()
{
	return nomAttribut;
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



} //----- Fin de Critere (constructeur de copie)



Critere::Critere()
// Algorithme :
// Un constructeur par d�faut.
{
#ifdef MAP
	cout << "Appel au constructeur de <Critere>" << endl;
#endif

} //----- Fin de Critere

Critere::Critere(string nomAttributT, bool utileT) : nomAttribut(nomAttributT), utile(utileT)
// Algorithme :
// Un constructeur avec tous les attributs
{
#ifdef MAP
	cout << "Appel au constructeur de <Critere>" << endl;
#endif



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

  //----------------------------------------------------- M�thodes prot�g�es
