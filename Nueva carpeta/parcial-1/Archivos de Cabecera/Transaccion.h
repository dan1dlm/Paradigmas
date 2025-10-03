#pragma once
#include "Fecha.h"
#include "Obra.h"

class Transaccion {
	static int autonumerico;
protected:
	int codigo;
	float monto;
	Fecha fecha;
	Obra* obraAsociada;
public:
	Transaccion(float monto, Fecha fecha, Obra* obra) : codigo(autonumerico), monto(monto), fecha(fecha), obraAsociada(obra) {
		autonumerico++;
	}
public:
	Fecha GetFecha() { return fecha; }
public:
	virtual float Ganancia() = 0;
	virtual std::string GetTipo() = 0;
	void ListInfo();
};

int Transaccion::autonumerico = 1;

void Transaccion::ListInfo() {
	std::cout << "Codigo: " << codigo << std::endl;
	std::cout << "Tipo: " << GetTipo() << std::endl;
	std::cout << "---OBRA---: " << std::endl;
	obraAsociada->ListInfo();
	std::cout << "Monto: " << monto << std::endl;
	std::cout << "Ganancia: " << Ganancia() << std::endl;
	std::cout << "Fecha: " << fecha.toString() << std::endl;
	std::cout << std::endl << std::endl;
}