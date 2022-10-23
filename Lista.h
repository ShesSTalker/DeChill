#ifndef _LISTA_H_
#define _LISTA_H_

template <typename Tipo>

class Lista
{
    private:
        int cantidad;
        Tipo* primero;

    public:
        bool esta_vacia();

        int cuantos_tiene();
};

#endif
