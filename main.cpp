#include <iostream>
#include "Lagartija.h"
#include "Constantes.h"
#include "Arbol.h"

using namespace std;

int main()
{

    ArbolB<Animal> *mi_arbol = new ArbolB<Animal>(3);
    cout << "L1" << endl;
    Lagartija *L1 = new Lagartija("C", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L1->obtener_nombre(), L1);
    cout << endl << "L2" << endl;
    Lagartija *L2 = new Lagartija("B", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L2->obtener_nombre(), L2);
    cout << endl << "L3" << endl;
    Lagartija *L3 = new Lagartija("A", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L3->obtener_nombre(), L3);
    cout << endl << "L4" << endl;
    Lagartija *L4 = new Lagartija("E", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L4->obtener_nombre(), L4);
    cout << endl << "L5" << endl;
    Lagartija *L5 = new Lagartija("Z", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L5->obtener_nombre(), L5);
    cout << endl << "L6" << endl;
    Lagartija *L6 = new Lagartija("D", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L6->obtener_nombre(), L6);
    cout << endl << "L7" << endl;
    Lagartija *L7 = new Lagartija("Zzzz", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L7->obtener_nombre(), L7);
    /*cout << endl << "L8" << endl;
    Lagartija *L8 = new Lagartija("Wtf", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L8->obtener_nombre(), L8);*/
    cout << endl;
    mi_arbol -> listar_creciente();

    delete mi_arbol;

    return 0;
}
