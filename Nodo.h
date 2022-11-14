#ifndef _NODO_H_
#define _NODO_H_

template < typename Tipo >
class Nodo
{
    //Atributos
    private:
        Tipo dato;
        Nodo<Tipo>* izquierdo;
        Nodo<Tipo>* derecho;
        Nodo<Tipo>* padre;

    //Metodos
    public:
        Nodo(Tipo dato);

        //PRE: - 
        //POS: devuelve el dato que contiene el nodo
        Tipo obtener_dato();

        //PRE: -
        //POS: establece el dato en el nodo
        void establecer_dato(Tipo dato);

        //PRE: -
        //POS: establece el puntero a la derecha al padre
        void establecer_derecho(Nodo<Tipo>* derecho, Nodo<Tipo>* padre);

        //PRE: -
        //POS: establece el puntero a la izquierda al padre
        void establecer_izquierdo(Nodo<Tipo>* izquierdo, Nodo<Tipo>* padre);

        //PRE: -
        //POS: establece el puntero al hijo derecho
        void establecer_derecho(Nodo<Tipo>* derecho);

        //PRE: -
        //POS: establece el puntero al nodo izquierdo
        void establecer_izquierdo(Nodo<Tipo>* izquierdo);

        //PRE: -
        //POS: establece el puntero al nodo padre
        void establecer_padre(Nodo<Tipo>* padre);

        //PRE: -
        //POS: devuelve el puntero al nodo hijo derecho
        Nodo<Tipo>* obtener_derecho();

        //PRE: -
        //POS: devuelve el puntero al nodo hijo izquierdo
        Nodo<Tipo>* obtener_izquierdo();

        //PRE: -
        //POS: devuelve el puntero al padre
        Nodo<Tipo>* obtener_padre();

        //PRE: -
        //POS: devuelve verdadero si el nodo es hoja y falso en caso contrario
        bool es_hoja();

        //PRE: -
        //POS: devuelve verdadero si el nodo solo tiene hijo derecho y falso en caso contrario
        bool solo_hijo_derecho();

        //PRE: -
        //POS: devuelve verdaderro si el nodo solo tiene hizo izquierdo y falso en caso contrario
        bool solo_hijo_izquierdo();
};

template < typename Tipo >
Nodo<Tipo>::Nodo(Tipo dato)
{
    this -> dato = dato;
    this -> derecho = NULL;
    this -> izquierdo = NULL;
    this -> padre = NULL;
}

template < typename Tipo >
Tipo Nodo<Tipo>::obtener_dato()
{
    return dato;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_derecho(Nodo<Tipo>* derecho, Nodo<Tipo>* padre)
{
    this ->  derecho = derecho;
    this -> padre = padre;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_izquierdo(Nodo<Tipo>* izquierdo, Nodo<Tipo>* padre)
{
    this -> izquierdo = izquierdo;
    this -> padre = padre; 
}

template < typename Tipo > 
void Nodo<Tipo>::establecer_derecho(Nodo<Tipo>* derecho)
{
    this -> derecho = derecho; 
}

template < typename Tipo > 
void Nodo<Tipo>::establecer_izquierdo(Nodo<Tipo>* izquierdo)
{
    this -> izquierdo = izquierdo;
}

template < typename Tipo >
void Nodo<Tipo>::establecer_padre(Nodo<Tipo>* padre)
{
    this -> padre = padre;
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::obtener_derecho()
{
    return derecho;
}

template < typename Tipo >
Nodo<Tipo>* Nodo<Tipo>::obtener_izquierdo()
{
    return izquierdo;
}

template < typename Tipo > 
Nodo<Tipo>* Nodo<Tipo>::obtener_padre()
{
    return padre;
}

template < typename Tipo >
bool Nodo<Tipo>::es_hoja()
{
    return (obtener_izquierdo() == NULL && obtener_derecho() == NULL);
}

template < typename Tipo >
bool Nodo<Tipo>::solo_hijo_derecho()
{
    return (obtener_izquierdo() == NULL && obtener_derecho() != NULL);
}

template < typename Tipo >
bool Nodo<Tipo>::solo_hijo_izquierdo()
{
    return (obtener_izquierdo() != NULL && obtener_derecho() == NULL);
}
#endif