#include "Pedido.h"

int Pedido :: autonumerico = 0;

Pedido :: Pedido(){
    this->codigoPedido = ++(this->autonumerico);
    this->idCliente = "";
    this->productoPedido = NULL;
    this->formaDePago = Debito;
    this->entregado = false;
}

Pedido :: Pedido(string idCliente, Producto* productoPedido, formaPago formaDePago, Fecha fechaPedido){
    this->codigoPedido = ++(this->autonumerico);
    this->idCliente = idCliente;
    this->productoPedido = productoPedido;
    this->formaDePago = formaDePago;
    this->fechaPedido = fechaPedido;
    this->entregado = false;
}

Pedido :: Pedido(Pedido& P){
    this->codigoPedido = P.codigoPedido;
    this->idCliente = P.idCliente;
    this->productoPedido = P.productoPedido;
    this->formaDePago = P.formaDePago;
    this->fechaPedido = P.fechaPedido;
    this->fechaEntrega = P.fechaEntrega;
    this->entregado = P.entregado;
}

void Pedido :: escribirInfo(){
    cout<<"Hola"<<endl;
}

void Pedido :: entregarPedido(Fecha f){
    this->fechaEntrega = f;
    this->entregado = true;
}

Fecha Pedido :: getFechaPedido(){return this->fechaPedido;}

int Pedido :: getCodigo(){return this->codigoPedido;}

double Pedido :: calcularCosto()
{
    double precio = productoPedido->calcularPrecioDeVenta();
    if(formaDePago == Credito){
        precio*=1.15;
    }

    return (precio + this->ENVIO);
}




