//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// ioVector.h
//============================================================================

#ifndef IOVECTOR_H_
#define IOVECTOR_H_

#include <iostream>
#include "Vector.h"

using namespace std;

// Sobrecarga de los operadores de inserción ( << ) y extraccion ( >> ) de flujo
// como usuarios del ADT VECTOR(ITEM)
ostream& operator<<(ostream& salida, Vector1 &V){
	for(unsigned int i=1;i<=V.capacidad();i++)
		salida<<V.elemento(i)<<" ";
	return salida;
}

istream& operator>>(istream& entrada, Vector1 &V){
	for(unsigned int i=1;i<=V.capacidad();i++)
		entrada>>V.elemento(i);
	return entrada;
}

#endif /* IOVECTOR_H_ */
