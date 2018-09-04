#ifndef JUGADOR
#define JUGADOR

#include <iostream>
#include <sstream>
using namespace std;

class Jugador
{
private:
	string nombre;
	string NombrePropiedades;
	int casas;
	double dinero;
	int hoteles;
	int serviciosPublicosAdquiridos;
	int estacionesAdquiridas;
	int hipotecas;
	int monopolios;
	int propiedades;
	int posicion;
	char ficha;
	bool pierdeTurno;
public:
	Jugador();
	~Jugador();
	void setFicha(char);
	void setPierdeTurno(bool);
	void setNombrePropiedades(string);
	void setServiciosPublicosAdquiridos(int);
	void setEstacionesAdquiridas(int);
	void setNombre(string);
	void setPosicion(int);
	void setCasas(int);
	void setDinero(double);
	void setHoteles(int);
	void setHipotecas(int);
	void setMonopolios(int);
	void setPropiedades(int);

	string getNombre();
	string getNombrePropiedades();
	bool getPierdeTurno();
	char getFicha();
	int getServiciosPublicosAdquiridos();
	int getEstacionesAdquiridas();
	int getPosicion();
	int getCasas();
	double getDinero();
	int getHoteles();
	int getHipotecas();
	int getMonopolios();
	int getPropiedades();

	string estadoJugador(); // falta agregar varios atributos de los que no estoy seguro


};
#endif
