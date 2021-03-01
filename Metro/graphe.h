#include <stdio.h>
#include <stdlib.h>


/* Les Structures */

	/* Structure de données permettant de stocker un graphe */
typedef struct {
	int nbSommets;					// Nombre de sommets dans le graphe
	int ** matrice_adjacence;		// Tableau contenant le temps entre deux sommets (suivant l'orientation du graphe)
} graphe;


/* Les Fonctions de manipulation */

// Initialise le graphe et la matrice à NULL
graphe init_graphe_NULL(graphe G,int S);

// Libère la mémoire stockant le graphe
void libere_graphe(graphe G);

// Initialise le graphe et la matrice à partir du fichier metro.txt
graphe init_graphe(int n);
