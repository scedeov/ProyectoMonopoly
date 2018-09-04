#include "Dado.h"

int Dado::lanzaDado() // Al lanzar el mismo metodo dos veces al mismo tiempo, genera el mismo numero aleatorio, deben ser distintos.
{
	srand((unsigned)time(0));

	int numero = rand() % 12 + 1;
	if (numero == 1)
		numero = 2;

	return numero;

}
