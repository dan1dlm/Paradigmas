#include "Inmobiliaria.h"

const double Inmobiliaria :: COMISION = 0.10;

Inmobiliaria::Inmobiliaria(int cod, string nomb, string cuit)
{
	this->codigoAFIP = cod;
	this->nombreEmpresa = nomb;
	this->CUIT = cuit;
}

void Inmobiliaria ::alquilar(int idCliente, Inmueble *inmueble, Fecha &fechaI, Fecha &fechaF)
{
	// COMPLETAR DE ACUERDO A LOS PARAMETROS RECIBIDOS

	Alquiler* nuevoAlquiler = nullptr;
	/*
	 * El tipo de alquiler se determina teniendo en cuenta la duraci�n.
	 * Un alquiler de 6 meses o mas corresponde a un alquiler Permanente,
	 * en otro caso, se considera un alquiler de tipo Temporal.
	 */
	
	int meses = fechaF - fechaI;

	if(meses <6)
		nuevoAlquiler = new AlquilerTemporal(idCliente, inmueble, fechaI, fechaF);
	else
		nuevoAlquiler = new AlquilerPermanente(idCliente, inmueble, fechaI, fechaF);

	alquileres.push_back(nuevoAlquiler);
}



void Inmobiliaria::resumen()
{
	double comision = 0;

	for(Alquiler* a : alquileres)
	{
		a->listarInfo();
		comision += COMISION*a->calcularCosto();
	}

	cout<<"\n ----->> COMISION TOTAL: "<<comision<<endl;
	// COMPLETAR DE ACUERDO AL DIAGRAMA UML
}

Inmobiliaria::~Inmobiliaria()
{
	// SI ES NECESARIO COMPLETAR EL DESTRUCTOR ()
	for(Alquiler* a : alquileres)
	{
		delete a;
	}

	alquileres.clear();
}