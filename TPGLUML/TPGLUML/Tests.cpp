/*************************************************************************
Tests  -  description
-------------------
début                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Tests> (fichier Tests.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel



//------------------------------------------------------------- Constantes
//#define MAP ;


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int main()
{
	cout << "Programme de tests de l'application du TP : GL-UML 3IF" << endl << endl;
	cout << "---------- Test 1 : " << endl;
	cout << "Résultat du test_1 : " << test_1();
	return 0;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//SERVICE 0 :  
/*Initialisation du format d’empreinte à partir du fichier  F1 : 
ce service doit pouvoir permettre de savoir précisément comment
l’objet empreinte va être défini par la suite dans les différents 
fichiers textes.*/

	private bool test_1()
	//TEST_1 : Pas de fichier présent/pas de fichier ayant le nom voulu
	{
		return false;
	}
	//FIN TEST_1

	private bool test_2()
		//TEST_2: Fichier source erroné : vérifier que l’entête du fichier
		//		  est bien celle que l’on attend / vérifier que l’on a lu
		//		  tout le fichier (marque de fin ?)
	{
		return false;
	}
	//FIN TEST_2

//FIN SERVICE 0

