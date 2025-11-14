#ifndef INMOBILIARIA_H_
#define INMOBILIARIA_H_

#include <iostream>
#include <vector>
#include "Alquiler.h"

class Inmobiliaria {
	static const double COMISION; // 0.1
	int codigoAFIP;
	string nombreEmpresa;
	string CUIT;
	vector<Alquiler*> alquileres;
	//COMPLETAR ATRIBUTOS SI ES NECESARIO

public:
	Inmobiliaria(int cod, string nom, string cuit);
	void alquilar(int idCliente, Inmueble* inmueble, Fecha& fechaI, Fecha& fechaF);  //dependiendo de la cantidad de meses, va a crear un alquiler temporal o permanente, realizo el swtich
	void resumen();
	virtual ~Inmobiliaria();
};

#endif /* INMOBILIARIA_H_ */
