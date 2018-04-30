#include "Utilisateur.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class GestionUtilisateur
{
public:

	GestionUtilisateur();

	void creerCompte(string nom, string prenom, string motpasse, string adresse, string nomFichier);

	void afficherListeDocteurs(string nomFichier);

	bool connexion(string nom, string motpasse, string nomFichier);

	virtual ~GestionUtilisateur();
};

