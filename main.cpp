#include <iostream>
#include "Lagartija.h"
#include "Constantes.h"
#include "Arbol.h"

using namespace std;

int main()
{
    ArbolB<Animal *> *mi_arbol = new ArbolB<Animal *>(3);

    Lagartija *L1 = new Lagartija("Juan", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L1->obtener_nombre(), L1);

    Lagartija *L2 = new Lagartija("Martin", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L2->obtener_nombre(), L2);

    Lagartija *L3 = new Lagartija("Andy", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L3->obtener_nombre(), L3);

    Lagartija *L4 = new Lagartija("Dom", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L4->obtener_nombre(), L4);

    Lagartija *L5 = new Lagartija("Pepe", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L5->obtener_nombre(), L5);

    Lagartija *L6 = new Lagartija("Estrogeno", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L6->obtener_nombre(), L6);

    Lagartija *L7 = new Lagartija("Progesterona", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L7->obtener_nombre(), L7);

    Lagartija *L8 = new Lagartija("Wtf", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L8->obtener_nombre(), L8);

    delete mi_arbol;

    return 0;
}
