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
        Nodo<Tipo>** hijos;
        Nodo<Tipo>* padre;
        int claves_usadas;
        bool eliminado;

    //Metodos
    public:
        Nodo(int vias);

        void establecer_clave(strig nueva_clave, int posicion);

        void establecer_dato(Tipo nuevo_dato, string posicion);

        void establecer_padre(Nodo<Tipo>* padre);

        bool es_hoja();

        int obtener_claves_usadas();

        string* obtener_clave(int posicion);

        Tipo obtener_dato(int posicion);
        
        Nodo<Tipo>* obtener_hijo(int posicion);

        void insertar_no_lleno(string nueva_clave, Tipo nuevo_dato);

        Nodo<Tipo>* dividir(Nodo<Tipo>* nodo, string nueva_clave, Tipo nuevo_dato);

        void marcar_como_borrado();

        ~Nodo();

    private:
        void sumar_clave_usada();

        void establecer_hijo_izquierdo(Nodo<Tipo>* hijo_izquierdo);

        void establecer_hijo_medio(Nodo<Tipo>* hijo_medio);

        void establecer_hijo_derecho(Nodo<Tipo>* hijo_derecho);
};

template < typename Tipo >
Nodo<Tipo>::Nodo(int vias)
{
    claves = new string[vias - 1];
    datos = new Tipo[vias - 1];
    hijos = Nodo<Tipo>*[vias];
    padre = nullptr;
    claves_usadas = 0;
    eliminado = false;
}

template < typename Tipo >
void establecer_clave(string nueva_clave, int posicion)
{
    claves[posicion] == nueva_clave;
}

template < typename Tipo >
void establecer_dato(Tipo nuevo_dato, string posicion)
{
   datos[posicion] = nuevo_dato; 
}

template < typename Tipo >
void establecer_padre(Nodo<Tipo>* padre)
{
    this -> padre = padre;
}

template < typename Tipo >
bool Nodo<Tipo>::es_hoja()
{
    return (hijos[0] == nullptr && hijos[1] == nullptr && hijos[2] == nullptr);
}

template < typename Tipo >
int Nodo<Tipo>::obtener_claves_usadas()
{
    return claves_usadas;
}

template < typename Tipo >
string* Nodo<Tipo>::obtener_clave(int posicion)
{
    return claves[posicion];
}

template < typename Tipo >
Tipo Nodo<Tipo>::obtener_dato(int posicion)
{
    return datos[posicion];
}

template < typename Tipo >
void Nodo<Tipo>::sumar_clave_usada()
{
    claves_usadas++;
}

