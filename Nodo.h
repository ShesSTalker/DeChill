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
        Nodo();

        void establecer_clave(strig nueva_clave, int posicion);

        void establecer_dato(Tipo *nuevo_dato, int posicion);

        void establecer_padre(Nodo<Tipo>* padre);

        bool es_hoja();

        int obtener_claves_usadas();

        void intercambiar(int posicion_1, int posicion_2);

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
Nodo<Tipo>::Nodo()
{
    claves = new string[2];
    datos = new Tipo[2];
    hijos = Nodo<Tipo>*[3];
    padre = nullptr;
    claves_usadas = 0;
    eliminado = false;
}

template < typename Tipo >
void Nodo<Tipo>::intercambiar(int posicion_1, int posicion_2)
{
    string clave_aux = nodo -> obtener_clave(posicion_1);
    Tipo *dato_aux = nodo -> obtener_dato(posicion_1);

    nodo -> establecer_clave(nodo -> obtener_clave(posicion_2), posicion_1);
    nodo -> establecer_dato(nodo -> obtener_dato(posicion_2), posicion_1);

    nodo -> establecer_clave(clave_aux, posicion_2);
    nodo -> establecer_dato(dato_aux, posicion_2);
}

template < typename Tipo >
void establecer_clave(string nueva_clave, int posicion)
{
    claves[posicion] == nueva_clave;
}

template < typename Tipo >
void establecer_dato(Tipo *nuevo_dato, int posicion)
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
{ // Claves usadas puede ser 1 o 0
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
{   // Caso 1: raiz y hoja
    if(padre == nullptr && es_hoja)
    {
        Nodo<Tipo> *izq = new Nodo<Tipo>();
        Nodo<Tipo> *der = new Nodo<Tipo>();

        izq -> es_hoja = true;
        izq -> establecer_padre(nodo);
        der -> es_hoja = true;
        der -> establecer_padre(nodo);

        nodo -> establecer_hijo_derecho(der);
        nodo -> establecer_hijo_izquierdo(izq);
        nodo -> es_hoja = false;

        if(nueva_clave > nodo -> obtener_clave(0)) // Nueva clave es la mayor, va a izq y der se queda con posicion 1
        {
            izq -> insertar_no_lleno(nueva_clave, nuevo_dato);

            izq -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));
        }
        else if(nueva_clave < nodo -> obtener_clave(1)) // Nueva clave es la menor, va a der y izq se queda con posicion 0
        {
            der -> insertar_no_lleno(nueva_clave, nuevo_dato);

            izq -> insertar_no_lleno(nodo -> obtener_clave(0), nodo -> obtener_dato(0));

            nodo -> intercambiar(0, 1);
        }
        else // Nueva clave es la media, queda en nodo y se distribuyen las otras claves
        {
            izq -> insertar_no_lleno(nodo -> obtener_clave(0), nodo -> obtener_dato(0));

            der -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));
        }

        nodo -> establecer_clave(nullptr, 1);
        nodo -> establecer_dato(nullptr, 1);
        nodo -> claves_usadas--;
        return;
    }
    // Caso 2: hoja y padre no lleno.
    if(padre -> obtener_claves_usadas() = 1 && es_hoja)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>();

        nuevo -> es_hoja = true;
        nuevo -> establecer_padre(padre);
        // Establecer datos
        if(nueva_clave > nodo -> obtener_clave(0)) // Nueva clave es la mayor, sube la posicion 0
        {
            nuevo -> establecer_clave(nodo -> obtener_clave(1), 0);
            nuevo -> establecer_dato(nodo -> obtener_dato(1), 0);
            nodo -> establecer_clave(nullptr, 1);
            nodo -> establecer_dato(nullptr, 1);

            padre -> insertar_no_lleno(nodo -> obtener_clave(0), nodo -> obtener_dato(0));

            nodo -> establecer_clave(nueva_clave, 0);
            nodo -> establecer_dato(nuevo_dato, 0);
        }
        else if(nueva_clave < nodo -> obtener_clave(1)) // Nueva clave es la menor, sube la posicion 1
        {
            nuevo -> establecer_clave(nueva_clave, 0);
            nuevo -> establecer_dato(nuevo_dato, 0);

            padre -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

            nodo -> establecer_clave(nullptr, 1);
            nodo -> establecer_dato(nullptr, 1);
        }
        else // Nueva clave es la media, sube ella
        {
            nuevo -> establecer_clave(nodo -> obtener_clave(1), 0);
            nuevo -> establecer_dato(nodo -> obtener_dato(1), 0);
            nodo -> establecer_clave(nullptr, 1);
            nodo -> establecer_dato(nullptr, 1);

            padre -> insertar_no_lleno(nueva_clave, nuevo_dato);
        }
        // Establecer hijos
        if(nodo == padre -> obtener_hijo(0))
        {
            padre -> establecer_hijo_medio(nuevo);
        }
        else // Asumimos que los primeros dos hijos que se llenan son el izquierdo y el derecho
        {    // (lo cual es cierto por como hicimos el caso 1)
            padre -> establecer_hijo_medio(nodo);
            padre -> establecer_hijo_derecho(nuevo);
        }

        return;
    }
    // Caso 3: la puta que me parió
    return;
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