#include "Pedido.h"
#include "vector"

class Sistema{
    vector<Pedido*> pedidos;
    vector<Producto*> productos;
    Pedido* obtenerPedido(int);
    Producto* obtenerProducto(int);

    public:
    Sistema();
    void agregarProducto(Producto*);
    void registrarPedido(Fecha, string, int, formaPago);
    void cargarFechaEntrega(int, Fecha);
    void listarPedidos(Fecha);
};