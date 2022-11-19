#ifndef _NODO_H_
#define _NODO_H_

#include "Constantes.h"

template < typename Tipo >
class Nodo
{
    //Atributos
    private:
        Nodo<Tipo>* padre;
        string claves[DOS_CLAVES + 1];
        Tipo datos[DOS_CLAVES + 1];
        Nodo<Tipo>* hijos[TRES_VIAS]; 
        int cantidad_claves;
        bool eliminado;
        bool es_hoja;

    //Metodos
    public:
        Nodo(string clave, Tipo dato);

        //PRE: - 
        //POS: devuelve el dato que contiene el nodo
        string obtener_clave(int posicion);

        //PRE: -
        //POS:
        Tipo obtener_dato(int posicion);

        //PRE: -
        //POS: devuelve la cantidad de claves del nodo
        int obtener_cantidad_claves();

        //PRE: - 
        //POS: devuelve verdadero si el nodo esta eliminado y falso en caso contrario
        bool esta_eliminado();

        //PRE: -
        //POS: establece el puntero al hijo izquierdo del nodo
        void establecer_hijo_izquierdo(Nodo<Tipo>* hijo_izquierdo);

        //PRE: -
        //POS: establece el puntero al hijo mediano del nodo
        void establecer_hijo_mediano(Nodo<Tipo>* hijo_mediano);

        //PRE: -
        //POS: establece el puntero al hijo derecho del nodo
        void establecer_hijo_derecho(Nodo<Tipo>* hijo_derecho);

        //PRE: -
        //POS: establece el puntero al nodo padre
        void establecer_padre(Nodo<Tipo>* padre);

        //PRE: -
        //POS: devuelve el puntero al hijo del nodo en la posicion "posicion"
        Nodo<Tipo>* obtener_hijo(int posicion);

        //PRE: -
        //POS: devuelve el puntero al padre
        Nodo<Tipo>* obtener_padre();

        //PRE: -
        //POS: devuelve verdadero si el nodo es hoja y falso en caso contrario
        bool es_hoja();

        //PRE: -
        //POS:
        void insertar_no_lleno(string nueva_clave, Tipo nuevo_dato);

        //PRE:
        //POS:
        void insertar_lleno(Nodo<Tipo>* nodo ,string nueva_clave, Tipo nuevo_dato);

        //PRE:
        //POS:
        void dividir(Nodo<Tipo>* nodo, string nueva_clave, Tipo nuevo_dato);

    private:
        void establecer_nueva_clave(string nueva_clave, int posicion);

        void establecer_nuevo_dato(Tipo nuevo_dato, int posicion);

        void cambiar_posiciones(string nueva_clave, Tipo nuevo_dato);
};

