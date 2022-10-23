#ifndef _LISTA_H_
#define _LISTA_H_

template <typename Tipo>

class Lista
{
    private:
        int cantidad;
        Tipo* primero;

    public:
        Lista();
        
        bool esta_vacia();

        int cuantos_tiene();

        Tipo consulta(int posicion);
};

template <typename Tipo>
Tipo consulta(int posicion)
{
    return nullptr;
};

#endif
