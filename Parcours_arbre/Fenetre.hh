#pragma once

#include <QtGui/QApplication>
#include <QtGui/QPainter>
#include <QtGui/QWidget>

#include <iostream>
#include "ArbreB.h"
#include "Sommet.h"

class Fenetre : public QWidget{
private:
	ArbreB* A;
public:
	Fenetre(ArbreB* a){this->A = a;}
	
	void paintEvent(QPaintEvent* event){
		QPainter paint(this);
		
		char Lettre = this->A->getLettre();
		
		int x = paint.fontMetrics().width(this->A->getfd()->getOccurence())+10;
		int y = paint.fontMetrics().height()+10;
		
		
			paint.drawText(50,50+10, "Not implemented yet");
			paint.drawRect(45,40-y/2+10,x,y);
	}
	
	~Fenetre(){}
};
