//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// Vector.cpp
//============================================================================

#include <iostream>
#include "Vector.h"

using namespace std;

// OPERACIONES ADT VECTOR(ITEM)

//Operaciones Auxiliares
bool Vector1::reservarMemoria(unsigned int n){
	this->elementos = new item[n];
	if(this->elementos == NULL){
		return false;
	}
	else{
		for(unsigned int i=0;i<n;i++)
			this->elementos[i] = indef;
		return true;
	}
}

bool Vector1::redimensionar(unsigned int n){
	if(n > this->max){
		item *nuevo = new item[n];
		if(nuevo != NULL){
			for(unsigned int i=0;i<this->max;i++)
				nuevo[i] = this->elementos[i];
			for(unsigned int i=this->max; i<n;i++)
				nuevo[i] = indef;
			this->max = n;
			delete[] this->elementos;
			this->elementos = nuevo;
			return true;
		}
	}
	return false;
}

//Operaciones propias del ADT VECTOR(ITEM)
//void Vector1::crearVector(unsigned int n){
Vector1::Vector1(unsigned int n){
	if(!this->reservarMemoria(n))
		this->max=0;
	else
		this->max = n;
}

Vector1::Vector1(Vector1 &V){
	if(!this->reservarMemoria(V.max)){
		this->max=0;
		cout<<"ERROR - NO SE PUDO REALIZAR CORRECTAMENTE LA COPIA"<<endl;
	}
	else{
		this->max = V.max;
		for(unsigned int i=0;i<this->max;i++)
			this->elementos[i] = V.elementos[i];
	}
}

void Vector1::insertar(unsigned int p, item x){
	if(0 < p && p <= this->max || this->redimensionar(p)){
		this->elementos[p-1] = x;
	}
}

unsigned int Vector1::capacidad(){
	return this->max;
}

item& Vector1::elemento(unsigned int p){
	if(0 < p && p <= this->max)
		return this->elementos[p-1];
	else
		return this->elementos[0];
}

void Vector1::borrar(unsigned int p){
	if(0 < p && p <= this->max)
		this->elementos[p-1] = indef;
}

void Vector1::borrar(){
	for(unsigned int i=0;i<this->max;i++)
		this->elementos[i] = indef;
}

//void Vector1::destruir(){
Vector1::~Vector1(){
	delete[] this->elementos;
	this->max = 0;
}

//Sobrecarga del operador == como operacion propia del ADT VECTOR(ITEM)
bool Vector1::operator==(Vector1 &V2){
	unsigned int i=0;
	if(this->max == V2.max){
		while(i<this->max && this->elementos[i] == V2.elementos[i])
			i++;
		return i==this->max;
	}else
		return false;
}



