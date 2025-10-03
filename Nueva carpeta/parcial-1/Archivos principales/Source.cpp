
#include "Aplicacion.h"

int main(void) {
	Obra* obra1 = new Obra("Obra 1", "Juan", 50000);
	Obra* obra2 = new Obra("Obra 2", "Pedro", 70000);
	Obra* obra3 = new Obra("Obra 3", "Leonardo", 80000);
	Obra* obra4 = new Obra("Obra 4", "Alejandro", 40000);
	Aplicacion aplicacion;
	aplicacion.CrearCompra(40000, Fecha(20, 9, 2020), obra1);
	aplicacion.CrearCompra(65000, Fecha(15, 11, 2022), obra2);
	aplicacion.CrearVenta(75000, Fecha(10, 10, 2023), obra3);
	aplicacion.CrearVenta(60000, Fecha(13, 2, 2023), obra4);
	std::cout << "---TRANSACCIONES---" << std::endl;
	aplicacion.Resumen(Fecha(1, 1, 2019), Fecha(17, 10, 2023));
	std::cout << "-------------------" << std::endl;
	std::vector<Transaccion*> perdidas = aplicacion.ListarPerdidas();
	std::cout << std::endl << "---PERDIDAS---" << std::endl;
	for (Transaccion* transaccion : perdidas)
		transaccion->ListInfo();
	std::cout << std::endl << "---MAYOR GANANCIA---" << std::endl;
	aplicacion.MayorGanancia()->ListInfo();
	delete obra1;
	delete obra2;
	delete obra3;
	delete obra4;
	return 0;
}