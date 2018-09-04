#ifndef IMPUESTOS
#define IMPUESTOS

#include "Casilla.h"

class Impuestos : public Casilla
{
private:
	int impuesto;
public:
	Impuestos(int);
	virtual ~Impuestos();

	int getImpuesto();
	void setImpuesto(int);

	string mensajeImpuestos();


};
#endif
