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
//------------------------------------------------------ Include personnel

#include "GestionRisques.h"
#include "Empreinte.h"
#include "Categoriel.h"
#include "Numerique.h"
#include "Attribut.h"
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
	Empreinte e;
	while (entreeFichier.good())
	{

		getline(entreeFichier, line);
		stringstream ss;
		ss.str(line);
		string valeurAttribut;
		getline(ss, valeurAttribut, ';');
		for (int i = 0; i < Empreinte::format.size(); i++)
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
				Attribut * a = new Categoriel(Empreinte::format[i].first, valeurAttribut);
				e.ajouterAttribut(a);
			}
			else if (Empreinte::format[i].second.compare("Numerique") == 0)
			{
				Attribut * a = new Numerique(Empreinte::format[i].first, stoi(valeurAttribut));
				e.ajouterAttribut(a);
			}
			else
			{
				cout << "Erreur : l'un des attributs n'est ni numerique, ni categoriel" << endl;
				abort();
			}
		}
			

	}

			/*pair<string, string> nouvellePaire = make_pair(nomAttribut, typeAttribut);
			format.push_back(nouvellePaire);*/


		}
	}
}

void GestionRisques::chercherMaladie(string nomMaladie)
{
}

void GestionRisques::afficherMaladies()
{
}

void GestionRisques::initMaladies()
{

}
  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Méthodes protégées










