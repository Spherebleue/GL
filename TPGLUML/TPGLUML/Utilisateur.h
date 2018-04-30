#if ! defined ( Utilisateur_H )
#define Utilisateur_H
//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

class Utilisateur
{
//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------Fonction amies
public:

//-------------------------------------------- Constructeurs - destructeur

	Utilisateur();
    // Mode d'emploi :
    // Un constructeur par défaut, se contenant de creer la premiere cellule

    Utilisateur ( const Utilisateur & unUtilisateur);
    // Mode d'emploi :
    // Fait une copie en profondeur de l'objet donne en parametre, et
    // l ajoute au Empreinte.

    virtual ~Utilisateur( );
    // Mode d'emploi :
    // Destructeur de Empreinte

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string nom;
	string prenom;
	string motDePasse;
	string adresse;

};

#endif

