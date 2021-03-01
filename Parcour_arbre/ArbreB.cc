#include "ArbreB.h"

ArbreB::ArbreB() : Sommet(){
	this->fg=nullptr;
	this->fd=nullptr;
}

ArbreB::ArbreB(char l, int o) : Sommet(l,o){
	this->fg=nullptr;
	this->fd=nullptr;
}

ArbreB::ArbreB(const ArbreB& fg, const ArbreB& fd) : Sommet(){
	this->fg=new ArbreB(fg);
	this->fd=new ArbreB(fd);
}

ArbreB::ArbreB(const char * direction ,  const ArbreB& f) : Sommet(){
	if (std::strcmp(direction, "droite")==0){
		this->fd=new ArbreB(f);
		this->fg=nullptr;
	}
	else {
		this->fg=new ArbreB(f);
		this->fd=nullptr;
	}
}

ArbreB::ArbreB(char l, int o, const char * direction ,  const ArbreB& f) : Sommet(l,o){
	if (std::strcmp(direction, "droite")==0){
		this->fd=new ArbreB(f);
		this->fg=nullptr;
	}
	else {
		this->fg=new ArbreB(f);
		this->fd=nullptr;
	}
}
	
ArbreB::ArbreB(char l, int o, const ArbreB& fg, const ArbreB& fd) : Sommet(l,o){
	this->fg=new ArbreB(fg);
	this->fd=new ArbreB(fd);
}
	
ArbreB::~ArbreB(){
	if(fg)
		fg=nullptr;
	if(fd)
		fd=nullptr;
}

// fonction qui permet de retrouver ce qui se situe a droite et a gauche par rapport au sommet ou onse situe
ArbreB* ArbreB::getfg(){return this->fg;}
ArbreB* ArbreB::getfd(){return this->fd;}

// fonction qui permet de set un fils gauche ou fils droit 
void ArbreB::setfg(const ArbreB& A){fg=new ArbreB(A);}
void ArbreB::setfd(const ArbreB& A){fd=new ArbreB(A);}

//fonction qui renvoie toute les lettres et occurences par profondeur et si elle se situe a gauche ou a droite
int ArbreB::rechAllElem(int prof, char const * nomArbre, int gORd){

		if (gORd == -1)
			std::cout << "Sommet de l'arbre "<<  nomArbre <<  " egale a : '" << this->getLettre() << "' et son occurence a : " << this->getOccurence() << std::endl;

		else if (gORd)
			std::cout << "Element trouvé a la profondeur "<< prof << " : '" << this->getLettre() << "' et son occurence a : " << this->getOccurence() << " dans l'abre " << nomArbre << " a droite" << std::endl;

		else 
			std::cout << "Element trouvé a la profondeur "<< prof << " : '" << this->getLettre() << "' et son occurence a : " << this->getOccurence() << " dans l'abre " << nomArbre << " a gauche" << std::endl;


		if(fg and fd)
			return fg->rechAllElem(prof+1,nomArbre,0) + fd->rechAllElem(prof+1,nomArbre,1);
		else if(fg){
			return fg->rechAllElem(prof+1,nomArbre,0);
		}
		else if(fd){
			return fd->rechAllElem(prof+1,nomArbre,1);
		}

		else return 0;
}
	
//fonction de recherche d'un caractère dans un arbre, elle renvoie un boolean
bool ArbreB::rechElem(char l){
		if(this->getLettre()==l){
			return true;
		}
		if(fg and fd)
			return fg->rechElem(l) + fd->rechElem(l);
		if(fg){
			return fg->rechElem(l);
		}
		if(fd){
			return fd->rechElem(l);
		}
		return false;
}
	
//fonction de recherche d'un caractère dans un arbre, elle renvoie un rien
void ArbreB::rechercheElem(char l){
		if(this->getLettre()==l ){
			std::cout << "Element trouvé: " << l << "son occurence est de: " << this->getOccurence() << std::endl;
		}
		else{
			if(fg){
				fg->rechercheElem(l);
			}
			if(fd){
				fd->rechercheElem(l);
			}
		}
}

std::string ArbreB::codifierText(char l, std::string res){
	if(this->getLettre()==l)
		return res;

	if(fg->rechElem(l))
		return fg->codifierText(l, res + '1');

	if(fd->rechElem(l))
		return fd->codifierText(l, res + '0');

	return res;
}