//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// Producto.h
//============================================================================


#include "Fecha.h"

class Producto{
protected:
	int codigo;
	string descripcion;
	double precio;
	static double const INCREMENTO; //Al ser un atributo estático y constante esta permitida
										   //la inicializacion en la declaracion de la clase
public:
	Producto(int, string, double);
	//funciones virtuales
	void listarInformacion();
	virtual double calcularPrecioDeVenta() = 0;
	~Producto();
};


//CLASES DERIVADAS

class ProductoLimpieza : public Producto{
	bool esToxico;

	public: 
	ProductoLimpieza(bool, int, string, double);
	void listarInformacion();
	double calcularPrecioDeVenta();
	~ProductoLimpieza();
};

class ProductoAlimenticio : public Producto{
	Fecha fechaVencimiento;
	bool esAptoCeliaco;

	public:
	ProductoAlimenticio(Fecha&, bool, int, string, double);
	void listarInformacion();
	double calcularPrecioDeVenta();
	~ProductoAlimenticio();
	bool estaVencido();
};








