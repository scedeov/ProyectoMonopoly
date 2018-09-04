#ifndef TABLERO
#define TABLERO
#include "Solar.h"
#include "Ferrocarril.h"
#include "Esquina.h"
#include "Impuestos.h"
#include "ServicioPublico.h"
#include "Suerte.h"
#include "Jugador.h"

#include <iostream>
#include <sstream>
#include <Windows.h>

using namespace std;

const int tamano = 32;

enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };


class Tablero
{
private:
	Casilla* v[tamano]; //ya esta terminado pero se ve muy grande
public:
	Tablero();
	~Tablero();
	void dibujaJugador(int, bool);
	void borraJugador(int, bool);
	void dibujaTablero(Jugador*, Jugador*); //version minimalista
	void cambiaColor(int);
	void imprimeFicha(Jugador*, Jugador*, int);
	void imprimeColorSoles(int);
	void restableceColor();
	Casilla* getPos(int);


	
};

#endif