template < typename Tipo >
void Nodo<Tipo>::insertar_no_lleno(string nueva_clave, Tipo nuevo_dato)
{
    if(nodo -> obtener_claves_usadas() == 0)
    {
        establecer_clave(nueva_clave, 0);
        establecer_dato(nuevo_dato, 0);
        sumar_clave_usada(); 
        return;   
    }

    if (nueva_clave > obtener_clave(0))
    {
        establecer_clave(nueva_clave, 1);
        establecer_dato(nuevo_dato, 1);
        sumar_clave_usada();
    }
    else 
    {
        establecer_clave(obtener_clave(0), 1);
        establecer_dato(obtener_dato(0), 1);
        establecer_clave(nueva_clave, 0);
        establecer_dato(nuevo_dato, 0);
        sumar_clave_usada();
    }
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::dividir(Nodo<Tipo>* nodo, string nueva_clave, Tipo nuevo_dato)
{
    if(padre == nullptr && es_hoja)
    {
        Nodo<Tipo> *nueva_raiz = new Nodo<Tipo>(3);
        Nodo<Tipo> *izq = new Nodo<Tipo>(3);
        Nodo<Tipo> *der = new Nodo<Tipo>(3);

        nueva_raiz -> es_hoja = false;
        nueva_raiz -> establecer_hijo_derecho(der);
        nueva_raiz -> establecer_hijo_izquierdo(izq);
        der -> es_hoja = true;
        der -> establecer_padre(nueva_raiz);
        izq -> es_hoja = true;
        izq -> establecer_padre(nueva_raiz);

        if(nueva_clave > nodo -> obtener_clave(0))
        {
            nueva_raiz -> establecer_clave(nodo -> obtener_clave(0), 0);
            nueva_raiz -> establecer_dato(nodo -> obtener_dato(0), 0);
            nueva_raiz -> sumar_clave_usada();

            izq -> establecer_clave(nueva_clave, 0);
            izq -> establecer_dato(nuevo_dato, 0);
            izq -> sumar_clave_usada();

            der -> establecer_clave(nodo -> obtener_clave(1), 0);
            der -> establecer_dato(nodo -> obtener_dato(1), 0);
            der -> sumar_clave_usada();
        }
        else if(nueva_clave < nodo -> obtener_clave(1))
        {
            nueva_raiz -> establecer_clave(nodo -> obtener_clave(1), 0);
            nueva_raiz -> establecer_dato(nodo -> obtener_dato(1), 0);
            nueva_raiz -> sumar_clave_usada();

            izq -> establecer_clave(nodo -> obtener_clave(0), 0);
            izq -> establecer_dato(nodo -> obtener_dato(0), 0);
            izq -> sumar_clave_usada();

            der -> establecer_clave(nueva_clave, 0);
            der -> establecer_dat(nuevo_dato, 0);
            der -> sumar_clave_usada();
        }
        else
        {
            nueva_raiz -> establecer_clave(nueva_clave, 0);
            nueva_raiz -> establecer_dato(nuevo_dato, 0);
            nueva_raiz -> sumar_clave_usada();

            izq -> establecer_clave(nodo -> obtener_clave(0), 0);
            izq -> establecer_dato(nodo -> obtener_dato(0), 0);
            izq -> sumar_clave_usada();

            der -> establecer_clave(nodo -> obtener_clave(1), 0);
            der -> establecer_dat(nodo -> obtener_dato(1), 0);
            der -> sumar_clave_usada();
        }

        delete nodo;
        return nueva_raiz;
    }

    if(padre -> obtener_claves_usadas() = 1)
    {
        
    }
    
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::dividir(Nodo<Tipo>* nodo, string nueva_clave, Tipo nuevo_dato)
{
    if(padre == nullptr)
    {
        if(nueva_clave > obtener_clave(0))
        {
            Nodo<Tipo>* padre = new Nodo<Tipo>(3);
            padre -> establecer_clave(obtener_clave(0), 0);
            padre -> establecer_dato(obtener_dato(0), 0);

            Nodo<Tipo>* hijo_izquierdo = new Nodo<Tipo>(3);
            hijo_izquierdo -> establecer_clave(nueva_clave, 0);
            hijo_izquierdo -> establecer_dato(nuevo_dato, 0);
            hijo_izquierdo -> establecer_padre(padre);

            Nodo<Tipo>* hijo_derecho = new Nodo<Tipo>(3);
            hijo_derecho -> establecer_clave(obtener_clave(1), 0);
            hijo_derecho -> establecer_dato(obtener_dato(1), 0);
            hijo_derecho -> establecer_padre(padre);

            padre -> establecer_hijo_izquierdo(hijo_izquierdo);
            padre -> establecer_hijo_derecho(hijo_derecho);

            if(!es_hoja)
            {

            }

            delete nodo;

            return hijo_izquierdo; 
        }
        if(nueva_clave > obtener_clave(1))
        {
            Nodo<Tipo>* padre = new Nodo<Tipo>(3);
            padre -> establecer_clave(obtener_clave(1), 0);
            padre -> establecer_dato(obtener_dato(1), 0);

            Nodo<Tipo>* hijo_izquierdo = new Nodo<Tipo>(3);
            hijo_izquierdo -> establecer_clave(obtener_clave(0), 0);
            hijo_izquierdo -> establecer_dato(obtener_dato(0), 0);
            hijo_izquierdo -> establecer_padre(padre);

            Nodo<Tipo>* hijo_derecho = new Nodo<Tipo>(3);
            hijo_derecho -> establecer_clave(nueva_clave, 0);
            hijo_derecho -> establecer_dato(nuevo_dato, 0);
            hijo_derecho -> establecer_padre(padre);

            padre -> establecer_hijo_izquierdo(hijo_izquierdo);
            padre -> establecer_hijo_derecho(hijo_derecho);

            delete nodo;
        }
        else if (nueva_clave > obtener_clave(0) && nueva_clave < obtener_clave(1))
        {
            Nodo<Tipo>* padre = new Nodo<Tipo>(3);
            padre -> establecer_clave(nueva_clave, 0);
            padre -> establecer_dato(nuevo_dato, 0);

            Nodo<Tipo>* hijo_izquierdo = new Nodo<Tipo>(3);
            hijo_izquierdo -> establecer_clave(obtener_clave(0), 0);
            hijo_izquierdo -> establecer_dato(obtener_dato(0), 0);
            hijo_izquierdo -> establecer_padre(padre);

            Nodo<Tipo>* hijo_derecho = new Nodo<Tipo>(3);
            hijo_derecho -> establecer_clave(obtener_clave(1), 0);
            hijo_derecho -> establecer_dato(obtener_dato(1), 0);
            hijo_derecho -> establecer_padre(padre);

            padre -> establecer_hijo_izquierdo(hijo_izquierdo);
            padre -> establecer_hijo_derecho(hijo_derecho);

            delete nodo;
        }
        return padre
    }
}

template <typename Tipo >
void Nodo<Tipo>::establecer_hijo_izquierdo(Nodo<Tipo>* hijo_izquierdo)
{
    hijos[0] = hijo_izquierdo;
}

template <typename Tipo >
void Nodo<Tipo>::establecer_hijo_medio(Nodo<Tipo>* hijo_medio)
{
    hijos[1] = hijo_medio;
}

template <typename Tipo >
void Nodo<Tipo>::establecer_hijo_derecho(Nodo<Tipo>* hijo_derecho)
{
    hijos[2] = hijo_derecho;
}

template < typename Tipo >
void Nodo<Tipo>::marcar_como_borrado()
{
    eliminado = true;
}

template < typename Tipo >
Nodo<Tipo>::~Nodo()
{
    claves[] delete;
    datos[] delete;
    hijos[] delete;
    padre = nullptr;
}

#endif