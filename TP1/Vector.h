#include <iostream>
using namespace std;
#define indef -9

//TRABAJO CON LAS POSICIONES DEL VECTOR EMPEZANDO DESDE 1, 2, ... , N, LOGRANDO QUE SEA MÁS ACCESIBLE AL USUARIO

struct
{
    int *elementos;
    unsigned int max;
} typedef Vector;

typedef int item;

// FUNCIONES AUXLIARES

bool reservarMemoria(Vector &V, unsigned int n)
{
    V.elementos = new int[n];
    if (V.elementos == nullptr)
    {
        return false;
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            V.elementos[i] = indef;
        }
    }

    return true;
}

//ESTA NO ES AUXILIAR PERO LA UTILIZO EN REDIMENSIONAR

Vector crearVector(unsigned int n = 10)
{
    Vector V;
    if (!reservarMemoria(V, n))
    {
        V.max = 0;
    }
    else
    {
        V.max = n;
    }
    return V;
}

bool redimensionar(Vector &V, unsigned int n)
{
    Vector nuevo = crearVector(n);

    for (size_t i = 0; i < V.max; i++)
    {
        nuevo.elementos[i] = V.elementos[i];
    }

    delete[] V.elementos;

    V.elementos = nuevo.elementos;
    V.max = n;

    if (V.max == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// FUNCIONES DEL ADT

//ACA VA crearVector



Vector insertar(Vector V, unsigned int p, item x)
{
    if (V.max >= p)
    {
        V.elementos[p-1] = x;
    }
    else
    {
        if (redimensionar(V, p))
        {
            V.elementos[p-1] = x;
        }else{
            cout<<endl<<"No se pudo ingresar el item: "<<x;
        }
    }

    return V;
}

int capacidad(Vector V){
    return V.max;
}

item& elemento(Vector V, unsigned int x){
    if(x > V.max){
        cout<<endl<<"No se encuentra disponible la posicion puesta"<<endl;
        return V.elementos[0];
    }else{
        return V.elementos[x-1];
    }
}

Vector borrar(Vector V, unsigned int p){
    if(p > V.max){
        return V;
    }else{
        V.elementos[p-1] = indef;
        return V;
    }
}

Vector borrar(Vector V){
    for(size_t i=0; i < V.max ; i++){
        V.elementos[i] = indef;
    }

    return V;
}

Vector destruir(Vector V){
    delete[] V.elementos;
    V.elementos = nullptr;
    V.max = 0;

    return V;
}

bool operator ==(Vector V1, Vector V2){
    if(V1.max != V2.max){
        return false;
    }else{
        for(size_t i=0; i<V1.max; i++){
            if(V1.elementos[i] != V2.elementos[i]){
                return false;
            }
        }
    }

    return true;
}

