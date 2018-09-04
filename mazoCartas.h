#ifndef MAZO
#define MAZO



#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int tam = 16;

class Mazo
{
private:
	string mazo[tam];
	int cantidad;
	int contador;

public:
	Mazo();
	virtual ~Mazo();
	void agregarCarta(string carta);
	void leeCartaArchivo();
	void muestraCarta();
};
#endif
