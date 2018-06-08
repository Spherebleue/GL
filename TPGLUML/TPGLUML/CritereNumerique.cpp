/*************************************************************************
CritereNumerique  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <CritereNumerique> (fichier CritereNumerique.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>


//------------------------------------------------------ Include personnel

#include "CritereNumerique.h"

//------------------------------------------------------------- Constantes
//#define MAP ;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


ostream& operator<<(ostream &strm, const CritereNumerique &At)
//Pour afficher
{
    strm << "Nom : " << At.nomAttribut << ", utilite : " << At.utile <<", ecart-type : " << At.ecartType << ", moyenne :" << At.moyenne;
	return strm;
}

CritereNumerique * CritereNumerique::copieCritere()
{
	return new CritereNumerique(*this);
}

double CritereNumerique::getEcartType()
{
	return ecartType;
}
double CritereNumerique::getMoyenne()
{
	return moyenne;
}

//-------------------------------------------- Constructeurs - destructeur
CritereNumerique::CritereNumerique(const CritereNumerique & unCritereNumerique)
// Algorithme :
// Un constructeur de copie.
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <CritereNumerique>" << endl;
#endif
	nomAttribut = unCritereNumerique.nomAttribut;
	utile = unCritereNumerique.utile;
	ecartType = unCritereNumerique.ecartType;
	moyenne = unCritereNumerique.moyenne;


} //----- Fin de CritereNumerique (constructeur de copie)



CritereNumerique::CritereNumerique()
// Algorithme :
// Un constructeur par défaut.
{
#ifdef MAP
	cout << "Appel au constructeur de <CritereNumerique>" << endl;
#endif

} //----- Fin de CritereNumerique

CritereNumerique::CritereNumerique(string nomAttributT, bool utileT, double ecartTypeT, double moyenneT) : Critere(nomAttributT, utileT), ecartType(ecartTypeT), moyenne(moyenneT)
// Algorithme :
// Un constructeur avec tous les attributs
{
#ifdef MAP
	cout << "Appel au constructeur de <CritereNumerique>" << endl;
#endif


} //----- Fin de CritereNumerique




CritereNumerique::~CritereNumerique()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <CritereNumerique>" << endl;
#endif


} //----- Fin de ~CritereNumerique
  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées
