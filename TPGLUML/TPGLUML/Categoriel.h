#if ! defined ( Categoriel_H )
#define Categoriel_H
//--------------------------------------------------- Interfaces utilisées
#include "Attribut.h"
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

class Categoriel : public Attribut
{
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------Fonction amies
public:

    friend ostream& operator<<(ostream&, const Categoriel &); 
//-------------------------------------------- Constructeurs - destructeur
    Categoriel ( const Categoriel & uneCategoriel );
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre, et
    // l ajoute au Categoriel.

    Categoriel ();
    // Mode d'emploi :
    // Un constructeur par défaut, se contenant de creer la premiere cellule

    Categoriel (string nom , string valeur);
    // Mode d'emploi :
    // Un constructeur par défaut, se contenant de creer la premiere cellule

	Categoriel * copieAttribut();
	ostream & output(ostream&) const  ;

	string getValeur();

    virtual ~Categoriel ( );
    // Mode d'emploi :
    // Destructeur de Categoriel

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Categoriels protégés
	string valeur;

};

#endif 