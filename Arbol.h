#ifndef _ARBOLB_H_
#define _ARBOLB_H_

#include "Nodo.h"

template < typename Tipo >
class ArbolB
{
    //Atributos
    private:
        Nodo<Tipo>* raiz;
        int orden;

    //Metodos
    public:
        ArbolB(int orden);

        bool arbol_vacio();

        Nodo<Tipo>* obtener_raiz();

        void establecer_raiz(Nodo<Tipo>* nueva_raiz);

        int obtener_orden();

        void insertar(string nueva_clave, Tipo nuevo_dato);

        Nodo<Tipo>* buscar(string clave, int &posicion);

        void mostrar();
    
    private:
        Nodo<Tipo>* buscar(Nodo<Tipo>* nodo_actual, string clave, int &posicion);

        bool buscar_nodo_actual(Nodo<Tipo>* nodo_actual, string clave, int &posicion);

        Nodo<Tipo>* insertar(Nodo<Tipo>* raiz, string nueva_clave, Tipo nuevo_dato);

        bool empujar(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* &nuevo_nodo, string nueva_clave, Tipo nuevo_dato, string &pivote); 

        void meter_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* rama_derecha, string nueva_clave, Tipo nuevo_dato, int posicion);

        void dividir_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* nodo, string &pivote, Tipo nuevo_dato, int posicion);
};

#endif

template < typename Tipo >
ArbolB<Tipo>::ArbolB(int orden)
{
    raiz = NULL;
    this -> orden = orden;
}

template < typename Tipo >
bool ArbolB<Tipo>::arbol_vacio()
{
    return raiz == NULL;
}

template < typename Tipo >
Nodo<Tipo>* ArbolB <Tipo>::obtener_raiz()
{
    return raiz;
}

template < typename Tipo >
void ArbolB<Tipo>::establecer_raiz(Nodo<Tipo>* nueva_raiz)
{
    raiz = nueva_raiz;
}

template < typename Tipo >
int ArbolB<Tipo>::obtener_orden()
{
    return orden;
}

template < typename Tipo >
Nodo<Tipo>* ArbolB<Tipo>::buscar(string clave, int &posicion)
{
    return buscar(raiz, clave, posicion);
}

template < typename Tipo > 
void ArbolB<Tipo>::mostrar()
{
    mostrar
}

template < typename Tipo >
void ArbolB<Tipo>::insertar(string nueva_clave, Tipo nuevo_dato)
{
    raiz = insertar(raiz, nueva_clave, nuevo_dato);
}

template < typename Tipo > 
Nodo<Tipo>* ArbolB<Tipo>::insertar(Nodo<Tipo>* raiz, string nueva_clave, Tipo nuevo_dato)
{
    bool sube_arriba;
    string pivote;
    Nodo<Tipo>* nodo;

    if(obtener_raiz() == NULL)
    {
        raiz = new Nodo<Tipo>(obtener_orden());
    }

    sube_arriba = empujar(raiz, nodo, nueva_clave, nuevo_dato, pivote);
    if (sube_arriba)
    {
        Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(grado);
        nuevo_nodo -> cuenta(1);// unsa sola clave
        nuevo_nodo -> clave(1, pivote);
        nuevo_nodo -> rama(0, raiz);//claves mayores
        nuevo_nodo -> rama(1, nodo);//claves menores
        raiz = nuevo_nodo;
    }
    return raiz;
}   

template < typename Tipo > 
Nodo<Tipo>* ArbolB<Tipo>::buscar(Nodo<Tipo>* nodo_actual, string clave, int &posicion)
{
    bool encontrado;

    if(nodo_actual == NULL)
    {
        return NULL;
    }
    else
    {
        encontrado = buscar_nodo_actual(nodo_actual, clave, posicion);
        
        if (encontrado)
        {
            return nodo_actual;
        }
        else 
        {
            return buscar(nodo_actual -> obtener_hijo(posicion), clave, posicion);
        }
    }
}

