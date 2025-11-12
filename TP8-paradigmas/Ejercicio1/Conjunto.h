//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// Conjunto.h
//============================================================================

#include <iostream>


using namespace std;
typedef int item;



class Conjunto{
	static const int MAX = 10;
	static item *indefinido;
	int indice;
	item elementos[MAX];

 public:
	Conjunto();
	void agregar(item X);
	int cantidad();

	bool esConjuntoVacio();
	void escribir();

	friend class IteradorDeConjunto;

};


