#if ! defined ( Docteur_H )
#define Docteur_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>
#include "Utilisateur.h"

class Docteur : public Utilisateur
{
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------Fonction amies
public:

//-------------------------------------------- Constructeurs - destructeur
    Docteur ( const Docteur & unDocteur);
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre, et
    // l ajoute au Empreinte.

	Docteur();
    // Mode d'emploi :
    // Un constructeur par défaut, se contenant de creer la premiere cellule


    virtual ~Docteur( );
    // Mode d'emploi :
    // Destructeur de Empreinte

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	
};

#endif

