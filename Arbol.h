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
        //POS: inserta una nueva clave y un nuevo dato en el arbol.
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

        bool empujar(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* &nuevo_nodo, string nueva_clave, Tipo* nuevo_dato, string &pivote, Tipo* &pivote_dato); 

        void meter_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* hijo, string nueva_clave, Tipo* nuevo_dato, int posicion);

        void dividir_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* &nodo, string &pivote, Tipo* &pivote_dato, Tipo* nuevo_dato, int posicion);

        void mostrar_en_orden(Nodo<Tipo>* nodo_actual, int nivel);
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
    Tipo* pivote_dato;
    Nodo<Tipo>* nodo = NULL;

    cout << endl << endl << "INGRESO NUEVA CLAVE" << endl;

    if(raiz == NULL)
    {
        raiz = new Nodo<Tipo>(obtener_orden());
        meter_nodo(raiz, NULL, nueva_clave, nuevo_dato, 0);
    }
    else
    {
        sube_arriba = empujar(raiz, nodo, nueva_clave, nuevo_dato, pivote, pivote_dato);
    
        if (sube_arriba)
        { 
            Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(obtener_orden());
            cout << "cambiando cantidad en insertar(): 1" << endl;
            nuevo_nodo -> cambiar_cantidad_claves_usadas(1);    
            nuevo_nodo -> establecer_clave(PRIMERA_CLAVE, pivote); 
            nuevo_nodo -> establecer_dato(PRIMER_DATO, pivote_dato);
            nuevo_nodo -> establecer_hijo(PRIMER_HIJO, raiz);    
            nuevo_nodo -> establecer_hijo(SEGUNDO_HIJO, nodo);    
            raiz = nuevo_nodo;
        }
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
    mostrar_en_orden(raiz, PRIMER_DATO);
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
bool ArbolB<Tipo>::empujar(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* &nuevo_nodo, string nueva_clave, Tipo* nuevo_dato, string &pivote, Tipo* &pivote_dato)
{
    int posicion;
    bool sube_arriba = false;

    if(nodo_actual == NULL)
    {
        sube_arriba = true;
        pivote = nueva_clave;
        pivote_dato = nuevo_dato;
        nuevo_nodo = NULL;
    }
    else
    {
        buscar_nodo_actual(nodo_actual, nueva_clave, posicion);
        cout << "buscar_nodo_actual() devuelve " << posicion << endl;
        sube_arriba = empujar(nodo_actual -> obtener_hijo(posicion), nuevo_nodo, nueva_clave, nuevo_dato, pivote, pivote_dato);

        if(sube_arriba)
        {
            if(nodo_actual -> nodo_lleno())
            {
                cout << "entro a meter_nodo() lleno" << endl;
                meter_nodo(nodo_actual, nuevo_nodo, pivote, nuevo_dato, posicion);
                cout << "entro a dividir_nodo()" << endl;
                dividir_nodo(nodo_actual, nuevo_nodo, pivote, pivote_dato, nuevo_dato, posicion);
                cout << "POSICION: " << posicion << endl;
            } 
            else
            { 
                cout << "entro a meter_nodo() no lleno" << endl;
                meter_nodo(nodo_actual, nuevo_nodo, pivote, pivote_dato, posicion);
                sube_arriba = false;
            } 
        }
    }
    cout << "sube_arriba: " << sube_arriba << endl;
    return sube_arriba;
}

template < typename Tipo >
void ArbolB<Tipo>::meter_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* hijo, string nueva_clave, Tipo* nuevo_dato, int posicion)
{
    if(nodo_actual -> es_hoja())
    {
        cout << "NO HOJA" << endl;
        for(int i = nodo_actual -> obtener_cantidad_claves_usadas(); i > posicion; i--)
        {
            nodo_actual -> establecer_clave(i, nodo_actual -> obtener_clave(i - 1));
            nodo_actual -> establecer_dato(i, nodo_actual -> obtener_dato(i - 1));
            nodo_actual -> establecer_hijo(i, nodo_actual -> obtener_hijo(i - 1));
        }
    }
    else 
    {
        for(int j = nodo_actual -> obtener_cantidad_claves_usadas(); j >= posicion + 1; j--)
        {
           cout << "CANTIDAD DE ELEMENTOS: " << nodo_actual -> obtener_cantidad_claves_usadas() << endl;
            nodo_actual -> establecer_clave(j, nodo_actual -> obtener_clave(j - 1));
            nodo_actual -> establecer_dato(j, nodo_actual -> obtener_dato(j - 1));
            cout << "Establezco en posicion: " << j << " con direccion: "  << nodo_actual -> obtener_hijo(j - 1) << endl; 
            nodo_actual -> establecer_hijo(j + 1, nodo_actual -> obtener_hijo(j));
        }
    }
    cout << "Clave guardada " << nueva_clave  << " en posicion: " << posicion << endl;
    nodo_actual -> establecer_clave(posicion, nueva_clave);
    nodo_actual -> establecer_dato(posicion, nuevo_dato);

    if(hijo != NULL)
    {
        cout << "Hijo no hoja " << posicion + 1 << " establecido en meter_nodo(), direccion " << hijo << endl; 
        nodo_actual -> establecer_hijo(posicion + 1, hijo); 
    }
    else
    {
        cout << "Hijo hoja " << posicion << " establecido en meter_nodo(), direccion " << hijo << endl; 
        nodo_actual -> establecer_hijo(posicion, hijo); 
    }

    nodo_actual -> cambiar_cantidad_claves_usadas(nodo_actual -> obtener_cantidad_claves_usadas() + 1);
    cout << "cambiando cantidad en meter_nodo(): " << nodo_actual -> obtener_cantidad_claves_usadas() << endl;
}

