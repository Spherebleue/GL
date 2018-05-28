#ifndef CRITERE_H_INCLUDED
#define CRITERE_H_INCLUDED

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

class Critere
{
	//----------------------------------------------------------------- PUBLIC
	//-------------------------------------------------------Fonction amies
public:
  	
	friend ostream& operator<<(ostream&, const Critere &); 

	//-------------------------------------------- Constructeurs - destructeur
	Critere(const Critere & uneCritere);
	// Mode d'emploi :
	// Fait une copie en profondeur de l'objet donne en parametre, et
	// l ajoute au Critere.

	Critere();
	// Mode d'emploi :
	// Un constructeur par défaut, se contenant de creer la premiere cellule

	Critere(string, bool);
	// Mode d'emploi :
	// Un constructeur pour créer un Critere

	string getNom();

	bool getUtile();


	
	
	virtual Critere * copieCritere() =0;


	virtual ~Critere();
	// Mode d'emploi :
	// Destructeur de Critere

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- Méthodes protégées

	//----------------------------------------------------- Attributs protégés
	string nomAttribut;
	bool utile;


};

#endif

