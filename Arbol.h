#ifndef _ARBOLB_H_
#define _ARBOLB_H_

#include "Nodo.h"

using namespace std;

template < typename Tipo >
class ArbolB
{
    //Atributos
    private:
        Nodo<Tipo>* raiz;
        int orden;

    //Metodos
    public:
        //Constructor con parametros, inicializa el puntero raiz en NULL y el orden del Arbol B.
        ArbolB(int orden);

        //PRE: -
        //POS: devuelve true si el arbol esta vacio o falso en caso contrario.
        bool arbol_vacio();

        //PRE: -
        //POS: devuelve el puntero raiz.
        Nodo<Tipo>* obtener_raiz();

        //PRE:
        //POS:
        void establecer_raiz(Nodo<Tipo>* nueva_raiz);

        //PRE: -
        //POS: devuelve el orden (cantidad maxima de vias/hijos) del Arbol B.
        int obtener_orden();

        //PRE: -
        //POS:
        void insertar(string nueva_clave, Tipo* nuevo_dato);

        //PRE: - 
        //POS: Busca el nombre del animal que buscamos mediante la clave (nombre) y nos devuelve el nodo y la posicion en la que se encuentra.
        Nodo<Tipo>* buscar(string clave, int &posicion);

        //PRE: -
        //POS: lista los animales almacenados en el Arbol B de manera creciente segun la clave (nombre).
        void listar_creciente();

        //Destructor. 
        ~ArbolB();
    
    private:
        Nodo<Tipo>* buscar(Nodo<Tipo>* nodo_actual, string clave, int &posicion);

        bool buscar_nodo_actual(Nodo<Tipo>* nodo_actual, string clave, int &posicion);

        Nodo<Tipo>* insertar(Nodo<Tipo>* raiz, string nueva_clave, Tipo* nuevo_dato);

        bool empujar(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* &nuevo_nodo, string nueva_clave, Tipo* nuevo_dato, string &pivote); 

        void meter_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* hijo, string nueva_clave, Tipo* nuevo_dato, int posicion);

        void dividir_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* nodo, string &pivote, Tipo* nuevo_dato, int posicion);

        void in_orden(Nodo<Tipo>* nodo_actual);
};

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
void ArbolB<Tipo>::insertar(string nueva_clave, Tipo* nuevo_dato)
{
    raiz = insertar(raiz, nueva_clave, nuevo_dato);
}

