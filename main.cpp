#include <iostream>
#include <cstdlib>
#include "Menu.h"
#include "Sistema.h"
#include "time.h"

using namespace std;

int main()
{
    //Semilla para generar numeros aleatorios
    srand((unsigned) time(NULL));
    Sistema* sistema = new Sistema();

    sistema->cargar_mapa_grafo();
    sistema->procesar_opcion(0);
    delete sistema;

    return 0;
}
