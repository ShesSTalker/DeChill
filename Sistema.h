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

        void verificar_nombre(int posicion);

        //PRE: El nombre del animal no debe estar en la lista
        //POS: Carga el animal a la lista
        void rescatar_animal();

        void mostrar_submenu();

        void ingresar_opcion_submenu(int &opcion_submenu);

        void procesar_opcion_submenu(int opcion_submenu);

        void  opciones_individuales(int &opcion_individual);

        void procesar_opcion_indivual (int opcion_individual, Animal* animal);

        void eleccion_individual();

        void alimentar_todos();

        void duchar_todos();

        void pedir_espacio(int &espacio);

        //PRE: -
        //POS: Guarda todos los cambios realizados al  archivo csv de animales
        void guardar();

        //PRE: -
        //POS: 
        ~Sistema();
};
#endif //_SISTEMA_H_