/*************************************************************************
                           Docteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Docteur> (fichier Docteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Docteur.h"

//------------------------------------------------------------- Constantes
#define MAP ;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
ostream& operator<<(ostream &strm, const Docteur& Doc)
//Pour afficher
{
	strm << "Nom : " << Doc.nom << ", prenom : " << Doc.prenom << " , mdp : " << Doc.motDePasse << ", adresse : " << Doc.adresse;
	return strm;
}
//-------------------------------------------- Constructeurs - destructeur


Docteur::Docteur(const Docteur & unDocteur) : Utilisateur(unDocteur.nom, unDocteur.prenom, unDocteur.motDePasse, unDocteur.adresse)
// Algorithme :
// Un constructeur de copie.
{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Docteur>" << endl;
#endif


} //----- Fin de Docteur (constructeur de copie)


Docteur::Docteur ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Docteur>" << endl;
		#endif

	} //----- Fin de Docteur

Docteur::Docteur(string nomT, string prenomT, string motDePasseT, string adresseT) : Utilisateur(nomT, prenomT, motDePasseT, adresseT)
// Algorithme :
// Un constructeur 
{
#ifdef MAP
	cout << "Appel au constructeur de <Docteur>" << endl;
#endif

} 

Docteur::~Docteur ()
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Docteur>" << endl;
		#endif


	} //----- Fin de ~Docteur
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
