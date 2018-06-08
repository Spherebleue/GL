/*************************************************************************
Menu_Main  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/


//---- Réalisation de la classe <Menu_Main> (fichier Menu_Main.cpp) ----------

//---------------------------------------------------------------- INCLUDE


//-------------------------------------------------------- Include système

using namespace std;

#include <iostream>
#include <string>


//------------------------------------------------------ Include personnel

#include "GestionUtilisateur.h"
#include "GestionRisques.h"

//-------------------------------------------------------------------Menus


void Menu_ConnexionDocteur();

void Menu_DocteurConnecte(string, string);

void Menu_ConnexionAdministrateur();

void Menu_AdministrateurConnecte(string, string);

void Menu_InscriptionDocteur();

int  Menu_Principal();

void Menu_ModificationFichier();



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
	string nom = "---";
	string prenom = "---";
	string motpasse = "---";
	cout << "Entrez vos donnees toutes en majuscules, s il vous plait, sauf votre mot de passe: " << endl << endl << "Nom : ";
	getline(cin, nom);
	cout << "Prenom : ";
	getline(cin, prenom);
	cout << "Mot de passe : ";
	getline(cin, motpasse);
	cout << endl;
	/* Appel a la methode connexion */
	GestionUtilisateur uneGestionUtilisateur;
	if (uneGestionUtilisateur.connexion(nom, prenom, motpasse, "ListeDocteurs.txt"))
	{
		Menu_DocteurConnecte(prenom, nom);
	}
	else
	{
		Menu_Principal();
	}
}



void Menu_DocteurConnecte(string prenom, string nom) {

	GestionRisques gestRisques;
	GestionUtilisateur gestUt;
	gestUt.ecritureLog("Log.txt", prenom, nom, "Connexion");
    Empreinte::initialiserFormat();
	gestRisques.initMaladies("Donnees/F2_ok.txt");

	string valeurCommande;

	cout << "---------------------------------------------------------------------------------------------------";

	cout << endl << "Bienvenu Docteur, veuillez choisir un choix: " << endl << endl;

    bool termine = false;
    while(!termine){
		
		cout << endl;
		cout << endl;
        cout << "1. \tSe deconnecter" << endl;
        cout << "2. \tAnalyse empreinte" << endl;
        cout << "3. \tAffichage des maladies prises en compte" << endl;
        cout << "4. \tDescription des caracteristiques d'une maladie" << endl << endl;
        cout << "Entrer 1, 2, 3 ou 4 suivant l option que vous souhaitez utiliser puis appuyer sur la touche entrer." << endl;
        cout << "Votre choix : ";

        char choix = outil_ObtenirChoix();

        switch (choix) {
            case '1': {
                cout << "VOUS ETES DECONNECTE" << endl << endl;
                termine=true;
                break;
            }
            case '2': {
				gestUt.ecritureLog("Log.txt", prenom, nom, "Analyse");
                cout << "Analyse Empreinte" << endl << endl;
                cout << "Nom Fichier ? " << endl;
                cin >> valeurCommande;
				cin.ignore();
                gestRisques.analyserFichier(valeurCommande);
                break;
            }
            case '3': {
				gestUt.ecritureLog("Log.txt", prenom, nom, "Affichage");
                cout << "Affichage des maladies prises en compte" << endl << endl;
                gestRisques.afficherMaladies();
                break;
            }
            case '4': {
				gestUt.ecritureLog("Log.txt", prenom, nom, "Description");
                cout << "Description des caracteristiques d une maladie" << endl << endl;
                cout << "Nom de la maladie ?" << endl;
                cin >> valeurCommande;
				cin.ignore();
                gestRisques.chercherMaladie(valeurCommande);
                break;
            }
            default: {
                cout << endl << "ATTENTION : Vous n avez pas pris un choix valide." << endl << endl;
                break;
            }
        }

    }
}



void Menu_ConnexionAdministrateur() {

	/* Demande de renseignements */
	cout << endl << endl << "Connexion Administrateur" << endl << endl;
	string nom = "---";
	string prenom = "---";
	string motpasse = "---";
	cout << "Entrez vos donnees toutes en majuscules, s il vous plait, sauf votre mot de passe : " << endl << endl << "Nom : ";
	getline(cin, nom);
	cout << "Prenom : ";
	getline(cin, prenom);
	cout << "Mot de passe : ";
	getline(cin, motpasse);
	cout << endl;
	/* Appel a la methode connexion */

	GestionUtilisateur uneGestionUtilisateur;
	if (uneGestionUtilisateur.connexion(nom, prenom, motpasse, "ListeAdministrateurs.txt"))
	{
		Menu_AdministrateurConnecte(prenom, nom);
	}
	else
	{
		Menu_Principal();
	}
}



