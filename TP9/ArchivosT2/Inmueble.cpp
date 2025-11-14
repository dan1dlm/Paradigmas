#include <sstream>
#include "Inmueble.h"

Inmueble::Inmueble(int cod, string desc, string dir, double costo){
	this->codigo=cod;
	this->descripcion=desc;
	this->direccion = dir;
	this->costoMensual=costo;
}

int Inmueble::getCodigo(){
	return this->codigo;
}

double Inmueble::getCostoMensual(){
	return this->costoMensual;
}

Inmueble::~Inmueble(){}


