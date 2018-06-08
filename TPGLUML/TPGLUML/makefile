ECHO=echo
COMP=g++
INT=Attribut.h Empreinte.h Categoriel.h Numerique.h Administrateur.h Docteur.h Utilisateur.h Critere.h CritereNumerique.h CritereCategoriel.h Menu_Main.h GestionRisques.h GestionUtilisateur.h Maladie.h
REAL=$(INT:.h=.cpp)
OBJ=$(REAL:.cpp=.o)
EXE=demoTraj
RMFLAG=-f
CLEAN=efface
OPCOMP=-O3 -g -ansi -pedantic -Wall -std=c++11

$(EXE):$(OBJ)
	$(ECHO) Edl
	$(COMP) -o $(EXE) $(OBJ) $(OPCOMP)

%.o: %.cpp
	$(ECHO) Compil de $<
	$(COMP) $(OPCOMP) -c $< 

$(CLEAN):
	rm $(RMFLAG) 
