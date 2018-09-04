#include "Control.h"

void Control::inicio()
{
	gameover = false;


	i.menuInicio();
	while (cin.get() != '\n')
	{
		cin.get();
	}
	//inicializadores
	t = new Tablero();
	m = new Mazo();

	system("cls");

	cout << "Ingrese el nombre del Jugador 1 -> "; _flushall();
	string Jugador1; getline(cin, Jugador1);
	while (Jugador1 == "")
	{
		cout << "Debe ingresar un nombre, el nombre no puede estar vacio. Favor ingrese su nombre de nuevo -> "; getline(cin, Jugador1);
	}

atajo1:
	cout << "Seleccione su ficha: (+) o (-) -> ";
	char ficha = _getch();
	while (ficha != '+' && ficha != '-')
	{
		cout << "Ficha no valida. Ingrese de nuevo la opcion." << endl;
		goto atajo1;
	}

	j1 = new Jugador();
	j1->setNombre(Jugador1);
	j1->setFicha(ficha);
	cout << "Su ficha es: " << j1->getFicha() << endl; pausa();
	//---------------------------
	system("cls");
	cout << "Ingrese el nombre del Jugador 2 -> "; _flushall();
	string Jugador2; getline(cin, Jugador2);
	while (Jugador2 == "" || Jugador1 == Jugador2)
	{
		cout << "Debe ingresar un nombre valido, el nombre no puede estar vacio o no puede ser igual al del primer Jugador. Favor ingrese su nombre de nuevo -> "; getline(cin, Jugador2);
	}

	j2 = new Jugador();
	j2->setNombre(Jugador2);
	if (ficha == '+')
		j2->setFicha('-');
	else
		j2->setFicha('+');
	cout << "Su ficha es: " << j2->getFicha() << endl;
	//------------------------------
	//El banco reparte el dinero y se muestra estado de los jugadores
	b = new Banco();
	b->reparteDineroJugadores(j1, j2); cout << "Repartiendo dinero a los jugadores..." << endl;
	cout << "Para una mejor experiencia de juego, favor maximizar la ventana..." << endl; pausa();

	dado = 0;

	turno = true; //true jugador 1, false jugador 2

	do
	{
		

		muestraTablero(turno);

		if (turno == true)
		{
			if (j1->getPierdeTurno() == true)
			{
				coordenadasXY(0, 28); cout << "Pierdes este turno por haber caido en la carcel el turno anterior." << endl;
				pausa();
				j1->setPierdeTurno(false);
				goto skip;
			}
		}
		else
		{
			if (j2->getPierdeTurno() == true)
			{
				coordenadasXY(0, 28);  cout << "Pierdes este turno por haber caido en la carcel el turno anterior." << endl;
				pausa();
				j2->setPierdeTurno(false);
				goto skip;
			}
		}

		coordenadasXY(0, 28); cout << "Desea lanzar los dados? Si <Enter> | Salir del juego <ESC> " << endl; int respuesta = _getch();
		while (respuesta != 13 && respuesta != 27)
		{
			cout << "Opcion incorrecta. Favor ingrese una opcion valida -> " << endl;
			respuesta = _getch();
		}

		if (respuesta == 27)
		{
			gameover = true;
			goto skip;
		}


		coordenadasXY(48, 0); cout << "Lanzando dado.. ->";
		dado = d.lanzaDado(); cout << dado << endl;
		coordenadasXY(48, 3); cout << "Presione Enter para mover su ficha.";
		cin.get();

		if (turno == true) //mantiene en movimiento las fichas
		{
			mueveJugador(j1);
			checkAccion(j1, t, b, m);
			pausa();
		}
		else
		{
			mueveJugador(j2);
			checkAccion(j2, t, b, m);
			pausa();
		}


		_flushall();
		cin.clear();
	skip:
		cambiaTurno(turno);
	} while (gameover == false);

	delete t;
	delete m;
	delete j1;
	delete j2;
	delete b;
}


void Control::coordenadasXY(int unX, int unY)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordenada;
	coordenada.X = unX;
	coordenada.Y = unY;
	SetConsoleCursorPosition(hCon, coordenada);
}

void Control::mueveJugador(Jugador* j)
{
	t->borraJugador(j->getPosicion(), turno); //posicion anterior

	int vieja = j->getPosicion();
	int nueva = vieja + dado;
	if (nueva > 31)
	{
		b->go(j); //otorga 200 cada vez que se pasa por go
		nueva = nueva - 32;
	}

	j->setPosicion(nueva);
	t->dibujaJugador(j->getPosicion(), turno); // posicion nueva
	muestraTablero(turno);
}

