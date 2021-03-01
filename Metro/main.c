#include "graphe.h"

int main(int argc, char **argv){

// Test si assez d'argument
	if(argc < 3){
		printf("Il manque un argument");
		return -1;
	}
	
// Vérification de l'ouverture du fichier
	FILE* F;
	F = fopen(metro.txt,"r");
	if(F == NULL) {
		printf("Echec de l'ouverture du fichier\n");
		exit(0);
	}
	fclose(F);

return 0;
}
