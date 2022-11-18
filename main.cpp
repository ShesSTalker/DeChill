#include "Constantes.h"
#include "Animal.h"
#include "Perro.h"
#include "Caballo.h"
#include "Gato.h"
#include "Lagartija.h"
#include "Erizo.h"
#include "Roedor.h"
#include "Conejo.h"
#include <iostream>
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
class ArbolB 
{
    private:
        Nodo<Tipo> *raiz;
        int t;

    public:
        ArbolB(int _t);
    
        void recorrer();

        void insertar(string clave_nueva, Tipo *dato_nuevo);

        Nodo<Tipo> *buscar(string buscando);

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

int main(void)
{
    ArbolB<Animal> *miArbol = new ArbolB<Animal>(3);

    Lagartija *L1 = new Lagartija("Pepito", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(L1 -> obtener_nombre(), L1);

    Lagartija *L2 = new Lagartija("Asdjsad", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(L2 -> obtener_nombre(), L2);

    Lagartija *L3 = new Lagartija("Chancho", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(L3 -> obtener_nombre(), L3);

    Lagartija *L4 = new Lagartija("Lagarto", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(L4 -> obtener_nombre(), L4);

    Lagartija *L5 = new Lagartija("Pejelagarto", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(L5 -> obtener_nombre(), L5);

    Lagartija *L6 = new Lagartija("123", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(L6 -> obtener_nombre(), L6);

    cout << "El Arbol B es:";
    miArbol -> recorrer();

    string k = "Pepito";
    (miArbol -> buscar(k) != NULL) ? 
        cout << k << " se encontro" << endl : cout << k << " no se encontro" << endl;

    k = "Pepita";
    (miArbol -> buscar(k) != NULL) ? 
        cout << k << " se encontro" << endl : cout << k << " no se encontro" << endl;

    delete miArbol;

    return 0;
}
