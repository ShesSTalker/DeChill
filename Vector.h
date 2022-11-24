#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "Constantes.h"

template < class Tipo >
class Vector
{
    //Atributos
    private:
        int longitud;
        Tipo* elementos;

    //Metodos
    public:
        //Vector sin parametros
        //PRE: la cantidad debe ser 0
        //POS: crea un objeto Vector de longitud 0, cantidad 0 y elemento = 0;
        Vector();

        //Constructor con parametros
        //PRE: cantidad debe ser mayor a 0 
        //POS: crea un objeto Vector de longitud = longitud_inicial 
        Vector(int longitud_inicial);

        //PRE: 0 <= posicion < longitud
        //POS: carga elemento en la posicion "posicion". Si se inserta la posición "longitud", se redimensiona el Vector.
        void cargar(Tipo cargado, int posicion);

        //PRE: 0 <= posicion < longitud
        //POS: devuelve el elemento que es en la posicion "posicion"
        Tipo obtener_elemento(int posicion);

        //PRE: -
        //POS: devuelve la longitud del vector
        int obtener_longitud();

        //PRE: -
        //POS: devuelve la posicion del elemento buscado
        int obtener_posicion(Tipo buscado);

        //Desconstructor
        //Pre: -
        //Pos: libera la memoria pedida
        ~Vector(); 

    private:
        //PRE: longitud == posicion
        //POS: redimensiona la longitud del vector 
        void redimensionar_vector();
};

template < class Tipo >
Vector<Tipo>::Vector()
{
    longitud = 0;
    elementos = 0;
}

template < class Tipo >
Vector<Tipo>::Vector(int longitud_inicial)
{
    longitud = longitud_inicial;
    elementos = new Tipo[longitud];
}

template < class Tipo >
void Vector<Tipo>::cargar(Tipo cargado, int posicion)
{
    if (longitud == posicion)
    {
        redimensionar_vector();
    }  

    this -> elementos[posicion] = cargado;
}

template < class Tipo >
Tipo Vector<Tipo>::obtener_elemento(int posicion)
{  
    Tipo elemento;

    if (posicion < longitud){
        elemento=elementos[posicion];
    }
    return elemento;
}

template < class Tipo >
int Vector<Tipo>::obtener_longitud()
{
    return longitud;
}

template < class Tipo >
int Vector<Tipo>::obtener_posicion(Tipo buscado){
    int i = 0;
    bool encontro =false;
    while (i < longitud && !encontro){
        if (elementos[i]==buscado){
            encontro=true;
        }else{
            i++;
        }
    }
    if(!encontro){
        return NO_ENCONTRO;
    }
    
    return i;
}
template < class Tipo >
void Vector<Tipo>::redimensionar_vector() 
{
    int nueva_longitud = longitud + 1;
    Tipo* vector_auxiliar;
    vector_auxiliar = new Tipo[nueva_longitud];
    
    for (int i = 0; i < longitud; i++)
    {
        vector_auxiliar[i] = elementos[i];
    }
    
    delete [] elementos;
    this -> elementos = vector_auxiliar;
    longitud = nueva_longitud;
}

template < class Tipo >
Vector<Tipo>::~Vector()
{
    for (int i = 0; i < longitud,i++){
        delete elementos[i];

    }
    
    delete[] elementos;
}

#endif