/*************************************************************************
Maladie  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Maladie> (fichier Maladie.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel

#include "Maladie.h"


//------------------------------------------------------------- Constantes
//#define MAP ;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
Maladie::Maladie(const Maladie & unMaladie)
// Algorithme :
// Un constructeur de copie.
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Maladie>" << endl;
#endif


} //----- Fin de Maladie (constructeur de copie)




Maladie::Maladie()
// Algorithme :
// Un constructeur par défaut.
{
#ifdef MAP
	cout << "Appel au constructeur de <Maladie>" << endl;
#endif

} //----- Fin de Maladie

Maladie::Maladie(string nomT, int tailleTableau)
// Algorithme :
// Un constructeur avec tous les attributs
{
#ifdef MAP
	cout << "Appel au constructeur de <Maladie>" << endl;
#endif
	nom = nomT;
	listeCritere = new Critere * [tailleTableau];
	nombreCritere = tailleTableau;



} //----- Fin de Maladie

void Maladie::ajouterCritere(Critere * critere, int position)
{
	
	listeCritere[position] = critere->copieCritere();


}



void Maladie::afficherContenu()
{
	cout << "Nom maladie : " << nom.c_str() << endl;
	for (int i = 0; i < nombreCritere; i++)
	{
		cout << listeCritere[i] << endl;;
	}
	
}

Maladie::~Maladie()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Maladie>" << endl;
#endif
	for (int i = 0; i < nombreCritere; i++)
	{
		delete listeCritere[i];
	}
	delete [] listeCritere;

} //----- Fin de ~Maladie
  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées