#ifndef _NODO_H_
#define _NODO_H_

#include <iostream>

using namespace std;

template < typename Tipo >
class Nodo
{
    //Atributos
    private:
        string* claves;
        Tipo* datos;
        Nodo<Tipo>* hijos;
        Nodo<Tipo>* padre;
        int maximo_claves;
        int cantidad_claves_usadas;

    //Metodos
    public:
        Nodo(int orden);

        bool nodo_lleno();

        string obtener_clave(int posicion);

        Tipo obtener_dato(int posicion);

        void establecer_clave(int posicion, string nueva_clave);

        Nodo<Tipo>* obtener_hijo(int posicion);

        void establecer_hijo(int posicion, Nodo<Tipo>* nuevo_hijo);

        int obtener_cantidad_claves_usadas();

        bool es_hoja();

        ~Nodo();
    private:
        void cambiar_cantidad_claves_usadas(int valor);
};

template < typename Tipo >
bool Nodo<Tipo>::es_hoja()
{
    bool hoja = true;
    for(int i = 0; i < obtener_cantidad_claves_usadas() + 1; i++)
    {
        if(obtener_hijo(i) != nullptr)
        {
            hoja = false;
            break;
        }
    }

    return hoja;
}

template < typename Tipo >
Nodo<Tipo>::~Nodo()
{
    int i;
    bool hoja = es_hoja();
    for(i = 0; i < obtener_cantidad_claves_usadas(); i++)
    {
        if(!hoja)
            delete obtener_hijo(i);

        delete obtener_dato(i);
    }

    if(!hoja)
        delete obtener_hijo(i);

    delete[] claves;
    delete[] datos;
    delete[] hijos;
}

template < typename Tipo >
Nodo<Tipo>::Nodo(int orden)
{
    maximo_claves = orden;
    claves = new string[orden];
    hijos = new Nodo<Tipo>[orden];
    for (int i = 0; i <= orden; i++)
    {
        hijos[i] = NULL;
    }
    cantidad_claves_usadas = 0;
}

template < typename Tipo >
bool Nodo<Tipo>::nodo_lleno()
{
    return(claves_usadas == maximo_claves - 1);
}

template < typename Tipo > 
string Nodo<Tipo>::obtener_clave(int posicion)
{
    return claves[posicion];
}

template < typename Tipo > 
Tipo Nodo<Tipo>::obtener_dato(int posicion)
{
    return datos[posicion];
}

template < typename Tipo >
void Nodo<Tipo>::establecer_clave(int posicion, string nueva_clave)
{
    claves[posicion] = nueva_clave;
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::obtener_hijo(int posicion)
{
    return hijos[posicion];
}

template < typename Tipo >
void Nodo<Tipo>::establecer_hijo(int posicion, Nodo<Tipo>* nuevo_hijo)
{
    hijos[posicion] = nuevo_hijo;
}

template < typename Tipo >
int Nodo<Tipo>::obtener_cantidad_claves_usadas()
{
    return cantidad_claves_usadas;
}

template < typename Tipo >
void Nodo<Tipo>::cambiar_cantidad_claves_usadas(int valor)
{
    cantidad_claves_usadas = valor;
}

#endif