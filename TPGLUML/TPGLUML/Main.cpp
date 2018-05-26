/*************************************************************************
                           main  -  description
                             -------------------
    début                : 26/01/2018
    copyright            : (C) 2018 par B3332 (Duraffourg & Gangalic)
    e-mail               : b3332@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <main> (fichier main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

#include "Categoriel.h"
#include "Numerique.h"
#include "Empreinte.h"
#include "CritereCategoriel.h"
#include "CritereNumerique.h"
#include "GestionRisques.h"

//------------------------------------------------------ Include personnel
#include "GestionUtilisateur.h"


//-------------------------------------------------------------------Tests

int testCategoriel_1 ()
// test constructeur
{
    Categoriel canard ("canard", "canardj");
    cout<< canard<<endl;
	//cout << (canard.getValeur());
    return 0;
}

int testNumerique_1 ()
//test numerique
{
    Numerique canard ("canard", 42);
    cout<< canard<<endl;
    return 0;
}




int testCritere_1()
//test critere
{
	CritereCategoriel canard("canard", false, "bouh");
	cout<<canard<<endl;
	return 0;
}

int testCritere_2()
//test critere
{
	CritereNumerique canard("canard", false, 3, 8);
	cout<<canard<<endl;
	return 0;
}

int test_CodeInit()
{
	Empreinte::initialiserFormat();
	for (int i = 0; i < int (Empreinte::format.size()); i++)
	{
		cout << Empreinte::format[i].first << ", " << Empreinte::format[i].second << endl;
	}
	return 0;
}

int test_analyseFichier()
{
	GestionRisques gr;
	gr.analyserFichier("F3_ok.txt");
	return 0;
}

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
