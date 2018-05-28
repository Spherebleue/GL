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
}

void GestionRisques::afficherMaladies()
{
}

void GestionRisques::initMaladies(string nomFichier)
{
	ifstream entreeFichier;
	entreeFichier.open(nomFichier);

	assert(entreeFichier);                        //verifie que le fichier est bien trouve

	string line;
	getline(entreeFichier, line);
	multimap<string, Empreinte> liste;

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

		pair <multimap<string, Empreinte>::iterator, multimap<string, Empreinte>::iterator> ret;
		ret = liste.equal_range("Aucune");


		//for (multimap<string, Empreinte>::iterator it = ret.first; it != ret.second; ++it)

		for (auto i = ret.first; i != ret.second; ++i)
		{

		}
	}
}
        //pair<

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
						fichier << vectMaladies[i].getListeCritere()[j]->getNom() << ";" << vectMaladies[i].getListeCritere()[j]->getUtile();
	
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










