#pragma once
#include "PochArreglo.h"

// Se considera como posicion par aquella del arreglo desde 0 a MAX - 1, contando el 0

class IteradorPar {
	Arreglo& arreglo;
	int posicion;
public:
	IteradorPar(Arreglo& a) : arreglo(a), posicion(a.capacidad() - 1) {}
public:
	void Anterior() {
		if (posicion % 2 == 0) {
			posicion = posicion - 2; 
		}
		else {
			posicion = posicion - 1;
		}
	}
	int Actual() { return arreglo.elemento(posicion); }
	bool EsVacio() { return posicion < 0; }
};