#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include "Sistema.h"
#include <ctime>

using namespace std;

int main()
{
    //Semilla para generar numeros aleatorios
    
    srand((unsigned) time(NULL));
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

    sistema -> guardar();
    
    delete menu;
    delete sistema;
    return 0;
}
