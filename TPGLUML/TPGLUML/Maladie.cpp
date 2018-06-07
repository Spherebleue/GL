/*************************************************************************
Maladie  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Maladie> (fichier Maladie.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>


//------------------------------------------------------ Include personnel

#include "Maladie.h"
#include "Empreinte.h"


//------------------------------------------------------------- Constantes
//#define MAP ;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
Maladie::Maladie(const Maladie & uneMaladie)
// Algorithme :
// Un constructeur de copie.
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Maladie>" << endl;
#endif
	nom = uneMaladie.nom;
	listeCritere = new Critere *[int (Empreinte::format.size())];
	for (int i = 0; i<int(Empreinte::format.size()); i++)
	{
		listeCritere[i] = uneMaladie.listeCritere[i]->copieCritere();
	}
} //----- Fin de Maladie (constructeur de copie)




Maladie::Maladie()
// Algorithme :
// Un constructeur par défaut.
{
#ifdef MAP
	cout << "Appel au constructeur de <Maladie>" << endl;
#endif

} //----- Fin de Maladie

Maladie::Maladie(string nomT)
// Algorithme :
// Un constructeur avec tous les attributs
{
#ifdef MAP
	cout << "Appel au constructeur de <Maladie>" << endl;
#endif
	nom = nomT;
	listeCritere = new Critere * [int (Empreinte::format.size())];
} //----- Fin de Maladie

void Maladie::ajouterCritere(Critere * critere, int position)
{
	listeCritere[position] = critere->copieCritere();
}



void Maladie::afficherContenu()
{
	cout << "Nom maladie : " << nom.c_str() << endl;
	for (int i = 0; i < int(Empreinte::format.size()); i++)
	{
		cout << "critere numero : " << i << endl;
		cout << listeCritere[i] << endl;;
	}

}

string Maladie::getNom()
{
	return nom;
}

Critere** Maladie::getListeCritere()
{
	return listeCritere;
}

Maladie::~Maladie()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Maladie>" << endl;
#endif
	for (int i = 0; i < int(Empreinte::format.size()); i++)
	{
		delete listeCritere[i];
	}
	delete [] listeCritere;

} //----- Fin de ~Maladie
  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées
