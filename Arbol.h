#ifndef _ARBOLB_H_
#define _ARBOLB_H_

#include "Nodo.h"

template < typename Tipo >
class ArbolB
{
    //Atributos
    private:
        Nodo<Tipo>* raiz;
        bool clave_ubicada;

    //Metodos
        ArbolB();

        Nodo<Tipo>* obtener_raiz();

        Nodo<Tipo>* insertar(Nodo<Tipo>* nodo, string nueva_clave, Tipo nuevo_dato);
};

template < typename Tipo > 
ArbolB<Tipo>::ArbolB()
{
    this -> raiz = nullptr;
    bool clave_ubicada = false;
}

template < typename Tipo >
Nodo<Tipo>* ArbolB<Tipo>::obtener_raiz()
{
    return raiz;
}

template < typename Tipo > 
Nodo<Tipo>* ArbolB<Tipo>::insertar(Nodo<Tipo>* nodo,string nueva_clave, Tipo nuevo_dato)
{
    if (obtener_raiz() == nullptr)
    {
        nodo = new Nodo<Tipo>(3);
        nodo -> establecer_clave(nueva_clave, 0);
        nodo -> establecer_dato(nuevo_dato, 0);
    }
    else if (nodo -> es_hoja && nodo -> obtener_claves_usadas() < 2)
    {
        nodo -> insertar_no_lleno(nueva_clave, nuevo_dato);
    }
    else if (nodo -> es_hoja && nodo-> obtener_claves_usadas == 2)
    {
        nodo = nodo -> dividir(nodo, nueva_clave, nuevo_dato);
    }
    else if(nodo -> !es_hoja() && nueva_clave < nodo -> obtener_clave(0))
    {
        insertar(nodo -> obtener_hijo(0), nueva_clave, nuevo_dato);
    }
    else if(nodo -> !es_hoja() && nodo -> obtener_claves_usadas() < 2 && nueva_clave > nodo -> obtener_clave(0))
    {
        insertar(nodo -> obtener_hijo(2), nueva_clave, nuevo_dato);
    }
    else if(nodo -> !es_hoja() && nodo -> obtener_claves_usadas() == 2 && nueva_clave > nodo -> obtener_clave(1))
    {
        insertar(nodo -> obtener_hijo(2), nueva_clave, nuevo_dato);
    }
    else if(nodo -> !es_hoja() && nodo -> obtener_claves_usadas() == 2 && nueva_clave > nodo -> obtener_clave(0) && nueva_clave < nodo -> obtener_clave(1))
    {
        insertar(nodo -> obtener_hijo(1), nueva_clave, nuevo_dato);
    }

    return raiz;
}

#endif