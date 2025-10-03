/*
 * PARADIGMAS DE PROGRAMACION - 2do PARCIAL 2023 - 15/12/23
 *
 * APELLIDO Y NOMBRE: POCH IÑAKI
 *
 * Arreglo.h
 *
 */

#ifndef ARREGLO_H_
#define ARREGLO_H_

#include <iostream>
using namespace std;

class IteradorPar;

class Arreglo {
	const int indefinido;
	int* arreglo;
	int MAX;
	int* reservarMemoria(unsigned int tama);
public:
	Arreglo(unsigned int dim, int indef);
	bool insertarElemento(int item, int posicion);
	int  elemento(int posicion);
	bool eliminarElemento(int posicion);
	void escribir();
	int capacidad();
	bool pertenece(int X);
	~Arreglo();

	friend class IteradorPar;
};

int* Arreglo::reservarMemoria(unsigned int tama) {
	int* reserva = new int[tama];
	if (reserva == NULL) {
		cout << "Problema: no se pudo realizar la reserva";
	}
	return reserva;
}

Arreglo::Arreglo(unsigned int dim, int indef) :indefinido(indef) {
	this->MAX = dim;
	this->arreglo = reservarMemoria(this->MAX);
	if (this->arreglo == NULL)
		this->MAX = 0;
	else
		for (int i = 0; i < this->MAX; i++)
			this->arreglo[i] = this->indefinido;
}


bool Arreglo::insertarElemento(int item, int posicion) {
	bool resultado = false;
	if (0 <= posicion && posicion < this->MAX) {
		this->arreglo[posicion] = item;
		resultado = true;
	}
	return resultado;
}

int  Arreglo::elemento(int posicion) {
	if (0 <= posicion && posicion < this->MAX)
		return this->arreglo[posicion];
	else
		return this->indefinido;
}

bool Arreglo::eliminarElemento(int posicion) {
	bool resultado = false;
	if (0 <= posicion && posicion < this->MAX) {
		this->arreglo[posicion] = this->indefinido;
		resultado = true;
	}
	return resultado;
}

void Arreglo::escribir() {
	cout << endl << " CONTENEDOR INT:" << endl;
	for (int i = 0; i < this->MAX; i++) {
		cout << "     " << this->arreglo[i] << endl;
	}
}

int Arreglo::capacidad() {
	return this->MAX;
}

bool Arreglo::pertenece(int X) {
	int k = 0;
	while (k < this->MAX && this->arreglo[k] != X) {
		k++;
	}
	return k < this->MAX;
}

Arreglo::~Arreglo() {
	this->MAX = 0;
	delete[] this->arreglo;
};


#endif /* ARREGLO_H_ */
