#include "mazoCartas.h"

Mazo::Mazo()
{
	cantidad = 0;
	contador = 0;
	for (int x = 0; x < tam; x++)
	{
		mazo[x] = "Sin definir";
	}
}

Mazo::~Mazo()
{
	cantidad = 0;
}

void Mazo::agregarCarta(string carta)
{
	if (cantidad < tam)
	{
		mazo[cantidad] = carta;
		cantidad++;
	}
}

void Mazo::leeCartaArchivo() //incompleto
{
	fstream txt;
	txt.open("cartas.txt", ios::in||ios::app);
	string carta;
	if (!txt)
		cout << "Error abriendo el archivo" << endl;
	else
	{
		txt.seekg(0);
		while (!txt.eof())
		{
			txt.read((char*)&carta, sizeof(string));
			agregarCarta(carta);
		}
		txt.close();
	}
}

void Mazo::muestraCarta()  // tiene que poner la carta mostrada al fondo. //incompleto
{
	cout << mazo[contador];
	string temp = mazo[contador];
	for (int y = 0; y < tam; y++)
	{
		if (y == tam - 1)
			mazo[y] = temp;
		else
		{
			mazo[y] = mazo[y + 1];
		}
	}

	contador++;

	if (contador > 15)
		contador = 0;
}
