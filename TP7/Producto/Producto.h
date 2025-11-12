//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// Producto.h
//============================================================================

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include <iostream>
using namespace std;

class Producto{
	int codigo;
	string descripcion;
	double precio;
	static double const INCREMENTO = 0.10; //Al ser un atributo estático y constante esta permitida
										   //la inicializacion en la declaracion de la clase
public:
	Producto(int, string, double);
	void listarInformacion();
	double calcularPrecioDeVenta();
	~Producto();
};

#endif /* PRODUCTO_H_ */