template < typename Tipo >
Nodo<Tipo>::Nodo(string clave, Tipo dato)
{
    this -> padre = nullptr;;
    this -> claves[PRIMERA_CLAVE] = clave; 
    this -> datos [PRIMERA_CLAVE] = dato;
    for (int i = 0; i < TRES_VIAS; i++)
        this -> hijos[i] = nullptr;
    this -> cantidad_claves = 1;
    this -> eliminado = false;
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
int Nodo<Tipo>::obtener_cantidad_claves()
{
    return cantidad_claves;
}

template < typename Tipo > 
void Nodo<Tipo>::establecer_hijo_izquierdo(Nodo<Tipo>* hijo_izquierdo)
{
    hijos[HIJO_IZQUIERDO] = hijo_izquierdo; 
}

template < typename Tipo >
void Nodo<Tipo>::establecer_hijo_mediano(Nodo<Tipo>* hijo_mediano)
{
    hijos[HIJO_MEDIANO] = hijo_mediano;
}

template < typename Tipo > 
void Nodo<Tipo>::establecer_hijo_derecho(Nodo<Tipo>* hijo_derecho)
{
    hijos[HIJO_DERECHO] = hijo_derecho;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_padre(Nodo<Tipo>* padre)
{
    this -> padre = padre;
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::obtener_hijo(int posicion)
{
    return hijos[posicion];
}

template < typename Tipo > 
Nodo<Tipo>* Nodo<Tipo>::obtener_padre()
{
    return padre;
}

template < typename Tipo >
bool Nodo<Tipo>::es_hoja()
{
    return (obtener_primera_via() == nullptr && obtener_hijo_mediano() == nullptr && obtener_tercera_via() == nullptr);
}

template < typename Tipo > 
void Nodo<Tipo>::insertar_no_lleno(string nueva_clave, Tipo nuevo_dato)
{
    if (es_hoja() && obtener_cantidad_claves() < DOS_CLAVES)
    {
       if (obtener_clave(PRIMERA_CLAVE) < nueva_clave)
       {
            establecer_nueva_clave(SEGUNDA_CLAVE);
            establecer_nuevo_dato(SEGUNDA_CLAVE);
            cantidad_claves++;
       }
       else
       {
            cambiar_posiciones(nueva_clave, nuevo_dato);
            cantidad_claves++;
       }
    }
    else 
    {
        
    }
}

template < typename Tipo > 
void Nodo<Tipo>::insertar_lleno(Nodo<Tipo>* nodo, string nueva_clave, Tipo nuevo_dato)
{
    if (obtener_clave(PRIMERA_CLAVE) < nueva_clave && obtener_clave(SEGUNDA_CLAVE) < nueva_clave)
        {
            establecer_nueva_clave(CLAVE_EXTRA) = obtener_clave(SEGUNDA_CLAVE);
            establecer_nueva_clave(SEGUNDA_CLAVE) = obtener_clave(PRIMERA_CLAVE);
            establecer_nueva_clave(PRIMERA_CLAVE) = nueva_clave;

            establecer_nuevo_dato(CLAVE_EXTRA) = obtener_dato(SEGUNDA_CLAVE);
            establecer_nuevo_dato(SEGUNDA_CLAVE) = obtener_dato(PRIMERA_CLAVE);
            establecer_nuevo_dato(PRIMERA_CLAVE) = nuevo_dato;
        }
        else if (obtener_clave(PRIMERA_CLAVE) > nueva_clave && obtener_clave(SEGUNDA_CLAVE) < nueva_clave)
        {
            establecer_nueva_clave(CLAVE_EXTRA) = obtener_clave(SEGUNDA_CLAVE);
            establecer_nueva_clave(SEGUNDA_CLAVE) = nueva_clave;
            
            establecer_nuevo_dato(CLAVE_EXTRA) = obtener_clave(SEGUNDA_CLAVE);
            establecer_nuevo_dato(SEGUNDA_CLAVE) = nuevo_dato; 
        }
        else
        {
            establecer_nueva_clave(CLAVE_EXTRA) = nueva_clave;
            
            establecer_nuevo_dato(CLAVE_EXTRA)= nuevo_dato;
        }
        dividir()
}

template <typename Tipo >
void Nodo<Tipo>::dividir(Nodo<Tipo>* nodo, string nueva_clave, Tipo nuevo_dato)
{
    if(nodo -> obtener_padre() == nullptr)
    {
        Nodo<Tipo>* izquierdo = new Nodo<Tipo>(nodo -> obtener_clave(PRIMERA_CLAVE), nodo -> obtener_dato(PRIMERA_CLAVE));
        izquierdo -> establecer_padre(nodo);
        nodo -> establecer_hijo_izquierdo(izquierdo);

        Nodo<Tipo>* derecho = new Nodo<Tipo>(nodo -> obtener_clave(CLAVE_EXTRA), nodo -> obtener_dato(CLAVE_EXTRA));
        derecho -> establecer_padre;
        nodo -> establecer_hijo_derecho(derecho);

        nodo -> establecer_nueva_clave(nodo -> obtener_clave(SEGUNDA_CLAVE), PRIMERA_CLAVE)
    }
}

template <typename Tipo >
void Nodo<Tipo>::establecer_nueva_clave(string nueva_clave, int posicion)
{
    claves[SEGUNDA_CLAVE] = nueva_clave;
}

template <typename Tipo >
void Nodo<Tipo>::establecer_nuevo_dato(Tipo nuevo_dato, int posicion)
{
    datos[SEGUNDA_CLAVE] = nuevo_dato;
}

template < typename Tipo >
void Nodo<Tipo>::cambiar_posiciones(string nueva_clave, Tipo nuevo_dato)
{
    string auxiliar1;
    Tipo auxiliar2;

    auxiliar1 = obtener_clave(PRIMERA_CLAVE);
    establecer_nueva_clave(nueva_clave, PRIMERA_CLAVE);
    establecer_nueva_clave(auxiliar1, SEGUNDA_CLAVE);

    auxiliar2 = obtener_dato(PRIMERA_CLAVE);
    establecer_nuevo_dato(nuevo_dato, PRIMERA_CLAVE);
    establecer_nuevo_dato(auxiliar2, SEGUNDA_CLAVE);
}

#endif