/*************************************************************************
Critere  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
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

void Critere::afficher()
{
	cout << "Nom : " << nomAttribut.c_str() << ", utilite : " << utile ;
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