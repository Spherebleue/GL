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

//-------------------------------------------- Constructeurs - destructeur
    Administrateur ( const Administrateur & unAdministrateur);
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre, et
    // l ajoute au Empreinte.

	Administrateur();
    // Mode d'emploi :
    // Un constructeur par défaut, se contenant de creer la premiere cellule


    virtual ~Administrateur( );
    // Mode d'emploi :
    // Destructeur de Empreinte

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	
};

