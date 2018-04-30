#include <cstring>

class GestionRisques
{
public:
	GestionRisques();
	
	void initMaladies();
	
	void analyserFichier(string nomFichier);
	
	void chercherMaladie(string nomMaladie);
	
	void afficherMaladies();
	
	virtual ~GestionRisques();
};

