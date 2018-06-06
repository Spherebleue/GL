
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
	// Un constructeur par d�faut


	virtual ~GestionRisques();
	// Mode d'emploi :
	// Destructeur de Administateur

	void initMaladies(string);

	void analyserFichier(string nomFichier);

	void chercherMaladie(string nomMaladie);

	void afficherMaladies();

	void enregistrerMaladies(vector<Maladie>);

    multimap<string, Empreinte> CreerListeEmpreinteAvecMaladie(string nomFichier);

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s

};
#endif



