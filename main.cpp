#include <iostream>
#include "NodoArbol.h"
#include "Sistema.h"
#include "Menu.h"

using namespace std;

int main()
{
    NodoArbol<Animal> *miNodo = new NodoArbol<Animal>;

    cout << "TESTING TESTING 1 2 3" << endl;

    delete miNodo;

    return 0;
}
