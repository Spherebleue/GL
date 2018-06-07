/*************************************************************************
GestionRisques  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GestionRisques> (fichier GestionRisques.h) ------------
#if ! defined ( GestionRisques_H )
#define GestionRisques_H
//--------------------------------------------------- Interfaces utilisées

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
	//----------------------------------------------------------------Méthodes publiques

	void initMaladies(string);
	// Mode d'emploi :
	// Cette methode parcourt le fichier contenant des empreintes et les maladies associées, et détermine quels attributs sont des symptômes de la maladie et peuvent donc être utlisés en tant que critère pour déterminer si un patient est malade ou non

	void analyserFichier(string nomFichier);
	// Mode d'emploi :
	// Cette methode va analyser le ou les empreintes présente(s) dans le fichier en les comparant avec les maladies présentes dans le fichier contenant les maladies et leurs critères et affichera les maladies associées à chacune des Empreinte

	void chercherMaladie(string nomMaladie);
	// Mode d'emploi :
	// Cette methode parcourt le fichier contenant les maladies et leurs crtières et affiche les critères de la maladie passée en paramètre

	void afficherMaladies();
	// Mode d'emploi :
	// Cette méthode parcourt le fichier contenant les maladies et leurs crtières et affiche les noms de toutes les maladies

	void enregistrerMaladies(vector<Maladie>);
	// Mode d'emploi :
	// Cette methode va écrire dans un fichier la liste des maladies et leurs critières

	multimap<string, Empreinte> CreerListeEmpreinteAvecMaladie(string nomFichier);
	// Mode d'emploi :
	// Cette methode va lire le fichier contenant les empreintes et les maladies associées, et rentrer ces informations dans une map ayant en clé le nom de la maladie et en valeur l'Empreinte associée
	//-------------------------------------------- Constructeurs - destructeur
	GestionRisques(const GestionRisques & unGestionRisques);
	// Mode d'emploi :
	// Fait une copie en profondeur d'un objet GestionRisques

	GestionRisques();
	// Mode d'emploi :
	// Un constructeur par défaut


	virtual ~GestionRisques();
	// Mode d'emploi :
	// Destructeur de Administateur

	

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

};
#endif



