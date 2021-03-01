#include "Cryptage.h"

std::vector<ArbreB> triVecteur(std::vector<ArbreB> A){
	ArbreB tmp;
	for(size_t i=0; i<A.size();i++){
		for(size_t j=0;j<A.size();j++){
			if(A[i].getOccurence() > A[j].getOccurence()){
				tmp.setLettre(A[i].getLettre());
				tmp.setOccurence(A[i].getOccurence());
				
				A[i].setLettre(A[j].getLettre());
				A[i].setOccurence(A[j].getOccurence());
				
				A[j].setLettre(tmp.getLettre());
				A[j].setOccurence(tmp.getOccurence());
			}
		}
	}
	return A;
}


void initTabAscii(ArbreB* tab){
	for(int i=0;i<26;i++){	//Les lettres minuscules ASCII 
		tab[i].setLettre((char)(i+65));
		tab[i].setOccurence(0);
	}
}

void fileToTab(const char* path){
	char b;
	std::ifstream f(path);
	ArbreB tabFile[26];
	
	//initialisation tableau
	initTabAscii(tabFile);
	
	for(int i=0; i < 26; i++){	//Les lettres minuscules ASCII 
		std::cout << tabFile[i].getLettre() << ", " << tabFile[i].getOccurence() << std::endl;
	}
	
	//Lecture Fichier
	while( f.get(b) ){
		std::cout << b;
		//Incrémentation de l'occurence de la lettre dans le tableau
		for(int i=0; i < 26; i++){
			if(b == tabFile[i].getLettre() || (char)(b-32) == tabFile[i].getLettre()){
				tabFile[i].incremente();
			}
		}
	}
	std::cout << std::endl;
	f.close();
	
	//Crée un vecteur d'arbres stockant les lettres ayant une occurrence non nulle
	std::vector<ArbreB> v;
	for(int i=0; i < 26; i++){	
		if(tabFile[i].getOccurence() != 0){
			v.push_back(tabFile[i]);
		}
	}
	for(size_t i=0; i < v.size(); i++)
		std::cout << v[i].getLettre() << ", " << v[i].getOccurence() << std::endl;
	
	//Tri du tableau
	v=triVecteur(v);
	std::cout << std::endl;
	for(size_t i=0 ; i < v.size(); i++)	//Affichage
		std::cout <<v[i].getLettre()<< ", " << v[i].getOccurence() << std::endl;
	std::cout << std::endl;
	
	//Fusion
	ArbreB tmp1(v.back().getLettre(),v.back().getOccurence());
	v.pop_back();
	ArbreB tmp2(v.back().getLettre(),v.back().getOccurence());
	v.pop_back();
	ArbreB tmp(tmp1,tmp2);
	v.push_back(tmp);
	v.back().setOccurence(tmp1.getOccurence()+tmp2.getOccurence());
	
	for(size_t i=0; i < v.size(); i++)	//Affichage
		std::cout <<v[i].getLettre()<< ", " << v[i].getOccurence() << std::endl;
	
	//Construction Arbre Final
	while(v.size() > 1){
		v=triVecteur(v);
		tmp1.setLettre(v.back().getLettre());
		tmp1.setOccurence(v.back().getOccurence());
		v.pop_back();
		tmp2.setLettre(v.back().getLettre());
		tmp2.setOccurence(v.back().getOccurence());
		v.pop_back();
		//tmp(tmp1,tmp2);
		tmp.setfg(tmp1);
		tmp.setfd(tmp2);
		v.push_back(tmp);
		v.back().setOccurence(tmp1.getOccurence()+tmp2.getOccurence());
	}
	std::cout << std::endl;
	
	for(size_t i=0;i<v.size();i++)	//Affichage
		std::cout <<v[i].getLettre()<< ", " << v[i].getOccurence() << std::endl;
	
};