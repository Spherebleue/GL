/*************************************************************************
                           SelectionLigne  -  description
                             -------------------
    dÃ©but                : 26/01/2018
    copyright            : (C) 2018 par B3332 (Duraffourg & Gangalic)
    e-mail               : b3332@insa-lyon.fr
*************************************************************************/

//---------- RÃ©alisation de la classe <SelectionLigne> (fichier SelectionLigne.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systÃ¨me
using namespace std;
#include <iostream>
#include <cstring>
#include <cassert>
#include <sstream>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include<ctime>

#include "stdlib.h"
//-------------------------------------------------------------------Tests


static int SelectionLigneAlea(string nomFichierSource, string nomFichierDestination, int nbLigne)
{
        string table[5000];
        ifstream ifs;
        ifs.open(nomFichierSource.c_str());
        ofstream ofs;
        ofs.open(nomFichierDestination.c_str());

        string line;
        getline(ifs, line);
        //on place l'entete
        ofs<<line<<"\n";

        for(int i = 0 ; i<5000 ; i++)
        {
                getline(ifs, line);
                table[i] = line;
        }

        srand(time(NULL));
        int offset = rand()%(5001-nbLigne);
        for(int i = 0 ; i<nbLigne ; i++)
        {
			ofs<<table[i+offset]<<"\n";
		}
		ifs.close();
		ofs.close();
    return 0;
}

