//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// Producto.cpp
//============================================================================


#include "Producto.h"

const double Producto :: INCREMENTO = 0.10;


Producto::Producto(int codigo, string descripcion, double precio): codigo(codigo), descripcion(descripcion), precio(precio){}

void Producto::listarInformacion(){
	cout<<"Producto "<<endl;
	cout<<"        Codigo: "<< this->codigo<<endl;
	cout<<"        Descripcion: "<< this->descripcion<<endl;
	cout<<"        Precio: "<< this->precio<<endl;
	cout<<"        Precio de venta: "<< this->calcularPrecioDeVenta()<<endl;
}

Producto::~Producto(){
	cout<<"Destructor Producto codigo: "<<this->codigo<<endl;
}

//FUNCIONES DERIVADAS

//ProductoLimpieza

ProductoLimpieza :: ProductoLimpieza(bool esToxico, int codigo, string descripcion, double precio) : esToxico(esToxico), Producto(codigo, descripcion, precio){}

double ProductoLimpieza :: calcularPrecioDeVenta(){
	return this->precio*(1 + this->INCREMENTO);
}

void ProductoLimpieza :: listarInformacion(){
	this->listarInformacion();
	cout<<"        EsToxico: "<<this->esToxico<<endl;
}

//ProductoAlimenticio

ProductoAlimenticio :: ProductoAlimenticio(Fecha& fecha, bool esAptoCeliaco, int codigo, string descripcion, double precio) : Producto(codigo, descripcion, precio){
	this->esAptoCeliaco = esAptoCeliaco;
	this->fechaVencimiento = fecha;
}

double ProductoAlimenticio :: calcularPrecioDeVenta(){
	return this->precio*(1 + this->INCREMENTO/2);
}

void ProductoAlimenticio :: listarInformacion(){
	this->listarInformacion();
	cout<<"        Es apto para celiacos: "<<this->esAptoCeliaco<<endl;
}

bool ProductoAlimenticio :: estaVencido(){
	return 2025 < this->fechaVencimiento.getAnio();
}










