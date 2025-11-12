#include "Venta.h"

class Almacen{
    vector<Venta*> ventas;

    public:
    Almacen(){};
    void crearVenta(vector<Producto*>, vector<int>, Fecha& fechaVenta);
    double calcularMontoTotalVentas(short mes, short anio);
    void listarInformacion();
};