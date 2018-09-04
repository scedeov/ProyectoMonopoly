#include "Impuestos.h"

Impuestos::Impuestos(int cas)
{
	setNumeroCasilla(cas);
	tipoPropiedad = nombrePropiedad = "Impuestos";
	setSimboloCasilla("IMP");

	switch (cas)
	{
	case 9: impuesto = 190; break;
	case 23: impuesto = 160; break;
	default: impuesto = 0; break;
	}

}

Impuestos::~Impuestos()
{
}

int Impuestos::getImpuesto()
{
	return impuesto;
}

void Impuestos::setImpuesto(int nImpuesto)
{
	impuesto = nImpuesto;
}

string Impuestos::mensajeImpuestos()
{
	stringstream s;
	s << tipoPropiedad << endl;
	s << "El banco necesita dinero para no quedar en la quiebra." << endl;
	s << "Se te cobra: " << impuesto << endl;

	return s.str();
}
