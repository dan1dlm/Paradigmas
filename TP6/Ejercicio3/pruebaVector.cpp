#include "Vector.h"

unsigned int ContarPares(Vector V){
    int cantidadPares = 0;
    for(int i=0; i < V.capacidad(); i++){
        if(V.elemento(i)%2 == 0){
            cantidadPares++;
        }
    }

    return cantidadPares;
}


int main(){
    Vector V1;
    
    V1.insertar(1, 4);
    V1.insertar(2, 5);
    V1.insertar(3, 6);

    Vector V2(13);


    int resultado = ContarPares(V1);

    cout<<"Cantidad de elementos pares: "<<resultado<<endl;
}