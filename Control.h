#ifndef CONTROL
#define CONTROL


//-----------------
#include <conio.h>
#include <iostream>
#include <string>
using namespace std;
//--------------
#include "Interfaz.h"
#include "Dado.h"
#include "Jugador.h"
#include "Banco.h"
#include "Tablero.h"
#include "mazoCartas.h"

class Control
{
private:
	Interfaz i;
	Dado d;
	Jugador* j1;
	Jugador* j2;
	Banco* b;
	Tablero* t;
	Mazo* m;
	bool turno;
	int dado;
	bool pierdeTurno;
	bool gameover;

public:
	void inicio();
	void vealacarcel(Jugador*);
	void coordenadasXY(int, int);
	void mueveJugador(Jugador*);
	void cambiaTurno(bool);
	void muestraTablero(bool);
	void checkAccion(Jugador*, Tablero*, Banco*, Mazo*);
	bool verificaColor(Jugador*, string);
	void pausa();
};
#endif