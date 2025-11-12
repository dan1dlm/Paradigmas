#include "Sistema.h"

Pedido* Sistema :: obtenerPedido(int codPedido){
    for(Pedido* p : pedidos){
        if(p->getCodigo() == codPedido)
            return p;
    }

    return NULL;
}

Producto* Sistema :: obtenerProducto(int codProducto){
    for(Producto* p: productos){
        if(p->getCodigo() == codProducto)
            return p;
    }

    return NULL;
}

void Sistema :: agregarProducto(Producto* P){
    this->productos.push_back(P);
}

void Sistema :: registrarPedido(Fecha fechaPedido, string idCliente, int codigoProducto, formaPago formaDePago){
    Producto* productoEncontrado = obtenerProducto(codigoProducto);
    if(productoEncontrado){
        Pedido* nuevoPedido = new Pedido(idCliente, productoEncontrado, formaDePago, fechaPedido);
        pedidos.push_back(nuevoPedido);
    }
}

void Sistema :: cargarFechaEntrega(int codPedido, Fecha f){
    Pedido* pedidoE = obtenerPedido(codPedido);
    if(pedidoE){
        pedidoE->entregarPedido(f);
    }
}

void Sistema :: listarPedidos(Fecha f){
    for(Pedido* p : pedidos){
        if(p->getFechaPedido() == f){
            p->escribirInfo();
        }
    }
}
