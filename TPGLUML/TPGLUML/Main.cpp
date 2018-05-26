/*************************************************************************
                           main  -  description
                             -------------------
    début                : 26/01/2018
    copyright            : (C) 2018 par B3332
    e-mail               : b3332@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <main> (fichier main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "GestionUtilisateur.h"


//-------------------------------------------------------------------Tests
int GestionUtilisateur_Test_1()
//Test GestionUtilisateur constructeur
{
	
	GestionUtilisateur uneGestionUtilisateur = GestionUtilisateur();
	return 0;
}

int creerCompte_Test()
//Test creerCompte
{
	GestionUtilisateur uneGestionUtilisateur;
	uneGestionUtilisateur.creerCompte("CHAIZA", "GUSTAVO","gustavo@gmail.com","gustavo","ListeDocteurs.txt");
	return 0;
}

int afficherListeDocteurs_Test()
//Test afficherListeDocteurs
{
	GestionUtilisateur uneGestionUtilisateur;
	uneGestionUtilisateur.afficherListeDocteurs("ListeDocteurs.txt");
	return 0;
}

int connexion_Test_reussie()
//Test connexion GestionUtilisateur
{
	GestionUtilisateur uneGestionUtilisateur;
	uneGestionUtilisateur.connexion("CHAIZA","GUSTAVO","gustavo","ListeDocteurs.txt");
	return 0;
}

int connexion_Test_echouee()
//Test connexion GestionUtilisateur
{
	GestionUtilisateur uneGestionUtilisateur;
	uneGestionUtilisateur.connexion("CHAIZA", "REYNALDO", "gustavo", "ListeDocteurs.txt");
	return 0;
}

int main(int argc, char* argv[])
{
	GestionUtilisateur_Test_1();
	creerCompte_Test();
	afficherListeDocteurs_Test();
	connexion_Test_reussie();
	connexion_Test_echouee();
	while (true);
}
