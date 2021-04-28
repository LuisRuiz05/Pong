//Proyecto Final: Videojuego
//PONG SOCCER
//Luis Fernando Ruiz Ram�rez 			0224451
//Jonathan Oswualdo Cuevas Jim�nez		0225174

////////////////////////DECLARACI�N DE FUNCIONES Y DEFINICI�N DE PARAMETROS///////////////////////////////////////////////////////
#include <iostream>											//Librer�a de C++
#include <string>											//Librer�a para incluuir cadenas de texto
#include <Windows.h> 										//Para controlar la ventena de consola
#include <conio.h> 											//Para detectar las teclas que se presionen
#include <stdio.h>											//Para lineas de codigo en C
#include "Funciones.h"										//Llamamos a la librer�a Funciones, para acceder a sus funciones
#include "Players.h"										//Llamamos a la librer�a Players, para acceder a sus metodos y funciones
#include "Pelota.h"											//Llamamos a la librer�a Peltota, para acceder a sus metodos y funciones

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////FUNCI�N MAIN//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	char tecla;												//Declaraci�n del atributo que ingresa un caracter del teclado
	bool gameOver = false;									//Declaraci�n e inicializaci�n de la variable que iniciar� el juego o lo terminar�
	int longitud1 = 20, latitud = 12, longitud2 = 91;		//Declaraci�n de las coordenadas de los jugadores
	int op_jugador;											//Declaraci�n de la variable para el modo de juego
	int op_dif;												//Declaraci�n de la variable para la dificultad del juego

	apagarCursor(false);									//Funci�n que apaga el cursos de la impresi�n de pantalla	
	startGame();											//Funci�n que imprime texto de START para iniciar el juego
	do {
		gotoxy(40, 17); cin >> op_jugador;					//Ingresa el modo de juego
	} while (op_jugador != 1 && op_jugador != 2);			//Condicional para que el modo de juego ingresado sea v�lido
	system("cls");											//Funci�n para borrar mensaje

	difficulty();											//Funci�n para mostrar el men� de dificultad
	do {
		gotoxy(50, 16); cin >> op_dif;						//Ingresa la dificultad del juego
	} while (op_dif < 1 || op_dif > 3);						//Condicional para que la dificultad de juego ingresada sea v�lida
	system("cls");

	printContorno();										//Funcion para mostrar el contorno Sdel campo

	leftPlayer p1;											//Se define un objeto de la clase leftPlayer
	p1.setX(longitud1);										//Se le asigna un valor referente a una coordenada en X
	p1.setY(latitud);										//Se le asigna un valor referente a una coordenada en Y

	rightPlayer p2;											//Se define un objeto de la clase rightPlayer
	p2.setX(longitud2);										//Se le asigna un valor referente a una coordenada en X
	p2.setY(latitud);										//Se le asigna un valor referente a una coordenada en Y

	pelota ball;											//Se define un objeto de la clase pelota

	p1.mostrar();											//Se llama al metoodo que muestra el objeto del jugador 1
	p2.mostrar();											//Se llama al metoodo que muestra el objeto del jugador 2
	ball.mostrar();											//Se llama al metoodo que muestra el objeto pelota

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////INICIO DEL JUEGO//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	while (gameOver != true) {								//Este ciclo se ejecutr� mientras gameover sea diferente que true
		p1.printScore(26, 28);								//Imprimimos marcador del jugador 1
		p2.printScore(86, 28);								//Imprimimos marcador del jugador 2
		p1.mover();											//Metodo que mueve el objeto del jugador 1
		Sleep(5);											//Es un descanso que se da para que detecte la tecla
		if(op_jugador==1){
		p2.mover();											//Metodo que mueve el objeto del jugador 2 manualmente
		}
		if(op_jugador==2){
			p2.computadora(ball.getX(), ball.getY(), 
			ball.getXPlus(), ball.getYPlus(), op_dif);		//Metodo que mueve el objeto del jugador 2 automaticamente							
		}
		
		ball.colision(p1, p2);								//Metodo que detecta colision con los jugadores
		ball.gol(p1, p2);									//Metodo que detecta si hubo un gol
		p1.mostrar();										//Muestra nuevamente al jugador 1 despu�s de borrar la pantalla
		p2.mostrar();										//Muestra nuevamente al jugador 2 despu�s de borrar la pantalla

		if (p1.getScore() == 3 || p2.getScore() == 3) {
			gameOver = true;								//Una vez que se cumple con la condici�n se cambia el valor de la variable gameover a true
			system("cls");									//Una vez que se cumple con la condici�n se limpia la pantalla para terminar el juego
			gameOverShow();									//Muestra que el juego se ha terminado

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////Muestra el resultado final del juego////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			gotoxy(10, 10); cout << "MARCADOR FINAL: IZQUIERDA: " << p1.getScore() << " DERECHA: " <<p2.getScore();
			cout << endl;
		}
		Sleep(30);											//Es un descanso que se da para controlar la velocidad del juego
	}
}
