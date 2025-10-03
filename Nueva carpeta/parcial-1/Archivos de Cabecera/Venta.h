#pragma once
#include "Transaccion.h"

class Venta : public Transaccion {
public:
	Venta(float monto, Fecha fecha, Obra* obra) : Transaccion(monto, fecha, obra) {}
public:
	float Ganancia() { return monto - obraAsociada->GetMontoSugerido(); }
	std::string GetTipo() { return "Venta"; }
};