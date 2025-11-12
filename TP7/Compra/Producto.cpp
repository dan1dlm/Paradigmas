#include "Producto.h"

Producto :: Producto(){this->codigo = 0;this->descripcion = "";this->precio = 0.0;}

Producto :: Producto(int codigo, string descripcion, double precio){
    this->codigo = codigo;
    this->descripcion = descripcion;
    this->precio = precio;
}

int Producto :: getCodigo(){return this->codigo;}
double Producto :: getPrecio(){return this->precio;}
string Producto :: getDescripcion(){return this->descripcion;}