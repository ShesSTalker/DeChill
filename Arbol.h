#ifndef _ARBOLB_H_
#define _ARBOLB_H_

#include "Nodo.h"

template < typename Tipo >
class ArbolB
{
    //Atributos
    private:
        Nodo<Tipo>* raiz;

    //Metodos
    public:
        ArbolB();

        Nodo<Tipo>* obtener_raiz();

        void insertar(Nodo<Tipo>* nodo, string nueva_clave, Tipo *nuevo_dato);

        bool buscar();

        ~ArbolB();

    private:
        void establecer_raiz(Nodo<Tipo>* nueva_raiz);
};

template < typename Tipo > 
ArbolB<Tipo>::ArbolB()
{
    this -> raiz = nullptr;
}

template < typename Tipo >
Nodo<Tipo>* ArbolB<Tipo>::obtener_raiz()
{
    return raiz;
}

template < typename Tipo >
void ArbolB<Tipo>::establecer_raiz(Nodo<Tipo> *nueva_raiz)
{
    raiz = nueva_raiz;
}

template < typename Tipo > 
void ArbolB<Tipo>::insertar(Nodo<Tipo>* nodo, string nueva_clave, Tipo *nuevo_dato)
{
    if (obtener_raiz() == nullptr)
    {
        nodo = new Nodo<Tipo>();
        establecer_raiz(nodo);
        nodo -> insertar_no_lleno(nueva_clave, nuevo_dato);

        return;
    }

    if(nodo -> es_hoja())
    {
        if(nodo -> obtener_claves_usadas() == 2)
            nodo -> dividir(nodo, nueva_clave, nuevo_dato);
        else
            nodo -> insertar_no_lleno(nueva_clave, nuevo_dato);

        return;
    }

    if(nueva_clave < nodo -> obtener_clave(0))
    {
        insertar(nodo -> obtener_hijo(0), nueva_clave, nuevo_dato);
    }
    else if(nueva_clave < nodo -> obtener_clave(1))
    {
        insertar(nodo -> obtener_hijo(1), nueva_clave, nuevo_dato);
    }
    else
    {
        insertar(nodo -> obtener_hijo(2), nueva_clave, nuevo_dato);
    }
}

template < typename Tipo >
ArbolB<Tipo>::~ArbolB()
{
    delete obtener_raiz();
}

#endif
