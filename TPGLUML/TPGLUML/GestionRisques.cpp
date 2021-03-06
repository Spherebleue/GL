/*************************************************************************
GestionRisques  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GestionRisques> (fichier GestionRisques.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <fstream>
#include <string>
//------------------------------------------------------ Include personnel

#include "GestionRisques.h"
#include "Empreinte.h"
#include "Categoriel.h"
#include "Numerique.h"
#include "Attribut.h"
#include "CritereCategoriel.h"
#include "CritereNumerique.h"
#include "math.h"
//------------------------------------------------------------- Constantes
//#define MAP ;
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
//-------------------------------------------- Constructeurs - destructeur

GestionRisques::GestionRisques(const GestionRisques & unGestionRisques)
// Algorithme :
// Un constructeur de copie.
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <GestionRisques>" << endl;
#endif

} //----- Fin de GestionRisques (constructeur de copie)



GestionRisques::GestionRisques()
// Algorithme :
// Un constructeur par défaut.
{
#ifdef MAP
	cout << "Appel au constructeur de <GestionRisques>" << endl;
#endif

} //----- Fin de GestionRisques

GestionRisques::~GestionRisques()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <GestionRisques>" << endl;
#endif

} //----- Fin de ~GestionRisques

bool GestionRisques::analyserFichier(string nomFichier)
{
	ifstream entreeFichier;
	entreeFichier.open(nomFichier);

	string line;
	getline(entreeFichier, line);

	stringstream ss;
	ss.str(line);
	getline(ss, line, ';');
	int count = 0;
	while (ss.good())
	{
		getline(ss, line, ';');
		count++;
	}
	if (count != int(Empreinte::format.size()))
	{
		cout << "Erreur : le format du fichier " << nomFichier << " ne correspond pas au format des metadonnees" << endl;
		return false;
	}

	vector <Empreinte *> vectEmpreinte;
	while (entreeFichier.good()) // tant qu'il y a des empreintes , on cree des objets Empreinte que l'on met dans un vecteur
	{
		Empreinte * e = new Empreinte();
		getline(entreeFichier, line);
		stringstream ss;
		ss.str(line);
		string valeurAttribut;
		getline(ss, valeurAttribut, ';');
		if (valeurAttribut.compare("") != 0)
		{
			for (int i = 0; i < int(Empreinte::format.size()); i++)
			{
				if (i == Empreinte::format.size())
				{
					getline(ss, valeurAttribut);
				}
				else
				{
					getline(ss, valeurAttribut, ';');
				}
				if (Empreinte::format[i].second.compare("Categoriel") == 0) //verifie que le type est bien le bon
				{
					Categoriel * a = new Categoriel(Empreinte::format[i].first, valeurAttribut);
					e->ajouterAttribut(a);
				}
				else if (Empreinte::format[i].second.compare("Numerique") == 0)
				{
					Numerique * a = new Numerique(Empreinte::format[i].first, stod(valeurAttribut));
					e->ajouterAttribut(a);
				}
				else
				{
					cout << "Erreur : l'un des attributs n'est ni numerique, ni categoriel" << endl;
					abort();
				}
			}
			//cout << *e << endl;
			vectEmpreinte.push_back(e);
		}
	}
	entreeFichier.close();
	vector <string> empreinteMaladie; //le vecteur qui contiendra ce qu'il faudra afficher : les empreintes et leur maladies
	int compteurSymptomes;
	int nombreUtile = 0;
	double ecartType = 0.0;
	double moyenne = 0.0;
	string attribut;
	string nomMaladie = "je ne suis pas vide";
	string elementVecteur;
	

	for (int i = 0; i < int(vectEmpreinte.size()); i++)
	{
		ifstream entreeFichierMaladies;
		entreeFichierMaladies.open("Donnees/ListeMaladies.txt");
		assert(entreeFichierMaladies);
		string numero = to_string(i + 1);
		elementVecteur = "Empreinte numero" + numero + ": ";

		while (entreeFichierMaladies.good())
		{
			nombreUtile = 0;
			getline(entreeFichierMaladies, line);
			stringstream ss;
			ss.str(line);
			getline(ss, nomMaladie, ';');
			compteurSymptomes = 0;
			for (int j = 0; j < int(Empreinte::format.size()); j++)
			{
				getline(ss, attribut, ';');
				if (attribut.compare("") != 0)
				{
					if (attribut.compare("1") == 0)
					{
						nombreUtile++;
						getline(ss, attribut, ';');

						if (Empreinte::format[j].second.compare("Categoriel") == 0) // si c'est un type Catagoriel, on vérifie que la valeur est identique
						{
							if (attribut.compare(dynamic_cast <Categoriel*>(vectEmpreinte[i]->getListeAttribut()[j])->getValeur()) == 0)
								compteurSymptomes++;
						}
						else if (Empreinte::format[j].second.compare("Numerique") == 0) // s'il est numérique, on regarde si la valeur appartient à l'intervalle [moyenne - 2*ecartType ; moyenne + 2*ecartType] 
						{
							moyenne = stod(attribut);
							getline(ss, attribut, ';');
							ecartType = stod(attribut);
							if (dynamic_cast <Numerique*>(vectEmpreinte[i]->getListeAttribut()[j])->getValeur() <= (moyenne + 1.96*ecartType)
								&& dynamic_cast <Numerique*>(vectEmpreinte[i]->getListeAttribut()[j])->getValeur() >= (moyenne - 1.96*ecartType))
								compteurSymptomes++;
						}
					}
				}
			}
			if (((compteurSymptomes * 100 / nombreUtile) >= 90) && (nomMaladie.compare("Aucune") !=0)) //on considère que la personne a une maladie si elle a au moins 90% des symptomes
				elementVecteur = elementVecteur + nomMaladie + " ";
		}
		empreinteMaladie.push_back(elementVecteur);
		entreeFichierMaladies.close();
	}
	for (int t = 0; t< empreinteMaladie.size(); t++)
	{
		if (empreinteMaladie[t].compare("Empreinte numero" + to_string(t+1) + ": ")==0)
			cout << empreinteMaladie[t] << "aucune "<< endl;
		else
			cout << empreinteMaladie[t]  << endl;
	}
	return true;
}

bool GestionRisques::chercherMaladie(string nomMaladie)
{
	ifstream entreeFichier;
	entreeFichier.open("Donnees/ListeMaladies.txt");
	string ligne;
	string nomMaladieFichier;
	bool trouve = false;
	stringstream ss;

	if (entreeFichier)
	{
		getline(entreeFichier, ligne);
		while (entreeFichier.good() && trouve == false) {
			ss.str(ligne);
			getline(ss, nomMaladieFichier, ';');
			if (nomMaladieFichier.compare(nomMaladie) == 0)
			{
				trouve = true;
				cout << "Maladie demandee : " << nomMaladie << endl;
			}
			else
			{
				getline(entreeFichier, ligne);
			}
		}
		if (trouve == true)
		{
			for (int i = 0; i< int(Empreinte::format.size()); i++)
			{
				cout << Empreinte::format[i].first << " : ";
				getline(ss, ligne, ';');
				cout << "Utilite - " << ligne;
				if (ligne.compare("1") == 0)
				{
					if (Empreinte::format[i].second.compare("Categoriel") == 0)
					{

						getline(ss, ligne, ';');

						cout << "; Categorie - " << ligne;
					}
					else if (Empreinte::format[i].second.compare("Numerique") == 0)
					{
						getline(ss, ligne, ';');
						cout << "; Moyenne - " << ligne;
						getline(ss, ligne, ';');

						cout << "; Ecart-Type - " << ligne;
					}
				}
				cout << endl;
			}
			entreeFichier.close();
		}
		else
		{
			cout << "La maladie n a pas ete trouve" << endl;
			return false;
		}
	}
	else
	{
		cerr << "Probleme d'ouverture de fichier " << endl;
		return false;
	}
	return true;
}

void GestionRisques::afficherMaladies()
{
	ifstream entreeFichier;
	entreeFichier.open("Donnees/ListeMaladies.txt");
	string ligne;
	if (entreeFichier)
	{
		cout << "Liste des maladies prises en compte : " << endl;
		while (entreeFichier.good()) {
			getline(entreeFichier, ligne);
			stringstream ss;
			ss.str(ligne);
			getline(ss, ligne, ';');
			if (ligne.compare("Aucune")!=0)
				cout << ligne << endl;
		}
		entreeFichier.close();
	}
	else
	{
		cerr << "Problème d'ouverture de fichier " << endl;
	}
}

multimap<string, Empreinte> GestionRisques::creerEmpreintesAvecMaladie(string nomFichier)
{
	ifstream entreeFichier;
	entreeFichier.open(nomFichier);
	string line = "je suis pas vide";
	getline(entreeFichier, line);
	multimap<string, Empreinte> liste;
	set<string> nomDesMaladies;

	while (entreeFichier.good())
	{
		Empreinte e;
		getline(entreeFichier, line);
		stringstream ss;
		ss.str(line);
		string valeurAttribut;
		getline(ss, valeurAttribut, ';');
		string maladie = "";
		if (valeurAttribut.compare("") == 0)
		{
			return liste;
		}
		for (int i = 0; i <= int(Empreinte::format.size()); i++)
		{
			if (i == (Empreinte::format.size()))
			{
				getline(ss, maladie, '\r');
				if (maladie.compare("") == 0)
				{
					maladie = "Aucune";
				}
			}
			else
			{
				getline(ss, valeurAttribut, ';');
				if (Empreinte::format[i].second.compare("Categoriel") == 0) //verifie que le type est bien le bon
				{
					Categoriel * a = new Categoriel(Empreinte::format[i].first, valeurAttribut);
					//cout << *a << endl;
					e.ajouterAttribut(a);
				}
				else if (Empreinte::format[i].second.compare("Numerique") == 0)
				{
					Numerique * a = new Numerique(Empreinte::format[i].first, stod(valeurAttribut));
					e.ajouterAttribut(a);
				}
				else
				{
					cout << "Erreur : l'un des attributs n'est ni numerique, ni categoriel" << endl;
					abort();
				}

			}
		}
		liste.insert(make_pair(maladie, e));
	}
	entreeFichier.close();
	return liste;
}

void GestionRisques::initMaladies(string nomFichier)
{
	vector<Maladie> defMaladies;
	multimap<string, Empreinte> liste = creerEmpreintesAvecMaladie(nomFichier);
	set<string> nomDesMaladies;

	for (auto it = liste.begin(); it != liste.end(); ++it)
	{
		if (nomDesMaladies.find((*it).first) == nomDesMaladies.end())
		{
			nomDesMaladies.insert((*it).first);
		}
	}

	//----------------------------------CREATION DE LA MALADIE "AUCUNE"
	pair <multimap<string, Empreinte>::iterator, multimap<string, Empreinte>::iterator> bordListe;
	bordListe = liste.equal_range("Aucune");

	Maladie mAucune("Aucune");
	for (int att = 0; att < int(Empreinte::format.size()); att++)
	{
		if (Empreinte::format[att].second.compare("Categoriel") == 0)
		{
			map<string, int> nbApparition;
			for (auto i = bordListe.first; i != bordListe.second; ++i)
			{
				string val = (dynamic_cast<Categoriel*> (i->second.getListeAttribut()[att]))->getValeur();
				auto testPresence = nbApparition.find(val);
				if (testPresence != nbApparition.end())
				{
					testPresence->second += 1;
				}
				else
				{
					nbApparition.insert(pair<string, int>(val, 1));
				}
			}
			//Parcours de la map pour trouver la valeur qui apparait le plus souvent
			int max = 0;
			string valMax;
			for (auto i = nbApparition.begin(); i != nbApparition.end(); i++)
			{
				if (i->second > max)
				{
					max = i->second;
					valMax = i->first;
				}
			}
			CritereCategoriel * c = new CritereCategoriel(Empreinte::format[att].first, true, valMax);
			mAucune.ajouterCritere(c, att);
		}
		else
		{
			double somme = 0;
			int nbAtt = 0;
			for (auto i = bordListe.first; i != bordListe.second; ++i)
			{
				somme += (dynamic_cast<Numerique*> (i->second.getListeAttribut()[att]))->getValeur();
				nbAtt++;
			}
			double moyenne = somme / nbAtt;
			somme = 0;
			for (auto i = bordListe.first; i != bordListe.second; ++i)
			{
				double valeur = (dynamic_cast<Numerique*> (i->second.getListeAttribut()[att]))->getValeur();
				somme += (valeur - moyenne)*(valeur - moyenne);
			}
			double ecartType = sqrt(somme / nbAtt);
			CritereNumerique * c = new CritereNumerique(Empreinte::format[att].first, true, ecartType, moyenne);
			mAucune.ajouterCritere(c, att);
		}

	}
	defMaladies.push_back(mAucune);
	//----------------------------FIN DE L'INIT de "AUCUNE"

	//----------------------------ANALYSE DE TOUTE LES MALADIES
	nomDesMaladies.erase("Aucune");
	for (auto i = nomDesMaladies.begin(); i != nomDesMaladies.end(); i++)
	{
		pair <multimap<string, Empreinte>::iterator, multimap<string, Empreinte>::iterator> bordListe;
		bordListe = liste.equal_range(*i);

		Maladie uneMaladie(*i);
		for (int att = 0; att < int(Empreinte::format.size()); att++)
		{
			if (Empreinte::format[att].second.compare("Categoriel") == 0)
			{
				map<string, int> nbApparition;
				//on compte le nombre d'apparition pour chaque attribut
				for (auto j = bordListe.first; j != bordListe.second; ++j)
				{
					string val = (dynamic_cast<Categoriel*> (j->second.getListeAttribut()[att]))->getValeur();
					auto testPresence = nbApparition.find(val);
					if (testPresence != nbApparition.end())
					{
						testPresence->second += 1;
					}
					else
					{
						nbApparition.insert(pair<string, int>(val, 1));
					}
				}

				//Parcours de la map pour trouver la valeur qui apparait le plus souvent
				int max = 0;
				string valMax;
				for (auto j = nbApparition.begin(); j != nbApparition.end(); j++)
				{
					if (j->second > max)
					{
						max = j->second;
						valMax = j->first;
					}
				}
				bool valid = true;
				if (valMax.compare(dynamic_cast<CritereCategoriel*> (mAucune.getListeCritere()[att])->getCategorie()) == 0)
				{
					valid = false;
				}
				CritereCategoriel * c = new CritereCategoriel(Empreinte::format[att].first, valid, valMax);
				uneMaladie.ajouterCritere(c, att);
			}
			else
			{
				double somme = 0;
				int nbAtt = 0;
				for (auto i = bordListe.first; i != bordListe.second; ++i)
				{
					somme += (dynamic_cast<Numerique*> (i->second.getListeAttribut()[att]))->getValeur();
					nbAtt++;
				}
				double moyenne = somme / nbAtt;
				somme = 0;
				for (auto i = bordListe.first; i != bordListe.second; ++i)
				{
					double valeur = (dynamic_cast<Numerique*> (i->second.getListeAttribut()[att]))->getValeur();
					somme += (valeur - moyenne)*(valeur - moyenne);
				}
				double ecartType = sqrt(somme / nbAtt);

				//Vérification de la pertinance du critère (utile)
				bool valid = true;

				double moyenneAucune = dynamic_cast<CritereNumerique*> (mAucune.getListeCritere()[att])->getMoyenne();
				double ecartTypeAucune = dynamic_cast<CritereNumerique*> (mAucune.getListeCritere()[att])->getEcartType();

				if ((moyenne >= moyenneAucune - 1.96*ecartTypeAucune) && (moyenne <= moyenneAucune + 1.96*ecartTypeAucune))
				{
					valid = false;
				}
				CritereNumerique * c = new CritereNumerique(Empreinte::format[att].first, valid, ecartType, moyenne);
				uneMaladie.ajouterCritere(c, att);
			}
		}
		defMaladies.push_back(uneMaladie);
	}
	enregistrerMaladies(defMaladies);
}


void GestionRisques::supprimerEmpreinte(string nomFichier, string empreinteAEffacer)
{
	string ligne;
	ifstream lectureFichier(nomFichier);
	if (!lectureFichier.is_open())
	{
		cout << "Erreur lors de l'ouverture" << endl;
		return;
	}
	ofstream ecritureFichier("nouveauFichier.txt");
	while (getline(lectureFichier, ligne, ';'))
	{
		if (ligne != empreinteAEffacer)
		{
			ecritureFichier << ligne << ";";
			getline(lectureFichier, ligne);
			ecritureFichier << ligne << "\n";
		}
		else
		{
			getline(lectureFichier, ligne);
		}
	}
	lectureFichier.close();
	ecritureFichier.close();
	remove(nomFichier.c_str());
	rename("nouveauFichier.txt", nomFichier.c_str());


}

void GestionRisques::supprimerLignes(string nomFichier, string ligneAEffacer)
{
	string ligne;

	ifstream lectureFichier(nomFichier);
	if (!lectureFichier.is_open())
	{
		cout << "Erreur lors de l'ouverture" << endl;
		return;
	}
	ofstream ecritureFichier("nouveauFichier.txt");
	while (getline(lectureFichier, ligne))
	{
		if (ligne != ligneAEffacer)
			ecritureFichier << ligne << "\n";
	}
	lectureFichier.close();
	ecritureFichier.close();
	remove(nomFichier.c_str());
	rename("nouveauFichier.txt", nomFichier.c_str());


}

void GestionRisques::ajouterLignes(string nomFichier, string ligneAAjouter)
{
	ofstream fichier(nomFichier, ios::app);
	fichier << ligneAAjouter << endl;
	fichier.close();


}

void GestionRisques::enregistrerMaladies(vector<Maladie> vectMaladies)
{
	ofstream fichier("Donnees/ListeMaladies.txt", ios::trunc);

	if (fichier)
	{
		for (int i = 0; i < vectMaladies.size(); i++)
		{
			fichier << vectMaladies[i].getNom() << ";";
			for (int j = 0; j<int(Empreinte::format.size()); j++)
			{
				fichier << vectMaladies[i].getListeCritere()[j]->getUtile() << ";";

				if (vectMaladies[i].getListeCritere()[j]->getUtile() == true)
				{
					if (Empreinte::format[j].second.compare("Categoriel") == 0) //verifie que le type est bien le bon
					{
						fichier << (dynamic_cast<CritereCategoriel*> ((vectMaladies[i].getListeCritere()[j])))->getCategorie() << ";";

					}
					else if (Empreinte::format[j].second.compare("Numerique") == 0)
					{
						fichier << (dynamic_cast<CritereNumerique*> ((vectMaladies[i].getListeCritere()[j])))->getMoyenne() << ";" << (dynamic_cast<CritereNumerique*> ((vectMaladies[i].getListeCritere()[j])))->getEcartType() << ";";
					}

				}
			}
			if (i<vectMaladies.size() - 1) {
				fichier << endl;
			}
		}
		fichier.close();
	}
	else
	{
		cerr << "Problème d'ouverture de fichier " << endl;
	}
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées












