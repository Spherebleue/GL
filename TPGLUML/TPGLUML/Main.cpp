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
#include "Empreinte.h"
#include "CritereCategoriel.h"
#include "CritereNumerique.h"
#include "GestionRisques.h"

//------------------------------------------------------ Include personnel

int testCategoriel_1 ()
// test constructeur
{
    Categoriel canard ("canard", "canardj");
    cout<< canard<<endl;
	//cout << (canard.getValeur());
    return 0;
}

int testNumerique_1 ()
//test numerique
{
    Numerique canard ("canard", 42);
    cout<< canard<<endl;
    return 0;
}




int testCritere_1()
//test critere
{
	CritereCategoriel canard("canard", false, "bouh");
	cout<<canard<<endl;
	return 0;
}

int testCritere_2()
//test critere
{
	CritereNumerique canard("canard", false, 3, 8);
	cout<<canard<<endl;
	return 0;
}


int test_CodeInit()
{
	Empreinte::initialiserFormat();
	for (int i = 0; i < int (Empreinte::format.size()); i++)
	{
		cout << Empreinte::format[i].first << ", " << Empreinte::format[i].second << endl;
	}
	return 0;
}
int test_analyseFichier()

{
	GestionRisques gr;
	gr.analyserFichier("F3_ok.txt");
	return 0;
}
int main(int argc, char* argv[])
{
    testCategoriel_1();
    testNumerique_1 ();
	testCritere_1();
	testCritere_2();
	test_CodeInit();
	test_analyseFichier();
	while (true);
}
