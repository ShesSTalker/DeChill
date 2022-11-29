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
    
    cout << endl << "L8" << endl;
    Lagartija *L8 = new Lagartija("Wtf", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L8->obtener_nombre(), L8);
    
    cout << endl << "L9" << endl;
    Lagartija *L9 = new Lagartija("G", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L9->obtener_nombre(), L9);
    
    cout << endl << "L10" << endl;
    Lagartija *L10 = new Lagartija("L", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L10->obtener_nombre(), L10);
    
    cout << endl << "L11" << endl;
    Lagartija *L11 = new Lagartija("N", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L11->obtener_nombre(), L11);
    
    cout << endl << "L12" << endl;
    Lagartija *L12 = new Lagartija("P", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L12->obtener_nombre(), L12);
    
    cout << endl << "L13" << endl;
    Lagartija *L13 = new Lagartija("F", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L13->obtener_nombre(), L13);
    
    cout << endl << "L14" << endl;
    Lagartija *L14 = new Lagartija("H", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L14->obtener_nombre(), L14);
    
    cout << endl << "L15" << endl;
    Lagartija *L15 = new Lagartija("R", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L15->obtener_nombre(), L15);
    
    cout << endl << "L16" << endl;
    Lagartija *L16 = new Lagartija("J", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L16->obtener_nombre(), L16);
    
    cout << endl << "L17" << endl;
    Lagartija *L17 = new Lagartija("Y", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L17->obtener_nombre(), L17);
    
    cout << endl << "L18" << endl;
    Lagartija *L18 = new Lagartija("M", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L18->obtener_nombre(), L18);
    
    cout << endl << "L19" << endl;
    Lagartija *L19 = new Lagartija("K", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L19->obtener_nombre(), L19);
    
    cout << endl << "L20" << endl;
    Lagartija *L20 = new Lagartija("S", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L20->obtener_nombre(), L20);
    
    cout << endl << "L21" << endl;
    Lagartija *L21 = new Lagartija("U", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L21->obtener_nombre(), L21);
    
    cout << endl << "L22" << endl;
    Lagartija *L22 = new Lagartija("I", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L22->obtener_nombre(), L22);
    
    cout << endl << "L23" << endl;
    Lagartija *L23 = new Lagartija("O", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L23->obtener_nombre(), L23);
    
    cout << endl << "L24" << endl;
    Lagartija *L24 = new Lagartija("T", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L24->obtener_nombre(), L24);
    
    cout << endl << "L25" << endl;
    Lagartija *L25 = new Lagartija("X", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L25->obtener_nombre(), L25);
   
    cout << endl << "L26" << endl;
    Lagartija *L26 = new Lagartija("Q", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L26->obtener_nombre(), L26);
    
    cout << endl << "L27" << endl;
    Lagartija *L27 = new Lagartija("V", 1, DIMINUTO, TRAVIESO);
    mi_arbol->insertar(L27->obtener_nombre(), L27);
    cout << endl;
    mi_arbol -> listar_creciente();

    delete mi_arbol;

    return 0;
}
