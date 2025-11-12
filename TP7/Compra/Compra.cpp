#include "Compra.h"

// FUNCIONES CLASE LLAMADA

Compra ::Compra()
{
    this->codigo = 0;
}

Compra ::Compra(int codigo, Fecha &fechaCompra, vector<Producto*> productosComprados) : fechaCompra(fechaCompra)
{
    this->codigo = codigo;
    this->productos = productosComprados;
}



double Compra :: totalProductos(){
    double total = 0;
    for(Producto* p : productos){
        total += p->getPrecio();
    }

    return total;
}

double Compra :: calcularMonto(){
    return 0;
}

void Compra :: escribirInfo(){}

Fecha Compra ::getFecha() { return this->fechaCompra; }

// FUNCIONES clase CompraDeContado
double CompraDeContado ::DESCUENTO = 0.15;

CompraDeContado ::CompraDeContado(int codigo, Fecha &fechaCompra, vector<Producto*> productos) : Compra(codigo, fechaCompra, productos) {}

double CompraDeContado ::calcularMonto()
{
    double monto;
    monto = this->totalProductos();
    return monto * (1 - DESCUENTO);
}

 

void CompraDeContado :: escribirInfo(){
    cout<<"\nCompra de CONTADO"<<endl;
    for(Producto* p : this->productos){
        cout<<"Codigo: "<<p->getCodigo()<<endl;
        cout<<"Descripcion: "<<p->getDescripcion()<<endl;
        cout<<"Precio: "<<p->getPrecio()<<endl;
    }
}

// FUNCIONES clase CompraEnCuotas
double CompraEnCuotas ::INTERES3CUOTAS = 0.10;

double CompraEnCuotas ::INTERES6CUOTAS = 0.20;

CompraEnCuotas ::CompraEnCuotas(int codigo, Fecha &fechaCompra, int cantidadCuotas, vector<Producto*> productos) : Compra(codigo, fechaCompra, productos)
{
    this->cantidadCoutas = cantidadCoutas;
}

double CompraEnCuotas ::calcularMonto()
{
    double monto;
    monto = this->totalProductos();

    if (this->cantidadCoutas == 3)
        return monto * (1 + INTERES3CUOTAS);
    else
        return monto * (1 + INTERES6CUOTAS);

    return monto;
}

void CompraEnCuotas :: escribirInfo(){
    cout<<"\nCompra en COUTAS:"<<endl;
    for(Producto* p : this->productos){
        cout<<"Codigo: "<<p->getCodigo()<<endl;
        cout<<"Descripcion: "<<p->getDescripcion()<<endl;
        cout<<"Precio: "<<p->getPrecio()<<endl;
    }
}