void Menu_AdministrateurConnecte(string prenom, string nom) {

	GestionUtilisateur gestUt;
	gestUt.ecritureLog("Log.txt", prenom, nom, "Connexion");

	cout << "---------------------------------------------------------------------------------------------------";

	cout << endl << endl << "Bien Administrateur, veuillez choisir un choix: " << endl << endl;

    bool termine=false;
    while(!termine)
    {
		cout << endl;
		cout << endl;
        cout << "1. \tSe deconnecter" << endl;
        cout << "2. \tModifier le fichier" << endl;
        cout << "Entrer 1 ou 2 suivant l option que vous souhaitez utiliser puis appuyer sur la touche entrer." << endl << endl;
        cout << "Votre choix : ";

        char choix = outil_ObtenirChoix();
        switch (choix) {
            case '1': {
                cout << "VOUS ETES DECONNECTE" << endl << endl;
                termine=true;
                break;
            }
            case '2': {
                cout << "Modifier le fichier" << endl << endl;
				gestUt.ecritureLog("Log.txt", prenom, nom, "Modification");
                Menu_ModificationFichier();
                break;
            }
            default: {
                cout << endl << "ATTENTION : Vous n avez pas pris un choix valide." << endl << endl;
                break;
            }
        }
    }
}
void Menu_ModificationFichier()

{
	GestionRisques gestRisques;
	string ligne;
	cout << "---------------------------------------------------------------------------------------------------" << endl;

	bool termine=false;
    while(!termine)
    {

		cout << endl;
		cout << endl;
        cout << "1. \tAjouter une ligne" << endl;
        cout << "2. \tSupprimer une ligne" << endl;
        cout << "3. \tSupprimer une empreinte via son ID" << endl;
		cout << "4. \tRevenir au menu" << endl;
        cout << "Entrer 1, 2, 3 ou 4 suivant l option que vous souhaitez utiliser puis appuyer sur la touche entrer." << endl << endl;
        char choix = outil_ObtenirChoix();
        switch (choix) {
            case '1': {
                cout << "Ajout de ligne" << endl << endl;
                cout << "Ligne a ajouter ?" << endl;
                getline(cin, ligne);
                gestRisques.ajouterLignes("F3_ok.txt", ligne);
                break;
            }
            case '2': {
                cout << "Suppression de ligne" << endl << endl;
                cout << "Ligne a supprimer ?" << endl;
                getline(cin, ligne);
                gestRisques.supprimerLignes("F3_ok.txt", ligne);
                break;
            }
            case '3': {
                cout << "Suppression de l empreinte" << endl << endl;
                cout << "ID de l Empreinte ?" << endl;
                getline(cin, ligne);
                gestRisques.supprimerEmpreinte("F3_ok.txt", ligne);
                break;
            }
			case '4': {
				return;
			}
            default: {
                cout << endl << "ATTENTION : Vous n avez pas pris un choix valide." << endl << endl;
                break;
            }
        }
    }
}


void Menu_InscriptionDocteur() {

    bool termine=false;
    while(!termine)
    {
        cout << endl << "Veuillez inserez vos donnees personnelles a enregistrer, s il vous plait : " << endl << endl;

        cout << "1. \tNom : ";
        string Nom = outil_ObtenirMot();
        cout << "2. \tPrenom : ";
        string Prenom = outil_ObtenirMot();
        cout << "3. \tVotre courriel electronique : ";
        string Courriel = outil_ObtenirMot();
        cout << "4. \tVotre mot de passe : ";
        string Motpasse = outil_ObtenirMot();

        cout << "---------------------------------------------------------------------------------------------------";
        cout << endl << endl << "Ce sont les donnees que vous avez choisi : " << endl << endl;
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
                break;
            }
            case '2': {
                GestionUtilisateur uneGestionUtilisateur;
                uneGestionUtilisateur.creerCompte(Nom, Prenom, Courriel, Motpasse, "ListeDocteurs.txt");
                cout << "VOTRE COMPTE A ETE CREE" << endl;
                termine=true;
                break;
            }
            case '3': {
                cout << "INSCRIPTION ANNULEE" << endl;
                termine=true;
                break;
            }
            default: {
                cout << endl << "ATTENTION : Vous n'avez pas pris un choix valide." << endl << endl;
                cout << "INSCRIPTION NON REUSSIE" << endl;
                termine=true;
                break;
            }
        }
    }
}



int Menu_Principal() {

	cout << endl;
	cout << "---------------------------------------------------------------------------------------------------";
	cout << endl;
	cout << endl << "BIENVENU a l'application des tests medicaux d empreintes" << endl << endl;

    bool termine=false;
    while(!termine)
    {
		cout << endl;
		cout << endl;
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
                termine=true;
                return 1; // On sort de l'application
            }
            default: {
                return 0; // On reste dans l'application
            }
        }
    }
    return 0;
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
