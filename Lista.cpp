#include "Lista.h"

template < typename Tipo >
Lista<Tipo>::Lista()
{
    primero = 0;
    cantidad = 0;
    cursor = 0; 
}

template < typename Tipo >
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

template < typename Tipo >
Tipo Lista<Tipo>::consulta(int posicion)
{
    Nodo<Tipo>* nodo = obtener_nodo(posicion);
    return (nodo -> obtener_dato());
}

template < typename Tipo >
void Lista<Tipo>::baja(int posicion)
{
    Nodo<Tipo>* borrar = primero;
    
    if(posicion == 1)
    {
        primero = borrar -> obtener_siguiente();
    }
    else
    {
        Nodo<Tipo>* anterior = obtener_nodo(posicion - 1);
        borrar  = anterior -> obtener_siguiente();
        anterior -> cambiar_siguiente(borrar -> obtener_siguiente());
    }
    delete borrar;
    cantidad --;
}

template < typename Tipo >
bool Lista<Tipo>::vacia()
{
    return (cantidad == 0);
}

template < typename Tipo >
int Lista<Tipo>::obtener_cantidad()
{
    return cantidad;
}

template < typename Tipo >
bool Lista<Tipo>::hay_siguiente()
{
    return (cursor != 0);
}

template < typename Tipo >
Tipo Lista<Tipo>::siguiente()
{
    Tipo dato = cursor -> obtener_dato();
    cursor = cursor -> obtener_siguiente();
    return dato;
}

template < typename Tipo >
void Lista<Tipo>::iniciar()
{
    cursor = primero;
}

template < typename Tipo >
Lista<Tipo>::~Lista()
{
    while (!vacia())
    {
        baja(1);
    }
}

