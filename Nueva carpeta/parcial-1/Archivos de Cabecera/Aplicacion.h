#pragma once
#include "Compra.h"
#include "Venta.h"
#include <vector>

class Aplicacion {
	std::vector<Transaccion*> transacciones;
public:
	Aplicacion() {}
	~Aplicacion() {
		for (Transaccion* transaccion : transacciones)
			delete transaccion;
	}
public:
	void CrearVenta(float monto, Fecha fecha, Obra* obra) { transacciones.push_back(new Venta(monto, fecha, obra)); }
	void CrearCompra(float monto, Fecha fecha, Obra* obra) { transacciones.push_back(new Compra(monto, fecha, obra)); }
	void Resumen(Fecha fechaInicio, Fecha fechaFin);
	std::vector<Transaccion*> ListarPerdidas();
	Transaccion* MayorGanancia();
};

void Aplicacion::Resumen(Fecha fechaInicio, Fecha fechaFin) {
	float total = 0;
	for (Transaccion* transaccion : transacciones) {
		Fecha fechaTransaccion = transaccion->GetFecha();
		if (fechaTransaccion < fechaFin && fechaTransaccion - fechaInicio > 0) {
			transaccion->ListInfo();
			total += transaccion->Ganancia();
		}
	}
	std::cout << "GANANCIA TOTAL: " << total << std::endl;
}

std::vector<Transaccion*> Aplicacion::ListarPerdidas() {
	std::vector<Transaccion*> perdidas;
	for (Transaccion* transaccion : transacciones) {
		if (transaccion->Ganancia() < 0)
			perdidas.push_back(transaccion);
	}
	return perdidas;
}

Transaccion* Aplicacion::MayorGanancia() {
	Transaccion* mayorGanancia = transacciones[0];
	for (Transaccion* transaccion : transacciones) {
		if (transaccion->Ganancia() > mayorGanancia->Ganancia())
			mayorGanancia = transaccion;
	}
	return mayorGanancia;
}