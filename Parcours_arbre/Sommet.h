#pragma once

class Sommet{
private:
	char lettre;
	int occurence;
public:
	Sommet();
	Sommet(char l, int o);
	
	~Sommet();
	
	void setLettre(char l);
	char getLettre();
	
	void setOccurence(int o);
	
	int getOccurence();
	
	void incremente();
};
