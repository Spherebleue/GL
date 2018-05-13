/*************************************************************************
                           main  -  description
                             -------------------
    début                : 26/01/2018
    copyright            : (C) 2018 par B3332 (Duraffourg & Gangalic)
    e-mail               : b3332@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <main> (fichier main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include "Categoriel.h"
#include "Numerique.h"
#include "CritereCategoriel.h"
#include "CritereNumerique.h"

//------------------------------------------------------ Include personnel

int testCategoriel_1 ()
// test constructeur
{
    Categoriel canard ("canard", "canard");
    cout<< canard;
    return 0;
}

int testNumerique_1 ()
//test numerique
{
    Numerique canard ("canard", 42);
    cout<< canard;
    return 0;
}

int testAttribut_1()
//test attribut
{
	Attribut canard("canard");
	cout << canard << endl;
	return 0;
}


int testCritere_1()
//test critere
{
	CritereCategoriel canard("canard", false, "bouh");
	canard.afficher();
	return 0;
}
int testCritere_2()
//test critere
{
	CritereNumerique canard("canard", false, 3, 8);
	canard.afficher();
	return 0;
}

int main(int argc, char* argv[])
{
    testCategoriel_1();
 //   testNumerique_1 ();
   // testAttribut_1 ();
	testCritere_1();
	testCritere_2();
	while(true)
	{ }

}
