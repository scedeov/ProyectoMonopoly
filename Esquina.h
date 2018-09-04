#ifndef ESQUINA
#define ESQUINA

#include "Casilla.h"

class Esquina : public Casilla
{
private:
	bool parqueo;
	bool veCarcel;
	bool carcel;
	bool go;
public:
	Esquina(int, int);
	void setParqueo(bool);
	void setVeCarcel(bool);
	void setCarcel(bool);
	void setGo(bool);
	void limpiaAtributos();
	virtual ~Esquina();
	string mensajeEsquina();
	


};
#endif