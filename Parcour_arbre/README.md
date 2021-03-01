Nous avons pensé pour le projet à l'implémentation de deux classes : 
-Une classe Sommet qui a deux attributs: char lettre et int occurence.
-Une classe ArbreB qui hérite de la classe Sommet et qui a comme attributs deux pointeurs sur des ArbreB.

Le constructeur par défaut de Sommet a pour lettre='0' et occurence=0, et le constructeur par défaut de ArbreB appelle le constructeur de Sommet
et ses pointeurs pointent sur NULL.

Nous avons implémenté plusieurs constructeurs dans la classe ArbreB afin de construire un arbre final qui contiendra les adresses des arbres créés.

La méthode rechAllElem(int prof, char const * nomArbre, int gORd) permet de parcourir l'arbre en question
Nous avons également implémenté deux méthodes de recherche d'un élément dans l'arbre, l'une renvoyant un booléen et l'autre ne renvoyant rien.

Les tests de notre code sont réalisés dans la classe Main.

La partie interface graphique n'affiche malheureusement pas notre arbre final.

Les commandes de compilation et d'éxécution à partir du dossier du projet sont : 
$ make
$ ./main
