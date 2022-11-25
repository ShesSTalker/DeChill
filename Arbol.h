#ifndef _ARBOLB_H_
#define _ARBOLB_H_

#include "Nodo.h"

template < typename Tipo >
class ArbolB
{
    //Atributos
    private:
        Nodo<Tipo>* raiz;
        int orden;

    //Metodos
    public:
        ArbolB(int orden);

        bool arbol_vacio();

        Nodo<Tipo>* obtener_raiz();

        void establecer_raiz(Nodo<Tipo>* nueva_raiz);

        int obtener_orden();

        void insertar(string nueva_clave, Tipo nuevo_dato);

        Nodo<Tipo>* buscar(string clave, int &posicion);
    
    private:
        Nodo<Tipo>* buscar(Nodo<Tipo>* nodo_actual, string clave, int &posicion);

        bool buscar_nodo_actual(Nodo<Tipo>* nodo_actual, string clave, int &posicion);

        Nodo<Tipo>* insertar(Nodo<Tipo>* raiz, string nueva_clave, Tipo nuevo_dato);

        bool empujar(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* nuevo_nodo, string nueva_clave, Tipo nuevo_dato, string &pivote); 
};

#endif

template < typename Tipo >
ArbolB<Tipo>::ArbolB(int orden)
{
    raiz = NULL;
    this -> orden = orden;
}

template < typename Tipo >
bool ArbolB<Tipo>::arbol_vacio()
{
    return raiz == NULL;
}

template < typename Tipo >
Nodo<Tipo>* ArbolB <Tipo>::obtener_raiz()
{
    return raiz;
}

template < typename Tipo >
void ArbolB<Tipo>::establecer_raiz(Nodo<Tipo>* nueva_raiz)
{
    raiz = nueva_raiz;
}

template < typename Tipo >
int ArbolB<Tipo>::obtener_orden()
{
    return orden;
}

template < typename Tipo >
Nodo<Tipo>* ArbolB<Tipo>::buscar(string clave, int &posicion)
{
    return buscar(raiz, clave, posicion);
}

template < typename Tipo >
void ArbolB<Tipo>::insertar(string nueva_clave, Tipo nuevo_dato)
{
    raiz = insertar(raiz, nueva_clave, nuevo_dato);
}

template < typename Tipo > 
Nodo<Tipo>* ArbolB<Tipo>::insertar(Nodo<Tipo>* raiz, string nueva_clave, Tipo nuevo_dato)
{
    bool sube_arriba;
    string pivote;
    Nodo<Tipo>* nodo;

    sube_arriba = empujar(raiz, nodo, nueva_clave, nuevo_dato, pivote);
    if (sube_arriba)
    {
        Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(grado);
        nuevo_nodo -> cuenta(1);// unsa sola clave
        nuevo_nodo -> clave(1, pivote);
        nuevo_nodo -> rama(0, raiz);//claves mayores
        nuevo_nodo -> rama(1, nodo);//claves menores
        raiz = nuevo_nodo;
    }
    return raiz;
}   

template < typename Tipo > 
Nodo<Tipo>* ArbolB<Tipo>::buscar(Nodo<Tipo>* nodo_actual, string clave, int &posicion)
{
    bool encontrado;

    if(nodo_actual == NULL)
    {
        return NULL;
    }
    else
    {
        encontrado = buscar_nodo_actual(nodo_actual, clave, posicion);
        
        if (encontrado)
        {
            return nodo_actual;
        }
        else 
        {
            return buscar_nodo_actual(nodo_actual -> obtener_hijo(posicion), clave, posicion);
        }
    }
}

template < typename Tipo >
bool ArbolB<Tipo>::buscar_nodo_actual(Nodo<Tipo>* nodo_actual, string clave, int &posicion)
{
    int i;
    bool encontrado;

    if(clave < nodo_actual -> obtener_clave(1))
    {
        encontrado = false;
        i = 0;
    }
    else
    {
        i = nodo_actual -> obtener_cantidad_claves_usadas() - 1;

        while(clave < nodo_actual -> obtener_clave(i) && i < 1)
        {
            if (clave == nodo_actual -> obtener_clave(i))
            {
                encontrado = true;
            }
        }
    }
    posicion = i;
    
    return encontrado;
}

template < typename Tipo >
bool ArbolB<Tipo>::empujar(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* nuevo_nodo, string nueva_clave, Tipo nuevo_dato, string &pivote)
{
    int i;
    bool encontrado, sube_arriba = false;

    if(nodo_actual == NULL)
    {
        sube_arriba = true;
        pivote = nueva_clave;
        nuevo_nodo = NULL;
    }
    else
    {
        encontrado = buscar_nodo_actual(nodo_actual, nuevo_clave, i);
        
        if(encontrado)
        {
            sube_arriba = empujar(nodo_actual -> obtener_hijo(i), nuevo_nodo, nueva_clave, nuevo_dato, pivote);
        }

        if(sube_arriba)
        {
            
        }
    }
}