#ifndef _LISTA_H_
#define _LISTA_H_

#include "Nodo.h"

template < class Tipo >
class Lista
{
    //Atributos
    private:
        Nodo<Tipo>* primero;
        int cantidad;
        Nodo<Tipo>* cursor;

    public:
        //Constructor
        //PRE: -
        //PRE:  Inicializa primero = 0  (Puntero a NULL), cantidad = 0 y cursor = 0 (Puntero a NULL) 
        Lista();

        //PRE: - 
        //POS: Agrega dato en la posicion "posicion" 
        void alta(Tipo dato, int posicion);

        //PRE: - 
        //POS: Devuelve el dato que se encuentre en la posicion "posicion"
        Tipo consulta(int posicion);

        //PRE: La lista no debe estar vacia
        //POS: Da de baja el dato que se encurntra en la posicion "posicion"
        void baja(int posicion);

        //PRE: -
        //POS: Devuelve verdadero si la lista esta vacia y falso en caso contrario
        bool vacia();

        //PRE: - 
        //POS: Devuelve la cantidad de elementos que hay en la lista 
        int obtener_cantidad();

        //PRE: - 
        //POS: Devuelve verdadero si hay un elemento en la siguiente posicion y falso en caso contrario
        bool hay_siguiente();

        //PRE: - 
        //POS: Devuelve el dato y mueve el cursor al siguiente 
        Tipo siguiente();

        //PRE: No debe haber un elemento en la siguiente posicion 
        //POS: Pone el cursor al principio 
        void iniciar();

        //Destructor
        ~Lista();

    private:
        //PRE: -
        //POS: Devuelve un puntero al nodo que esta en posicion
        Nodo<Tipo>* obtener_nodo(int posicion);
};

template < typename Tipo >
Nodo<Tipo>* Lista<Tipo>::obtener_nodo(int posicion)
{
    Nodo<Tipo>* auxiliar = primero;

    for (int i = 1; i < posicion; i++)
    {
        auxiliar = auxiliar -> obtener_siguiente();
    } 
    return auxiliar;
}

#endif
