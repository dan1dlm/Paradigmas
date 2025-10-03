//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// CuentaObjeto.cpp
//============================================================================

#include "CuentaObjeto.h"

//Inicializacion de variables estaticas
int CuentaObjeto::objCreados=0;
int CuentaObjeto::objDestruidos=0;

//Constructor por defecto
CuentaObjeto::CuentaObjeto(){
	objCreados++;
	cout<<"Const x defecto: "<<this<<endl;
}

//Constructor copia
CuentaObjeto::CuentaObjeto(CuentaObjeto &co){
	objCreados++;
	cout<<"Const copia: "<<this<<endl;
}

CuentaObjeto& CuentaObjeto::metodo1(CuentaObjeto &co){
	cout<<"(Inicio metodo1)"<<endl;
	cout<<"   Objeto receptor del mensaje: "<<this<<endl;
	cout<<"   Objeto argumento del mensaje: "<<&co<<endl;
	cout<<"(Fin metodo1)"<<endl;
	return co;
}

CuentaObjeto CuentaObjeto::metodo2(CuentaObjeto co){
	cout<<"(Inicio metodo2)"<<endl;
	cout<<"   Objeto receptor del mensaje: "<<this<<endl;
	cout<<"   Objeto argumento del mensaje: "<<&co<<endl;
	cout<<"(Fin metodo2)"<<endl;
	return co;
}

void CuentaObjeto::mostrarResumen(){
	cout<<"      - Creados: "<<objCreados<<endl;
	cout<<"      - Destruidos: "<<objDestruidos<<endl;
}

//Destructor
CuentaObjeto::~CuentaObjeto(){
	objDestruidos++;
	cout<<"Destructor: "<<this<<endl;
}


