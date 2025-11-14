#include <sstream>

#include "Alquiler.h"
int Alquiler::autonumerico = 0;

int Alquiler::getCantidadMeses()
{

	// COMPLETAR CON EL CODIGO CORRESPONDIENTE.
	// TENGA EN CUENTA LAS OPERACIONES IMPLEMENTADAS EN LA CLASE FECHA DADA

	return 0;
}

Alquiler::Alquiler(int idCliente, Inmueble *inmueble, Fecha &fechaI, Fecha &fechaF)
{

	this->codigo = ++autonumerico;
	this->idCliente = idCliente;
	this->fechaInicio = fechaI;
	this->fechaFin = fechaF;
	// COMPLETAR INICIALIZACION SI ES NECESARIO
	this->inmueble = inmueble; // ver si es solo eso
}

int Alquiler :: getCantidadMeses()
{
	return (this->fechaFin - this->fechaInicio);
}

// BORRE LA IMPLEMENTACION DE CALCULAR COSTO DE LA CLASE BASE

void Alquiler::listarInfo()
{

	cout << "Codigo de alquiler: " << this->codigo << endl;
	cout << "Id Cliente: " << this->idCliente << endl;
	cout << "Fecha de inicio" << this->fechaInicio << endl;
	cout << "Fecha de fin" << this->fechaFin << endl;
}

Alquiler::~Alquiler()
{
	// SI ES NECESARIO COMPLETAR EL DESTRUCTOR
	delete this->inmueble;
}

// implementacion de las clases derivadas

// ALQUILER PERMANENTE:
AlquilerPermanente ::AlquilerPermanente(int id, Inmueble *inmueble, Fecha &fechaI, Fecha &fechaF) : Alquiler(id, inmueble, fechaI, fechaF) {}

double AlquilerPermanente ::calcularCosto()
{
	double monto = (this->getCantidadMeses() + 2) * this->inmueble->getCostoMensual();

	return monto;
}
// ALQUILER TEMPORAL

const double AlquilerTemporal ::INTERES_MENSUAL = 1.015;

AlquilerTemporal ::AlquilerTemporal(int id, Inmueble *inmueble, Fecha &fechaI, Fecha &fechaF) : Alquiler(id, inmueble, fechaI, fechaF) {}

double AlquilerTemporal ::calcularCosto()
{

	double montoAcc = this->inmueble->getCostoMensual();
	int cantidadMeses = this->getCantidadMeses();

	for (int i = cantidadMeses; i > 0; i--)
	{
		montoAcc = montoAcc + this->INTERES_MENSUAL * montoAcc;
	}

	return montoAcc;
}

void AlquilerTemporal ::listarInfo()
{
	this->listarInfo();
	cout<<"INTERES MENSUAL: "<<this->INTERES_MENSUAL<<endl;
}