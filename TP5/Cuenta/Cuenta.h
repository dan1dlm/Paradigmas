#include <iostream>
using namespace std;

class Cuenta{
    int numero;
    long int dniTitular;
    double saldo;

    public: 
    void crear(int num, long int titular, double monto);
    bool depositar(double monto);
    bool extraer(double monto);
    double getSaldo();
    void mostrarInformacion();
};

void Cuenta :: crear(int num, long int titular, double monto){
    numero = num;
    dniTitular = titular;
    saldo = monto;
}

bool Cuenta :: depositar(double monto){
    if(monto > 0){
        saldo += monto;

        return true;
    }

    return false;
}

bool Cuenta :: extraer(double monto){
    if(monto<= 0 || monto > saldo){
        return false;
    }

    saldo -= monto;

    return true;
}

double Cuenta :: getSaldo(){
    return saldo;
}

void Cuenta :: mostrarInformacion(){
    cout<<"Numero de cuenta: "<<numero<<"\nDNI: "<<dniTitular<<"\nSaldo disponible: "<<saldo;
}