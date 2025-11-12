#ifndef ITERADOR_DE_CONJUNTO_INVERSO_H
#define ITERADOR_DE_CONJUNTO_INVERSO_H

#include "ConjuntoGenerico.h"

template <class item>

class IteradorDeConjuntoInverso
{
    const Conjunto<item> &conj;
    int pos;

public:
    IteradorDeConjuntoInverso(const Conjunto<item> &conj);
    bool hayMasElementos();
    item elementoActual();
    void avanzar(); //retroceder
};

template <class item>
IteradorDeConjuntoInverso<item>::IteradorDeConjuntoInverso(const Conjunto<item> &conj) : conj(conj)
{
    pos = conj.indice - 1;
}

template <class item>
bool IteradorDeConjuntoInverso<item>::hayMasElementos()
{
    return pos >= 0; // mientras no nos pasemos de la posicion inicial
}

template <class item>
item IteradorDeConjuntoInverso<item>::elementoActual() { return conj.elementos[pos]; }

template <class item>
void IteradorDeConjuntoInverso<item>::avanzar()
{
    --pos;
}

#endif // ITERADOR_DE_CONJUNTO_INVERSO_H