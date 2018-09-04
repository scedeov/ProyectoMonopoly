#include "Jugador.h"

Jugador::Jugador()
{
	nombre = "Sin definir";
	casas = 0;
	dinero = 1500;
	hoteles = 0;
	estacionesAdquiridas = 0;
	serviciosPublicosAdquiridos = 0;
	hipotecas = 0;
	monopolios = 0;
	propiedades = 0;
	posicion = 0;
	NombrePropiedades = "";
	pierdeTurno = false;
	
}

Jugador::~Jugador()
{
}

void Jugador::setFicha(char xFicha)
{
	ficha = xFicha;
}

void Jugador::setPierdeTurno(bool pierde)
{
	pierdeTurno = pierde;
}

void Jugador::setNombrePropiedades(string nombrep)
{
	NombrePropiedades = nombrep;
}

void Jugador::setServiciosPublicosAdquiridos(int nServicios)
{
	serviciosPublicosAdquiridos = nServicios;
}

void Jugador::setEstacionesAdquiridas(int nEstaciones)
{
	estacionesAdquiridas = nEstaciones;
}

void Jugador::setNombre(string unNombre)
{
	nombre = unNombre;
}

void Jugador::setPosicion(int nPos)
{
	posicion = nPos;
}

void Jugador::setCasas(int unCasas)
{
	casas = unCasas;
}

void Jugador::setDinero(double unDinero)
{
	dinero = unDinero;
}

void Jugador::setHoteles(int unHoteles)
{
	hoteles = unHoteles;
}

void Jugador::setHipotecas(int nHipotecas)
{
	hipotecas = nHipotecas;
}

void Jugador::setMonopolios(int nMonopolios)
{
	monopolios = nMonopolios;
}

void Jugador::setPropiedades(int nPropiedades)
{
	propiedades = nPropiedades;
}

string Jugador::getNombre()
{
	return nombre;
}

string Jugador::getNombrePropiedades()
{
	return NombrePropiedades;
}

bool Jugador::getPierdeTurno()
{
	return pierdeTurno;
}

char Jugador::getFicha()
{
	return ficha;
}

int Jugador::getServiciosPublicosAdquiridos()
{
	return serviciosPublicosAdquiridos;
}

int Jugador::getEstacionesAdquiridas()
{
	return estacionesAdquiridas;
}

int Jugador::getPosicion()
{
	return posicion;
}

int Jugador::getCasas()
{
	return casas;
}

double Jugador::getDinero()
{
	return dinero;
}

int Jugador::getHoteles()
{
	return hoteles;
}

int Jugador::getHipotecas()
{
	return hipotecas;
}

int Jugador::getMonopolios()
{
	return monopolios;
}

int Jugador::getPropiedades()
{
	return propiedades;
}

string Jugador::estadoJugador()
{
	stringstream s;

	s << "Nombre: " << nombre << endl;
	s << "Dinero: " << dinero << endl;
	if (propiedades > 0)
		s << "Propiedades Adquiridas: " << NombrePropiedades << endl;
	s << "Cant. Casas: " << casas << endl;
	s << "Cant. Hoteles: " << hoteles << endl;
	s << "Cant. Servicios Publicos: " << serviciosPublicosAdquiridos << endl;
	s << "Cant. Estaciones de Ferrocarril: " << estacionesAdquiridas << endl;

	return s.str();
}
