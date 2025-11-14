#include <iostream>

#include "Inmobiliaria.h"
using namespace std;

int main() {

/* ------------------------------------------------------------------------------------------------------
 *	AGREGUE EL CODIGO DE PRUEBA QUE NECESITE PARA AVANZAR
 *	DURANTE EL DESARROLLO
 *	------------------------------------------------------------------------------------------------------
*/

// ----- ALQUILER #1 -----

	Fecha fecha1(8, 04, 2023);
	Fecha fecha2(8, 12, 2023);

	int idCliente1 = 111;

// ----- ALQUILER #2 -----

	Fecha fecha3(16, 1, 2024);
	Fecha fecha4(21, 4, 2024);

	int idCliente2 = 222;

// ----- ALQUILER #3 -----

	Fecha fecha5;
	Fecha fecha6;


	// CREAR UNA INMOBILIARIA CON LOS SIGUIENTES DATOS:
	// - CODIGO AFIP = 777
	// - NOMBRE EMPRESA = Hogar dulce hogar
	// - CUIT = 12-34567890 - 1

	Inmobiliaria Inmobiliaria(777, "Hogar dulce hogar", "12-32567890-1");


	// DESDE LA INMOBILIARIA
	// - ALQUILAR UN INMUEBLE DESDE EL 08/04/2023 HASTA EL 08/12/2023 PARA UN CLIENTE CON ID 111



	// - ALQUILAR UN INMUEBLE DESDE EL 16/01/2024 HASTA EL 21/04/2024 PARA UN CLIENTE CON ID 222



	// - ALQUILAR UN INMUEBLE DESDE EL 24/05/2024 HASTA EL 24/05/2025 PARA UN CLIENTE CON ID 333



	// OBTENER UN RESUMEN DE LA INMOBILIARIA


	return 0;

}

