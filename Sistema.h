#ifndef _SISTEMA_H_
#define _SISTEMA_H_

#include "Menu.h"

class Sistema
{
    //Atributos
    private:
        Lista<Animal*>* animales; 

    //Metodos
    public:
        //PRE: -
        //POS: Inicializa la lista de animales
        Sistema();

        //PRE: -
        //POS: Inicializa el sistema 
        void iniciar_sistema();

        //PRE: - 
        //POS: Lee los datos del arcivo csv de animales
        void leer_datos();

        //PRE: -
        //POS: carga el animal en la lista de animales
        void cargar_animal(char especie, string nombre, int edad, char tamanio, char personalidad);

        //PRE: opcion_tomada debe ser 0 < opcion_tomada <= 6
        //POS: Procesa opcion_tomada para ejecutar las operaciones de la opcion elejida por el usuario
        void procesar_opcion(int opcion_tomada);

        // PRE: -
        // POS: aumenta el hambre del animal y reduce (o no) su higiene, basándose en las características del animal particular
        void pasar_tiempo();

        //PRE: -
        //POS: Imprime por pantalla todos los animales de la lista.
        void listar_animales(Lista<Animal*>* animales); 

        //PRE: -
        //POS: Muestra por pantalla la informacion del animal
        void mostrar_animal(Animal* mi_animal);

        //PRE: -
        //POS: Le pide al usario el nombre del animal rescatado y lo devuelve
        void pedir_nombre(string &nombre);

        //PRE: - 
        //POS: Devuelve la posicion del animal en la lista si el nombre existe en la lista y -1 si no existe       
        int buscar_nombre(string nombre);

        void verificar_nombre(int posicion, string nombre);

        //PRE: El nombre del animal no debe estar en la lista
        //POS: Carga el animal a la lista
        void rescatar_animal(string nombre);

        //PRE: -
        //POS: Imprime por pantalla las opciones del submenu 
        void mostrar_submenu();

        //PRE: -
        //POS: Le pide al usuario que ingrese la opcion del submenu que desea ejecutar y hace la validacion
        void ingresar_opcion_submenu(int &opcion_submenu);

        //PRE: 1 <= opcion_submenu <= 4
        //POS: Realiza la opcion del submenu tomada por el usuario
        void procesar_opcion_submenu(int opcion_submenu);

        //PRE: -
        //POS: Imprime por pantalla las opciones individuales de cada animal de la reserva y le pide la opcion que desea ejecutar
        void  opciones_individuales(int &opcion_individual);

        //PRE: La opcion individual tomada por el usuario, no debe ser la tercera de las opciones individuales 
        //POS:  Realiza la opcion individual tomada por el usuario 
        void procesar_opcion_indivual (int opcion_individual, Animal* animal);

        //PRE: -
        //POS: Recorre toda la lista para que el usuario pueda elegir que hacer (opciones individuales) con cada animal de la reserva
        void eleccion_individual();

        //PRE: -
        //POS: Deja en 0 el hambre de todos los animales de la reserva
        void alimentar_todos();

        //PRE: -
        //POS: Vuelve a poner en 100 la higiene de todos los animales que requieran ducha, en caso contrario imprimira que el animal no requiere ducha
        void duchar_todos();

        //PRE:
        //POS:
        void pedir_espacio(int &espacio);

        //PRE: -
        //POS: Guarda todos los cambios realizados al  archivo csv de animales
        void guardar();

        //PRE: -
        //POS: 
        ~Sistema();
};
#endif //_SISTEMA_H_