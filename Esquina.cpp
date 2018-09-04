#include "Esquina.h"

Esquina::Esquina(int num, int cas)
{
	setNumeroCasilla(cas);
	go = false;
	carcel = false;
	veCarcel = false;
	parqueo = false;

	switch (num) // define el tipo de esquina desde que se crea
	{
	case 1:
	{
		go = true;
		setNombrePropiedad("GO");
		setSimboloCasilla(" GO");
		setJugador1(false);
		break;
	}
	case 2:
	{
		carcel = true;
		setNombrePropiedad("Carcel");
		setSimboloCasilla("KRL");
		break;
	}
	case 3:
	{
		parqueo = true;
		setNombrePropiedad("Parqueo");
		setSimboloCasilla("PRQ");
		break;
	}
	case 4:
	{
		veCarcel = true;
		setNombrePropiedad("Ve a la Carcel");
		setSimboloCasilla("GKR");
		break;
	}
	default: break;
	}
}

void Esquina::setParqueo(bool parqu)
{
	parqueo = parqu;
}

void Esquina::setVeCarcel(bool veCar)
{
	veCarcel = veCar;
}

void Esquina::setCarcel(bool car)
{
	carcel = car;
}

void Esquina::setGo(bool g)
{
	go = g;
}

void Esquina::limpiaAtributos()
{
	parqueo = false;

}

Esquina::~Esquina()
{
}

string Esquina::mensajeEsquina()
{
	stringstream s;
	s << nombrePropiedad << endl;
	if (parqueo)
		s << "Felicidades, has ganado el acumulado." << endl;
	if (veCarcel)
	{
		s << "Felicidades, has metido las patas." << endl;
		s << " Pierdes el siguiente turno y en caso de que no poseas dinero para pagar la fianza, seguiras perdiendo turnos LOL :^)" << endl;
	}
	if (carcel)
		s << "Has visitado a un familiar en la carcel y te han dejado encerrado por traer droga consigo." << endl;
	

	return s.str();
}
