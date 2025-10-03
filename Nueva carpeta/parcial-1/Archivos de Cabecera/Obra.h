#pragma once
#include <iostream>

class Obra {
	static int autonumerico;
	int codigo;
	std::string nombreObra;
	std::string nombreCreador;
	float montoSugerido;
public:
	Obra(std::string nombreObra, std::string nombreCreador, float montoSugerido) :
		codigo(autonumerico), nombreObra(nombreObra), nombreCreador(nombreCreador), montoSugerido(montoSugerido) {
		autonumerico++;
	}
public:
	float GetMontoSugerido() { return montoSugerido; }
	void ListInfo();
};

int Obra::autonumerico = 1;

void Obra::ListInfo() {
	std::cout << "Codigo: " << codigo << std::endl;
	std::cout << "Nombre de la obra: " << nombreObra << std::endl;
	std::cout << "Nombre del creador: " << nombreCreador << std::endl;
	std::cout << "Monto sugerido: " << montoSugerido << std::endl;
	std::cout << "----------" << std::endl;
}