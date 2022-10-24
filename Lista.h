#ifndef _LISTA_H_
#define _LISTA_H_

#include "Nodo.h"

template <typename Tipo>
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
        bool vacia()

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
        Nodo* obtener_nodo(int posicion);
};

template <typename Tipo>
Lista<Tipo>::Lista()
{
    primero = 0;
    cantidad = 0;
    cursor = 0; 
}

template <typename Tipo>
void Lista<Tipo>::alta(Tipo dato, int posicion)
{
    Nodo<Tipo>* nuevo = new Nodo<Tipo>(dato);
    Nodo<Tipo>* siguiente =nuevo;

    if (posicion == 1)
    {
        primero = nuevo;
    }
    else
    {
        Nodo<Tipo>* anterior = obtener_nodo(posicion - 1);
        siguiente = anterior -> anterior -> obtener_siguiente();
        anterior -> cambiar_siguiente(nuevo);
    }
    nuevo -> cambiar_siguiente(siguiente);
    cantidad++;
}

template <typename Tipo>
Tipo Lista<Tipo>::consulta(int posicion)
{
    Nodo<Tipo>* nodo = obtener_nodo(posicion);
    return (nodo -> obtener_dato());
}

#endif