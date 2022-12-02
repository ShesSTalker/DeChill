#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include "Sistema.h"
#include <ctime>

using namespace std;

int main()
{
    // Semilla para generar numeros aleatorios
    srand((unsigned) time(NULL));

    Menu *menu = new Menu;
    Sistema *sistema = new Sistema;

    int opcion;

    sistema -> leer_animales();
    sistema -> cargar_mapa_grafo();
    menu -> bienvenida();

    bool no_clausurado = true;
    
    do
    {
        menu -> mostrar_menu();
        menu -> pedir_opcion();
        opcion = menu -> obtener_opcion_tomada();
        sistema -> procesar_opcion(opcion);

        no_clausurado = sistema -> pasar_tiempo();
    }
    while (opcion != GUARDAR_Y_SALIR && no_clausurado != false);
    
    if(no_clausurado == false)
        sistema -> clausurar();

    sistema -> guardar();
    
    delete menu;
    delete sistema;
    return 0;
}
