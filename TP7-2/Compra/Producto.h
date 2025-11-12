
// #ifndef PRODUCTO_H_
// #define PRODUCTO_H_
#include <iostream>
using namespace std;

class Producto{
    int codigo;
    string descripcion;
    double precio;

    public:
    Producto();
    Producto(int, string, double);
    int getCodigo();
    double getPrecio();
    string getDescripcion();
};



// #endif 