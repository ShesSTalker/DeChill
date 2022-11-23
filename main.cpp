#include "Animal.h"
#include "Perro.h"
#include "Caballo.h"
#include "Gato.h"
#include "Lagartija.h"
#include "Erizo.h"
#include "Roedor.h"
#include "Conejo.h"
#include <iostream>
using namespace std;

#include "Arbol.h"
#include "Nodo.h"

int main(void)
{
    ArbolB<Animal> *miArbol = new ArbolB<Animal>();

    Lagartija *L1 = new Lagartija("Pepito", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(miArbol -> obtener_raiz(), L1 -> obtener_nombre(), L1);

    Lagartija *L2 = new Lagartija("Asdjsad", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(miArbol -> obtener_raiz(), L2 -> obtener_nombre(), L2);

    Lagartija *L3 = new Lagartija("Chancho", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(miArbol -> obtener_raiz(), L3 -> obtener_nombre(), L3);

    Lagartija *L4 = new Lagartija("Lagarto", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(miArbol -> obtener_raiz(), L4 -> obtener_nombre(), L4);

    Lagartija *L5 = new Lagartija("Pejelagarto", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(miArbol -> obtener_raiz(), L5 -> obtener_nombre(), L5);

    Lagartija *L6 = new Lagartija("123", 1, DIMINUTO, DORMILON);
    miArbol -> insertar(miArbol -> obtener_raiz(), L6 -> obtener_nombre(), L6);

    delete miArbol;

    return 0;
}
