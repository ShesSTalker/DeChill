#ifndef NODO_H
#define NODO_H

#include <string>
#include "ArbolB.h"
using namespace std;

template < typename Tipo >
class Nodo {
    private:
        string *claves;
        Tipo **datos;
        // Averiguar qué es "t", exactamente
        int t;
        Nodo<Tipo> **hijos;
        int cantidad_claves;
        bool es_hoja;

    public: // Agregar PRE y POS
        // PRE: 
        // POS: 
        Nodo(int _t, bool _es_hoja);

        // PRE: 
        // POS:
        void insertar_no_lleno(string clave_nueva, Tipo *dato_nuevo);

        // PRE:
        // POS:
        void dividir_hijo(int i, Nodo<Tipo> *y);

        // PRE:
        // POS:
        void recorrer();

        // PRE:
        // POS:
        Nodo<Tipo> *buscar(string buscando);

        // PRE:
        // POS:
        ~Nodo();
        
    template < typename Tipo2 > 
    friend class ArbolB;
};

template < typename Tipo >
Nodo<Tipo>::~Nodo()
{
    int i;
    for(i = 0; i < cantidad_claves; i++)
    {
        if(!es_hoja)
            delete hijos[i];

        delete datos[i];
    }

    if(!es_hoja)
        delete hijos[i];

    delete[] datos;
    delete[] claves;
    delete[] hijos;
}

template < typename Tipo >
Nodo<Tipo> *Nodo<Tipo>::buscar(string buscando)
{
    int i = 0;
    while(i < cantidad_claves && buscando > claves[i])
        i++;

    if(claves[i] == buscando)
        return this;

    if(es_hoja)
        return nullptr;

    return hijos[i] -> buscar(buscando);
}


template < typename Tipo >
Nodo<Tipo>::Nodo(int _t, bool _es_hoja) {
    t = _t;
    es_hoja = _es_hoja;

    claves = new string[2 * t - 1];
    hijos = new Nodo<Tipo> *[2 * t];
    datos = new Tipo *[2 * t - 1];

    cantidad_claves = 0;
}

template < typename Tipo >
void Nodo<Tipo>::recorrer()
{
    int i;
    for(i = 0; i < cantidad_claves; i++)
    {
        if(!es_hoja)
            hijos[i] -> recorrer();

        cout << " " << claves[i];
    }

    if(!es_hoja)
        hijos[i] -> recorrer();

}

template < typename Tipo >
void Nodo<Tipo>::insertar_no_lleno(string clave_nueva, Tipo *dato_nuevo)
{
    int i = cantidad_claves - 1;
    if(es_hoja)
    {
        while(i >= 0 && claves[i] > clave_nueva)
        {
            claves[i + 1] = claves[i];
            datos[i + 1] = datos[i];
            i--;
        }

        claves[i + 1] = clave_nueva;
        datos[i + 1] = dato_nuevo;
        cantidad_claves++;
    }
    else
    {
        while(i >= 0 && claves[i] > clave_nueva)
            i--;

        if(hijos[i + 1] -> cantidad_claves == 2 * t - 1)
        {
            dividir_hijo(i + 1, hijos[i + 1]);

            if(claves[i + 1] < clave_nueva)
                i++;
        }
        hijos[i + 1] -> insertar_no_lleno(clave_nueva, dato_nuevo);
    }
}

// Renombremos qué es "y" y qué es "z". Además intentar qué carajo hace esto
template < typename Tipo >
void Nodo<Tipo>::dividir_hijo(int i, Nodo<Tipo> *y)
{
    Nodo<Tipo> *z = new Nodo<Tipo>(y -> t, y -> es_hoja);
    z -> cantidad_claves = t - 1;

    for(int j = 0; j < t - 1; j++)
    {
        z -> claves[j] = y -> claves[j + t];
        z -> datos[j] = y -> datos[j + t];
    }

    if(!(y -> es_hoja))
    {
        for(int j = 0; j < t; j++)
            z -> hijos[j] = y -> hijos[j + t];
    }

    y -> cantidad_claves = t - 1;
    for(int j = cantidad_claves; j >= i + 1; j--)
        hijos[j + 1] = hijos[j];

    hijos[i + 1] = z;

    for(int j = cantidad_claves - 1; j >= i; j--)
    {
        claves[j + 1] = claves[j];
        datos[j + 1] = datos[j];
    }

    claves[i] = y -> claves[t - 1];
    datos[i] = y -> datos[t - 1];
    cantidad_claves++;
}

#endif
