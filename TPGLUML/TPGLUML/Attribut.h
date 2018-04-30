#if ! defined ( Attribut_H )
#define Attribut_H
//--------------------------------------------------- Interfaces utilisées
#include "Attribut.h"
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

class Attribut
{
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------Fonction amies
public:

//-------------------------------------------- Constructeurs - destructeur
    Attribut ( const Attribut & uneAttribut );
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre, et
    // l ajoute au Attribut.

    Attribut ();
    // Mode d'emploi :
    // Un constructeur par défaut, se contenant de creer la premiere cellule


    virtual ~Attribut ( );
    // Mode d'emploi :
    // Destructeur de Attribut

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string nom;

};

#endif 