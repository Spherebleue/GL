
#if ! defined ( GestionRisques_H )
#define GestionRisques_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "Utilisateur.h"

class GestionRisques : public Utilisateur
{
	//----------------------------------------------------------------- PUBLIC
	//-------------------------------------------------------Fonction amies
public:


	//-------------------------------------------- Constructeurs - destructeur
	GestionRisques(const GestionRisques & unGestionRisques);
	// Mode d'emploi :
	// Fait une copie en profondeur de l'objet donne en parametre

	GestionRisques();
	// Mode d'emploi :
	// Un constructeur par défaut


	virtual ~GestionRisques();
	// Mode d'emploi :
	// Destructeur de Administateur

	void initMaladies();

	void analyserFichier(string nomFichier);

	void chercherMaladie(string nomMaladie);

	void afficherMaladies();


	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés

};
#endif



