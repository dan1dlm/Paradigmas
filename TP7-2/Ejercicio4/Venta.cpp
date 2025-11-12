#include "Venta.h"

int Venta :: autoincremento = 1;

Venta :: Venta(Fecha& fechaVenta){
    this->codigoVenta = ++autoincremento;
    this->fechaVenta = fechaVenta;
}

Fecha Venta :: getFecha(){return this->fechaVenta;}

void Venta :: agregar(Producto* producto, int cantidad){
    item *nuevoItem = new item(producto, cantidad);
    this->items.push_back(nuevoItem);
}

double Venta :: calcularMontoTotal(){
    double total = 0;
    for(item* i : items){
        total += i->calcularTotal();
    }

    return total;
}

void Venta :: listarInformacion(){
    cout<<"----------------------------------"<<endl;
    cout<<"Informacion de Venta: "<<endl;
    cout<<"Codigo de venta: "<<this->codigoVenta<<endl;
    cout<<"Fecha de la venta: "<<this->fechaVenta<<endl;
    for(item* i : items){
        i->getProducto()->listarInformacion();
        cout<<"Cantidad: "<<i->getCantidad()<<endl;
    }
    cout<<"MONTO TOTAL: "<<calcularMontoTotal()<<endl;
}



