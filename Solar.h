#ifndef SOLAR
#define SOLAR

#include "Casilla.h"

class Solar : public Casilla
{
private:
	string color;
public:
	Solar(int, int); // talvez se pueda simplificar a solo un int
	string getColor();
	virtual ~Solar();


};
#endif