template < typename Tipo >
bool ArbolB<Tipo>::buscar_nodo_actual(Nodo<Tipo>* nodo_actual, string clave, int &posicion)
{
    int i = nodo_actual -> obtener_cantidad_claves_usadas();
    bool encontrado = false;

    if(clave < nodo_actual -> obtener_clave(0))
    {       
        posicion = 0;
    }
    else if(clave > nodo_actual -> obtener_clave(i - 1))
    {
        posicion = i;
    }
    else
    {
        i -= 1;

        while(clave < nodo_actual -> obtener_clave(i) && i > 0 && !encontrado)
        {
            if (clave == nodo_actual -> obtener_clave(i))
            {
                encontrado = true;
            }
             i--;
        }
        posicion = i + 1;
    }
    
    return encontrado;
}

template < typename Tipo >
bool ArbolB<Tipo>::empujar(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* &nuevo_nodo, string nueva_clave, Tipo nuevo_dato, string &pivote)
{
    int posicion;
    bool encontrado, sube_arriba = false;

    if(nodo_actual == NULL)
    {
        sube_arriba = true;
        pivote = nueva_clave;
        nuevo_nodo = NULL;
    }
    else
    {
        encontrado = buscar_nodo_actual(nodo_actual, nueva_clave, posicion);
  
        sube_arriba = empujar(nodo_actual -> obtener_hijo(posicion), nuevo_nodo, nueva_clave, nuevo_dato, pivote);

        if(sube_arriba)
        {
            if(nodo_actual -> nodo_lleno())
            {
                dividir_nodo(nodo_actual, nuevo_nodo, pivote, posicion);
            } 
            else
            {
                meter_nodo(nodo_actual, nuevo_nodo, pivote, nuevo_dato, posicion);
                sube_arriba = false;
            } 
        }
    }
    return sube_arriba;
}

template < typename Tipo >
void ArbolB<Tipo>::meter_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* rama_derecha, string nueva_clave, Tipo nuevo_dato, int posicion)
{
    for(int i = nodo_actual -> obtener_cantidad_claves_usadas(); i > posicion; i--)
    {
        nodo_actual -> establecer_clave(i, nodo_actual -> obtener_clave(i - 1));
        nodo_actual -> establecer_dato(i, nodo_actual -> obtenener_dato(i - 1));
        nodo_actual -> establecer_hijo(i, nodo_actual -> obtener_hijo(i - 1));
    }

    nodo_actual -> establecer_clave(posicion, nueva_clave);
    nodo_actual -> establecer_dato(posicion, nuevo_dato);
    nodo_actual -> establecer_hijo(posicion, rama_derecha);

    nodo_actual -> cambiar_cantidad_claves_usadas(nodo_actual -> obtener_cantidad_claves_usadas() + 1);
}

template < typename Tipo >
void ArbolB<Tipo>::dividir_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* nodo, string &pivote, Tipo nuevo_dato, int posicion)
{
    int posicion_nodo, posicion_pivote;
    Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(obtener_orden());

    posicion_nodo = posicion;

    if (obtener_orden() % 2 == 0)
    {
        posicion_pivote = (obtener_orden() / 2) - 1;
    }
    else
    {
        posicion_pivote = (obtener_orden() / 2);
    }

    for(int i = posicion_pivote + 1; i < obtener_orden(); i++)
    {
        nuevo_nodo -> establecer_clave(0, nodo_actual -> obtener_clave(i));
        nuevo_nodo -> establecer_dato(0, nodo_actual -> obtener_dato(i));
        nuevo_dato -> establecer_hijo(0, nodo_actual -> obtener_hijo(i));
    }
    nuevo_nodo -> cambiar_cantidad_claves_usadas((obtener_orden() - 1) - posicion_pivote);
    
    if(posicion_nodo <= obtener_orden() / 2)
    {
        meter_nodo(nodo_actual, nodo, pivote, nuevo_dato, posicion);
    }
    else
    {
        posicion = posicion_nodo - posicion_pivote;
        meter_nodo(nuevo_nodo, nodo, pivote, nuevo_dato, posicion);
    }
    pivote = nodo_actual -> obtener_clave(nodo_actual -> obtener_cantidad_claves_usadas());
    nuevo_nodo -> establecer_hijo(0, nodo_actual -> obtener_hijo(nodo_actual -> obtener_cantidad_claves_usadas()));
    nodo_actual -> cambiar_cantidad_claves_usadas(nodo_actual -> obtener_cantidad_claves_usadas() - 1);
    nodo = nuevo_nodo; 
}