void Control::cambiaTurno(bool xturno)
{
	if (xturno == true)
		turno = false;
	else
		turno = true;
}
void Control::muestraTablero(bool turno)
{
	system("cls");
	cout << "Turno del Jugador ";
	if (turno == true)
	{
		cout << "1  ";
		cout << j1->getNombre(); cout << " " << j1->getFicha() << endl;
		cout << j1->estadoJugador();
	}
	else
	{
		cout << "2  ";
		cout << j2->getNombre(); cout << " " << j2->getFicha() << endl;
		cout << j2->estadoJugador();
	}

	cout << endl << endl;


	t->dibujaTablero(j1, j2);
	coordenadasXY(16, 12);
	cout << "Acumulado";
	coordenadasXY(16, 13);
	cout << b->getPozo();
	coordenadasXY(0, 32);





}

void Control::checkAccion(Jugador* j, Tablero* tab, Banco* banc, Mazo* mazo)
{
	Casilla* casilla = t->getPos(j->getPosicion());

	if (dynamic_cast<Solar*>(casilla) || dynamic_cast<Servicio_Publico*>(casilla) || dynamic_cast<Ferrocarril*>(casilla))
	{
		char answer;
		cout << casilla->infoCasilla();
		if (casilla->getDueno() == j->getNombre())
		{
			if (dynamic_cast<Solar*>(casilla))
			{
				Solar* temp = dynamic_cast<Solar*>(casilla);

				string color = temp->getColor();
				if (verificaColor(j, color) == true)
				{
					if (temp->getCantidadCasas() == MAX_CASAS)
					{
						cout << "Posees 4 Casas en esta Propiedad. Deseas construir un Hotel Si <Y> No <N> " << endl;
						answer = _getch();
						while (toupper(answer) != 'Y' && toupper(answer) != 'N')
						{
							cout << "Opcion Incorrecta. Digite una opcion valida " << endl;
							answer = _getch();
						}
						if (toupper(answer) == 'Y')
						{
							if (j->getDinero() > HOTEL)
							{
								j->setDinero(j->getDinero() - HOTEL);
								b->setDinero(b->getDinero() + HOTEL);
								temp->setHotel(true);
								j->setHoteles(j->getHoteles() + 1);
								muestraTablero(turno);
								cout << endl << "Listo"; cin.get();
							}
						}
					}
					else
					{
						cout << "Eres propietario de todos los Soles de color " << temp->getColor() << endl;
						cout << "Deseas construir casas? Si <Y> No <N> " << endl;
						answer = _getch();
						while (toupper(answer) != 'Y' && toupper(answer) != 'N')
						{
							cout << "Opcion Incorrecta. Digite una opcion valida " << endl;
							answer = _getch();
						}
						if (toupper(answer) == 'Y')
						{
							if (j->getDinero() > CASA)
							{
								j->setDinero(j->getDinero() - CASA);
								b->setDinero(j->getDinero() + CASA);
								b->setPozo(b->getPozo() + (CASA * PORCENTAJE_CASA_HOTEL));
								temp->setCantidadCasas(temp->getCantidadCasas() + 1);
								j->setCasas(j->getCasas() + 1);
								muestraTablero(turno);
								cout << endl << "Listo" << endl;
							}
						}

					}

				}
			}
		}
		if (casilla->getDueno() == "No tiene dueno")
		{
			if (j->getDinero() < casilla->getPrecioCompra())
				cout << "No posees dinero suficiente para comprar esta propiedad. " << endl;
			else
			{
				cout << "Desea comprar la propiedad? Si <Y> No <N> " << endl;
				answer = _getch();
				while (toupper(answer) != 'Y' && toupper(answer) != 'N')
				{
					cout << "Opcion Incorrecta. Ingrese una opcion valida-> " << endl;
					answer = _getch();
				}
				if (toupper(answer) == 'Y')
				{
					if (j->getDinero() >= casilla->getPrecioCompra())
					{
						j->setDinero(j->getDinero() - casilla->getPrecioCompra());
						b->setDinero(b->getDinero() + (casilla->getPrecioCompra()*INTERES_VENTA));
						b->setPozo(b->getPozo() + (casilla->getPrecioCompra() - (casilla->getPrecioCompra()*INTERES_VENTA)));
						casilla->setJugadorDueno(j);
						casilla->setDueno(j->getNombre());
						j->setPropiedades(j->getPropiedades() + 1);
						j->setNombrePropiedades(j->getNombrePropiedades() + "  " + t->getPos(j->getPosicion())->getSimboloCasilla());
						muestraTablero(turno);
						cout << endl << "Listo" << endl;
					}
				}
			}
		}

		if (casilla->getDueno() != "No tiene dueno" && casilla->getDueno() != j->getNombre())
		{
			cout << "Has caido en una casilla propiedad de " << casilla->getJugadorDueno()->getNombre() << endl;
			cout << "Debes pagar el alquiler correspondiente -> " << casilla->getPrecioAlquiler() << endl;
			cout << "Pagar Si <Y> No <N> "; char ans = _getch();
			while (toupper(ans) != 'Y' && toupper(ans) != 'N')
			{
				cout << "Opcion Incorrecta. Ingrese una opcion valida ->"; ans = _getch();
				cout << endl;
			}
			if (toupper(ans) == 'N')
			{
				cout << "Te has resistido a pagar el alquiler. Vas a la carcel por carebarro." << endl;
				goto carcel;
			}
			else
			{

				if (j->getDinero() > casilla->getPrecioAlquiler())
				{
					j->setDinero(j->getDinero() - casilla->getPrecioAlquiler());
					casilla->getJugadorDueno()->setDinero(casilla->getJugadorDueno()->getDinero() + casilla->getPrecioAlquiler());
					b->setPozo(b->getPozo() + casilla->getPrecioAlquiler());
				}
				else
				{
					cout << "Insuficiente Dinero. Has Perdido." << endl;
					gameover = true;
				}
			}
		}
	}

	if (dynamic_cast<Esquina*>(casilla))
	{
		Esquina* temp = dynamic_cast<Esquina*>(casilla);

		coordenadasXY(0, 32); cout << temp->mensajeEsquina();
		pausa();
		//--------------------------------
		if (j->getPosicion() == 8)
		{
			coordenadasXY(0, 32); cout << temp->mensajeEsquina();
		carcel:
			double fianza = 400;

			j->setPierdeTurno(true);

			if (j->getDinero() < fianza)
			{
				cout << "No tienes dinero suficiente para pagar la fianza. Has perdido." << endl;
				gameover = true;
			}
			else
			{
				j->setDinero(j->getDinero() - 400);
				cout << "Has salido de la carcel pagando la fianza, pero aun asi debes pasar la noche ahi, y por ello pierdes un turno. " << endl;
				j->setPierdeTurno(true);
			}
		}
		//------------------------------------
		if (j->getPosicion() == 16)
		{
			Esquina* temp = dynamic_cast<Esquina*>(casilla);
			b->otorgaAcumulado(j);
			muestraTablero(turno);
			coordenadasXY(0, 32); cout << temp->mensajeEsquina();
		}
		//------------------------------------
		if (j->getPosicion() == 24)
		{
			Esquina* temp = dynamic_cast<Esquina*>(casilla);

			vealacarcel(j);
			muestraTablero(turno);
			coordenadasXY(0, 32); cout << temp->mensajeEsquina();
			goto carcel;
		}
	}
	//---------------------------
	if (dynamic_cast<Impuestos*>(casilla))
	{
		Impuestos* temp = dynamic_cast<Impuestos*>(casilla);
		j->setDinero(j->getDinero() - temp->getImpuesto());
		banc->setDinero(banc->getDinero() + temp->getImpuesto());
		banc->setPozo(banc->getPozo() + (temp->getImpuesto()*0.50));
		muestraTablero(turno);
		coordenadasXY(0, 32);  cout << temp->mensajeImpuestos();

	}

	if (dynamic_cast<Suerte*>(casilla)) // agregar metodo aque actue dependiendo de la carta que sale
	{
		cout << "Aun no ha sido implementado :(" << endl;
	}

}
void Control::vealacarcel(Jugador* j)
{
	t->borraJugador(j->getPosicion(), turno);
	j->setPosicion(8);
	t->dibujaJugador(j->getPosicion(), turno);
}

bool Control::verificaColor(Jugador* j, string color)
{
	int cont = 0;
	for (int x = 0; x < 32; x++)
	{
		if (dynamic_cast<Solar*>(t->getPos(x)) && j->getNombre() == t->getPos(x)->getDueno())
		{

			Solar* temp = dynamic_cast<Solar*>(t->getPos(x));
			if (temp->getColor() == color)
				cont++;

		}
		if (cont == 3)
			return true;
	}
	return false;
}

void Control::pausa()
{
	cout << "Presione ENTER para continuar... ";
	cin.get();
}


