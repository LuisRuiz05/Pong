#pragma once
#include <iostream>													//Librería de C++
#include <string>													//Librería para incluuir cadenas de texto
#include <Windows.h> 												//Para controlar la ventena de consola
#include <conio.h> 													//Para detectar las teclas que se presionen
#include <stdio.h>													//Libreria de programación en C
using namespace std;

void gotoxy(int x, int y) {											//Funcion que inicializa en consola con las coordenadas dadas
	HANDLE hCon;													//objeto de tipo ventana de consola, identificador de nuestra ventana
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);							//tomar el control de la salida

	COORD Pos;														//Se crea un objeto de tipo COORD
	Pos.X = x;														//Se le asignan los valores al objeto refiriendose a un punto e una coordenada
	Pos.Y = y;														//Se le asignan los valores al objeto refiriendose a un punto e una coordenada
	SetConsoleCursorPosition(hCon, Pos);							//Permite dar una posición al cursor
}


void apagarCursor(bool x) {											//Función que apaga el cursor o no
	HANDLE hCon;													//objeto de tipo ventana de consola, identificador de nuestra ventana
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);							//tomar el control de la salida
	CONSOLE_CURSOR_INFO cci;										//objeto para tomar información del cursor
	cci.dwSize = 1;
	cci.bVisible = x;												//Asignamos el valor de la variable booleana al atributo
	SetConsoleCursorInfo(hCon, &cci);								//Se pasa por referencia porque es un valor que se estará actualizando 
}


void printContorno() {
	//Dimensiones 120x30
	gotoxy(18, 0); cout << "PONG SOCCER."							//Imprime un titulo en la cabecera
		"                    by: JONATHAN CUEVAS & LUIS RUIZ";

	/////////////////////////////////////////////////Ciclo for que imprime la linea central/////////////////////////////////////////////////

	/*for (int i = 1; i < 26; i++)
		gotoxy(58, i); cout << "I";
	}*/

	/////////////////////////////////////////Ciclo for que imprime el contorno superior e inferior/////////////////////////////////////////

	for (int i = 5; i < 115; i++) {
		gotoxy(i, 1); printf("%c", 205);
		gotoxy(i, 26); printf("%c", 205);
	}

	/////////////////////////////////Ciclo for que imprime el contorno lateral izquierdo y derecho superior/////////////////////////////////

	for (int i = 2; i < 8; i++) {
		gotoxy(5, i); printf("%c", 186);
		gotoxy(115, i); printf("%c", 186);
	}

	/////////////////////////////////Ciclo for que imprime el contorno lateral izquierdo y derecho inferior/////////////////////////////////

	for (int i = 20; i < 26; i++) {
		gotoxy(5, i); printf("%c", 186);
		gotoxy(115, i); printf("%c", 186);
	}


	//////////////////////////////////////////////////Impresion del lateral de la porteria//////////////////////////////////////////////////

	gotoxy(116, 19); printf("%c", 205);
	gotoxy(4, 19); printf("%c", 205);
	gotoxy(117, 19); printf("%c", 205);
	gotoxy(3, 19); printf("%c", 205);
	gotoxy(116, 8); printf("%c", 205);
	gotoxy(4, 8); printf("%c", 205);
	gotoxy(117, 8); printf("%c", 205);
	gotoxy(3, 8); printf("%c", 205);

	//////////////////////////////////////////////////Impresion del fondo de la porteria//////////////////////////////////////////////////

	for (int i = 9; i < 19; i++) {
		gotoxy(118, i); printf("%c", 186);
	}
	for (int i = 9; i < 19; i++) {
		gotoxy(2, i); printf("%c", 186);
	}

	///////////////////////////////////////////////////////Impresion de las esquinas///////////////////////////////////////////////////////

	gotoxy(5, 1); printf("%c", 201);								//Pinta esquina superior izquierda
	gotoxy(115, 1); printf("%c", 187);								//Pinta esquina superior derecha
	gotoxy(5, 26); printf("%c", 200);								//Pinta esquina inferior izquierda
	gotoxy(115, 26); printf("%c", 188);								//Pinta esquina inferior derecha
	
	gotoxy(115, 19); printf("%c", 201);								//Pinta esquina superior izquierda en la porteria
	gotoxy(5, 19); printf("%c", 187);								//Pinta esquina superior derecha en la porteria
	gotoxy(115, 8); printf("%c", 200);								//Pinta esquina inferior izquierda en la porteria
	gotoxy(5, 8); printf("%c", 188);								//Pinta esquina inferior derecha en la porteria

	gotoxy(2, 19); printf("%c", 200); 								//Pinta esquina superior izquierda en la porteria
	gotoxy(118, 19); printf("%c", 188);								//Pinta esquina superior derecha en la porteria
	gotoxy(2, 8); printf("%c", 201);								//Pinta esquina inferior izquierda en la porteria
	gotoxy(118, 8); printf("%c", 187);								//Pinta esquina inferior derecha en la porteria
}

