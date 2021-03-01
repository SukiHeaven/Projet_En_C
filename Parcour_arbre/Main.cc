#include <iostream>
#include <fstream>

// #include <QtGui/QApplication>
// #include <QtGui/QPainter>
// #include <QtGui/QWidget>

#include "ArbreB.h"
#include "Sommet.h"
#include "Cryptage.h"
//#include "Fenetre.hh"

int main(int argc,char** argv){
	
	const char * d = "droite";
	const char * g = "gauche";

	ArbreB a ('a',3); 						// création d'un sommet seul avec la lettre "a" et l'occurence "3"
	ArbreB b ; 								// création d'un sommet vide 0,0
	ArbreB c ('c',4); 						// création d'un sommet seul avec la lettre "c" et l'occurence "4"

	ArbreB ArbreCA (a,c); 					// creation d'un arbre ArbreB ArbreCA  avec les deux sommet a et c qui aura pour sommet vide
	ArbreB ArbreVideCA( 'd',5,g,ArbreCA ); 	// creation d'un arbre avec un  sommet avec la lettre d et une occurence de 5 a partir d'un autre arbre qu'on positionne dans la branche gauche 

	// ArbreVideCA.rechAllElem(0,"ArbreVideCA",-1); // recherche de tout les elements contenue dans l'arbre ArbreVideCA
	// std::cout << std::endl;

	// ArbreCA.setLettre('f');					//change la lettre du sommet de l'arbre ArbreVideCA
	// ArbreCA.setOccurence(9); 				//change l'occurence du sommet de l'arbre ArbreVideCA

	// ArbreVideCA.getfg();					//permet de pointer vers le noeud qui se situe a gauche
	// ArbreCA.getfd();						//permet de pointer vers le noeud qui se situe a droite

	// ArbreVideCA.getfg()->setOccurence(9); 	//change l'occurence du noeud de droite de l'arbre ArbreVideCA
	// ArbreVideCA.getfg()->setLettre('b');	//change la lettre du noeud de droite de l'arbre ArbreVideCA

	// ArbreVideCA.rechAllElem(0,"ArbreVideCA",-1);
	// std::cout << std::endl;

	// ArbreCA.getfd()->setLettre('q');		//change la lettre du noeud de gauche de l'arbre ArbreB ArbreCA 
	// ArbreCA.getfd()->setOccurence(15); 		//change l'occurence du noeud de a gauche de l'arbre ArbreB ArbreCA 

	// ArbreCA.rechAllElem(0,"ArbreCA",-1); 
	// std::cout << std::endl;

	//Test Lecture fichier
	
	//fileToTab("../test.txt");
	//Partie Qt
	/*QApplication app(argc,argv);
	Fenetre window(&ArbreCA);
	window.show();
	
	return app.exec();*/
	
	//return 0;
}