template < typename Tipo >
void ArbolB<Tipo>::dividir_nodo(Nodo<Tipo>* nodo_actual, Nodo<Tipo>* &nodo, string &pivote, Tipo* &pivote_dato, Tipo* nuevo_dato, int posicion)
{
    int posicion_medio;
    Nodo<Tipo>* nuevo_nodo = new Nodo<Tipo>(obtener_orden());

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
        cout << "Clave trasladada " << nodo_actual -> obtener_clave(i) << endl;
        nuevo_nodo -> establecer_clave(i - posicion_medio - 1, nodo_actual -> obtener_clave(i));
        nuevo_nodo -> establecer_dato(i - posicion_medio - 1, nodo_actual -> obtener_dato(i));
        cout << "Hijo " << i - posicion_medio - 1<< " establecido en for loop dividir_nodo(), direccion " << nodo_actual -> obtener_hijo(i)  << endl;
        nuevo_nodo -> establecer_hijo(i - posicion_medio - 1, nodo_actual -> obtener_hijo(i));
    }
    cout << "cambiando cantidad de claves en el nuevo nodo en dividir:" << (obtener_orden() - 1) - posicion_medio << endl;
    nuevo_nodo -> cambiar_cantidad_claves_usadas((obtener_orden() - 1) - posicion_medio);
    cout << "cambiando cantidad de claves en el nodo actual en dividir:" << posicion_medio << endl;
    nodo_actual -> cambiar_cantidad_claves_usadas(posicion_medio);
    
    if(nodo_actual -> hijo_auxiliar_ocupado())
    {
        nuevo_nodo -> establecer_hijo(nuevo_nodo -> obtener_cantidad_claves_usadas(), nodo_actual -> obtener_hijo(HIJO_AUXILIAR));
    }

    pivote = nodo_actual -> obtener_clave(nodo_actual -> obtener_cantidad_claves_usadas());
    pivote_dato = nodo_actual -> obtener_dato(nodo_actual -> obtener_cantidad_claves_usadas());
    nodo = nuevo_nodo;
    cout << "Sube como pivote: " << pivote << " con hijo derecho:" << nodo <<endl; 
}

template <typename Tipo>
void ArbolB<Tipo>::mostrar_en_orden(Nodo<Tipo>* nodo_actual, int nivel)
{
    Animal* animal;

    if(nodo_actual != NULL)
    {
        mostrar_en_orden(nodo_actual -> obtener_hijo(PRIMER_HIJO), nivel + 1);

        for(int i = 0; i < nodo_actual -> obtener_cantidad_claves_usadas(); i++)
        {   
            animal = nodo_actual -> obtener_dato(i);
            if(animal  -> obtener_estado_animal() != ADOPTADO && animal -> obtener_estado_animal() != FUGADO)
            {
                animal -> mostrar_animal(); 
                cout << nivel << ") " << nodo_actual -> obtener_clave(i) << endl;
            }
            mostrar_en_orden(nodo_actual -> obtener_hijo(i + 1), nivel + 1);
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