/*************************************************************************
CritereCategoriel  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <CritereCategoriel> (fichier CritereCategoriel.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <cstring>
#include <string>


//------------------------------------------------------ Include personnel

#include "CritereCategoriel.h"

//------------------------------------------------------------- Constantes
//#define MAP ;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques

/*void CritereCategoriel::afficher()
{
	Critere::afficher();
	cout<< ", valeur : "<< categorie <<endl;
}*/

ostream& operator<<(ostream &strm, const CritereCategoriel &At)
//Pour afficher
{
	strm << "Nom : " << At.nomAttribut << ", utilite : " << At.utile << ", valeur : "<< At.categorie;
	return strm;
}

CritereCategoriel * CritereCategoriel::copieCritere()
{
	return new CritereCategoriel(*this);
}

//-------------------------------------------- Constructeurs - destructeur
CritereCategoriel::CritereCategoriel(const CritereCategoriel & unCritereCategoriel)
// Algorithme :
// Un constructeur de copie.
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <CritereCategoriel>" << endl;
#endif
	nomAttribut = unCritereCategoriel.nomAttribut;
	utile = unCritereCategoriel.utile;
	categorie = unCritereCategoriel.categorie;



} //----- Fin de CritereCategoriel (constructeur de copie)



CritereCategoriel::CritereCategoriel()
// Algorithme :
// Un constructeur par d�faut.
{
#ifdef MAP
	cout << "Appel au constructeur de <CritereCategoriel>" << endl;
#endif

} //----- Fin de CritereCategoriel

CritereCategoriel::CritereCategoriel(string nomAttributT, bool utileT, string categorieT) : Critere(nomAttributT, utileT), categorie(categorieT)
// Algorithme :
// Un constructeur avec tous les attributs
{
#ifdef MAP
	cout << "Appel au constructeur de <CritereCategoriel>" << endl;
#endif

} //----- Fin de CritereCategoriel




CritereCategoriel::~CritereCategoriel()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CritereCategoriel>" << endl;
#endif


} //----- Fin de ~CritereCategoriel
  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- M�thodes prot�g�es
