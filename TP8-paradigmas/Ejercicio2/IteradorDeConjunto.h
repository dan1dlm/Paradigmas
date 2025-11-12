
#ifndef ITERADOR_DE_CONJUNTO_H_
#define ITERADOR_DE_CONJUNTO_H_

#include "ConjuntoGenerico.h"
template <class item>
class IteradorDeConjunto{
    const Conjunto<item>& conj;
    int pos;

    public:
    IteradorDeConjunto(const Conjunto<item>& conj);
    bool hayMasElementos();
    item elementoActual();
    void avanzar();
};

template <class item>
IteradorDeConjunto<item> :: IteradorDeConjunto(const Conjunto<item>& conj) : conj(conj){
    pos = 0;
}

template <class item>
bool IteradorDeConjunto<item> :: hayMasElementos(){
    return pos < conj.indice;
}


template <class item>
item IteradorDeConjunto<item> :: elementoActual(){
    return conj.elementos[this->pos];
}

template <class item>
void IteradorDeConjunto<item> :: avanzar(){
    pos++;
}



#endif //ITERADOR_DE_CONJUNTO_H_