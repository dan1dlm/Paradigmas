#include "Tienda.h"

Tienda :: Tienda(string nombre, string direccion){
    this->nombre = nombre;
    this->direccion = direccion;
}

void Tienda :: generarCompra(int codigo, Fecha& fechaCompra, vector<Producto*> productos, int cantidadCoutas){
    Compra* nuevaCompra = crearCompraSegunTipo(codigo, fechaCompra, productos, cantidadCoutas);
    compras.push_back(nuevaCompra);
}

Compra* Tienda :: crearCompraSegunTipo(int codigo, Fecha& fechaCompra, vector<Producto*> productos, int cantidadCoutas){
    Compra* nuevaCompra;
    switch(cantidadCoutas){
        case 0 : nuevaCompra = new CompraDeContado(codigo, fechaCompra, productos); break;
        default : nuevaCompra = new CompraEnCuotas(codigo, fechaCompra, cantidadCoutas, productos); break;
    }

    return nuevaCompra;
}

void Tienda :: resumenMesCompra(short mes, short anio){
    for(Compra* c : compras ){
        if(c->getFecha().getAnio() == anio && c->getFecha().getMes() == mes){
            c->escribirInfo();
        }
    }
}

Tienda :: ~Tienda(){
    for(Compra* c : compras){
        delete c;
    }

    compras.clear();
}