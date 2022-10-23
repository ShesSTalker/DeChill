#ifndef _NODO_H_
#define _NODO_H_

template < typename Tipo >
class Nodo
{
    //Atributos
    private:
        Tipo dato;
        Nodo* siguiente;

    //Metodos
    public:
        //PRE: -
        //POS: Crea un nodo con dato = dato y siguente = 0 (puntero a NULL)
        Nodo (Tipo dato);

        //PRE: -
        //POS: El puntero al siguiente nodo apunta a puntero
        void cambiar_siguiente (Nodo* puntero)
        
        //PRE: -
        //POS: Devuelve el dato que contiene el nodo
        Tipo obtener_dato();

        //PRE: - 
        //POS: Devuelve el puntero al siguiente nodo
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
Nodo* Nodo<Tipo>::obtener_siguiente() 
{
    return siguiente;
}

#endif