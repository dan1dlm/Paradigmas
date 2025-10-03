//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// PruebaCuentaObjeto.cpp
//============================================================================

#include <iostream>
#include "CuentaObjeto.h"
using namespace std;

int main() {
	cout<<endl<<"INICIO DEL PROGRAMA DE PRUEBA"<<endl<<endl;

	cout<<endl<<"  ----------------------"<<endl;
	cout<<"   1er Resumen"<<endl;
	CuentaObjeto::mostrarResumen();
	cout<<"  ----------------------"<<endl<<endl;

	cout<<"Invocacion al constructor por defecto"<<endl;
	CuentaObjeto obj1; //Se invoca el constructor por defecto cuando uno instancia un objeto de la clase
	cout<<"(Fin constructor por defecto)"<<endl;

	cout<<endl<<"  ----------------------"<<endl;
	cout<<"   2do Resumen"<<endl;
	CuentaObjeto::mostrarResumen();
	cout<<"  ----------------------"<<endl<<endl;

	cout<<endl<<"##########	INICIO BLOQUE DE CODIGO  ##########"<<endl<<endl;
	{
		cout<<"Invocacion al constructor por defecto"<<endl;
		static CuentaObjeto obj2;
		cout<<"(Fin constructor por defecto)"<<endl;

		cout<<endl<<"  ----------------------"<<endl;
		cout<<"   3er Resumen"<<endl;
		CuentaObjeto::mostrarResumen();
		cout<<"  ----------------------"<<endl<<endl;

		cout<<"Invocacion al constructor copia"<<endl;
		CuentaObjeto obj3(obj1);
		cout<<"(Fin constructor copia)"<<endl;

		cout<<endl<<"  ----------------------"<<endl;
		cout<<"   4to Resumen"<<endl;
		CuentaObjeto::mostrarResumen();
		cout<<"  ----------------------"<<endl<<endl;

		cout<<"Invocacion al constructor por defecto a traves del operador NEW"<<endl;
		CuentaObjeto *obj4 = new CuentaObjeto();
		cout<<"(Fin constructor por defecto)"<<endl;

		cout<<endl<<"  ----------------------"<<endl;
		cout<<"   5to Resumen"<<endl;
		CuentaObjeto::mostrarResumen();
		cout<<"  ----------------------"<<endl<<endl;

		cout<<"Invocacion a la funcion miembro metodo1"<<endl;
		obj1 = obj2.metodo1(obj1); //El método pasa la direccion del metodo que manda el argumento, en este caso, la direccion de obj1

		cout<<endl<<"  ----------------------"<<endl;
		cout<<"   6to Resumen"<<endl;
		CuentaObjeto::mostrarResumen(); 
		cout<<"  ----------------------"<<endl<<endl;

		cout<<"Invocacion a la funcion miembro metodo2"<<endl;
		obj4->metodo2(obj1);

		cout<<endl<<"  ----------------------"<<endl;
		cout<<"   7mo Resumen"<<endl;
		CuentaObjeto::mostrarResumen();
		cout<<"  ----------------------"<<endl<<endl;
		cout<<endl<<"##########  FIN BLOQUE DE CODIGO  ##########"<<endl<<endl;

	}

	cout<<endl<<"  ----------------------"<<endl;
	cout<<"   8vo Resumen"<<endl;
	CuentaObjeto::mostrarResumen();
	cout<<"  ----------------------"<<endl<<endl;

	cout<<endl<<"FIN DEL PROGRAMA DE PRUEBA"<<endl<<endl;
	return 0;
}
