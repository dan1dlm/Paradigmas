#include "Producto.h"

class item{
    int cantidad;
    double precioUnitario;
    Producto* producto;

    public:
    item(Producto*, int);
    double calcularTotal();
    Producto* getProducto();
    int getCantidad();
};