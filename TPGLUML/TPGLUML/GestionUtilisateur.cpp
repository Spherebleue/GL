/*************************************************************************
GestionUtilisateurs  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GestionUtilisateur> (fichier GestionUtilisateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <string>
//------------------------------------------------------ Include personnel
#include "GestionUtilisateur.h"

//------------------------------------------------------------- Constantes
//#define MAP ;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool GestionUtilisateur::connexion(string nom, string prenom, string motpasse, string nomFichier)
// Algorithme :
{
	ifstream fichier(nomFichier);
	string ligneNom;
	string lignePrenom;
	string ligneMotpasse;
	int compteur = 0;
	if (fichier)
	{

		getline(fichier, ligneNom, ';');
		getline(fichier, lignePrenom, ';');
		while ((ligneNom.compare(nom) !=0 || lignePrenom.compare(prenom)!=0) && fichier.good())
		{
			
			getline(fichier, ligneNom);
			getline(fichier, ligneNom, ';');
			getline(fichier, lignePrenom, ';');
			compteur++;
		}
	}
	getline(fichier, ligneNom, ';');
	getline(fichier, ligneMotpasse);
	if (motpasse == ligneMotpasse)
	{
		cout << "Vous etes connecte" << endl;
		return true;
	}
	else
	{
		cout << "Connexion echouee" << endl;;
		return false;
	}
}

void GestionUtilisateur::afficherListeDocteurs(string nomFichier)
// Algorithme :
{
	ifstream fichier(nomFichier);
	if (fichier)
	{
		string ligne;
		while (getline(fichier, ligne))
		{
			cout << ligne << endl;
		}
	}
	else
	{
		cerr << "Impossible d'ouvrir le fichier CompteDocteurs." << endl;
	}
}

void GestionUtilisateur::creerCompte(string nom, string prenom, string adresse, string motpasse, string nomFichier)
// Algorithme :
{
	ofstream fichier(nomFichier, ios::app);
	if (fichier)
	{
		{
			fichier << nom << ';' << prenom << ';' << adresse << ';' << motpasse << endl;
		}
	}
	else
	{
		cerr << "Impossible d'ouvrir le fichier CompteDocteurs." << endl;
	}
}

//-------------------------------------------- Constructeurs - destructeur

GestionUtilisateur::GestionUtilisateur(const GestionUtilisateur & uneGestionUtilisateur)
// Algorithme :
// Un constructeur de copie.
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <GestionUtilisateur>" << endl;
	#endif
} //----- Fin de GestionUtilisateur (constructeur de copie)


GestionUtilisateur::GestionUtilisateur()
// Algorithme :
// Un constructeur par défaut.
{
	#ifdef MAP
		cout << "Appel au constructeur de <GestionUtilisateur>" << endl;
	#endif
} //----- Fin de GestionUtilisateur

GestionUtilisateur::~GestionUtilisateur()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <GestionUtilisateur>" << endl;
#endif

} //----- Fin de ~GestionUtilisateur


  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées