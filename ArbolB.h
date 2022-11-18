#ifndef ARBOL_B_H
#define ARBOL_B_H

#include "Nodo.h"
using namespace std;

template < typename Tipo >
class ArbolB 
{
    private:
        Nodo<Tipo> *raiz;
        int t;

    public: // Agregar PRE y POS
        // PRE: 
        // POS:
        ArbolB(int _t);
    
        // PRE: 
        // POS:
        void recorrer();

        // PRE: 
        // POS:
        void insertar(string clave_nueva, Tipo *dato_nuevo);

        // PRE: 
        // POS:
        Nodo<Tipo> *buscar(string buscando);

        // PRE: 
        // POS:
        ~ArbolB();
};

template < typename Tipo >
ArbolB<Tipo>::~ArbolB()
{
    if(raiz != nullptr)
    {
        delete raiz;
    }
}

template < typename Tipo >
ArbolB<Tipo>::ArbolB(int _t)
{
    raiz = nullptr;
    t = _t;
}

template < typename Tipo >
void ArbolB<Tipo>::recorrer()
{
    if(raiz != nullptr)
    {
        raiz -> recorrer();
    }
    cout << endl;
}

template < typename Tipo >
Nodo<Tipo> *ArbolB<Tipo>::buscar(string buscando)
{
    if(raiz == nullptr)
        return nullptr;

    return raiz -> buscar(buscando);
}

template < typename Tipo >
void ArbolB<Tipo>::insertar(string clave_nueva, Tipo *dato_nuevo)
{
    if(raiz == nullptr)
    {
        raiz = new Nodo<Tipo>(t, true);
        raiz -> claves[0] = clave_nueva;
        raiz -> datos[0] = dato_nuevo;
        raiz -> cantidad_claves = 1;
    }
    else
    {
        if(raiz -> cantidad_claves == 2 * t - 1)
        {
            Nodo<Tipo> *divido = new Nodo<Tipo>(t, false);

            divido -> hijos[0] = raiz;

            divido -> dividir_hijo(0, raiz);

            int i = 0;
            if(divido -> claves[0] < clave_nueva)
              i++;

            divido -> hijos[i] -> insertar_no_lleno(clave_nueva, dato_nuevo);

            raiz = divido;
        }
        else
        {
            raiz -> insertar_no_lleno(clave_nueva, dato_nuevo);
        }
    }
}



#endif
