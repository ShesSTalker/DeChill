#ifndef _ARBOL_H_
#define _ARBOL_H_

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
        void insertar(Tipo clave);

        //PRE:
        //POS:
        void mostrar_en_orden();

        //PRE:
        //POS:
        bool buscar_clave(Tipo clave);

        //PRE:
        //POS:
        Tipo buscar_minimo();

        //PRE:
        //POS:
        Tipo buscar_maximo();

        //PRE:
        //POS:
        Tipo hijo(Tipo clave);

        //PRE:
        //POS:
        Tipo padre(Tipo clave);

        //PRE:
        //POS:
        void remover(Tipo clave);

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
        Nodo<Tipo>* insertar(Nodo<Tipo>* nodo, Tipo clave); 
};

template < typename Tipo >
Arbol<Tipo>::Arbol()
{
    this -> raiz = NULL;
}

template < typename Tipo >
void Arbol<Tipo>::insertar(Tipo clave)
{   
    this -> raiz = insetar(this -> raiz, clave);
}

template < typename Tipo >
void Arbol<Tipo>::mostrar_en_orden()
{
    mostrar_en_orden(this -> raiz);
}

template < typename Tipo >
bool Arbol<Tipo>::buscar_clave(Tipo clave)
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
Tipo Arbol<Tipo>::hijo(Tipo clave)
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
Tipo Arbol<Tipo>::padre(Tipo clave)
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
void Arbol<Tipo>::remover(Tipo clase)
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
Nodo<Tipo>* Arbol<Tipo>::insertar(Nodo<Tipo>* nodo, Tipo clave)
{
    
}

#endif