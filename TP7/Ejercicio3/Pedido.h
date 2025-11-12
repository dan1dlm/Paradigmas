#include <iostream>
#include "Producto.h"
#include "Fecha.h"

enum formaPago {Debito, Credito};

class Pedido{
    static int autonumerico;
    int codigoPedido;
    string idCliente;
    Producto* productoPedido;
    formaPago formaDePago;
    Fecha fechaPedido;
    Fecha fechaEntrega;
    bool entregado;
    static const double ENVIO = 3000;

    public:
    Pedido();
    Pedido(string, Producto*, formaPago, Fecha);
    Pedido(Pedido&);
    void escribirInfo();
    void entregarPedido(Fecha);
    Fecha getFechaPedido();
    int getCodigo();
    double calcularCosto();
};