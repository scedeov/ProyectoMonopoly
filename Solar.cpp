#include "Solar.h"

Solar::Solar(int num, int cas)
{
	setNumeroCasilla(cas);
	if (num >= 1 && num <= 3)
	{
		color = "Azul";

		if (num == 1)
		{
			setNombrePropiedad("Avenida Lopez");
			setSimboloCasilla("AVL");
			setPrecioCompra(230);
		}
		if (num == 2)
		{
			setNombrePropiedad("Avenida Toros");
			setSimboloCasilla("AVT");
			setPrecioCompra(100);
		}
		if (num == 3)
		{
			setNombrePropiedad("Avenida Camaano");
			setSimboloCasilla("AVC");
			setPrecioCompra(540);
		}
	}

	if (num > 3 && num <= 6)
	{
		color = "Amarillo";

		if (num == 4)
		{
			setNombrePropiedad("Zona Franca");
			setSimboloCasilla("ZNF");
			setPrecioCompra(200);
		}
		if (num == 5)
		{
			setNombrePropiedad("Finca Miramar");
			setSimboloCasilla("FKM");
			setPrecioCompra(300);
		}
		if (num == 6)
		{
			setNombrePropiedad("Mirador");
			setSimboloCasilla("MDR");
			setPrecioCompra(300);
		}
	}

	if (num > 6 && num <= 9)
	{
		color = "Rojo";

		if (num == 7)
		{
			setNombrePropiedad("Avenida Perez");
			setSimboloCasilla("AVP");
			setPrecioCompra(200);
		}
		if (num == 8)
		{
			setNombrePropiedad("Avenida Segunda");
			setSimboloCasilla("AV2");
			setPrecioCompra(250);
		}
		if (num == 9)
		{
			setNombrePropiedad("Heredia Media Calle");
			setSimboloCasilla("HMC");
			setPrecioCompra(450);
		}
	}

	if (num > 9 && num <= 12)
	{
		color = "Verde";

		if (num == 10)
		{
			setNombrePropiedad("Laguinilla Escuela");
			setSimboloCasilla("LAE");
			setPrecioCompra(400);
		}
		if (num == 11)
		{
			setNombrePropiedad("Calle Los Perdidos");
			setSimboloCasilla("CLP");
			setPrecioCompra(230);
		}
		if (num == 12)
		{
			setNombrePropiedad("Calle Soledad");
			setSimboloCasilla("CSO");
			setPrecioCompra(280);
		}
	}

	tipoPropiedad = "Solar";

}

string Solar::getColor()
{
	return color;
}

Solar::~Solar()
{
}
