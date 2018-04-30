s#include <cstring>

class GestionUtilisateur
{
public:

	GestionUtilisateur();

	void CreerCompte(string nom, string prenom, string motpasse, string adresse);

	void AffichageListeDocteurs(string nomFichier);

	virtual ~GestionUtilisateur();
};

