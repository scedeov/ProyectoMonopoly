#ifndef BANCO
#define BANCO

#define INTERES_VENTA 0.35
#define PORCENTAJE_INICIAL 0.05
#define HOTEL 10000
#define MAX_CASAS 4
#define CASA 2500
#define PORCENTAJE_CASA_HOTEL 0.15
#define MAX_MONOPOLIO 2


#include <iostream>
#include <sstream>

#include "Jugador.h"
#include "Casilla.h"


using namespace std;

class Banco 
{
private:
	double pozo;
	double dinero;
public:
	Banco();
	~Banco();
	void setPozo(double);
	void setDinero(double);
	double getPozo();
	double getDinero();
	string estadoBanco();
	void interesHacienda(); //metodo que cobra un interes por cada venta de propiedades entre jugadores y lo agregue al pozo;
	void reparteDineroJugadores(Jugador*, Jugador*); //puede que necesite cambiar los punteros, estudiar bien eso.
	void otorgaAcumulado(Jugador*); //le otorga el acumulado que hay en el pozo al jugador que logre caer en esa casilla
	void cobraPeaje(Jugador*, Jugador*); // le cobra la cantidad correspondiente al jugador que caiga en la casilla, dependiendo de las casas y hoteles, asi como tambien si la posee o no
	void go(Jugador*);
};
#endif