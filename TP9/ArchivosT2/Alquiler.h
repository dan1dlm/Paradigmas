#ifndef ALQUILER_H_
#define ALQUILER_H_

#include <iostream>
#include "Inmueble.h"
#include "Fecha.h"

using namespace std;

class Alquiler {
	protected:
	static int autonumerico;
	int codigo;
	int idCliente;
	Fecha fechaInicio;
	Fecha fechaFin;
	Inmueble* inmueble;
	//COMPLETAR ATRIBUTOS SI ES NECESARIO

	int getCantidadMeses();

public:
	Alquiler(int id, Inmueble* inmueble, Fecha& fechaI, Fecha& fechaF);
	virtual double calcularCosto() = 0;
	virtual void listarInfo();
	virtual ~Alquiler();
};


class AlquilerPermanente : public Alquiler{
	public:
	AlquilerPermanente(int, Inmueble*, Fecha&, Fecha&);
	double calcularCosto();
};

class AlquilerTemporal : public Alquiler{
	static const double INTERES_MENSUAL; //0.015

	public:
	AlquilerTemporal(int, Inmueble*, Fecha&, Fecha&);
	double calcularCosto();
	void listarInfo();
};





#endif /* ALQUILER_H_ */
