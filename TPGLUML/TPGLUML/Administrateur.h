#if ! defined ( Administrateur_H )
#define Administrateur_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "Utilisateur.h"

class Administrateur : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------Fonction amies
public:
	friend ostream& operator<<(ostream&, const Administrateur &);

//-------------------------------------------- Constructeurs - destructeur
    Administrateur ( const Administrateur & unAdministrateur); 
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre

	Administrateur();
    // Mode d'emploi :
    // Un constructeur par défaut

	Administrateur(string, string, string, string);
	// Mode d'emploi :
	// un constructeur


    virtual ~Administrateur( );
    // Mode d'emploi :
    // Destructeur de Administateur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	
};
#endif

