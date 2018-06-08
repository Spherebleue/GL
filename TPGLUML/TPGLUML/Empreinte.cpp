/*************************************************************************
Empreinte  -  description
-------------------
début                : 30/04/2018
copyright            : (C) 2018 par Lea Ferrere - Gustavo Chaiaa-Ramirez - Gregoire Bailly - Maud Duraffourg
e-mail               : maud.duraffourg@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Empreinte> (fichier Empreinte.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Empreinte.h"
#include <sstream>

using namespace std;
//------------------------------------------------------------- Constantes
//#define MAP ;

//----------------------------------------------------------------- PUBLIC
string Empreinte::fichierFormat = "Donnees/DataSet1/HealthMeasurementDescription.txt";
vector< pair<string, string> > Empreinte::format;


ostream& operator<<(ostream &strm, const Empreinte& Emp)
//Pour afficher
{
	for (int i = 0; i < int(Emp.attributs.size()); i++)
	{
		strm << (*Emp.attributs[i]) << ", ";

	}
	return strm;
}

void Empreinte::initialiserFormat()
{

    ifstream entreeFichier;
    entreeFichier.open(fichierFormat);

    assert(entreeFichier);                        //verifie que le fichier est bien trouve

    string line;
    getline(entreeFichier, line);
    assert(line.compare("AttributeName;AttributeType")==0);    //verifie que l'entete est bien la bonne
    getline(entreeFichier, line);
    assert(line.compare("NoID;ID")==0);

    while(entreeFichier.good())
    {
		getline(entreeFichier, line);
        stringstream ss;
        ss.str(line);
        string nomAttribut;
        getline(ss, nomAttribut,';');
        if(nomAttribut!="")
        {
            assert(nomAttribut!=line);                  //veririe que la ligne est bien formee

            string typeAttribut;
            getline(ss, typeAttribut,'\r');

            if(typeAttribut.compare("string")==0)       //verifie que le type est bien le bon
            {
                typeAttribut="Categoriel";
            }
            else if (typeAttribut.compare("double")==0)
            {
                typeAttribut="Numerique";
            }
            else
            {
                cout<<"Erreur : l'un des attributs n'est ni numerique, ni categoriel"<<endl;
                cout<<"il s'agit de la ligne :"<< line <<endl;
                abort();
            }

            pair<string,string> nouvellePaire=make_pair(nomAttribut,typeAttribut);
            format.push_back(nouvellePaire);
        }
       
    }
    entreeFichier.close();

}




//----------------------------------------------------- Méthodes publiques
void Empreinte::ajouterAttribut(Attribut * attribut)
{

	attributs.push_back(attribut->copieAttribut());
}


//-------------------------------------------- Constructeurs - destructeur
Empreinte::Empreinte ( const Empreinte & uneEmpreinte )
// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Empreinte>" << endl;
		#endif
        this->ID = uneEmpreinte.ID;
        for (int i = 0; i<int(Empreinte::format.size()); i++)
        {
            attributs.push_back(uneEmpreinte.attributs[i]->copieAttribut());
        }

	} //----- Fin de Empreinte (constructeur de copie)


Empreinte::Empreinte ()
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Empreinte>" << endl;
		#endif

	} //----- Fin de Empreinte


Empreinte::Empreinte (std::vector <Attribut *> nouveauxAttributs)
// Algorithme :
// Un constructeur par défaut.
	{
		#ifdef MAP
			cout << "Appel au constructeur de <Empreinte>" << endl;
		#endif
       /* if( this->format.empty())
        {
            initialiserFormat();
        }
		this->ID =ID;

		assert(this->format.size()==nouveauxAttributs.size());
*/
        this->attributs=nouveauxAttributs;

	} //----- Fin de Empreinte



Empreinte::~Empreinte ( )
// Algorithme :
//
	{
		#ifdef MAP
		    cout << "Appel au destructeur de <Empreinte>" << endl;
		#endif
	} //----- Fin de ~Empreinte


vector <Attribut *> Empreinte::getListeAttribut()
{
	return attributs;
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
