//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// Pelicula.h
//============================================================================

#ifndef PELICULA_H_
#define PELICULA_H_

#include <iostream>
using namespace std;

enum produccion {N, I};

class Pelicula {

	static int autonumerico;
	int codigo;
	string titulo;
	string director;
	bool estreno;
	float precioBase;
	enum produccion tipoPelicula;

public:
	//Constructor por defecto
	Pelicula();
	//Constructor con parametros
	Pelicula(string, string, bool, float, enum produccion);
	//Constructor copia
	Pelicula(const Pelicula&);

	static int getAutonumerico();
	void setDirector(string);
	void listarInformacion();
	float calcularCosto();

	//Destructor
	~Pelicula();

};

#endif /* PELICULA_H_ */
