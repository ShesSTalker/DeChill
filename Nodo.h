#ifndef _NODO_H_
#define _NODO_H_

#include <iostream>
#include <string>
#include "Constantes.h"

using namespace std;

template < typename Tipo >
class Nodo
{
    //Atributos
    private:
        string* claves;
        Tipo** datos;
        Nodo<Tipo>** hijos;
        int maximo_claves;
        int cantidad_claves_usadas;

    //Metodos
    public:
        //Constrctor con parametro, inicializa los atributos e inicializa el orden del nodo.
        Nodo(int orden);

        //PRE: - 
        //POS: devuelve verdadero si el nodo esta lleno y falso en caso contrario.
        bool nodo_lleno();

        //PRE: -
        //POS: devuelve verdadero si el hijo axiliar esta siendo ocupado y falso en caso contrario.
        bool hijo_auxiliar_ocupado();

        //PRE: -
        //POS: devuelve la clave que se encuentra en la posicion "posicion".
        string obtener_clave(int posicion);

        //PRE: -
        //POS: devuelve el dato que se encuentra en la posicion del "posicion".
        Tipo* obtener_dato(int posicion);

        //PRE: -
        //POS: devuelve el hijo en la posicion "posicion".
        Nodo<Tipo>* obtener_hijo(int posicion);

        //PRE: -
        //POS: guarda nueva_clave en la posicion "posicion".
        void establecer_clave(int posicion, string nueva_clave);

        //PRE: -
        //POS: guarda nuevo_dato en la posicion "posicion".
        void establecer_dato(int posicion, Tipo* nuevo_dato);

        //PRE: -
        //POS: guarda nuevo_hijo en la posicion "posicion".
        void establecer_hijo(int posicion, Nodo<Tipo>* nuevo_hijo);

        //PRE: -
        //POS: devuelve la cantidad de claves en el nodo.
        int obtener_cantidad_claves_usadas();

        //PRE: -
        //POS: cambia la cantidad de claves en el nodo por "valor".
        void cambiar_cantidad_claves_usadas(int valor);

        //PRE: -
        //POS: devuelve verdadero si el nodo es hoja y falso en caso contrario.
        bool es_hoja();

        //Destructor.
        ~Nodo();
};

template < typename Tipo >
Nodo<Tipo>::Nodo(int orden)
{
    maximo_claves = orden;
    claves = new string[orden];
    datos = new Tipo*[orden];
    hijos = new Nodo<Tipo>*[orden + 1];
    for(int i = 0; i < orden; i++)
    {
        claves[i] = "";
        datos[i] = NULL;
    }
    for(int j = 0; j < orden + 1; j++)
    {
        hijos[j] = NULL; 
    }
    cantidad_claves_usadas = 0;
}

template < typename Tipo >
bool Nodo<Tipo>::nodo_lleno()
{
    return(obtener_cantidad_claves_usadas() == maximo_claves - 1);
}

template < typename Tipo >
bool Nodo<Tipo>::hijo_auxiliar_ocupado()
{
    return (hijos[maximo_claves] != NULL);
}

template < typename Tipo > 
string Nodo<Tipo>::obtener_clave(int posicion)
{
    return claves[posicion];
}

template < typename Tipo > 
Tipo* Nodo<Tipo>::obtener_dato(int posicion)
{
    return datos[posicion];
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::obtener_hijo(int posicion)
{
    return hijos[posicion];
}

template < typename Tipo >
void Nodo<Tipo>::establecer_clave(int posicion, string nueva_clave)
{
    claves[posicion] = nueva_clave;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_dato(int posicion, Tipo* nuevo_dato)
{
    datos[posicion] = nuevo_dato;
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

template < typename Tipo >
bool Nodo<Tipo>::es_hoja()
{
    bool hoja = true;
    int i = 0;

    while(i < obtener_cantidad_claves_usadas() + 1  && hoja)
    {
        if(obtener_hijo(i) != NULL)
        {
            hoja = false;
        }
        i++;
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
        {
            delete obtener_hijo(i); 
        }
        delete obtener_dato(i);
    }

    if(!hoja)
    {
        delete obtener_hijo(i);
    }

    delete[] claves;
    delete[] datos;
    delete[] hijos;
}

#endif