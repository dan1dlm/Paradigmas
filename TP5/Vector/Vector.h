#include <iostream>
using namespace std;

typedef int item;

class Vector{
    item *elementos;
    int MAX;

    //METODOS AUXILIARES
    bool reservarMemoria(int tama);
    bool redimensionar(int tama);

    public:
    void crearVector(int n = 10);
    void insertar(const int p, int item);
    int capacidad();
    item elemento(const int p);
    void borrar();
    void borrar(const int p);
    void destruir();
    void mostrar();
};

//Desarrollo de métodos

bool Vector :: reservarMemoria(int tama){
    item *resultado = new item[tama];
    if(resultado != NULL){
        for(int i = 0; i < tama; i++){
            resultado[i] = -1;
        }

        delete[] elementos;
        elementos = resultado;
        MAX = tama;
        
        return true;
    }


    return false;
}

bool Vector :: redimensionar(int tama){
    int tope = MAX;
    item* nuevo = new item[tope];

    if(nuevo == NULL)
        return false;

    for(int i=0; i < tope; i++){
        nuevo[i] = elementos[i];
    }

    delete[] elementos;

    if(reservarMemoria(tama)){
        for(int i=0; i < tope; i++){
            elementos[i] = nuevo[i];
        }

        MAX = tama;

        delete[] nuevo;
        
        return true;
    }

    return false;
}

void Vector :: crearVector(int n){
    bool resultado = reservarMemoria(n);
    if(n <= 0 || !resultado)
        MAX = 0;
}

void Vector :: insertar(const int p, int item){
    if(p < MAX)
        elementos[p] = item;
    else{
        if(redimensionar(p + 1)){
            elementos[p] = item;
        }
    }    
}

int Vector :: capacidad(){
    return MAX;
}

item Vector :: elemento(int p){
    if(p < MAX)
        return elementos[p];
    else
        return -1;
}

void Vector :: borrar(){
    for(int i = 0; i < MAX; i++){
        elementos[i] = -1;
    }
}

void Vector :: borrar(const int p){
    if(p < MAX)
        elementos[p] = -1;
}

void Vector :: destruir(){
    delete[] elementos;
}

void Vector :: mostrar(){
    for(int i=0; i < MAX; i++){
        cout<<"elementos "<<i<<": "<<elementos[i]<<endl;
    }
}
