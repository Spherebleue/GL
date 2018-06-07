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
#include <utility>

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

int test_CreerListeEmpreinteAvecMaladie()
//Test creerListeEmpreinteAvecMaladie ne retourne pas de null
{
    Empreinte::initialiserFormat();
    GestionRisques gr;
    multimap<string, Empreinte> liste = gr.creerListeEmpreinteAvecMaladie("Donnees/F2_ok.txt");
    for (auto it=liste.begin(); it!=liste.end(); ++it)
	{
        cout<< (*it).first << " : "<< (*it).second<<endl;
	}
	return 0;
}

int test_initMaladies()
{
    Empreinte::initialiserFormat();
    GestionRisques gr;
    gr.initMaladies("Donnees/F2_ok.txt");
    return 0;
}

int test_PrintMaladies()
{
	pair<string, string> nouvellePaire = make_pair("canard", "Numerique");
	Empreinte::format.push_back(nouvellePaire);
	Empreinte::format.push_back(nouvellePaire);
	Maladie m("m");
	Maladie m2("m2");
	CritereNumerique * canard = new CritereNumerique ("canard", true, 3, 8);
	CritereNumerique  * canard2 = new CritereNumerique("canard", false, 3, 4);
	m.ajouterCritere(canard, 0);
	m.ajouterCritere(canard2,1);
	m2.ajouterCritere(canard2, 0);
	m2.ajouterCritere(canard,1);
	vector<Maladie> v;
	v.push_back(m);
	v.push_back(m2);
	GestionRisques g;
	cout << "passe" << endl;
	g.enregistrerMaladies(v);
	cout << "no prob" << endl;
	return 0;
}

int test_affichageMaladies()
{
	GestionRisques g;
	g.afficherMaladies();
	return 0;
}

int test_chercherMaladie()
//test chercherMaladie maladie présente
{
	GestionRisques g;
	test_PrintMaladies();
	g.chercherMaladie("m2");
	return 0;
}

int test_mauvaisChercherMaladie()
//test chercherMaladie maladie non présente
{
	GestionRisques g;
	test_PrintMaladies();
	g.chercherMaladie("m3");
	return 0;
}

int test_analyse ()
{
    GestionRisques g;
    g.analyserFichier("Donnees/F3_ok.txt");
    return 0;
}
int test_supprimerLigne()
{

    GestionRisques gr;
    gr.supprimerLignes("Donnees/F2_ok (copie).txt", "3;None;12;145;12.1;11;Maladie1" );
    return 0;

}

int test_ajouterLigne()
{

    GestionRisques gr;
    gr.ajouterLignes("Donnees/F2_ok (copie).txt", "4;None;12;149;12.1;12;Maladie3" );
    return 0;

}
int main(int argc, char* argv[])
{
	//GestionUtilisateur_Test_1();
	//creerCompte_Test();
	//afficherListeDocteurs_Test();
	//connexion_Test_reussie();
	//connexion_Test_echouee();
	//test_PrintMaladies();
	//test_affichageMaladies();
	//test_chercherMaladie();
	//test_mauvaisChercherMaladie();
	//test_CreerListeEmpreinteAvecMaladie();
	test_initMaladies();
	//test_supprimerLigne();
	test_ajouterLigne();
	//test_analyse();
	//while (true);
}
