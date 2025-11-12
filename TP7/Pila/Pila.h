/*
 * Pila.h
 */

#ifndef PILA_H_
#define PILA_H_
#include <iostream>

using namespace std;
typedef int item;
const int indefinido=-999;

class Pila{
	int tope;
	item *arreglo;
	int MAX;
	item* reservarMemoria(int tama);

 public:
	Pila(int dim = 10);

	void push(int item);
	item  top();
	void pop();
	bool esPilavacia();
	void escribir();

	~Pila();
};

#endif  //PILA_H_






