#if ! defined ( GestionUtilisateur_H )
#define GestionUtilisateur_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <assert.h>
#include "Utilisateur.h"

class GestionUtilisateur
{
	//----------------------------------------------------------------- PUBLIC
	//----------------------------------------------------------Fonction amies
public:

	bool connexion(string nom, string prenom, string motpasse, string nomFichier);
	// Mode d'emploi :
	// Renvoie true si lenom et mot de passe se troouve dans le fichier nomFichier.

	void afficherListeDocteurs(string nomFichier);
	// Mode d'emploi :
	// Affiche la liste de docteurs contenue dans le fichier de nom nomFichier.

	void creerCompte(string nom, string prenom,string adresse, string motpasse, string nomFichier);
	// Mode d'emploi :
	// Cree une objets utilisateur avec les donnees recues et l'enregistre dans un fichier.

	//-------------------------------------------- Constructeurs - destructeur
	GestionUtilisateur(const GestionUtilisateur & uneGestionUtilisateur);
	// Mode d'emploi :
	// Fait une copie en profondeur de l'objet donne en parametre, et
	// l ajoute au GestionUtilisateur.

	GestionUtilisateur();
	// Mode d'emploi :
	// Un constructeur par défaut, se contentant de creer la premiere cellule

	virtual ~GestionUtilisateur();
	// Mode d'emploi :
	// Destructeur de GestionUtilisateur

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

};



#endif
