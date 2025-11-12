#include "IteradorDeConjunto.h"

IteradorDeConjunto :: IteradorDeConjunto(const Conjunto& conj) : conj(conj){
    pos = 0;
}

bool IteradorDeConjunto :: hayMasElementos(){
    return pos < conj.indice;
}

item IteradorDeConjunto :: elementoActual(){
    return conj.elementos[this->pos];
}

void IteradorDeConjunto :: avanzar(){
    pos++;
}



