#pragma once
#include <iostream>											//Librería de C++
#include <string>											//Librería para incluuir cadenas de texto
#include <Windows.h> 										//Para controlar la ventena de consola
#include <conio.h> 											//Para detectar las teclas que se presionen
#include <stdio.h>											//Libreria de programación en C
#include "Funciones.h"										//Llamamos a la librería Funciones, para acceder a sus funciones

using namespace std;

#define Up 72												//Etiqueta para la tecla de arriba
#define Low 80												//Etiqueta para la tecla de abajo
#define Left 75												//Etiqueta para la tecla de izquierda
#define Right 77											//Etiqueta para la tecla de derecha
#define A 65												//Etiqueta para la tecla A
#define S 83												//Etiqueta para la tecla S
#define D 68												//Etiqueta para la tecla D
#define W 87												//Etiqueta para la tecla W

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////CLASE MADRE/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class players {
public:
	players();
	~players();

	void mostrar();
	void borrar();

	void setX(int);
	int getX();
	void setY(int);
	int getY();
	
	void setScore(int);
	int getScore();
	void printScore(int, int);

protected:
	int x;
	int y;
	int score;
};

players::players() {
	x = 58;
	y = 24;
	score = 0;
}

players::~players() {

}

void players::mostrar() {
	//SetConsoleOutputCP( CP_UTF8 );							//Imprimir caracteres especiales
	gotoxy(x, y); printf("%c", 219);
	gotoxy(x, y + 1); printf("%c", 219);
	gotoxy(x, y + 2); printf("%c", 219);
	gotoxy(x, y + 3); printf("%c", 219);
}

void players::borrar() {
	gotoxy(x, y); cout << " ";
	gotoxy(x, y + 1); cout << " ";
	gotoxy(x, y + 2); cout << " ";
	gotoxy(x, y + 3); cout << " ";
}

//Getters y Setters

void players::setX(int _X) {
	x = _X;
}
int players::getX() {
	return x;
}

void players::setY(int _y) {
	y = _y;
}
int players::getY() {
	return y;
}

void players::setScore(int _score) {
	score = _score;
}
int players::getScore() {
	return score;
}

void players::printScore(int x, int y) {
	gotoxy(x, y); cout << "GOALS: " << score ;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////JUGADOR IZQUIERDA//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class leftPlayer : public players {
public:
	void mover();
};

void leftPlayer::mover() {
	char tecla;
	if (_kbhit()) {												//Detecta SI una tecla esta presionada-------Metodo que detecta la tecla oprimida
		tecla = _getch();										//Guardar valor en la variable tecla

		borrar();

		//Detectar el movimiento
		if ((tecla == A) && (x >= 7)) {
			x -= 2;
		}
		if ((tecla == D) && (x <= 56)) {
			x += 2;
		}
		if ((tecla == W) && (y >= 4)) {
			y -= 2;
		}
		if ((tecla == S) && (y < 22)) {
			y += 2;
		}

		mostrar();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////JUGADOR DERECHA//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class rightPlayer : public players {
public:
	void mover();
	void computadora(int _x, int _y, int _incrementoX, int _incrementoY, int op);
};

void rightPlayer::mover() {
	char tecla;
	if (_kbhit()) {												//Detecta SI una tecla esta presionada-------Metodo que detecta la tecla oprimida
		tecla = _getch();										//Guardar valor en la variable tecla

		borrar();

		//Detectar el movimiento
		if ((tecla == Left) && (x >= 60)) {
			x -= 2;
		}
		if ((tecla == Right) && (x <= 112)) {
			x += 2;
		}
		if ((tecla == Up) && (y >= 4)) {
			y -= 2;
		}
		if ((tecla == Low) && (y < 22)) {
			y += 2;
		}

		mostrar();
	}
}

void rightPlayer::computadora(int _x, int _y, int _incrementoX, int _incrementoY, int op) {
	if (op == 1) {
		if ((_x > 80) && (_incrementoX > 0) && (_x < 92)) {
			borrar();
			if ((_y > y + 1) && (y < 21)) {
				y++;
			}
			if ((_y < y + 1) && (y >= 5)) {
				y--;
			}
			mostrar();
		}
	}
	else if (op == 2) {
		if ((_x > 70) && (_incrementoX > 0) && (_x < 92)) {
			borrar();
			if ((_y > y + 1) && (y < 21)) {
				y++;
			}
			if ((_y < y + 1) && (y >= 5)) {
				y--;
			}
			mostrar();
		}
	}
	else if (op == 3) {
		if ((_x > 30) && (_incrementoX > 0) && (_x < 92)) {
			borrar();
			if ((_y > y + 1) && (y < 21)) {
				y++;
			}
			if ((_y < y + 1) && (y >= 5)) {
				y--;
			}
			mostrar();
		}
	}
}