#ifndef _VECTOR_H_
#define _VECTOR_H_

template < class Tipo >
class Vector
{
    //Atributos
    private:
        int longitud;
        int cantidad;
        Tipo* elemento;

    //Metodos
    public:
        //Vector sin parametros
        //PRE: la cantidad debe ser 0
        //POS: crea un objeto Vector de longitud 0, cantidad 0 y elemento = 0;
        Vector();

        //Constructor con parametros
        //PRE: cantidad debe ser mayor a 0 
        //POS: crea un objeto Vector de longitud = cantidad 
        Vector(int cantidad);

        //PRE: 0 <= posicion < longitud
        //POS: carga elemento en la posicion "posicion". Si se inserta la posición "longitud", se redimensiona el Vector.
        void cargar(Tipo elemento, int posicion);

        //PRE: 0 <= posicion < longitud
        //POS: devuelve el elemento que es en la posicion "posicion"
        Tipo obtener_elemento(int posicion);

        //PRE: -
        //POS: devuelve la cantidad de elementos que contiene el vector
        int obtener_cantidad();

        //PRE: -
        //POS: devuelve la longitud del vector
        int obtener_longitud();

        //Desconstructor
        //Pre: -
        //Pos: libera la memoria pedida
        ~Vector(); 

    private:
        //PRE: longitud == posicon == cantidad
        //POS: redimenciona la longitud del vector 
        void redimensionar_vector();
};

template < class Tipo >
Vector<Tipo>::Vector()
{
    longitud = 0;
    cantidad = 0;
    elemento = 0;
}

template < class Tipo >
Vector<Tipo>::Vector(int longitud_inicial)
{
    cantidad = 0;
    longitud = longitud_inicial;
    elemento = new Tipo[longitud];
}

template < class Tipo >
void Vector<Tipo>::cargar(Tipo elemento, int posicion)
{
    if (longitud == posicion)
    {
        redimensionar_vector();
    }  

    this -> elemento[posicion] = elemento;
    cantidad++;
}

template < class Tipo >
Tipo Vector<Tipo>::obtener_elemento(int posicion)
{   
    Tipo elemento = 0;
    if (posicion < longitud){
        elemento=elemento[posicion];
    }
    return elemento;
}

template < class Tipo >
int Vector<Tipo>::obtener_cantidad()
{
    return cantidad;
}

template < class Tipo >
int Vector<Tipo>::obtener_longitud()
{
    return longitud;
}

template < class Tipo >
void Vector<Tipo>::redimensionar_vector() 
{
    int nueva_longitud = longitud + 1;
    Tipo* vector_auxiliar;
    vector_auxiliar = new Tipo[nueva_longitud];
    
    for (int i = 0; i < longitud; i++)
    {
        vector_auxiliar[i] = elemento[i];
    }
    
    delete [] elemento;
    this -> elemento = vector_auxiliar;
    longitud = nueva_longitud;
}

template < class Tipo >
Vector<Tipo>::~Vector()
{
    for(int i = 0; i < longitud; i++)
    {
        delete elemento[i];
    }

    delete[] elemento;
}

#endif