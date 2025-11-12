// #ifndef COMPRA_H_
// #define COMPRA_H_

#include "Producto.h"
#include "Fecha.h"
#include <vector>

class Compra{
    protected:
    int codigo;
    Fecha fechaCompra;
    vector<Producto*> productos;

    //metodos protegidos
    double totalProductos();

    public:
    Compra();
    Compra(int, Fecha&, vector<Producto*>);
    
    //metodo que calcula el monto de la compra
    virtual double calcularMonto();
    virtual void escribirInfo();

    //Getters
    Fecha getFecha();
};



//CLASES DERIVADAS DE COMPRA
class CompraDeContado : public Compra{
    private:
    static double DESCUENTO;
    public:
    CompraDeContado(int codigo, Fecha &fechaCompra, vector<Producto*>);
    
    double calcularMonto();
    void escribirInfo();
};

class CompraEnCuotas : public Compra{
    private:
    static double INTERES3CUOTAS;
    static double INTERES6CUOTAS;
    int cantidadCoutas;

    public:
    CompraEnCuotas(int codigo, Fecha &fechaCompra, int cantidadCuotas, vector<Producto*>);

    double calcularMonto();
    void escribirInfo();
};

// #endif COMPRA_H_