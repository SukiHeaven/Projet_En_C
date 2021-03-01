#pragma once

#include "Sommet.h"
#include <iostream>
#include <cstring>

class ArbreB : public Sommet{

private:
	ArbreB* fg;
	ArbreB* fd;

public:

	ArbreB();
	ArbreB(char l, int o);
	ArbreB(const ArbreB& fg, const ArbreB& fd);
	ArbreB(const char * direction ,  const ArbreB& f);
	ArbreB(char l, int o, const char * direction ,  const ArbreB& f);
	ArbreB(char l, int o, const ArbreB& fg, const ArbreB& fd);
	~ArbreB();

	// fonction qui permet de retrouver ce qui se situe a droite et a gauche par rapport au sommet ou onse situe
	ArbreB* getfg();
	ArbreB* getfd();
	
	// fonction qui permet de set un fils gauche ou fils droit 
	void setfg(const ArbreB& A);
	void setfd(const ArbreB& A);
	
	int rechAllElem(int prof, char const * nomArbre, int gORd);//fonction qui renvoie toute les lettres et occurences par profondeur et si elle se situe a gauche ou a droite
	bool rechElem(char l);//fonction de recherche d'un caractère dans un arbre, elle renvoie un boolean
	void rechercheElem(char l);//fonction de recherche d'un caractère dans un arbre, elle renvoie un rien
	std::string codifierText(char l, std::string res);

};
