#ifndef _MENU_H_
#define _MENU_H_

#include "Constantes.h"
#include "Lista.h"
#include "Animal.h"

class Menu{
    //Atributos
    private:
        int opcion_tomada;

    //Metodos
    public:
        //PRE: -
        //POS: inicializa opcion_tomada en 0 .
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

        //PRE: -
        //POS: Devuelve la opcion tomada por el usuario
        int obtener_opcion_tomada();

    private:
        //PRE: -
        //POS: valida que el string recibido conste completamente de numeros, devolviendo true en caso afirmativo y false en caso contrario
        bool cadena_numeros_valida(string numeros);

};

#endif

