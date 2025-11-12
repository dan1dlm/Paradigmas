#include "Almacen.h"

int main(){
    Fecha f1(12, 2, 2027);
    Fecha f2(5, 8, 2030);
    Fecha f3(6, 9, 2017);
    Producto* p1 = new ProductoAlimenticio(f1, true, 12, "Gaseosa Coca-Cola 1l retornatble", 1500);
    Producto* p2 = new ProductoLimpieza(true, 441, "Jabon En Polvo 500g", 3000);

    vector<Producto*> productos;
    productos.push_back(p1);
    productos.push_back(p2);

    vector<int> cantidades;
    cantidades.push_back(2);
    cantidades.push_back(1);

    Almacen nuevoAlmacen;
    nuevoAlmacen.crearVenta(productos, cantidades, f3);


    nuevoAlmacen.listarInformacion();
}