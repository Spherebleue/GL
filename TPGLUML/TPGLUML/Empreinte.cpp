/*************************************************************************
                           Empreinte  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
string Empreinte::fichierFormat = "F1_ok.txt";
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

        assert(nomAttribut!=line);                  //veririe que la ligne est bien formee

        string typeAttribut;
        getline(ss, typeAttribut);

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
            abort();
        }

        pair<string,string> nouvellePaire=make_pair(nomAttribut,typeAttribut);
        format.push_back(nouvellePaire);

        
    }

}

//----------------------------------------------------- Méthodes publiques
void Empreinte::ajouterAttribut(Attribut * attribut)
{
	
	attributs.push_back(attribut->copieAttribut());
}


//-------------------------------------------- Constructeurs - destructeur
Empreinte::Empreinte ( const Empreinte & unEmpreinte )
// Algorithme :
// Un constructeur de copie.
	{
		#ifdef MAP
			cout << "Appel au constructeur de copie de <Empreinte>" << endl;
		#endif

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
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
