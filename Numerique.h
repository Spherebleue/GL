#if ! defined ( Numerique_H )
#define Numerique_H

//--------------------------------------------------- Interfaces utilisées

#include "Attribut.h"
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

class Numerique : public Attribut
{
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------Fonction amies
public:

 friend ostream& operator<<(ostream&, const Numerique &); 

//-------------------------------------------- Constructeurs - destructeur
    Numerique ( const Numerique & uneNumerique );
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre, et
    // l ajoute au Numerique.

    Numerique ();
    // Mode d'emploi :
    // Un constructeur par défaut, se contenant de creer la premiere cellule

    Numerique ( string nom, int valeur);
    // Mode d'emploi :
    // Un constructeure

    virtual ~Numerique ( );
    // Mode d'emploi :
    // Destructeur de Numerique

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Numeriques protégés
	int valeur;

};

#endif