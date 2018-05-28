#ifndef CRITERE_H_INCLUDED
#define CRITERE_H_INCLUDED

//--------------------------------------------------- Interfaces utilis�es

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
	// Un constructeur par d�faut, se contenant de creer la premiere cellule

	Critere(string, bool);
	// Mode d'emploi :
	// Un constructeur pour cr�er un Critere

	string getNom();

	bool getUtile();


	
	
	virtual Critere * copieCritere() =0;


	virtual ~Critere();
	// Mode d'emploi :
	// Destructeur de Critere

	//------------------------------------------------------------------ PRIVE

protected:
	//----------------------------------------------------- M�thodes prot�g�es

	//----------------------------------------------------- Attributs prot�g�s
	string nomAttribut;
	bool utile;


};

#endif

