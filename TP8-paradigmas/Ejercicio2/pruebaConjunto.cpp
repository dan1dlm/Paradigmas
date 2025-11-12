#include "IteradorDeConjunto.h"

template<class item>
bool pertenece(Conjunto<item>& conj, item X){
    IteradorDeConjunto<item> it(conj);
    bool resultado = false;

    while(!resultado && it.hayMasElementos()){
        resultado = it.elementoActual() == X;
        it.avanzar();
    }

    return resultado;
}

int main(){
    //creo un nuevo objeto Conjunto
    Conjunto<int> conj1;
    conj1.agregar(1);
    conj1.agregar(2);
    conj1.agregar(3);
    conj1.agregar(4);

  

   
    //itero el objeto conjunto utilizando la clase iterador
    //escribir por pantalla

    IteradorDeConjunto<int> it(conj1);
    int i=1;

    cout<<"Conjunto de elementos armada"<<endl;
    while(it.hayMasElementos()){
        cout<<"Elemento "<<i<<": "<<it.elementoActual()<<endl;
        it.avanzar();
        i++;
    }

    if(conj1.esConjuntoVacio())
        cout<<"\nEl Conjunto esta vacio"<<endl;
    else    
        cout<<"\nEl Conjunto contiene elementos"<<endl;

    //utilizo la funcion pertenece:
    if(pertenece(conj1, 3))
        cout<<"\nEl elemento 3 esta en la lista"<<endl;
    else    
        cout<<"\nEl elemento no 3 esta en la lista"<<endl;


      Conjunto<Cuenta> conj2;
    Cuenta c1;
    Cuenta c2;

    conj2.agregar(c1);
    conj2.agregar(c2);

     if(!conj2.esConjuntoVacio())
        cout<<"\n\nesta todo bien wachoo"<<endl;
    else    
        cout<<"\n\nEsta todo mal loco"<<endl;



    int cantidad = conj2.cantidad();

    cout<<"\n\ncantidad de conj2: "<<cantidad<<endl;

    return 0;
}

