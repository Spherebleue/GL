#if ! defined ( Empreinte_H )
#define Empreinte_H
//--------------------------------------------------- Interfaces utilisées
#include "Attribut.h"
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

class Empreinte
{
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------Fonction amies
public:

//-------------------------------------------- Constructeurs - destructeur
    Empreinte ( const Empreinte & uneEmpreinte );
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre, et
    // l ajoute au Empreinte.

    Empreinte ();
    // Mode d'emploi :
    // Un constructeur par défaut, se contenant de creer la premiere cellule


    virtual ~Empreinte ( );
    // Mode d'emploi :
    // Destructeur de Empreinte

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	String ID;
	Attribut * attributs;

};

