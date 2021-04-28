#pragma once
#include <iostream>											//Librería de C++
#include <string>											//Librería para incluuir cadenas de texto
#include <Windows.h> 										//Para controlar la ventena de consola
#include <conio.h> 											//Para detectar las teclas que se presionen
#include <stdio.h>											//Para lineas de codigo en C
#include "Funciones.h"										//Llamamos a la librería Funciones, para acceder a sus funciones
#include "Players.h"										//Llamamos a la librería de Players para referenciar sus objetos

using namespace std;

class pelota {
private:
	int x;
	int y;
	int xPlus;
	int yPlus;

public:
	pelota();
	~pelota();

	void mostrar();
	void borrar();
	void mover();
	void colision(class leftPlayer&, class rightPlayer&);
	void gol(class leftPlayer& P1, class rightPlayer& P2);

	void setX(int);
	int getX();
	void setY(int);
	int getY();
	void setXPlus(int);
	int getXPlus();
	void setYPlus(int);
	int getYPlus();
};

pelota::pelota() {
	x = 60;
	y = 15;
	xPlus = 1;
	yPlus = 1;
}

pelota::~pelota() {
	
}

void pelota::mostrar() {
	gotoxy(x, y); cout << "o";
}

void pelota::borrar() {
	gotoxy(x, y); cout << " ";
}

void pelota::colision(class leftPlayer& P1, class rightPlayer& P2) {
	if ( (x == P1.getX() && ( y >= P1.getY() && y <= P1.getY() + 3) ) || (x == P2.getX() && ( y >= P2.getY() && y <= P2.getY() + 3) ) ) {
		//borrar();
		xPlus = -xPlus;
		//yPlus = -yPlus;
	}
	mover();
}

void pelota::mover() {
	borrar();

	if (y > 24 || y < 3) {
		//borrar();
		yPlus = -yPlus;
	}
	if (x > 113 || x < 7) {
		//borrar();
		xPlus = -xPlus;
	}
	
	x += xPlus;
	y += yPlus;
	mostrar();
}

void pelota::gol(class leftPlayer& P1, class rightPlayer& P2) {
	if (x <= 6 && (y >= 9 && y <= 18)) {
		P2.setScore(P2.getScore() + 1);
		P1.printScore(26, 28);
		P2.printScore(86, 28);
		showGol();
		printContorno();
		x = 60;
		y = 15;
	}
	if (x == 114	 && (y >= 9 && y <= 18)) {
		P1.setScore(P1.getScore() + 1);
		P1.printScore(26, 28);
		P2.printScore(86, 28);
		showGol();
		printContorno();
		x = 60;
		y = 15;
	}
}

//Getters y Setters

void pelota::setX(int _x) {
	x = _x;
}
int pelota::getX() {
	return x;
}

void pelota::setY(int _y) {
	y = _y;
}
int pelota::getY() {
	return y;
}

void pelota::setXPlus(int _xPlus) {
	xPlus = _xPlus;
}
int pelota::getXPlus() {
	return xPlus;
}

void pelota::setYPlus(int _yPlus) {
	yPlus = _yPlus;
}
int pelota::getYPlus() {
	return yPlus;
}