//Imprime el texto de Game Over
void gameOverShow(){
	gotoxy(5, 5); cout <<  " _____ _____ _____ _____    _____ _____ _____ _____ ";
	gotoxy(5, 6); cout <<  "|   __|  _  |     |   __|  |     |  |  |   __| __  |";
	gotoxy(5, 7); cout <<  "|  |  |     | | | |   __|  |  |  |  |  |   __|    -|";
	gotoxy(5, 8); cout <<  "|_____|__|__|_|_|_|_____|  |_____| \___/|_____|__|__|";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
}

//Imprime el menú inicial del juego
void startGame(){
	gotoxy(30, 5); cout <<  " _______  _______  _______  ______    _______ ";
	gotoxy(30, 6); cout <<  "|       ||       ||   _   ||    _ |  |       |";
	gotoxy(30, 7); cout <<  "|  _____||_     _||  |_|  ||   | ||  |_     _|";
	gotoxy(30, 8); cout <<  "| |_____   |   |  |       ||   |_||_   |   |  ";
	gotoxy(30, 9); cout <<  "|_____  |  |   |  |       ||    __  |  |   |  ";
	gotoxy(30, 10); cout << " _____| |  |   |  |   _   ||   |  | |  |   |  ";
	gotoxy(30, 11); cout << "|_______|  |___|  |__| |__||___|  |_|  |___|  ";
	gotoxy(33, 14); cout << "PRESIONE 1 PARA MODO JUGADOR VS JUGADOR ";
	gotoxy(33, 15); cout << "PRESIONE 2 PARA MODO JUGADOR VS MAQUINA ";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
}

//Imprime un menú para seleccionar una dificultad
void difficulty() {
	gotoxy(50, 11); cout << "ELIJA UNA DIFICULTAD:";
	gotoxy(50, 13); cout << "1) MEDIO ";
	gotoxy(50, 14); cout << "2) DIFICIL ";
	gotoxy(50, 15); cout << "3) IMPOSIBLE ";

	gotoxy(40, 20); cout << "RECUERDE JUGAR CON LAS MAYUSCULAS ACTIVADAS";
}

//Imprime la animación de un gol
void showGol(){
	gotoxy(35, 5); cout <<  " _____ _____ _____ _____ _____ _____ _____ __    ";
	gotoxy(35, 6); cout <<  "|   __|     |     |     |     |     |     |  |   ";
	gotoxy(35, 7); cout <<  "|  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |__ ";
	gotoxy(35, 8); cout <<  "|_____|_____|_____|_____|_____|_____|_____|_____|";
	gotoxy(30, 10); cout <<  "AT&T, GNP SEGUROS Y TELEVISA DEPORTES, GOLAZO AZO AZO AZOOO";
	cout << endl;
	Sleep(2500);
	system("cls");
}
