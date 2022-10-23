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
        
        Tipo obtener_animal();

        Tipo* obtener_siguiente(); 
};

template <typename Tipo>
Tipo Nodo<Tipo>::obtener_animal()
{

}

#endif