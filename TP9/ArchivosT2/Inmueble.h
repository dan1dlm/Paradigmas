#ifndef INMUEBLE_H_
#define INMUEBLE_H_

#include <iostream>
#include "Fecha.h"

using namespace std;

class Inmueble {
	int codigo;
	string descripcion;
	string direccion;
	double costoMensual;

public:
	Inmueble(int cod, string desc, string dir, double costo);
	int getCodigo();
	double getCostoMensual();
	virtual ~Inmueble();
};

#endif /* INMUEBLE_H_ */
