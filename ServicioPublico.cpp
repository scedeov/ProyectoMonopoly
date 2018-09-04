#include "ServicioPublico.h"

Servicio_Publico::Servicio_Publico(int num, int cas)
{
	setNumeroCasilla(cas);
	agua = false;
	luz = false;

	switch (num)
	{
	case 1:
	{
		agua = true;
		setPrecioCompra(230);
		setNombrePropiedad("Instituto de Acueductos y Alcantarillados");
		setSimboloCasilla("AYA");
		break;
	}
	case 2:
	{
		luz = true;
		setPrecioCompra(250);
		setNombrePropiedad("Instituto Costarricense de Electricidad (ICE)");
		setSimboloCasilla("ICE");
		break;
	}
	default:
		setNombrePropiedad("Sin definir bro");
		break;
	}

	tipoPropiedad = "Servicio Publico";
}

Servicio_Publico::~Servicio_Publico()
{
}
