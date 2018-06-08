/*************************************************************************
GestionUtilisateur  -  description
-------------------
d�but                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GestionUtilisateur> (fichier GestionUtilisateur.h) ------------
#if ! defined ( GestionUtilisateur_H )
#define GestionUtilisateur_H

//--------------------------------------------------- Interfaces utilis�es

using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <assert.h>
#include "Utilisateur.h"

// Role de la classe <GestionUtilisateur>
// 
//
//------------------------------------------------------------------------

class GestionUtilisateur
{
	//----------------------------------------------------------------- PUBLIC

public:

	bool connexion(string nom, string prenom, string motpasse, string nomFichier);
	// Mode d'emploi :
	// Cette methode renvoie true si le nom et mot de passe se troouve dans le fichier nomFichier, et false sinon

	void afficherListeDocteurs(string nomFichier);
	// Mode d'emploi :
	// Cette methode affiche la liste de docteurs contenue dans le fichier de nom nomFichier.

	void creerCompte(string nom, string prenom,string adresse, string motpasse, string nomFichier);
	// Mode d'emploi :
	// Cette methode cree une objet Utilisateur avec les donnees recues et l'enregistre dans le fichier nomFichier.

	void ecritureLog(string nomFichier, string prenom, string nom, string requete);
	// Mode d'emploi :
	// Cette methode �crit dans un fichier de log � chaque fois qu'une requete est effectu�e.

	//-------------------------------------------- Constructeurs - destructeur
	GestionUtilisateur(const GestionUtilisateur & uneGestionUtilisateur);
	// Mode d'emploi :
	// Fait une copie en profondeur d'un objet GestionUtilisateur.

	GestionUtilisateur();
	// Mode d'emploi :
	// Un constructeur par d�faut

	virtual ~GestionUtilisateur();
	// Mode d'emploi :
	// Destructeur de GestionUtilisateur

	//------------------------------------------------------------------ PRIVE

protected:


};



#endif
