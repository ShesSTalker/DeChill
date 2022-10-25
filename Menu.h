#ifndef _MENU_H_
#define _MENU_H_

#include "Constantes.h"
#include "Lista.h"
#include "Animal.h"

class Menu{
    //Atributos
    private:
        int opcion_tomada;
        Lista<Animal*>* animales; 

    //Metodos
    public:
        //PRE: -
        //POS: inicializa opcion_tomada en 0 y animales en el puntero pasado como parámetro.
        Menu(Lista<Animal*>* animales);
        
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

        //PRE: -
        //POS: Imprime por pantalla todos los animales de la lista.
        void listar_animales(); 

        //PRE: -
        //POS: Muestra por pantalla la informacion del animal
        void mostrar_animal(Animal* mi_animal);

        //PRE: -
        //POS: si el animal ingresado no estaba en la Reserva, se agrega.
        void rescatar_animal();
};

#endif

