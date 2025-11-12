/*
 * Cuenta.h
 *
 *  Created on: Sep 26, 2010
 *      Author: hector
 */

#ifndef CUENTA_H_
#define CUENTA_H_
#include <iostream>
using namespace std;


class Cuenta {
protected:
	int numero;
	double saldo;
public:
	Cuenta(int numero=0, double saldo=0);
	Cuenta(const Cuenta &cuenta);
	virtual ~Cuenta();
	int getNumero() const;
	double getSaldo() const;
	bool depositar(double cantidad);
	bool extraer(double cantidad);
	friend bool operator==(Cuenta A, Cuenta B){
		if (A.numero == B.numero && A.saldo == B.saldo)
			return true;
		else
			return false;

	};

	friend ostream& operator <<(ostream& sale, Cuenta A){
		sale << "Cuenta"<<endl;
		sale<< "Numero : "<<A.numero<<endl;
		sale<< "Saldo: "<<A.saldo<<endl;
		return sale;

	};
};

Cuenta::Cuenta(int numero, double saldo) :
	numero(numero), saldo(saldo) {
	//cout << "Constructor de Cuenta (Clase Base)"<<endl;

}

Cuenta::Cuenta(const Cuenta &cuenta) :
	numero(cuenta.numero), saldo(cuenta.saldo) {
	//cout << "Constructor de Cuenta (Clase Base)"<<endl;
}


int Cuenta::getNumero() const {
	return numero;
}

bool Cuenta::depositar(double cantidad) {
	bool resultado=false;
	if (cantidad>0){
		saldo = saldo + cantidad;
		resultado=true;
	}
	return resultado;
}
bool Cuenta::extraer(double cantidad) {
	bool resultado = false;
	if (cantidad <= saldo) {
		saldo = saldo - cantidad;
		resultado = true;
	}
	return resultado;
}

double Cuenta::getSaldo() const {
	return saldo;
}

Cuenta::~Cuenta() {
	//cout << endl << "Cuenta " << this->numero << " destruida" << endl;

}

#endif //CUENTA_H_
