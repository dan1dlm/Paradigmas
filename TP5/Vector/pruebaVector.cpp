#include "Vector.h"



int main(){
    Vector V1;
    V1.crearVector(); // vector con 10 espacios
    V1.insertar(0, 5);
    V1.insertar(2, 5);
    V1.insertar(4, 5);

    V1.mostrar();

    V1.insertar(10, 91);
    cout<<endl;
    V1.mostrar();
    cout<<V1.capacidad();

    V1.borrar(0);
    cout<<endl;
    V1.mostrar();

    cout<<endl<<V1.elemento(2);

    V1.destruir();

}