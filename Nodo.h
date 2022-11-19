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
        int cantidad_hijos;
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
        //POS: devuelve la cantidad de hijos del nodo
        int obtener_cantidad_hijos();

        //PRE: - 
        //POS: devuelve verdadero si el nodo esta eliminado y falso en caso contrario
        bool esta_eliminado();
        
        //PRE: -
        //POS: establece la clave en la posicion "posicion" en el nodo
        void establecer_clave(string clave, int posicion);

        //PRE: -
        //POS: establece el puntero al hijo izquierdo y al nodo padre
        void establecer_hijo_izquierdo(Nodo<Tipo>* hijo_izquierdo, Nodo<Tipo>* padre);

        //PRE: -
        //POS: establece el puntero al hijo mediadno y al nodo padre
        void establecer_hijo_mediano(Nodo<Tipo>* hijo_mediano, Nodo<Tipo>* padre);

        //PRE: -
        //POS: establece el puntero al hijo derecho y al nodo padre
        void establecer_hijo_derecho(Nodo<Tipo>* hijo_derecho, Nodo<Tipo>* padre);

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
        //POS: devuelve el puntero al hijo izquierdo del nodo
        Nodo<Tipo>* obtener_hijo_izquierdo();

        //PRE: -
        //POS: devuelve el puntero al hijo mediano del nodo
        Nodo<Tipo>* obtener_hijo_mediano();

        //PRE: -
        //POS: devuelve el puntero al hijo derecho via del nodo
        Nodo<Tipo>* obtener_hijo_derecho();

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
        void dividir(Nodo<Tipo>* nodo, string nueva_clave, Tipo nuevo_dato);
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
int Nodo<Tipo>::obtener_cantidad_hijos()
{
    return cantidad_hijos;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_clave(string clave, int posicion)
{
    this -> claves[posicion] = clave;
    cantidad_claves++;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_hijo_izquierdo(Nodo<Tipo>* hijo_izquierdo, Nodo<Tipo>* padre)
{
    hijos[HIJO_IZQUIERDO] = hijo_izquierdo;
    this -> padre = padre;
    cantidad_hijos++;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_hijo_mediano(Nodo<Tipo>* hijo_mediano, Nodo<Tipo>* padre)
{
    hijos[HIJO_MEDIANO] = hijo_mediano;
    this -> padre = padre;
    cantidad_hijos++;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_hijo_derecho(Nodo<Tipo>* hijo_derecho, Nodo<Tipo>* padre)
{
    hijos[HIJO_DERECHO] = hijo_derecho;
    this -> padre = padre; 
    cantidad_hijos++;
}

template < typename Tipo > 
void Nodo<Tipo>::establecer_hijo_izquierdo(Nodo<Tipo>* hijo_izquierdo)
{
    hijos[HIJO_IZQUIERDO] = hijo_izquierdo; 
    cantidad_hijos++;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_hijo_mediano(Nodo<Tipo>* hijo_mediano)
{
    hijos[HIJO_MEDIANO] = hijo_mediano;
    cantidad_hijos++;
}

template < typename Tipo > 
void Nodo<Tipo>::establecer_hijo_derecho(Nodo<Tipo>* hijo_derecho)
{
    hijos[HIJO_DERECHO] = hijo_derecho;
    cantidad_hijos++;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_padre(Nodo<Tipo>* padre)
{
    this -> padre = padre;
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::obtener_hijo_izquierdo()
{
    return hijos[HIJO_IZQUIERDO];
}

template < typename Tipo > 
Nodo<Tipo>* Nodo<Tipo>::obtener_hijo_mediano()
{
    return hijos[HIJO_MEDIANO];
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::obtener_hijo_derecho()
{
    return hijos[HIJO_DERECHO];
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
    string auxiliar1;
    Tipo auxiliar2;

    if (es_hoja() && obtener_cantidad_claves < DOS_CLAVES)
    {
        auxiliar1 = claves[PRIMERA_CLAVE];
        claves[PRIMERA_CLAVE] = nueva_clave;
        claves[SEGUNDA_CLAVE] = auxiliar1;

        auxiliar2 = datos[PRIMERA_CLAVE];
        datos[PRIMERA_CLAVE] = dato;
        datos[SEGUNDA_CLAVE] = auxiliar2;
    }
    else 
    {
        if (nueva_clave < claves[PRIMERA_CLAVE] && nueva_clave < claves[SEGUNDA_CLAVE])
        {
            claves[CLAVE_EXTRA] = claves[SEGUNDA_CLAVE];
            claves[SEGUNDA_CLAVE] = claves[PRIMERA_CLAVE];
            claves[PRIMERA_CLAVE] = nueva_clave;

            datos[CLAVE_EXTRA] = datos[SEGUNDA_CLAVE];
            datos[SEGUNDA_CLAVE] = datos[PRIMERA_CLAVE];
            datos[PRIMERA_CLAVE] = nuevo_dato;
        }
        else if (nueva_clave < claves[PRIMERA_CLAVE] && nueva_clave > claves[SEGUNDA_CLAVE])
        {
            claves[CLAVE_EXTRA] = claves[SEGUNDA_CLAVE];
            claves[SEGUNDA_CLAVE] = nueva_clave;
            
            datos[CLAVE_EXTRA] = datos[SEGUNDA_CLAVE];
            datos[SEGUNDA_CLAVE] = nuevo_dato; 
        }
        else
        {
            claves[CLAVE_EXTRA] = nueva_clave;
            datos[CLAVE_EXTRA] = nuevo_dato;
        }
    }
}

template <typename Tipo >
void Nodo<Tipo>::dividir(Nodo<Tipo>* nodo, string nueva_clave, Tipo nuevo_dato)
{
    
}

#endif