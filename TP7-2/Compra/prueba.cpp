#include "Tienda.h"

int main(){
    Producto p1;
    Producto p2(234, "", 7234);
    vector<Producto*> productos;
    productos.push_back(&p1);
    productos.push_back(&p2);


    Tienda tienda1;
    Fecha f1(12, 3, 2025);
    tienda1.generarCompra(234, f1, productos); 
    tienda1.generarCompra(434, f1, productos, 3); 

    tienda1.resumenMesCompra(3, 2025);
}