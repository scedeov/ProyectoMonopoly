#include "Casilla.h"

Casilla::Casilla()
{
	tipoPropiedad = "Sin definir";
	nombrePropiedad = "Sin definir";
	precioAlquiler = 0;
	dueno = "No tiene dueno";
	simboloCasilla = "O";
	cantidadCasas = 0;
	hotel = false;
	precioCompra = 0;
	jugador1 = false;
	jugador2 = false;
	numeroCasilla = 0;
	jugadorDueno = nullptr;
}

Casilla::~Casilla()
{
}

double Casilla::getPrecioAlquiler()
{
	double precio = 0;
	int numCas = cantidadCasas + 1;
	precio = precioCompra - precioCompra*PORCENTAJE_ALQUILER;
	precio = precio*numCas;
	if (hotel == true)
		precio += precioCompra*0.50;

	return precio;
}

string Casilla::getTipoPropiedad()
{
	return tipoPropiedad;
}

string Casilla::getNombrePropiedad()
{
	return nombrePropiedad;
}

string Casilla::getDueno()
{
	return dueno;
}

string Casilla::getSimboloCasilla()
{
	return simboloCasilla;
}

Jugador * Casilla::getJugadorDueno()
{
	return jugadorDueno;
}

int Casilla::getCantidadCasas()
{
	return cantidadCasas;
}

int Casilla::getNumeroCasilla()
{
	return numeroCasilla;
}

bool Casilla::getHotel()
{
	return hotel;
}

int Casilla::getPrecioCompra()
{
	return precioCompra;
}

void Casilla::setNumeroCasilla(int nCasilla)
{
	numeroCasilla = nCasilla;
}

void Casilla::setJugadorDueno(Jugador * j)
{
	jugadorDueno = j;
}

void Casilla::setSimboloCasilla(string simbolo)
{
	simboloCasilla = simbolo;
}

void Casilla::setJugador1(bool j1)
{
	jugador1 = j1;
}

bool Casilla::getJugador1()
{
	return jugador1;
}

void Casilla::setJugador2(bool j2)
{
	jugador2 = j2;
}

bool Casilla::getJugador2()
{
	return jugador2;
}

void Casilla::setTipoPropiedad(string unTitulo)
{
	tipoPropiedad = unTitulo;
}

void Casilla::setNombrePropiedad(string unNombre)
{
	nombrePropiedad = unNombre;
}

void Casilla::setDueno(string unDueno)
{
	dueno = unDueno;
}

void Casilla::setCantidadCasas(int unCantidad)
{
	cantidadCasas = unCantidad;
}

void Casilla::setHotel(bool unHotel)
{
	hotel = unHotel;
}

void Casilla::setPrecioCompra(int unPrecio)
{
	precioCompra = unPrecio;
}

string Casilla::infoCasilla()
{
	stringstream s;
	s << nombrePropiedad << endl;
	if (dueno != "No tiene dueno")
	{
		s << "Dueno: " << dueno << endl;
		s << "Casas: " << cantidadCasas << endl;
		if (hotel)
			s << "Posee Hotel" << endl;
		s << "Precio a Pagar por Alquiler: " << getPrecioAlquiler() << endl;
	}
	else
	{
		s << dueno << endl;
		s << "Precio de Compra: " << precioCompra << endl;
	}
	return s.str();
}
