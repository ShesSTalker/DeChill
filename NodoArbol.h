#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H

#include "Animal.h"

class NodoArbol
{
    private:
        Animal *claves;
        int orden;
        NodoArbol **hijos;
        int cantidad_claves;
        bool es_hoja;

    public:
        NodoArbol(int _orden, bool _es_hoja);

        void insertar_no_lleno(Animal *nuevo);

        void partir_hijo(int i, Animal *y);

        void recorrer();

        NodoArbol *buscar(Animal *buscando);

    friend class Arbol;
};

NodoArbol::NodoArbol(int _orden, bool _es_hoja)
{
    orden = _orden;
    es_hoja = _es_hoja;

    claves = new Animal [2 * orden - 1];
    hijos = new NodoArbol *[2 * orden];

    cantidad_claves = 0;
}

void NodoArbol::recorrer()
{
    for(int i = 0; i < cantidad_claves; i++)
    {
        if(!es_hoja)
        {
            hijos[i] -> recorrer();
        }
        cout << " " << claves[i].obtener_nombre(); 
    }
}

#endif
