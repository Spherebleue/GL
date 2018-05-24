#ifndef ATTRIBUT_H_INCLUDED
#define ATTRIBUT_H_INCLUDED
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>


class Attribut
{
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------Fonction amies
public:

    friend ostream& operator<<(ostream&, const Attribut &); 

//-------------------------------------------- Constructeurs - destructeur
    Attribut ( const Attribut & uneAttribut );
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre, et
    // l ajoute au Attribut.

    Attribut ();
    // Mode d'emploi :
    // Un constructeur par défaut, se contenant de creer la premiere cellule

	Attribut(string);

	Attribut * copieAttribut();


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