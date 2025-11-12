// #ifndef TIENDA_H_
// #define TIENDA_H_
#include "Compra.h"

enum tipoCompra{Cuotas, Contado};

class Tienda{
    string nombre;
    string direccion;
    vector<Compra*> compras;
    Compra* crearCompraSegunTipo(int codigo, Fecha& fechaCompra, vector<Producto*>, int cantidadCoutas);

    public:
    Tienda() : nombre(""), direccion(""){};
    Tienda(string, string);
    ~Tienda();

    
    void generarCompra(int codigo, Fecha& fechaCompra, vector<Producto*>, int cantidadCoutas = 0);
    void resumenMesCompra(short, short);
};

// #endif 