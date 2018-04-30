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
#include "Attribut.h"

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

int testAttribut_1 ()
//test attribut
{
    Attribut canard ("canard");
    cout<< canard;
    return 0;
}

int main(int argc, char* argv[])
{
    testCategoriel_1();
    testNumerique_1 ();
    testAttribut_1 ();
}
