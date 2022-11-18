#ifndef _ARBOL_H_
#define _ARBOL_H_

#include "Constantes.h"
#include "Nodo.h"

template < typename Tipo >
class Arbol
{
    //Atributos
    private:
        Nodo<Tipo>* raiz;

    //Metodos
    public:
        Arbol();

        //PRE:
        //POS:
        void insertar(string clave, Tipo dato);

        //PRE:
        //POS:
        void mostrar_en_orden();

        //PRE:
        //POS:
        bool buscar_clave(string clave);

        //PRE:
        //POS:
        Tipo buscar_minimo();

        //PRE:
        //POS:
        Tipo buscar_maximo();

        //PRE:
        //POS:
        Tipo hijo(string clave);

        //PRE:
        //POS:
        Tipo padre(string clave);

        //PRE:
        //POS:
        void remover(string clave);

        //PRE:
        //POS:
        Nodo<Tipo>* obtener_raiz();

        //PRE:
        //POS:
        bool vacio();

        //PRE:
        //POS:
        void borrar_todo();

        ~Arbol<Tipo>();

    private:
        //PRE:
        //POS:
        Nodo<Tipo>* insertar(Nodo<Tipo>* nodo, string clave, Tipo dato); 
};

template < typename Tipo >
Arbol<Tipo>::Arbol()
{
    this -> raiz = NULL;
}

template < typename Tipo >
void Arbol<Tipo>::insertar(string clave, Tipo dato)
{   
    this -> raiz = insertar(this -> raiz, clave, dato);
}

template < typename Tipo >
void Arbol<Tipo>::mostrar_en_orden()
{
    mostrar_en_orden(this -> raiz);
}

template < typename Tipo >
bool Arbol<Tipo>::buscar_clave(string clave)
{
    Nodo<Tipo>* resultado = buscar_clave(this -> raiz, clave);
}

template < typename Tipo > 
Tipo Arbol<Tipo>::buscar_minimo()
{
    return buscar_minimo(this -> raiz);
}

template < typename Tipo >
Tipo Arbol<Tipo>::buscar_maximo()
{
    return buscar_maximo(this -> raiz);
}

template < typename Tipo >
Tipo Arbol<Tipo>::hijo(string clave)
{
    Nodo<Tipo>* clave_nodo = this -> buscar_clave(this -> raiz, clave);

    if (clave_nodo == NULL)
    {
        return -1;
    }
    else
    {
        return hijo(clave_nodo);
    }
}

template < typename Tipo >
Tipo Arbol<Tipo>::padre(string clave)
{
    Nodo<Tipo>* clave_nodo = this -> buscar_clave(this -> raiz, clave);

    if (clave_nodo == NULL)
    {
        return -1;
    }
    else
    {
        return padre(clave_nodo);
    }
}

template< typename Tipo >
void Arbol<Tipo>::remover(string clase)
{
    this -> raiz = remover(this -> raiz, clase);
}

template < typename Tipo > 
Nodo<Tipo>* Arbol<Tipo>::obtener_raiz()
{
    return this -> raiz;
}

template < typename Tipo >
bool Arbol<Tipo>::vacio()
{
    return this -> raiz == NULL;
}

template < typename Tipo >
void Arbol<Tipo>::borrar_todo()
{
    borrar_todo(this -> raiz);
}

template < typename Tipo >
Arbol<Tipo>::~Arbol()
{
    borrar_todo();
}

template < typename Tipo > 
Nodo<Tipo>* Arbol<Tipo>::insertar(Nodo<Tipo>* nodo, string clave, Tipo dato)
{
    if (nodo == NULL)
    {
        nodo = new Nodo<Tipo>(clave);
    }
    else if (clave > nodo -> obtener_clave(PRIMERA_CLAVE) && nodo -> obtener_cantidad_claves() < DOS_CLAVES)
    {
        nodo -> establecer_clave(clave, SEGUNDA_CLAVE);
    }
    else if (clave < nodo -> obtener_clave(PRIMERA_CLAVE) && nodo -> obtener_cantidad_claves() < DOS_CLAVES)
    {
        nodo -> cambiar_posicion(clave);
    }
    else if (clave < nodo -> obtener_clave(PRIMERA_CLAVE) && nodo -> obtener_cantidad_claves() == DOS_CLAVES)
    {
        nodo -> establecer_primera_via(insertar(nodo -> obtener_primera_via(), nodo));
        
    }
    else if (clave > nodo -> obtener_clave(PRIMERA_CLAVE) && nodo -> obtener_cantidad_claves() == DOS_CLAVES && clave <  nodo -> obtener_clave(SEGUNDA_CLAVE))
    {
        nodo -> establecer_primera_via(insertar(nodo -> obtener_segunda_via(), nodo));
    }
    else if (clave > nodo -> obtener_clave(PRIMERA_CLAVE) && nodo -> obtener_cantidad_claves() == DOS_CLAVES && nodo -> obtener_clave(SEGUNDA_CLAVE))
    {
        nodo -> establecer_primera_via(insertar(nodo -> obtener_tercera_via(), nodo));
    }
}

#endif