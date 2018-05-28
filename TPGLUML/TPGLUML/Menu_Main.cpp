/*************************************************************************

                      Menu Main  -  Description


    début                : 26/01/2018

    copyright            : (C) 2018 par B3332

    e-mail               : b3332@insa-lyon.fr

*************************************************************************/


//---- Réalisation de la classe <main> (fichier Menu_Main.cpp) ----------

//---------------------------------------------------------------- INCLUDE


//-------------------------------------------------------- Include système

using namespace std;

#include <iostream>


//------------------------------------------------------ Include personnel

#include "GestionUtilisateur.h"

//-------------------------------------------------------------------Menus


void Menu_ConnexionDocteur();

void Menu_DocteurConnecte();

void Menu_ConnexionAdministrateur();

void Menu_AdministrateurConnecte();

void Menu_InscriptionDocteur();

int  Menu_Principal();



//-------------------------------------------------------------------Outils


char outil_ObtenirChoix();

string outil_ObtenirMot();


//--------------------------------------------------------------Definitions


char outil_ObtenirChoix() {

	string ligne;

	getline(cin, ligne);
	const char* choix = ligne.c_str();

	return choix[0];

}



string outil_ObtenirMot() {

	string ligne;

	getline(cin, ligne);

	return ligne;

}




void Menu_ConnexionDocteur() {



	/* Demande de renseignements */
	
	cout << endl << "Connexion Docteur" << endl << endl;

	string Nom = "---";

	string Prenom = "---";

	string Motpasse = "---";

	cout << "Entrez vos donnees toutes en majuscules, s'il vous plait, sauf votre mot de passe: " << endl << endl << "Nom : ";
 
	getline(cin, Nom);

	cout << "Prenom : ";

	getline(cin, Prenom);

	cout << "Mot de passe : ";

	getline(cin, Motpasse);

	cout << endl;



	/* Appel a la methode connexion */

	GestionUtilisateur uneGestionUtilisateur;

	if (uneGestionUtilisateur.connexion(Nom, Prenom, Motpasse, "ListeDocteurs.txt"))
 
	{

		Menu_DocteurConnecte();

	}

	else
 
	{

		Menu_Principal();

	}

}



void Menu_DocteurConnecte() {


	cout << "---------------------------------------------------------------------------------------------------";

	cout << endl << "Bienvenu Docteur, veuillez choisir un choix: " << endl << endl;

	cout << "1. \tSe deconnecter" << endl;
	cout << "2. \tAnalyse empreinte" << endl;
	cout << "3. \tAffichage des maladies prises en compte" << endl;
	cout << "4. \tDescription des caracteristiques d'une maladie" << endl << endl;
	cout << "Entrer 1, 2, 3 ou 4 suivant l’option que vous souhaitez utiliser puis appuyer sur la touche entrer." << endl;

	cout << "Votre choix : ";


	char choix = outil_ObtenirChoix();



	switch (choix) {
	case '1': {
		cout << "VOUS ETES DECONNECTE" << endl << endl;
		break;
	}
	case '2': {
		cout << "AnalyseEmpreinte" << endl << endl;
		Menu_DocteurConnecte();
		break;
	}
	case '3': {
		cout << "Affichage des maladies prises en compte" << endl << endl;
		Menu_DocteurConnecte();
		break;
	}
	case '4': {
		cout << "Description des caracteristiques d'une maladie" << endl << endl;
		Menu_DocteurConnecte();
		break;
	}
	default: {
		cout << endl << "ATTENTION : Vous n'avez pas pris un choix valide." << endl << endl; 
		Menu_DocteurConnecte();
		break;
	}

	}

}



void Menu_ConnexionAdministrateur() {

	/* Demande de renseignements */

	cout << endl << endl << "Connexion Administrateur" << endl << endl;

	string Nom = "---";

	string Prenom = "---";

	string Motpasse = "---";

	cout << "Entrez vos donnees toutes en majuscules, s'il vous plait, sauf votre mot de passe : " << endl << endl << "Nom : ";

	getline(cin, Nom);

	cout << "Prenom : ";

	getline(cin, Prenom);

	cout << "Mot de passe : ";

	getline(cin, Motpasse);

	cout << endl;



	/* Appel a la methode connexion */

	GestionUtilisateur uneGestionUtilisateur;

	if (uneGestionUtilisateur.connexion(Nom, Prenom, Motpasse, "ListeAdministrateurs.txt"))
	{

		Menu_AdministrateurConnecte();

	}

	else

	{

		Menu_Principal();

	}

}



