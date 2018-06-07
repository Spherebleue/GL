/*************************************************************************
GestionRisques  -  description
-------------------
d�but                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GestionRisques> (fichier GestionRisques.h) ------------
#if ! defined ( GestionRisques_H )
#define GestionRisques_H
//--------------------------------------------------- Interfaces utilis�es

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <map>
#include "Utilisateur.h"
#include "Maladie.h"
#include "Empreinte.h"

// Role de la classe <GestionRisques>
// 
//
//------------------------------------------------------------------------


class GestionRisques : public Utilisateur
{
	//----------------------------------------------------------------- PUBLIC
	
public:
	//----------------------------------------------------------------M�thodes publiques

	void initMaladies(string);
	// Mode d'emploi :
	// Cette methode parcourt le fichier contenant des empreintes et les maladies associ�es, et d�termine quels attributs sont des sympt�mes de la maladie et peuvent donc �tre utlis�s en tant que crit�re pour d�terminer si un patient est malade ou non

	void analyserFichier(string nomFichier);
	// Mode d'emploi :
	// Cette methode va analyser le ou les empreintes pr�sente(s) dans le fichier en les comparant avec les maladies pr�sentes dans le fichier contenant les maladies et leurs crit�res et affichera les maladies associ�es � chacune des Empreinte

	void chercherMaladie(string nomMaladie);
	// Mode d'emploi :
	// Cette methode parcourt le fichier contenant les maladies et leurs crti�res et affiche les crit�res de la maladie pass�e en param�tre

	void afficherMaladies();
	// Mode d'emploi :
	// Cette m�thode parcourt le fichier contenant les maladies et leurs crti�res et affiche les noms de toutes les maladies

	void enregistrerMaladies(vector<Maladie>);
	// Mode d'emploi :
	// Cette methode va �crire dans un fichier la liste des maladies et leurs criti�res

	multimap<string, Empreinte> CreerListeEmpreinteAvecMaladie(string nomFichier);
	// Mode d'emploi :
	// Cette methode va lire le fichier contenant les empreintes et les maladies associ�es, et rentrer ces informations dans une map ayant en cl� le nom de la maladie et en valeur l'Empreinte associ�e
	//-------------------------------------------- Constructeurs - destructeur
	GestionRisques(const GestionRisques & unGestionRisques);
	// Mode d'emploi :
	// Fait une copie en profondeur d'un objet GestionRisques

	GestionRisques();
	// Mode d'emploi :
	// Un constructeur par d�faut


	virtual ~GestionRisques();
	// Mode d'emploi :
	// Destructeur de Administateur

	

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

};
#endif



