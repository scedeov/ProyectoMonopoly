#ifndef CASILLA
#define CASILLA

#define PORCENTAJE_ALQUILER 0.35
#include "Jugador.h"
#include <iostream>
#include <sstream>
using namespace std;

class Casilla // Padre
{
protected:
	string tipoPropiedad;
	string nombrePropiedad;
	string dueno;
	string simboloCasilla;
	bool jugador1;
	bool jugador2;
	int cantidadCasas;
	bool hotel;
	int precioCompra;
	int numeroCasilla;
	int precioAlquiler;
	Jugador* jugadorDueno;
public:
	Casilla();
	virtual ~Casilla();
	double getPrecioAlquiler();
	string getTipoPropiedad();
	string getNombrePropiedad();
	string getDueno();
	string getSimboloCasilla();
	Jugador* getJugadorDueno();
	int getCantidadCasas();
	int getNumeroCasilla();
	bool getHotel();
	int getPrecioCompra();
	void setNumeroCasilla(int);
	void setJugadorDueno(Jugador*);
	void setSimboloCasilla(string);
	void setJugador1(bool);
	bool getJugador1();
	void setJugador2(bool);
	bool getJugador2();
	void setTipoPropiedad(string);
	void setNombrePropiedad(string);
	void setDueno(string);
	void setCantidadCasas(int);
	void setHotel(bool);
	void setPrecioCompra(int);

	string infoCasilla();


};

#endif
