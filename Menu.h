#ifndef _MENU_H_
#define _MENU_H_

#include "Constantes.h"
#include "Lista.h"
#include "Animal.h"
#include "Casilla.h"
#include "Colores.h"

class Menu 
{
    private:
        int opcion_tomada;

    public:
        //PRE: -
        //POS: inicializa opcion_tomada en 0.
        Menu();
        
        //PRE: -
        //POS: imprime por pantalla un saludo al usuario.
        void bienvenida();
        
        //PRE: -
        //POS: imprime por pantalla el menú con las opciones.
        void mostrar_menu();

        //PRE: -
        //POS: imprime por pantalla el mapa.
        void mostrar_mapa(Casilla** mapa, int filas , int columnas);
       
        //PRE: -
        //POS: solicita al usuario que ingrese el numero de la opción que desea ejecutar.
        void pedir_opcion();

        //PRE: -
        //POS: devuelve la opción tomada por el usuario.
        int obtener_opcion_tomada();
    
        //PRE: -
        //POS: valida que el string recibido conste completamente de numeros, devolviendo true en caso afirmativo y false en caso contrario.
        bool cadena_numeros_valida(string numeros);
};

#endif