//ITERADOR PARA EL CONJUNTO EJERCICIO 1)

#include "Conjunto.h"

class IteradorDeConjunto{
    const Conjunto& conj;
    int pos;

    public:
    IteradorDeConjunto(const Conjunto& conj);
    bool hayMasElementos();
    item elementoActual();
    void avanzar();
};