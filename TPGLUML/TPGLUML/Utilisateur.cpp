/*************************************************************************
Utilisateur  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Utilisateur> (fichier Utilisateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Utilisateur.h"


//------------------------------------------------------------- Constantes
//#define MAP ;


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
ostream& operator<<(ostream &strm, const Utilisateur &Ut)
//Pour afficher
{
	strm << "Nom : " << Ut.nom << ", prenom : " << Ut.prenom << " , mdp : " << Ut.motDePasse <<", adresse : " << Ut.adresse;
	return strm;
}

//-------------------------------------------- Constructeurs - destructeur
Utilisateur::Utilisateur ( const Utilisateur & unUtilisateur ) : nom(unUtilisateur.nom), prenom(unUtilisateur.prenom), motDePasse(unUtilisateur.motDePasse), adresse(unUtilisateur.adresse)
// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Utilisateur>" << endl;
		#endif


	} //----- Fin de Utilisateur (constructeur de copie)


Utilisateur::Utilisateur ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Utilisateur>" << endl;
		#endif

	} //----- Fin de Utilisateur


Utilisateur::Utilisateur(string nomT, string prenomT, string motDePasseT, string adresseT) : nom(nomT), prenom(prenomT), motDePasse(motDePasseT), adresse(adresseT)
{

	#ifdef MAP
		cout << "Appel au constructeur de <Utilisateur>" << endl;
	#endif
}


Utilisateur::~Utilisateur ( )
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Utilisateur>" << endl;
		#endif


	} //----- Fin de ~Utilisateur
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
