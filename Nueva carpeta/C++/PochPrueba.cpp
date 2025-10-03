#include "PochArreglo.h"
#include "PochIterador.h"

void escribirPositivos(Arreglo& arreglo);

int main(void) {
	Arreglo arreglo(5, -999);
	arreglo.insertarElemento(1, 0); //Elemento, Posicion
	arreglo.insertarElemento(3, 1); //Elemento, Posicion
	arreglo.insertarElemento(-2, 2); //Elemento, Posicion
	arreglo.insertarElemento(5, 3); //Elemento, Posicion
	arreglo.insertarElemento(2, 4); //Elemento, Posicion
	arreglo.escribir();
	std::cout << "Elementos positivos del arreglo en posiciones pares: " << std::endl;
	escribirPositivos(arreglo);
	return 0;
}

void escribirPositivos(Arreglo& arreglo) {
	IteradorPar iterador(arreglo);
	while (!iterador.EsVacio()) {
		if (iterador.Actual() > 0)
			std::cout << iterador.Actual() << std::endl;
		iterador.Anterior();
	}
}