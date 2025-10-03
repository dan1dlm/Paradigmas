#include "Cuenta.h"


bool transferir(Cuenta &c1, Cuenta &c2, double monto){
    return(c1.extraer(monto) && c2.depositar(monto));
}


int main(){
    Cuenta c1, c2;
    c1.crear(1, 23523, 6000);
    c2.crear(1, 3634, 4000);

    if(transferir(c1, c2, 3000)){
        cout<<"Monto c1: "<<c1.getSaldo()<<"\nMonto c2: "<<c2.getSaldo()<<endl;
    }
}