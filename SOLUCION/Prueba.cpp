//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// Prueba.cpp
//============================================================================

#include <iostream>
#include "Pelicula.h"
using namespace std;

int main() {
	cout << "Valor inicial de la variable de clase autonumerico (0): " <<Pelicula::getAutonumerico()<<endl<<endl;

	//Se construye la pelicula P invocando al constructor por defecto
	Pelicula P;
	P.listarInformacion();
	P.setDirector("Nuevo Director");
	P.listarInformacion();

	//Se construye la pelicula Q invocando al constructor con parametros
	Pelicula Q("El Padrino", "Francis Ford Coppola", false, 11000, I);
	Q.listarInformacion();
	cout<<"Costo de la Pelicula: $"<<Q.calcularCosto()<<endl<<endl;

	//Se construye la pelicula R invocando al constructor copia
	Pelicula R(Q);
	//Se modifica el director de la pelicula R, copia de Q
	R.setDirector("Coppola");

	//Se lista la información de la pelicula Q y R
	R.listarInformacion();
	Q.listarInformacion();



	return 0;
}