template < typename Tipo > 
Nodo<Tipo>* ArbolB<Tipo>::insertar(Nodo<Tipo>* raiz, string nueva_clave, Tipo* nuevo_dato)
{
    bool sube_arriba;
    string pivote;
    Nodo<Tipo>* nodo;

    if(raiz == NULL)
    {
        raiz = new Nodo<Tipo>(obtener_orden());
        meter_nodo(raiz, NULL, nueva_clave, nuevo_dato, 0)
    }

    sube_arriba = empujar(raiz, nodo, nueva_clave, nuevo_dato, pivote);
    
    if (sube_arriba)
    { 
        Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(obtener_orden());
        nuevo_nodo -> cambiar_cantidad_claves_usadas(1);  // cuenta(1)
        nuevo_nodo -> establecer_clave(PRIMERA_CLAVE, pivote);        // clave(1, mediana)
        nuevo_nodo -> establecer_hijo(PRIMER_HIJO, raiz);           // rama(0, raiz)
        nuevo_nodo -> establecer_hijo(SEGUNDO_HIJO, nodo);           // rama(1, nodo)
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
void ArbolB<Tipo>::listar_creciente()
{
    in_orden(raiz);
}

template < typename Tipo >
bool ArbolB<Tipo>::buscar_nodo_actual(Nodo<Tipo>* nodo_actual, string clave, int &posicion)
{
    int i = nodo_actual -> obtener_cantidad_claves_usadas();
    bool encontrado = false;

    if(clave < nodo_actual -> obtener_clave(PRIMERA_CLAVE))
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
bool ArbolB<Tipo>::empujar(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* &nuevo_nodo, string nueva_clave, Tipo* nuevo_dato, string &pivote)
{
    int posicion;
    bool sube_arriba = false;

    if(nodo_actual == NULL)
    {
        sube_arriba = true;
        pivote = nueva_clave;
        nuevo_nodo = NULL;
    }
    else
    {
        buscar_nodo_actual(nodo_actual, nueva_clave, posicion);
  
        sube_arriba = empujar(nodo_actual -> obtener_hijo(posicion), nuevo_nodo, nueva_clave, nuevo_dato, pivote);

        if(sube_arriba)
        {
            if(nodo_actual -> nodo_lleno())
            {
                meter_nodo(nodo_actual, nuevo_nodo, pivote, nuevo_dato, posicion);
                dividir_nodo(nodo_actual, nuevo_nodo, pivote, nuevo_dato, posicion);
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
void ArbolB<Tipo>::meter_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* hijo, string nueva_clave, Tipo* nuevo_dato, int posicion)
{
    for(int i = nodo_actual -> obtener_cantidad_claves_usadas(); i > posicion; i--)
    {
        nodo_actual -> establecer_clave(i, nodo_actual -> obtener_clave(i - 1));
        nodo_actual -> establecer_dato(i, nodo_actual -> obtener_dato(i - 1));
        nodo_actual -> establecer_hijo(i, nodo_actual -> obtener_hijo(i - 1));
    }

    nodo_actual -> establecer_clave(posicion, nueva_clave);
    nodo_actual -> establecer_dato(posicion, nuevo_dato);
    nodo_actual -> establecer_hijo(posicion, hijo);

    nodo_actual -> cambiar_cantidad_claves_usadas(nodo_actual -> obtener_cantidad_claves_usadas() + 1);
}

template < typename Tipo >
void ArbolB<Tipo>::dividir_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* nodo, string &pivote, Tipo* nuevo_dato, int posicion)
{
    int posicion_ideal, posicion_medio;
    Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(obtener_orden());

    posicion_ideal = posicion;

    if (obtener_orden() % 2 == 0)
    {
        posicion_medio = (obtener_orden() / 2) - 1;
    }
    else
    {
        posicion_medio = (obtener_orden() / 2);
    }

    for(int i = posicion_medio + 1; i < obtener_orden(); i++)
    {
        nuevo_nodo -> establecer_clave(i - posicion_medio, nodo_actual -> obtener_clave(i));
        nuevo_nodo -> establecer_dato(i - posicion_medio, nodo_actual -> obtener_dato(i));
        nuevo_nodo -> establecer_hijo(i - posicion_medio, nodo_actual -> obtener_hijo(i));
    }
    nuevo_nodo -> cambiar_cantidad_claves_usadas((obtener_orden() - 1) - posicion_medio);
    nodo_actual -> cambiar_cantidad_claves_usadas(posicion_medio);
 
    /*
    if(posicion_ideal <= obtener_orden() / 2)
    {
        meter_nodo(nodo_actual, nodo, pivote, nuevo_dato, posicion);
        nuevo_nodo -> establecer_hijo(0, nodo_actual -> obtener_hijo(nodo_actual -> obtener_cantidad_claves_usadas()));
        nodo_actual -> cambiar_cantidad_claves_usadas(nodo_actual -> obtener_cantidad_claves_usadas() - 1);
    }
    else
    {
        posicion = posicion_ideal - posicion_medio;
        meter_nodo(nuevo_nodo, nodo, pivote, nuevo_dato, posicion);
        nuevo_nodo -> establecer_hijo(0, nodo_actual -> obtener_hijo(nodo_actual -> obtener_cantidad_claves_usadas()));
    }*/
    
    nuevo_nodo -> establecer_hijo(PRIMER_HIJO, nodo_actual -> obtener_hijo(nodo_actual -> obtener_cantidad_claves_usadas() + 1));
    pivote = nodo_actual -> obtener_clave(nodo_actual -> obtener_cantidad_claves_usadas());
    nodo = nuevo_nodo; 
}

template <typename Tipo>
void ArbolB<Tipo>::in_orden(Nodo<Tipo>* nodo_actual)
{
    if(raiz != NULL)
    {
        in_orden(nodo_actual -> obtener_hijo(PRIMER_HIJO));

        for(int i = 1; i <= nodo_actual -> obtener_cantidad_claves_usadas(); i++)
        {
            cout << nodo_actual -> obtener_clave(i) << endl;
            in_orden(nodo_actual -> obtener_hijo(i));
        }
    }
} 

template < typename Tipo >
ArbolB<Tipo>::~ArbolB()
{
    if(!arbol_vacio())
        delete obtener_raiz();
}

#endif