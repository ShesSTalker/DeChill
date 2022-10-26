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

        //PRE: opcion_tomada debe ser 0 < opcion_tomada <= 6
        //POS: Procesa opcion_tomada para ejecutar las operaciones de la opcion elejida por el usuario
        void procesar_opcion(Lista<Animal*>* animales);

        //PRE: -
        //POS: Imprime por pantalla todos los animales de la lista.
        void listar_animales(Lista<Animal*>* animales); 

        //PRE: -
        //POS: Muestra por pantalla la informacion del animal
        void mostrar_animal(Animal* mi_animal);

        //PRE: -
        //POS: Le pide al usario el nombre del animal rescatado, si el nombre ya existe se le da la opcion al usuario de cargar otro nombre o volver al menu;
        void ingresar_nombre(Lista<Animal*>* animales);

        //PRE: - 
        //POS: Devuelve verdadero si el nombre existe en la lista y falso si no existe       
        bool buscar_nombre(string nombre, Lista<Animal*>* animales);

        //PRE: El nombre del animal no debe estar en la lista
        //POS: Carga el animal a la lista
        void rescatar_animal();
};

#endif

