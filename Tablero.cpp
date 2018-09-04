#include "Tablero.h"


Tablero::Tablero()
{
	int cont1, cont2, cont3;
	cont1 = cont2 = cont3 = 1; //asigna el tipo de cada uno de los hijos

	for (int x = 0; x < tamano; x++)
	{


		if ((x == 0) || (x % (tamano / 4) == 0))
		{
			v[x] = new Esquina(cont1, x);
			cont1++;
		}
		else
			if (x == 9 || x == 23)
			{
				v[x] = new Impuestos(x);
			}
			else
				if (x == 2 || x == 18)
				{
					v[x] = new Servicio_Publico(cont2, x);
					cont2++;
				}
				else
					if (x == 5 || x == 11 || x == 22 || x == 30) //se le puede agregar nombre a las estaciones
					{
						v[x] = new Ferrocarril(x);
					}
					else
						if (x == 4 || x == 6 || x == 7 || x == 12 || x == 14 || x == 15 || x == 17 || x == 19 || x == 20 || x == 25 || x == 26 || x == 28)
						{
							v[x] = new Solar(cont3, x);
							cont3++;
						}
						else
							v[x] = new Suerte(x);
	}
}

Tablero::~Tablero()
{
	for (int x = 0; x < tamano; x++)
	{
		delete[] v[x];
	}
	//delete[] v;
}

void Tablero::dibujaJugador(int pos, bool turno)
{
	if (turno)
		v[pos]->setJugador1(true);
		
	else
		v[pos]->setJugador2(true);
}



void Tablero::borraJugador(int pos, bool turno)
{
	if (turno)
		v[pos]->setJugador1(false);
	else
		v[pos]->setJugador2(false);
}

void Tablero::dibujaTablero(Jugador* j1, Jugador* j2)
{
	int cont1 = 0;
	int cont2 = 31;
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			if (x == 0)
			{
				imprimeFicha(j1, j2, cont1);
				cont1++;
			}
			else
				if ((y == 8 && x != 0) && x != 8)
				{
					imprimeFicha(j1, j2, cont1);
					cont1++;
				}
				else
					if (y == 0)
					{
						imprimeFicha(j1, j2, cont2);
						cont2--;
					}
					else
						if (x == 8 && y != 0)
						{
							imprimeFicha(j1, j2, cont2);
							cont2--;
						}
						else
							cout << "     ";
		}
		cout << endl << endl;
	}

}

void Tablero::cambiaColor(int c)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}

void Tablero::imprimeFicha(Jugador* j1, Jugador* j2, int contador)
{
	if (v[contador]->getJugador1() == false && v[contador]->getJugador2() == false) //Ningun Jugador
	{
		imprimeColorSoles(contador);
		cout << v[contador]->getSimboloCasilla();
		restableceColor();
		cout << "  ";
	}

	if (v[contador]->getJugador1() == true && v[contador]->getJugador2() == true) //Ambos Jugadores
	{
		imprimeColorSoles(contador);
		cout << v[contador]->getSimboloCasilla();
		restableceColor();
		cout << "*" << " ";
	}

	if (v[contador]->getJugador1() == true && v[contador]->getJugador2() == false) //Jugador Uno
	{
		imprimeColorSoles(contador);
		cout << v[contador]->getSimboloCasilla();
		restableceColor();
		cout << j1->getFicha() << " ";
	}

	if (v[contador]->getJugador1() == false && v[contador]->getJugador2() == true) //Jugador Dos
	{
		imprimeColorSoles(contador);
		cout << v[contador]->getSimboloCasilla();
		restableceColor();
		cout << j2->getFicha() << " ";
	}
}

void Tablero::imprimeColorSoles(int contador)
{
	if (dynamic_cast<Solar*>(v[contador]))
	{
		Solar* temp = dynamic_cast<Solar*>(v[contador]);
		if (temp->getColor() == "Azul")
		{
			cambiaColor(BLUE);
		}
		if (temp->getColor() == "Amarillo")
		{
			cambiaColor(YELLOW);
		}
		if (temp->getColor() == "Rojo")
		{
			cambiaColor(RED);
		}
		if (temp->getColor() == "Verde")
		{
			cambiaColor(GREEN);
		}
	}
}

void Tablero::restableceColor()
{
	cambiaColor(GRAY);
}


Casilla * Tablero::getPos(int pos)
{
	return v[pos];
}
