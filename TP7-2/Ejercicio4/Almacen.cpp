#include "Almacen.h"


void Almacen :: crearVenta(vector<Producto*> productos, vector<int> cantidades, Fecha& fechaVenta){
   
    int cant = productos.size();
    Venta* nuevaVenta = new Venta(fechaVenta);
    for(int i=0; i < cant; i++){
        nuevaVenta->agregar(productos[i], cantidades[i]);   
    }

    this->ventas.push_back(nuevaVenta);
}

double Almacen :: calcularMontoTotalVentas(short mes, short anio){
    double total=0;
    for(Venta* v : ventas){
        if(v->getFecha().getMes() == mes && v->getFecha().getAnio() == anio){
            total += v->calcularMontoTotal();
        }
    }

    return total;
}

void Almacen :: listarInformacion(){
    for(Venta* v : ventas){
        v->listarInformacion();
    }
}