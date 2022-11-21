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
        Tipo** datos;

        Nodo<Tipo>** hijos;
        Nodo<Tipo>* padre;

        int claves_usadas;
        bool* eliminados;

    //Metodos
    public: // Hay que ver que onda el alcance de estos
        Nodo();

        int obtener_claves_usadas();

        Nodo<Tipo>* obtener_padre();

        string* obtener_clave(int posicion);

        Tipo obtener_dato(int posicion);
        
        Nodo<Tipo>* obtener_hijo(int posicion);

        void insertar_no_lleno(string nueva_clave, Tipo nuevo_dato);

        void marcar_como_eliminado(int posicion);

        ~Nodo();

    private:
        void establecer_clave(strig nueva_clave, int posicion);

        void establecer_dato(Tipo *nuevo_dato, int posicion);

        void intercambiar(int posicion_1, int posicion_2);

        void establecer_padre(Nodo<Tipo>* padre);

        bool es_hoja();

        Nodo<Tipo>* dividir(Nodo<Tipo>* nodo, string nueva_clave, Tipo nuevo_dato);

        void sumar_clave_usada();

        void restar_clave_usada();

        void establecer_hijo_izquierdo(Nodo<Tipo>* hijo_izquierdo);

        void establecer_hijo_medio(Nodo<Tipo>* hijo_medio);

        void establecer_hijo_derecho(Nodo<Tipo>* hijo_derecho);

    template < typename Tipo2 >
    friend class ArbolB;
};

template < typename Tipo >
Nodo<Tipo> *Nodo<Tipo>::obtener_padre()
{
    return padre;
}

