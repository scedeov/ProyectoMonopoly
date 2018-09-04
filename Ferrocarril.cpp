#include "Ferrocarril.h"

Ferrocarril::Ferrocarril(int cas)
{
	setNumeroCasilla(cas);
	tipoPropiedad = nombrePropiedad = "Ferrocarril";
	setSimboloCasilla("TRN");
	setPrecioCompra(200);
}

Ferrocarril::~Ferrocarril()
{
}
