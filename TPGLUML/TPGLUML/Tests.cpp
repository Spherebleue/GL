/*************************************************************************
Tests  -  description
-------------------
d�but                : $DATE$
copyright            : (C) $YEAR$ par $AUTHOR$
e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <Tests> (fichier Tests.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel



//------------------------------------------------------------- Constantes
//#define MAP ;


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
int main()
{
	cout << "Programme de tests de l'application du TP : GL-UML 3IF" << endl << endl;
	cout << "---------- Test 1 : " << endl;
	cout << "R�sultat du test_1 : " << test_1();
	return 0;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//SERVICE 0 :  
/*Initialisation du format d�empreinte � partir du fichier  F1 : 
ce service doit pouvoir permettre de savoir pr�cis�ment comment
l�objet empreinte va �tre d�fini par la suite dans les diff�rents 
fichiers textes.*/

	private bool test_1()
	//TEST_1 : Pas de fichier pr�sent/pas de fichier ayant le nom voulu
	{
		return false;
	}
	//FIN TEST_1

	private bool test_2()
		//TEST_2: Fichier source erron� : v�rifier que l�ent�te du fichier
		//		  est bien celle que l�on attend / v�rifier que l�on a lu
		//		  tout le fichier (marque de fin ?)
	{
		return false;
	}
	//FIN TEST_2

//FIN SERVICE 0

