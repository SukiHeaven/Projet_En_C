#include "Sommet.h"

Sommet::Sommet(){
	this->lettre='0';
	this->occurence=0;
}

Sommet::Sommet(char l, int o){
	this->lettre=l;
	this->occurence=o;
}
	
Sommet::~Sommet(){}
	
void Sommet::setLettre(char l){
	this->lettre=l;
}
	
char Sommet::getLettre(){
	return this->lettre;
}
	
void Sommet::setOccurence(int o){
	this->occurence=o;
}
	
int Sommet::getOccurence(){
	return this->occurence;
}

void Sommet::incremente(){
	this->occurence++;
}
