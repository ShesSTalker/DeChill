#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
    Menu* menu;
    int opcion;

    menu -> mostrar_menu();
    menu -> pedir_opcion();
    opcion = menu -> obtener_opcion_tomada();

    while (opcion != GUARDAR_Y_SALIR)
    {
        menu -> mostrar_menu();
        menu -> pedir_opcion();
        opcion = menu -> obtener_opcion_tomada();
    }

    return 0;
}
