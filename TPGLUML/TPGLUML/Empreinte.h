#if ! defined ( Empreinte_H )
#define Empreinte_H

//--------------------------------------------------- Interfaces utilisées

#include "Attribut.h"
using namespace std;
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <vector>
#include <assert.h>

class Empreinte
{
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------Fonction amies
public:

    string fichierFormat ="Donnes/F1_ok.txt";
    //void ajouterAttribut(Attribut *);

    void initialiserFormat();

//-------------------------------------------- Constructeurs - destructeur
    Empreinte ( const Empreinte & uneEmpreinte );
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre, et
    // l ajoute au Empreinte.

    Empreinte ();
    // Mode d'emploi :
    // Un constructeur par défaut, se contentant de creer la premiere cellule

	Empreinte(std::vector <Attribut> nouveauxAttributs);



    virtual ~Empreinte ( );
    // Mode d'emploi :
    // Destructeur de Empreinte

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string ID;
	vector <Attribut> attributs;
	static vector< pair<string,string> > format;

};

#endif
