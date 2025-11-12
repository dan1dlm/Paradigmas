#include "item.h"
#include "vector"

class Venta{
    static int autoincremento;
    int codigoVenta;
    Fecha fechaVenta;
    vector<item*> items;

    public:
    Venta(Fecha& fechaVenta);
    Fecha getFecha();
    void listarInformacion();
    void agregar(Producto*, int cantidad);
    double calcularMontoTotal();
    ~Venta();
};