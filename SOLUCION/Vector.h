//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// Vector.h
//============================================================================

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;

typedef int item;
const item indef = 9999;

class Vector1{
	item *elementos;
	unsigned int max;

	//Operaciones Auxiliares
	bool reservarMemoria(unsigned int n);
	bool redimensionar(unsigned int n);
public:
	//Operaciones propias del ADT VECTOR(ITEM)

	//void crearVector(unsigned int n=10);
	Vector1(unsigned int n=10);
	Vector1(Vector1 &V);

	void insertar(unsigned int p, item x);
	unsigned int capacidad();
	item& elemento(unsigned int x);
	void borrar(unsigned int p);
	void borrar();

	//void destruir();
	~Vector1();

	//Sobrecarga del operador == como operacion propia del ADT VECTOR(ITEM)
	bool operator==(Vector1 &V2);
};

#endif /* VECTOR_H_ */
