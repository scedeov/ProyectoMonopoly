#ifndef SERVICIO_PUBLICO
#define SERVICIO_PUBLICO

#include "Casilla.h"

class Servicio_Publico : public Casilla
{
private:
	bool luz;
	bool agua;
public:
	Servicio_Publico(int, int);
	virtual ~Servicio_Publico();


};
#endif