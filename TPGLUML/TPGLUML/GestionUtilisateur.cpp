#include "GestionUtilisateur.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

GestionUtilisateur::GestionUtilisateur()
{
}

void GestionUtilisateur::creerCompte(string nom, string prenom, string motpasse, string adresse, string nomFichier)
{
	
	ofstream fichier(nomFichier, ios::app);
	if (fichier)
	{
		{
			fichier << nom << ';' << prenom << ';' << adresse <<';'<< motpasse  << endl;
		}
	}
	else
	{
		cerr << "Impossible d'ouvrir le fichier CompteDocteurs." << endl;
	}

}

void GestionUtilisateur::afficherListeDocteurs(string nomFichier)
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

bool GestionUtilisateur::connexion(string nom, string motpasse, string nomFichier)
{
	ifstream fichier(nomFichier);
	string ligne;
	if (fichier)
	{
		
		getline(fichier, ligne, ';');
		while (ligne != nom)
		{
			getline(fichier, ligne);
			getline(fichier, ligne, ';');
		}
	}
	getline(fichier, ligne, ';');
	getline(fichier, ligne, ';');
	getline(fichier, ligne);
	if (motpasse == ligne)
		return true;
	else
		return false;
}

GestionUtilisateur::~GestionUtilisateur()
{
}
