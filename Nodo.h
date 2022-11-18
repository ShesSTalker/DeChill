#ifndef _NODO_H_
#define _NODO_H_

#include "Constantes.h"

template < typename Tipo >
class Nodo
{
    //Atributos
    private:
        Nodo<Tipo>* padre;
        string claves[DOS_CLAVES];
        Tipo datos[DOS_CLAVES];
        Nodo<Tipo>* vias[TRES_VIAS]; 
        int cantidad_claves;
        int cantidad_vias;
        bool eliminado;
        bool es_hoja;

    //Metodos
    public:
        Nodo(string clave, Tipo dato);

        //PRE: - 
        //POS: devuelve el dato que contiene el nodo
        string obtener_clave(int posicion);

        //PRE: -
        //POS: devuelve la cantidad de claves del nodo
        int obtener_cantidad_claves();

        //PRE: - 
        //POS: devuelve la cantidad de vias del nodo
        int obtener_cantidad_vias();

        //PRE: - 
        //POS: devuelve verdadero si el nodo esta eliminado y falso en caso contrario
        bool esta_eliminado();
        
        //PRE: -
        //POS: establece la clave en la posicion "posicion" en el nodo
        void establecer_clave(string clave, int posicion);

        //PRE: -
        //POS: establece el puntero a la via primera y al nodo padre
        void establecer_primera_via(Nodo<Tipo>* primera_via, Nodo<Tipo>* padre);

        //PRE: -
        //POS: establece el puntero a la via segunda y al nodo padre
        void establecer_segunda_via(Nodo<Tipo>* segunda_via, Nodo<Tipo>* padre);

        //PRE: -
        //POS: establece el puntero a la via tercera y al nodo padre
        void establecer_tercera_via(Nodo<Tipo>* segunda_via, Nodo<Tipo>* padre);

        //PRE: -
        //POS: establece el puntero a la primera via del nodo
        void establecer_primera_via(Nodo<Tipo>* primera_via);

        //PRE: -
        //POS: establece el puntero a la segunda via del nodo
        void establecer_segunda_via(Nodo<Tipo>* segunda_via);

        //PRE: -
        //POS: establece el puntero a la tercera via del nodo
        void establecer_tercera_via(Nodo<Tipo>* tercera_via);

        //PRE: -
        //POS: establece el puntero al nodo padre
        void establecer_padre(Nodo<Tipo>* padre);

        //PRE: -
        //POS: devuelve el puntero a la primera via del nodo
        Nodo<Tipo>* obtener_primera_via();

        //PRE: -
        //POS: devuelve el puntero a la segunda via del nodo
        Nodo<Tipo>* obtener_segunda_via();

        //PRE: -
        //POS: devuelve el puntero a la tercera via del nodo
        Nodo<Tipo>* obtener_tercera_via();

        //PRE: -
        //POS: devuelve el puntero al padre
        Nodo<Tipo>* obtener_padre();

        //PRE: -
        //POS: devuelve verdadero si el nodo es hoja y falso en caso contrario
        bool es_hoja();

        //PRE: -
        //POS: devuelve verdadero si el nodo solo tiene hijo derecho y falso en caso contrario
        bool solo_primera_via();

        //PRE: -
        //POS: devuelve verdaderro si el nodo solo tiene hizo izquierdo y falso en caso contrario
        bool solo_segunda_via();

        //PRE: -
        //POS:
        void Nodo<Tipo>::insertar_no_lleno(string nueva_clave, Tipo dato);
};

template < typename Tipo >
Nodo<Tipo>::Nodo(string clave, Tipo dato)
{
    this -> padre = NULL;
    this -> claves[PRIMERA_CLAVE] = clave; 
    this -> datos [PRIMERA_CLAVE] = dato;
    for (int i = 0; i < TRES_VIAS; i++)
        this -> vias[i] = NULL;
    this -> cantidad_claves = 1;
    this -> cantidad_vias = 0;
    this -> eliminado = false;
}

template < typename Tipo >
string Nodo<Tipo>::obtener_clave(int posicion)
{
    return claves[posicion];
}

template < typename Tipo >
int Nodo<Tipo>::obtener_cantidad_claves()
{
    return cantidad_claves;
}

template < typename Tipo >
int Nodo<Tipo>::obtener_cantidad_vias()
{
    return cantidad_vias;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_clave(string clave, int posicion)
{
    this -> claves[posicion] = clave;
    cantidad_claves++;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_primera_via(Nodo<Tipo>* primera_via, Nodo<Tipo>* padre)
{
    vias[PRIMERA_VIA] = primera_via;
    this -> padre = padre;
    cantidad_vias++;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_segunda_via(Nodo<Tipo>* segunda_via, Nodo<Tipo>* padre)
{
    vista[SEGUNDA_CLAVE] = segunda_via;
    this -> padre = padre;
    cantidad_vias++;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_tercera_via(Nodo<Tipo>* tercera_via, Nodo<Tipo>* padre)
{
    vias[TERCERA_VIA] = tercera_via;
    this -> padre = padre; 
    cantidad_vias++;
}

template < typename Tipo > 
void Nodo<Tipo>::establecer_primera_via(Nodo<Tipo>* primera_via)
{
    vias[PRIMERA_VIA] = primera_via; 
    cantidad_vias++;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_segunda_via(Nodo<Tipo>* segunda_via)
{
    vias[SEGUNDA_VIA] = segunda_via;
    cantidad_vias++;
}

template < typename Tipo > 
void Nodo<Tipo>::establecer_tercera_via(Nodo<Tipo>* tercera_via)
{
    vias[TERCERA_VIA] = tercera_via;
    cantidad_vias++;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_padre(Nodo<Tipo>* padre)
{
    this -> padre = padre;
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::obtener_primera_via()
{
    return vias[PRIMERA_VIA];
}

template < typename Tipo > 
Nodo<Tipo>* Nodo<Tipo>::obtener_segunda_via()
{
    return vias[SEGUNDA_VIA];
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::obtener_tercera_via()
{
    return vias[TERCERA_VIA];
}

template < typename Tipo > 
Nodo<Tipo>* Nodo<Tipo>::obtener_padre()
{
    return padre;
}

template < typename Tipo >
bool Nodo<Tipo>::es_hoja()
{
    return (obtener_primera_via() == NULL && obtener_segunda_via() == NULL && obtener_tercera_via() == NULL);
}

template < typename Tipo >
bool Nodo<Tipo>::solo_primera_via()
{
    return (obtener_primera_via() != NULL && obtener_segunda_via() == NULL && obtener_tercera_via() != NULL);
}

template < typename Tipo >
bool Nodo<Tipo>::solo_segunda_via()
{
    return (obtener_primera_via() == NULL && obtener_segunda_via() != NULL && obtener_tercera_via() == NULL);
}

template < typename Tipo > 
void Nodo<Tipo>::insertar_no_lleno(string nueva_clave, Tipo dato)
{
    string auxiliar1;
    Tipo auxiliar2;

    auxiliar1 = claves[PRIMERA_CLAVE];
    claves[PRIMERA_CLAVE] = clave;
    claves[SEGUNDA_CLAVE] = auxiliar1;

    auxiliar2 = datos[PRIMERA_CLAVE];
    datos[PRIMERA_CLAVE] = dato;
    datos[SEGUNDA_CLAVE] = auxiliar2;
}

#endif