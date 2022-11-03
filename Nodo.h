#ifndef _NODO_H_
#define _NODO_H_

template < typename Tipo >
class Nodo
{
    private:
        Tipo dato;
        Nodo* siguiente;

    public:
        //PRE: -
        //POS: crea un nodo con el dato ingresado y siguente en 0 (puntero a NULL).
        Nodo (Tipo dato);

        //PRE: -
        //POS: el puntero al siguiente nodo apunta al parámetro.
        void cambiar_siguiente (Nodo* puntero);
        
        //PRE: -
        //POS: devuelve el dato que contiene el nodo.
        Tipo obtener_dato();

        //PRE: - 
        //POS: devuelve el puntero al siguiente nodo.
        Nodo* obtener_siguiente(); 
};

template < typename Tipo >
Nodo<Tipo>::Nodo(Tipo dato)
{
    this -> dato = dato;
    this -> siguiente = 0;
}

template < typename Tipo >
void Nodo<Tipo>::cambiar_siguiente(Nodo* puntero)
{
    siguiente = puntero;
}

template < typename Tipo >
Tipo Nodo<Tipo>::obtener_dato()
{
    return dato;
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::obtener_siguiente() 
{
    return siguiente;
}

#endif