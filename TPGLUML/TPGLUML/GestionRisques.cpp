/*************************************************************************
GestionRisques  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
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
//------------------------------------------------------ Include personnel

#include "GestionRisques.h"
#include "Empreinte.h"
#include "Categoriel.h"
#include "Numerique.h"
#include "Attribut.h"
#include "CritereCategoriel.h"
#include "CritereNumerique.h"
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
//---- Fin de GestionRisques


GestionRisques::~GestionRisques()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <GestionRisques>" << endl;
#endif

} //----- Fin de ~GestionRisques

void GestionRisques::analyserFichier(string nomFichier)
{
	ifstream entreeFichier;
	entreeFichier.open(nomFichier);

	assert(entreeFichier);                        //verifie que le fichier est bien trouve

	string line;
	getline(entreeFichier, line);
	vector <Empreinte *> vectEmpreinte;
	while (entreeFichier.good())
	{
		Empreinte * e = new Empreinte();
		getline(entreeFichier, line);
		stringstream ss;
		ss.str(line);
		string valeurAttribut;
		getline(ss, valeurAttribut, ';');
		for (int i = 0; i < int (Empreinte::format.size()); i++)
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
				//cout << *a << endl;
				e->ajouterAttribut(a);
			}
			else if (Empreinte::format[i].second.compare("Numerique") == 0)
			{
				Numerique * a = new Numerique(Empreinte::format[i].first, stod(valeurAttribut));
				//cout << *a << endl;
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
	//cout << (vectEmpreinte.size()) << endl;
	for (int i = 0; i < int(vectEmpreinte.size()); i++)
	{
		cout << (*vectEmpreinte[i]) << endl;
	}

				
	
}

void GestionRisques::chercherMaladie(string nomMaladie)
{
	ifstream entreeFichier;
	entreeFichier.open("ListeMaladies.txt");
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
			cout << "Nom maladie " << nomMaladieFichier << endl;
			if (nomMaladieFichier.compare(nomMaladie) == 0)
			{
				trouve = true;
				cout << "Maladie demandée : " << nomMaladie << endl;
			}
			else
			{
				getline(entreeFichier, ligne);

			}
		}
			for (int i = 0; i< int(Empreinte::format.size()); i++)
			{
				
				cout << Empreinte::format[i].first << " : ";
				getline(ss, ligne, ';');
				cout << "Utilite - " << ligne;
				if (ligne.compare("1") == 0)
				{
					if (Empreinte::format[i].second.compare("Categoriel") == 0)
					{
						if (i == Empreinte::format.size())
						{
							getline(ss, ligne);

						}
						else
						{
							getline(ss, ligne, ';');
						}
						cout << "; Categorie - " << ligne;

					}
					else if (Empreinte::format[i].second.compare("Numerique") == 0)
					{
						getline(ss, ligne, ';');
						cout << "; Moyenne - " << ligne;
						if (i == Empreinte::format.size())
						{
							getline(ss, ligne);

						}
						else
						{
							getline(ss, ligne, ';');
							
						}
						cout << "; Ecart-Type - " << ligne;


					}
				}
				cout << endl;
				


			}
			
		


		entreeFichier.close();
	}
	else
	{

		cerr << "Problème d'ouverture de fichier " << endl;
	}

}

void GestionRisques::afficherMaladies()
{
	ifstream entreeFichier;
	entreeFichier.open("ListeMaladies.txt");
	string ligne;
	if (entreeFichier)
	{
		cout << "Liste des maladies prises en compte : " << endl;
		getline(entreeFichier, ligne);
		while (entreeFichier.good()) {
			stringstream ss;
			ss.str(ligne);
			getline(ss, ligne, ';');
			cout << ligne << endl;
			getline(entreeFichier, ligne);
			}		
		entreeFichier.close();
	}
	else
	{

		cerr << "Problème d'ouverture de fichier " << endl;
	}

}

void GestionRisques::initMaladies(string nomFichier)
{
	ifstream entreeFichier;
	entreeFichier.open(nomFichier);

	assert(entreeFichier);                        //verifie que le fichier est bien trouve

	string line;
	getline(entreeFichier, line);
	vector<Maladie> defMaladies;
	multimap<string, Empreinte> liste;
	set<string> nomDesMaladies;
	while (entreeFichier.good())
	{
		Empreinte * e = new Empreinte();
		getline(entreeFichier, line);
		stringstream ss;
		ss.str(line);
		string valeurAttribut;
		getline(ss, valeurAttribut, ';');
		string maladie = "";
		for (int i = 0; i <= int(Empreinte::format.size()); i++)
		{
			if (i == (Empreinte::format.size() + 1))
			{
				getline(ss, maladie);
				if (maladie.compare("") == 0)
				{
					maladie = "Aucune";
				}
				//ICI : recuperer le nom de la maladie ou "Aucune" si vide (je sais pas ce qui se passe si vide)
			}
			else
			{
				getline(ss, valeurAttribut, ';');
			}


			if (Empreinte::format[i].second.compare("Categoriel") == 0) //verifie que le type est bien le bon
			{
				Categoriel * a = new Categoriel(Empreinte::format[i].first, valeurAttribut);
				//cout << *a << endl;
				e->ajouterAttribut(a);
			}
			else if (Empreinte::format[i].second.compare("Numerique") == 0)
			{
				Numerique * a = new Numerique(Empreinte::format[i].first, stod(valeurAttribut));
				//cout << *a << endl;
				e->ajouterAttribut(a);
			}
			else
			{
				cout << "Erreur : l'un des attributs n'est ni numerique, ni categoriel" << endl;
				abort();
			}

		}
		//cout << *e << endl;
		liste.insert(pair<string, Empreinte>(maladie, *e));
		if (nomDesMaladies.find("maladie") == nomDesMaladies.end())
		{
			nomDesMaladies.insert(maladie);
		}


	}

	//----------------------------------CREATION DE LA MALADIE "AUCUNE"
	pair <multimap<string, Empreinte>::iterator, multimap<string, Empreinte>::iterator> ret;
	ret = liste.equal_range("Aucune");

	Maladie mAucune = new Maladie("Aucune", Empreinte::format.size());
	for (int att = 0; att <= int(Empreinte::format.size()); att++)
	{
		if (Empreinte::format[i].second.compare("Categoriel") == 0)
		{
			map<string, int> nbApparition;
			for (auto i = ret.first; i != ret.second; ++i)
			{
				string val = i->second[att].valeur;
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
			CritereCategoriel * c = new Critere(Empreinte::format[i].first, true, valMax);
			mAucune.ajouterCritere(c, att);
		}
		else
		{
			double somme = 0;
			int nbAtt = 0;
			for (auto i = ret.first; i != ret.second; ++i)
			{
				somme += i->second[att].valeur;
				nbAtt++;
			}
			double moyenne = somme / nbAtt;
			somme = 0;
			for (auto i = ret.first; i != ret.second; ++i)
			{
				somme += (i->second[att].valeur - moyenne)*(i->second[att].valeur - moyenne);
			}
			double ecartType = sqrt(somme / nbAtt);
			CritereNumerique * c = new CritereNumerique(Empreinte::format[i].first, true, ecartType, moyenne);
			mAucune.ajouterCritere(c, att);
		}

	}
	defMaladies.push_back(mAucune);
	//----------------------------FIN DE L'INIT de "AUCUNE"

	//----------------------------ANALYSE DE TOUTE LES MALADIES
	nomDesMaladies.erase("Aucune");
	for (int i = 0; i < nomDesMaladies.size(); i++)
	{
		pair <multimap<string, Empreinte>::iterator, multimap<string, Empreinte>::iterator> ret;
		ret = liste.equal_range(nomDesMaladies[i]);





		Maladie uneMaladie = new Maladie(nomDesMaladies[i], Empreinte::format.size());
		for (int att = 0; att <= int(Empreinte::format.size()); att++)
		{
			if (Empreinte::format[i].second.compare("Categoriel") == 0)
			{
				map<string, int> nbApparition;
				for (auto i = ret.first; i != ret.second; ++i)
				{
					string val = i->second[att].valeur;
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
				bool valid = true;
				if (valMax.compare(mAucune.getListeCritere()[att]->categorie) == 0)
				{
					valid = false;
				}
				CritereCategoriel * c = new Critere(Empreinte::format[i].first, valid, valMax);
				uneMaladie.ajouterCritere(c, att);
			}
			else
			{
				double somme = 0;
				int nbAtt = 0;
				for (auto i = ret.first; i != ret.second; ++i)
				{
					somme += i->second[att].valeur;
					nbAtt++;
				}
				double moyenne = somme / nbAtt;
				somme = 0;
				for (auto i = ret.first; i != ret.second; ++i)
				{
					somme += (i->second[att].valeur - moyenne)*(i->second[att].valeur - moyenne);
				}
				double ecartType = sqrt(somme / nbAtt);

				//Vérification de la pertinance du critère (utile)
				bool valid = true;
				if ((mAucune.getListeCritere()[att]->moyenne - 1.96*mAucube.getListeCritere()[att]->ecartType <= moyenne)
					&& (moyenne >= mAucune.getListeCritere()[att]->moyenne + 1.96*mAucube.getListeCritere()[att]->ecartType))
				{
					valid = false;
				}
				CritereNumerique * c = new CritereNumerique(Empreinte::format[i].first, valid, ecartType, moyenne);
				uneMaladie.ajouterCritere(c, att);
			}
		}


	}



}

void GestionRisques::enregistrerMaladies(vector<Maladie> vectMaladies)
{
			ofstream fichier("ListeMaladies.txt", ios::trunc);
			
			if (fichier)
			{
				for (int i = 0; i < vectMaladies.size(); i++)
				{

					fichier << vectMaladies[i].getNom() << ";";
					for (int j = 0; j<int(Empreinte::format.size()); j++)
					{
						fichier << vectMaladies[i].getListeCritere()[j]->getUtile();
	
						if (vectMaladies[i].getListeCritere()[j]->getUtile() == true)
						{
					
							if (Empreinte::format[j].second.compare("Categoriel") == 0) //verifie que le type est bien le bon
							{
								fichier << ";" << (dynamic_cast<CritereCategoriel*> ((vectMaladies[i].getListeCritere()[j])))->getCategorie();
						
							}
							else if (Empreinte::format[j].second.compare("Numerique") == 0)
							{
								fichier << ";" << (dynamic_cast<CritereNumerique*> ((vectMaladies[i].getListeCritere()[j])))->getMoyenne() << ";" << (dynamic_cast<CritereNumerique*> ((vectMaladies[i].getListeCritere()[j])))->getEcartType();
							}
						}
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










