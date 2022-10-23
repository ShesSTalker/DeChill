#ifndef _MENU_H_
#define _MENU_H_

#include "Constantes.h"
#include "Opciones.h"

class Menu{
    //Atributos
    private:
        int opcion_tomada; 
        Opcion* opcion;

    //Metodos
    public:
        //PRE: -
        //POS: Incianliza opcion_tomada en 0
        Menu();
        
        //PRE: -
        //POS: Imprime por pantalla un saludo al usuario
        void bienvenida();
        
        //PRE: -
        //POS: Imprime por pantalla el menu con las opciones
        void mostrar_menu();
       
        //PRE: -
        //POS: Solicita al usuario que ingrese el numero de la opcion que desea ejecutar.
        void pedir_opcion();

        //PRE: opcion_tomada debe ser 0 < opcion_tomada <= 6
        //POS: Procesa opcion_tomada para ejecutar las operaciones de la opcion elejida por el usuario
        void procesar_opcion(); 
};

#endif

