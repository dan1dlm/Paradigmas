#pragma once
#include "Transaccion.h"

class Compra : public Transaccion {
public:
	Compra(float monto, Fecha fecha, Obra* obra) : Transaccion(monto, fecha, obra) {}
public:
	float Ganancia() { return obraAsociada->GetMontoSugerido() - monto; }
	std::string GetTipo() { return "Compra"; }
};