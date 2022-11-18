#ifndef ARBOL_H
#define ARBOL_H

#include "NodoArbol.h"

class Arbol
{
    private:
        NodoArbol *raiz;
        int t;

    public:
        Arbol(int _t);

        void recorrer();

        NodoArbol *buscar(Animal *buscando);

        void insertar(Animal *nuevo);
};

template < class Tipo >
Arbol<Tipo>::Arbol(int _t)
{
    raiz = nullptr;
    t = _t;
}

template < class Tipo >
void Arbol<Tipo>::recorrer()
{
    if(raiz != nullptr)
    {
        raiz -> recorrer();
    }
}

template < class Tipo >
NodoArbol<Tipo> *Arbol<Tipo>::buscar(Tipo buscando)
{
    if(raiz == nullptr)
    {
        return nullptr;
    }

    return raiz -> buscar(buscando);
}

#endif
