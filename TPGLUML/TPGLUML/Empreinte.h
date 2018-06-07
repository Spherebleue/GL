/*************************************************************************
Empreinte  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Empreinte> (fichier Empreinte.h) ------------
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

// Role de la classe <Empreinte>
// 
//
//------------------------------------------------------------------------

class Empreinte
{
//----------------------------------------------------------------- PUBLIC
	static string fichierFormat;
	static vector< pair<string, string> > format;

public:
	//-------------------------------------------------------Fonction amies

	friend ostream& operator<<(ostream&, const Empreinte &);
	

	//-------------------------------------------------------Méthodes publiques

	void ajouterAttribut(Attribut *);
	// Mode d'emploi :
	// Cette methode permet d'ajouter un pointeur d'Attribut au vecteur de pointeurs d'Attribut  "attributs"

	void static initialiserFormat();
	// Mode d'emploi :
	// Cette méthode permet d'initialiser le format des empreintes ; elle va remplir le tableau static fichierFormat, qui servira à creer des objets Empreinte avec les bons type d'Attribut
	vector <Attribut *> getListeAttribut();
	// Mode d'emploi :
	// Une accesseur pour l'attribut "attributs"

//-------------------------------------------- Constructeurs - destructeur
    Empreinte ( const Empreinte & uneEmpreinte );
    // Mode d'emploi :
    // Fait une copie en profondeur d'un objet Empreinte

    Empreinte ();
    // Mode d'emploi :
    // Un constructeur par défaut, se contentant de creer la premiere cellule

	Empreinte(std::vector <Attribut*> nouveauxAttributs);
	// Mode d'emploi :
	// Un constructeur



    virtual ~Empreinte ( );
    // Mode d'emploi :
    // Destructeur de Empreinte

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string ID;
	vector <Attribut *> attributs;


};



#endif
