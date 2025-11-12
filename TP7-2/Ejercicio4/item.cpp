#include "item.h"

item :: item(Producto* producto, int cantidad){
    this->producto = producto;
    this->cantidad = cantidad;
    this->precioUnitario = producto->calcularPrecioDeVenta();
}

double item :: calcularTotal(){
    return (this->precioUnitario * this->cantidad);
}

Producto* item :: getProducto(){return this->producto;}

int item :: getCantidad(){return this->cantidad;}

