#if ! defined ( Utilisateur_H )
#define Utilisateur_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

class Utilisateur
{
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------Fonction amies
public:
	friend ostream& operator<<(ostream&, const Utilisateur &);

//-------------------------------------------- Constructeurs - destructeur

	Utilisateur();
    // Mode d'emploi :
    // Un constructeur par défaut

    Utilisateur ( const Utilisateur & unUtilisateur);
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre


	Utilisateur(string, string, string, string);
	// Mode d'emploi :
	// Un constructeur


    virtual ~Utilisateur( );
    // Mode d'emploi :
    // Destructeur de Utilisateur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string nom;
	string prenom;
	string motDePasse;
	string adresse;

};

#endif

