#include "graphe.h"


/* Initialise le graphe et la matrice à NULL */
graphe init_graphe_NULL(int n){    
    graphe G;
    G.nbSommets = n;
    G.matrice_adjacence = malloc(n*sizeof(int*));
    for (int i = 0; i < n; ++i)
        G.matrice_adjacence[i] = malloc(n*sizeof(int));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)    
            G.matrice_adjacence[i][j] = NULL;
    }
    return G;
}

/* Libère la mémoire stockant le graphe */
void libere_graphe(graphe G){
    for (int i = 0; i < G.nombre_sommet; ++i)    
        free(G.matrice_adjacence[i]);
    free(G.matrice_adjacence);
}

/* Initialise le graphe et la matrice à partir du fichier metro.txt */
graphe init_graphe(int n){
	
	// Vérification de l'ouverture du fichier
	FILE* F;
	F = fopen(metro.txt,"r");
	if(F == NULL) {
		printf("Echec de l'ouverture du fichier\n");
		exit(0);
	}
	fclose(F);
	

}
