//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// pruebaClaseVector.cpp
//============================================================================

#include <iostream>
#include "Vector.h"
#include "ioVector.h"

using namespace std;
int contarPares(Vector1 V);

int main() {
	cout<<"####### INICIO DEL PROGRAMA DE PRUEBA  #######"<<endl<<endl;
	const unsigned int MAX = 8;

	// Creo un objeto Vector con el constructor
	Vector1 F(MAX);

	// Controlo si el vector fue creado e inicializada correctamente con el constructor
	if(F.capacidad() == MAX){
		bool correcto = true;
		for(unsigned int i=1;i<=MAX;i++){
			if(F.elemento(i) != indef){
				cout<<"El vector NO se inicializó correctamente en la posición "<<i<<endl;
				correcto=false;
			}
		}
		if(correcto)
			cout<<"El vector se inicializo correctamente"<<endl;
	}
	else
		cout<<"El vector NO se inicializo con la capacidad indicada"<<endl;

	cout<<"Contenido del vector vacio"<<endl;
	cout<<"Contenido de mi vector"<<F<<endl;

	// Ingreso 2 items al vector utilizando la función miembro insertar
	F.insertar(1, 10);
	F.insertar(3, 30);

	// Ingreso 2 items al vector utilizando la referencia al dato de la posición p que retorna la operación elemneto
	F.elemento(5) = 50;
	F.elemento(7) = 70;

	cout<<"Contenido del vector"<<endl;
	cout<<F<<endl;

	cout<<"Contenido del vector en la posición 7 (70): "<<F.elemento(7)<<endl;

	cout<<"Contenido del vector en la posición 2 (indef): "<<F.elemento(2)<<endl;

	// Pruebo leer un objeto vector utilizando el operador de extracción de flujo sobrecargado (>>)
	cout<<"Ingrese los " <<F.capacidad()<<" elementos del vector"<<endl;
	cin>>F;

	//Pruebo escribir por pantalla un objeto vector utilizando el operador de inserción de flujo (<<)
	cout<<"El vector contiene los siguientes elementos: "<<F<<endl;

	// Escribo la capacidad del vector y su contenido
	cout<<"La capacidad del vector es: "<<F.capacidad()<<endl;

	cout<<"Contenido del vector"<<endl;
	cout<<F<<endl;

	// Pruebo insertar un elemento en una posición que supera la capacidad asignada al vector, éste debería crecer dinamicamente
	F.insertar(10, 200);

	// Escribo la nueva capacidad del vector y su contenido
	cout<<"La capacidad del vector luego de redimensionar el mismo es: "<<F.capacidad()<<endl;

	cout<<"Contenido del vector luego de redimensionar el mismo"<<endl;
	cout<<F<<endl;

	// Borro el elemento que se encuentra en la posición 7
	F.borrar(7);
	cout<<"Contenido del vector en la posición 7 luego de borrar el elemento de esa posicion (indef): "<<F.elemento(7)<<endl;

	cout<<"Contenido del vector luego de borrar el elemento de la posición 7"<<endl;
	cout<<F<<endl;

	// Borro todos los elementos del vector
	F.borrar();

	cout<<"Contenido del vector luego de borrar todos los elementos"<<endl;
	cout<<F<<endl;

	F.insertar(1, 10);
	F.insertar(5, 50);
	F.insertar(7, 100);
	F.insertar(10, 150);

	Vector1 F2(5);

	// Se espera mensaje: Los vectores NO son iguales
	if(F == F2)
		cout<<"Los vectores son iguales"<<endl;
	else
		cout<<"Los vectores NO son iguales"<<endl;

	F2.insertar(1, 10);
	F2.insertar(5, 50);
	F2.insertar(7, 100);

	// Se espera mensaje: Los vectores NO son iguales
	if(F == F2)
		cout<<"Los vectores son iguales"<<endl;
	else
		cout<<"Los vectores NO son iguales"<<endl;

	F2.insertar(10, 150);

	// Se espera mensaje: Los vectores son iguales
	if(F == F2)
		cout<<"Los vectores son iguales"<<endl;
	else
		cout<<"Los vectores NO son iguales"<<endl;

	// /*
	// PUNTO 3) e.
	// ----------------------------------------------------------------------------------------
	cout<<"----------------------------------------------------------------------------------------"<<endl;
	cout<<"Muestro la información del vector ANTES de invocar a la funcion externa contarPares"<<endl;
	cout<<"Capacidad del Vector F: "<<F.capacidad()<<endl;
	cout<<"Contenido del Vector F: "<<F<<endl;

	// Invoco a la operacion externa contarPares con el vector F
	cout<<"Cantidad de elementos pares del vector F: "<<contarPares(F)<<endl;

	cout<<"Muestro la información del vector DESPUES de invocar a la funcion externa contarPares"<<endl;
	cout<<"Capacidad del Vector F: "<<F.capacidad()<<endl;
	cout<<"Contenido del Vector F: "<<F<<endl;
	cout<<"----------------------------------------------------------------------------------------"<<endl;
	// ----------------------------------------------------------------------------------------
	// */

	// Destruyo los vectores creados invocando explicitamente al destructor de la clase
	cout<<"Invoco al destructor con el objeto F y el objeto F2"<<endl;
	F.~Vector1();
	F2.~Vector1();


	cout<<"Capacidad vector F (0): "<<F.capacidad()<<endl;
	cout<<"Capacidad vector F2 (0): "<<F2.capacidad()<<endl;

	cout<<endl<<"####### FIN DEL PROGRAMA DE PRUEBA  #######"<<endl;
	return 0 ;
}
int contarPares(Vector1 V){
	int cont = 0;
	for(unsigned int i=1;i<=V.capacidad();i++){
		if((V.elemento(i)%2)==0)
			cont++;
	}
	return cont;
}
