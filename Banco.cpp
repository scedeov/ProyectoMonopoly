#include "Banco.h"

Banco::Banco()
{
	pozo = 0;
	dinero = 10000;
}

Banco::~Banco()
{
}

void Banco::setPozo(double nPozo)
{
	pozo = nPozo;
}

void Banco::setDinero(double nDinero)
{
	dinero = nDinero;
}

double Banco::getPozo()
{
	return pozo;
}

double Banco::getDinero()
{
	return dinero;
}

string Banco::estadoBanco()
{
	stringstream s;
	s << "El acumulado en el pozo es de: " << pozo << endl;
	return s.str();
}

void Banco::reparteDineroJugadores(Jugador* j1, Jugador* j2)
{
	j1->setDinero(1500);
	j2->setDinero(1500);
}

void Banco::otorgaAcumulado(Jugador* j)
{
	j->setDinero(j->getDinero() + pozo);
	pozo = 0;
}

void Banco::cobraPeaje(Jugador* j1, Jugador* j2)
{

	j1->getPosicion();
}

void Banco::go(Jugador * j)
{
	j->setDinero(j->getDinero() + 200);
	cout << "El Banco te paga $200" << endl;
}
