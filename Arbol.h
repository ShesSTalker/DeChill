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
};

#endif