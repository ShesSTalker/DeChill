#ifndef _NODO_H_
#define _NODO_H_

template < typename Tipo >

class Nodo
{
    //Atributos
    private:
        Tipo animal;
        Nodo* siguiente;

    //Metodos
    public:
        Nodo (Tipo animal);

        void cambiar_siguiente (Nodo* puntero)
        
        Tipo obtener_nodo();

        Tipo* obtener_siguiente(); 
};

template < typename Tipo >
Nodo<Tipo>::Nodo(Tipo animal)
{
    this -> animal = animal;
    this -> siguiente = 0;
}

template < typename Tipo >
void Nodo<Tipo>::cambiar_siguiente(Nodo* puntero)
{
    siguiente = puntero;
}

template < typename Tipo >
Tipo Nodo<Tipo>::obtener_nodo()
{
    return Tipo;
}

#endif