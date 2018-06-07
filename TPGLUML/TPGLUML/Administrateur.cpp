/*************************************************************************
Administrateur  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Realisation de la classe <Administrateur> (fichier Administrateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Administrateur.h"


//------------------------------------------------------------- Constantes
//#define MAP ;


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

ostream& operator<<(ostream &strm, const Administrateur& Ad)
//Pour afficher
{
	strm << "Nom : " << Ad.nom << ", prenom : " << Ad.prenom << " , mdp : " << Ad.motDePasse << ", adresse : " << Ad.adresse;
	return strm;
}
//-------------------------------------------- Constructeurs - destructeur
Administrateur::Administrateur ( const Administrateur & unAdministrateur ) : Utilisateur (unAdministrateur.nom, unAdministrateur.prenom, unAdministrateur.motDePasse, unAdministrateur.adresse)
// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Administrateur>" << endl;
		#endif


	} //----- Fin de Administrateur (constructeur de copie)


Administrateur::Administrateur ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Administrateur>" << endl;
		#endif

	} //----- Fin de Administrateur

Administrateur::Administrateur(string nomT, string prenomT, string motDePasseT, string adresseT) : Utilisateur(nomT, prenomT,motDePasseT,adresseT)
// Algorithme :
// Un constructeur 
{
#ifdef MAP
	cout << "Appel au constructeur de <Administrateur>" << endl;
#endif

} //----- Fin de Administrateur



Administrateur::~Administrateur ( )
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Administrateur>" << endl;
		#endif


	} //----- Fin de ~Administrateur
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
