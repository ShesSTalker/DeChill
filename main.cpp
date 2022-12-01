#include <iostream>
#include "Sistema.h"
#include "Menu.h"

using namespace std;

int main()
{
    Menu *menu = new Menu;
    Sistema *sistema = new Sistema;

    int opcion;

    sistema -> leer_animales();
    menu -> bienvenida();
    
    do
    {
        menu -> mostrar_menu();
        menu -> pedir_opcion();
        opcion = menu -> obtener_opcion_tomada();
        sistema -> limpiar_pantalla();
        sistema -> procesar_opcion(opcion);
    }
    while (opcion != GUARDAR_Y_SALIR);
    
    delete menu;
    delete sistema;
    return 0;
}