void Menu_AdministrateurConnecte() {

	cout << "---------------------------------------------------------------------------------------------------";

	cout << endl << endl << "Bien Administrateur, veuillez choisir un choix: " << endl << endl;

	cout << "1. \tSe deconnecter" << endl;
	cout << "2. \tModifier le fichier" << endl;
	cout << "Entrer 1 ou 2 suivant l’option que vous souhaitez utiliser puis appuyer sur la touche entrer." << endl << endl;

	cout << "Votre choix : ";


	char choix = outil_ObtenirChoix();



	switch (choix) {

	case '1': {
		cout << "VOUS ETES DECONNECTE" << endl << endl;
		break;
	}
	case '2': {
		cout << "Modifier le fichier" << endl << endl;
		Menu_AdministrateurConnecte();
		break;
	}
	default: {
		cout << endl << "ATTENTION : Vous n'avez pas pris un choix valide." << endl << endl; 
		Menu_AdministrateurConnecte();
		break;
	}

	}

}



void Menu_InscriptionDocteur() {


	cout << endl << "Veuillez inserez vos donnees personnelles a enregistrer, sil vous plait : " << endl << endl;

	cout << "1. \tNom : ";
	string Nom = outil_ObtenirMot();
	cout << "2. \tPrenom : ";
	string Prenom = outil_ObtenirMot();
	cout << "3. \tVotre courriel electronique : ";
	string Courriel = outil_ObtenirMot();
	cout << "4. \tVotre mot de passe : ";
	string Motpasse = outil_ObtenirMot();


	cout << "---------------------------------------------------------------------------------------------------";

	cout << endl << endl << "Ces sont les donnees que vous avez choisi : " << endl << endl;

	cout << "1. \tNom : " << "\"" << Nom << "\"" << endl;
	cout << "2. \tPrenom : " << "\"" << Prenom << "\"" << endl;
	cout << "3. \tVotre courriel electronique : " << "\"" << Courriel << "\"" << endl;
	cout << "4. \tVotre mot de passe : " << "\"" << Motpasse << "\"" << endl << endl;

	cout << "Est-ce que vous etes d'accord ? " << endl << endl;
	cout << "1. \tEssayer a nouveau" << endl;
	cout << "2. \tJe suis d'accord" << endl;
	cout << "3. \tAnnuler et aller a l'acceuil" << endl << endl;

	cout << "Votre choix : ";


	char choix = outil_ObtenirChoix();


	switch (choix) {

	case '1': {
		Menu_InscriptionDocteur();
		break;
	}
	case '2': {
		GestionUtilisateur uneGestionUtilisateur;
		uneGestionUtilisateur.creerCompte(Nom, Prenom, Courriel, Motpasse, "ListeDocteurs.txt");
		cout << "VOTRE COMPTE A ETE CREE" << endl;
		break; 
	}
	case '3': {
		cout << "INSCRIPTION ANNULEE" << endl;
		break;
	}
	default: {
		cout << endl << "ATTENTION : Vous n'avez pas pris un choix valide." << endl << endl;
		cout << "INSCRIPTION NON REUSSIE" << endl;
		break;
	}

	}

}



int Menu_Principal() {

	cout << endl;

	cout << "---------------------------------------------------------------------------------------------------";

	cout << endl;
	cout << endl << "BIENVENU a l'application des tests medicaux d'empreintes" << endl << endl;

	cout << "1. \tConnexion Docteur" << endl;
	cout << "2. \tConnexion Administrateur" << endl;
	cout << "3. \tInscription Docteur" << endl;
	cout << "4. \tSortir du programme" << endl << endl;
	cout << "Entrer 1, 2, 3 ou 4 suivant le choix que vous souhaitez utiliser puis appuyer sur la touche entrer." << endl;
	cout << "Votre choix : ";


	char choix = outil_ObtenirChoix();

	cout << "---------------------------------------------------------------------------------------------------";
	cout << endl;

	switch (choix) {
		
	case '1': {
		Menu_ConnexionDocteur();
		return 0;
	}
	case '2': {
		Menu_ConnexionAdministrateur();
		return 0;
	}
	case '3': {
		Menu_InscriptionDocteur();
		return 0;
	}
	case '4': {
		return 1; // On sort de l'application
	}
	default: {
		return 0; // On reste dans l'application

	}

	}

}



int main(int argc, char* argv[])
{
	/* Menu principal */

	int home = Menu_Principal();

	while (home == 0) {
		home = Menu_Principal();
	}
	
	return 0;
}