template < typename Tipo >
Nodo<Tipo>::Nodo()
{
    claves = new string[2];
    datos = new Tipo[2];
    hijos = new Nodo<Tipo>[3];
    padre = nullptr;
    claves_usadas = 0;
    eliminados = new bool[3];
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
void Nodo<Tipo>::restar_clave_usada()
{
    claves_usadas--;
}

template < typename Tipo >
void Nodo<Tipo>::insertar_no_lleno(string nueva_clave, Tipo nuevo_dato)
{ 
    // Claves usadas puede ser 1 o 0
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
    Nodo<Tipo> *mi_padre = nodo -> obtener_padre();
    // Los primeros casos aplican a hojas
    if(nodo -> es_hoja())
    {
        // Caso 1: raiz y hoja
        if(mi_padre == nullptr)
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

            if(nueva_clave > nodo -> obtener_clave(1)) // Nueva clave es la mayor, va a der y izq se queda con posicion 0
            {
                der -> insertar_no_lleno(nueva_clave, nuevo_dato);

                izq -> insertar_no_lleno(nodo -> obtener_clave(0), nodo -> obtener_dato(0));

                // Borrar una clave de nodo
                nodo -> intercambiar(0, 1); 
                nodo -> restar_clave_usada();

                return nullptr; // No hace falta retornar aca ya que nunca se llama este caso por recursion
            }
            else if(nueva_clave < nodo -> obtener_clave(0)) // Nueva clave es la menor, va a izq y der se queda con posicion 1
            {
                izq -> insertar_no_lleno(nueva_clave, nuevo_dato);

                der -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

                // Borrar una clave de nodo
                nodo -> restar_clave_usada();

                return nullptr; // No hace falta retornar aca ya que nunca se llama este caso por recursion 
            }
            else // Nueva clave es la media, queda en nodo y se distribuyen las otras claves
            {
                der -> insertar_no_lleno(nodo -> obtener_clave(0), nodo -> obtener_dato(0));

                izq -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

                nodo -> establecer_clave(nueva_clave, 0);
                nodo -> establecer_dato(nuevo_dato, 0);

                // Borrar una clave de nodo
                nodo -> restar_clave_usada();

                return nullptr; // No hace falta retornar aca ya que nunca se llama este caso por recursion
            }
        }
        
        // Caso 2: hoja y padre no lleno.
        if(mi_padre -> obtener_claves_usadas() = 1)
        {
            Nodo<Tipo> *nuevo = new Nodo<Tipo>();

            nuevo -> es_hoja = true;
            nuevo -> establecer_padre(mi_padre);

            // Establecer hijos
            if(nodo == mi_padre -> obtener_hijo(0))
            {
                mi_padre -> establecer_hijo_medio(nuevo);
            }
            else // Asumimos que los primeros dos hijos que se llenan son el izquierdo y el derecho
            {    // (lo cual es cierto por como hicimos el caso 1)
                mi_padre -> establecer_hijo_medio(nodo);
                mi_padre -> establecer_hijo_derecho(nuevo);
            }

            // Establecer datos
            if(nueva_clave > nodo -> obtener_clave(1)) // Nueva clave es la mayor, sube la posicion 1
            {
                nuevo -> insertar_no_lleno(nueva_clave, nuevo_dato);

                mi_padre -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

                // Borrar una clave de nodo
                nodo -> restar_clave_usada();

                return nullptr; // No hace falta retornar aca ya que nunca se llama este caso por recursion
            }
            else if(nueva_clave < nodo -> obtener_clave(0)) // Nueva clave es la menor, sube la posicion 0
            {
                nuevo -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_clave(1));

                mi_padre -> insertar_no_lleno(nodo -> obtener_clave(0), nodo -> obtener_dato(0));

                nodo -> establecer_clave(nueva_clave 0);
                nodo -> establecer_dato(nuevo_dato, 0);

                // Borrar una clave de nodo
                nodo -> restar_clave_usada();

                return nullptr; // No hace falta retornar aca ya que nunca se llama este caso por recursion
            }
            else // Nueva clave es la media, sube ella
            {
                nuevo -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

                mi_padre -> insertar_no_lleno(nueva_clave, nuevo_dato);

                // Borrar una clave de nodo
                nodo -> restar_clave_usada();

                return nullptr; // No hace falta retornar aca ya que nunca se llama este caso por recursion
            }
        }

        // Caso 3: hoja y padre lleno (empieza recursion)
        if(nueva_clave > nodo -> obtener_clave(1)) // Nueva clave es la mayor, sube la posicion 1
        {
            mi_padre = dividir(mi_padre, nodo -> obtener_clave(1), nodo -> obtener_dato(1));
        }
        else if(nueva_clave < nodo -> obtener_clave(0)) // Nueva clave es la menor, sube la posicion 0
        {
            mi_padre = dividir(mi_padre, nodo -> obtener_clave(0), nodo -> obtener_dato(0));
        }
        else // Nueva clave es la media, sube ella
        {
            mi_padre = dividir(mi_padre, nueva_clave, nuevo_dato);
        }

        Nodo<Tipo> *nuevo = new Nodo<Tipo>();

        nuevo -> es_hoja = true;
        nuevo -> establecer_padre(mi_padre);

        if(mi_padre -> obtener_hijo(0) == nullptr)
            mi_padre -> establecer_hijo_izquierdo(nuevo);
        else
        {
            mi_padre -> establecer_hijo_izquierdo(nodo);
            mi_padre -> establecer_hijo_derecho(nuevo);
        }

        // Establecer datos
        if(nueva_clave > nodo -> obtener_clave(1)) // Nueva clave es la mayor, subió la posicion 1
        {
            nuevo -> insertar_no_lleno(nueva_clave, nuevo_dato);

            // Borrar una clave de nodo
            nodo -> restar_clave_usada();

            return nullptr; // No hace falta retornar aca ya que nunca se llama este caso por recursion
        }
        else if(nueva_clave < nodo -> obtener_clave(0)) // Nueva clave es la menor, subió la posicion 0
        {
            nuevo -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

            nodo -> establecer_clave(nueva_clave 0);
            nodo -> establecer_dato(nuevo_dato, 0);

            // Borrar una clave de nodo
            nodo -> restar_clave_usada();

            return nullptr ; // No hace falta retornar aca ya que nunca se llama este caso por recursion
        }
        else // Nueva clave es la media, subió ella
        {
            nuevo -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

            // Borrar una clave de nodo 
            nodo -> restar_clave_usada();

            return nullptr; // No hace falta retornar aca ya que nunca se llama este caso por recursion
        }
    }

    // Caso 4: raiz y no hoja
    if(mi_padre == nullptr)
    {
        Nodo<Tipo> *izq = new Nodo<Tipo>();
        Nodo<Tipo> *der = new Nodo<Tipo>();

        izq -> es_hoja = false;
        izq -> establecer_padre(nodo);
        der -> es_hoja = false;
        der -> establecer_padre(nodo);

        nodo -> establecer_hijo_derecho(der);
        nodo -> establecer_hijo_izquierdo(izq);
        nodo -> es_hoja = false;

        if(nueva_clave > nodo -> obtener_clave(1)) // Nueva clave es la mayor, va a der y izq se queda con posicion 0
        {
            der -> insertar_no_lleno(nueva_clave, nuevo_dato);

            izq -> insertar_no_lleno(nodo -> obtener_clave(0), nodo -> obtener_dato(0));

            // Borrar una clave de nodo
            nodo -> intercambiar(0, 1); 
            restar_clave_usada();

            // Cambiar hijos
            izq -> establecer_hijo_izquierdo(nodo -> obtener_hijo(0));
            izq -> establecer_hijo_derecho(nodo -> obtener_hijo(1));
            der -> establecer_hijo_izquierdo(nodo -> obtener_hijo(2));

            return der;
        }
        else if(nueva_clave < nodo -> obtener_clave(0)) // Nueva clave es la menor, va a izq y der se queda con posicion 1
        {
            izq -> insertar_no_lleno(nueva_clave, nuevo_dato);

            der -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

            // Borrar una clave de nodo
            nodo -> restar_clave_usada();

            // Cambiar hijos
            izq -> establecer_hijo_izquierdo(nodo -> obtener_hijo(0));
            der -> establecer_hijo_izquierdo(nodo -> obtener_hijo(1));
            der -> establecer_hijo_derecho(nodo -> obtener_hijo(2));

            return izq;
        }
        else // Nueva clave es la media, queda en nodo y se distribuyen las otras claves
        {
            der -> insertar_no_lleno(nodo -> obtener_clave(0), nodo -> obtener_dato(0));

            izq -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

            nodo -> establecer_clave(nueva_clave, 0);
            nodo -> establecer_dato(nuevo_dato, 0);

            // Borrar una clave de nodo
            nodo -> restar_clave_usada();

            // Cambiar hijos
            izq -> establecer_hijo_izquierdo(nodo -> obtener_hijo(0));
            izq -> establecer_hijo_derecho(nodo -> obtener_hijo(1));
            der -> establecer_hijo_derecho(nodo -> obtener_hijo(2));

            return der;
        }
    }   
 
    // Caso 5: no hoja y padre no lleno (viene de recursion y frena recursion)
    if(mi_padre -> obtener_claves_usadas() = 1)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>();

        nuevo -> es_hoja = false;
        nuevo -> establecer_padre(mi_padre);

        if(nodo == mi_padre -> obtener_hijo(0))
        {
            mi_padre -> establecer_hijo_medio(nuevo);
        }
        else // Asumimos que los primeros dos hijos que se llenan son el izquierdo y el derecho
        {    // (lo cual es cierto por como hicimos el caso 1)
            mi_padre -> establecer_hijo_medio(nodo);
            mi_padre -> establecer_hijo_derecho(nuevo);
        }

        // Establecer datos
        if(nueva_clave > nodo -> obtener_clave(1)) // Nueva clave es la mayor, subió la posicion 1
        {
            nuevo -> insertar_no_lleno(nueva_clave, nuevo_dato);

            // Borrar una clave de nodo
            nodo -> restar_clave_usada();

            // Cambiar hijos
            nodo -> establecer_hijo_derecho(nodo -> obtener_hijo(1));
            nodo -> establecer_hijo_medio(nullptr);

            return nuevo;
        }
        else if(nueva_clave < nodo -> obtener_clave(0)) // Nueva clave es la menor, subió la posicion 0
        {
            nuevo -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

            nodo -> establecer_clave(nueva_clave, 0);
            nodo -> establecer_dato(nuevo_dato, 0);

            // Borrar una clave de nodo
            nodo -> restar_clave_usada();

            // Cambiar hijos
            nuevo -> establecer_hijo_izquierdo(nodo -> obtener_hijo(1));
            nuevo -> establecer_hijo_derecho(nodo -> obtener_hijo(2));
            nodo -> establecer_hijo_medio(nullptr);

            return nodo;
        }
        else // Nueva clave es la media, subió ella
        {
            nuevo -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

            // Borrar una clave de nodo
            nodo -> restar_clave_usada();

            // Cambiar hijos
            nodo -> establecer_hijo_derecho(nodo -> obtener_hijo(1));
            nuevo -> establecer_hijo_derecho(nodo -> obtener_hijo(2));
            nodo -> establecer_hijo_medio(nullptr);

            return nuevo;
        }
    }

    // Caso 6: no hoja y padre lleno (viene de recursion y continua recursion)
    if(nueva_clave > nodo -> obtener_clave(1)) // Nueva clave es la mayor, sube la posicion 1
    {
        mi_padre = dividir(mi_padre, nodo -> obtener_clave(1), nodo -> obtener_dato(1));
    }
    else if(nueva_clave < nodo -> obtener_clave(0)) // Nueva clave es la menor, sube la posicion 0
    {
        mi_padre = dividir(mi_padre, nodo -> obtener_clave(0), nodo -> obtener_dato(0));
    }
    else // Nueva clave es la media, sube ella
    {
        mi_padre = dividir(mi_padre, nueva_clave, nuevo_dato);
    }

    Nodo<Tipo> *nuevo = new Nodo<Tipo>();

    nuevo -> es_hoja = false;
    nuevo -> establecer_padre(mi_padre);

    if(mi_padre -> obtener_hijo(0) == nullptr)
        mi_padre -> establecer_hijo_izquierdo(nuevo);
    else
    {
        mi_padre -> establecer_hijo_izquierdo(nodo);
        mi_padre -> establecer_hijo_derecho(nuevo);
    }

    // Establecer datos
    if(nueva_clave > nodo -> obtener_clave(1)) // Nueva clave es la mayor, subió la posicion 1
    {
        nuevo -> insertar_no_lleno(nueva_clave, nuevo_dato);

        // Borrar una clave de nodo
        nodo -> restar_clave_usada();

        // Cambiar hijos
        nodo -> establecer_hijo_derecho(nodo -> obtener_hijo(1));
        nodo -> establecer_hijo_medio(nullptr);

        return nuevo;
    }
    else if(nueva_clave < nodo -> obtener_clave(0)) // Nueva clave es la menor, subió la posicion 0
    {
        nuevo -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

        nodo -> establecer_clave(nueva_clave, 0);
        nodo -> establecer_dato(nuevo_dato, 0);

        // Borrar una clave de nodo
        nodo -> restar_clave_usada();

        // Cambiar hijos
        nuevo -> establecer_hijo_izquierdo(nodo -> obtener_hijo(1));
        nuevo -> establecer_hijo_derecho(nodo -> obtener_hijo(2));
        nodo -> establecer_hijo_medio(nullptr);

        return nodo;
    }
    else // Nueva clave es la media, subió ella
    {
        nuevo -> insertar_no_lleno(nodo -> obtener_clave(1), nodo -> obtener_dato(1));

        // Borrar una clave de nodo
        nodo -> restar_clave_usada();

        // Cambiar hijos
        nodo -> establecer_hijo_derecho(nodo -> obtener_hijo(1));
        nuevo -> establecer_hijo_derecho(nodo -> obtener_hijo(2));
        nodo -> establecer_hijo_medio(nullptr);

        return nuevo;
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
void Nodo<Tipo>::marcar_como_eliminado(int posicion)
{
    eliminado[posicion] = true;
}

template < typename Tipo >
Nodo<Tipo>::~Nodo()
{   
    int i;
    for(i = 0; i < nodo -> obtener_claves_usadas(); i++)
    {
        if(!es_hoja)
            delete hijos[i];

        delete datos[i];
    }
    
    if(!es_hoja)
        delete hijos[i];

    delete[] hijos;
    delete[] datos;
    delete[] claves;
    delete[] eliminados;
}

#endif
