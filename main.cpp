#include <iostream>
#include "Menu.h"
#include "Sistema.h"

using namespace std;

int main()
{
    Menu* menu = new Menu();
    Sistema* sistema = new Sistema();
    int opcion;

    sistema -> leer_datos();
    menu -> bienvenida();
    
    do
    {
        menu -> mostrar_menu();
        menu -> pedir_opcion();
        opcion = menu -> obtener_opcion_tomada();
        sistema -> procesar_opcion(opcion);
    }
    while (opcion != GUARDAR_Y_SALIR);

    sistema -> guardar();
    
    delete menu;
    delete sistema;

    return 0;
}
