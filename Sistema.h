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
        //POS:
        Sistema();

        //PRE: - 
        //POS: Lee los datos del arcivo csv de animales
        void leer_datos();

        //PRE: opcion_tomada debe ser 0 < opcion_tomada <= 5
        //POS: Procesa opcion_tomada para ejecutar las operaciones de la opcion elejida por el usuario
        void procesar_opcion(int opcion_tomada);

        //PRE: -
        //POS: Guarda todos los cambios realizados al archivo csv de animales
        void guardar();

        //PRE: -
        //POS: 
        ~Sistema();

    private:
        //PRE: -
        //POS: carga el animal en la lista de animales
        void cargar_animal(char especie, string nombre, int edad, char tamanio, char personalidad);

        // PRE: -
        // POS: aumenta el hambre del animal y reduce (o no) su higiene, basándose en las características del animal particular
        void pasar_tiempo();

        //PRE: -
        //POS: Imprime por pantalla todos los animales de la lista.
        void listar_animales(); 

        //PRE: -
        //POS: Muestra por pantalla la informacion del animal
        void mostrar_animal(Animal* mi_animal);

        //PRE: -
        //POS: Le pide al usario que ingrese el nombre del animal rescatado
        void pedir_nombre(string &nombre);

        //PRE: - 
        //POS: Devuelve la posicion del animal en la lista si el nombre existe en la lista y -1 si no existe       
        int buscar_nombre(string nombre);

        //PRE: -
        //POS: Si el nombre ya existe en la lista le da la opcion al usuario de volver a ingresar otro nombre o volver al menu inicial, si no existe, rescata al animal. 
        void verificar_nombre(int posicion, string nombre);

        //PRE: El nombre del animal no debe estar en la lista
        //POS: Pide el resto de datos del animal para rescatarlo y aniadirlo a a la lista de animales
        void rescatar_animal(string nombre);

        //PRE: -
        //POS: Imprime por pantalla las opciones del submenu 
        void mostrar_submenu();

        //PRE: -
        //POS: Le pide al usuario que ingrese la opcion del submenu que desea ejecutar y hace la validacion
        void ingresar_opcion_submenu(int &opcion_submenu);

        //PRE: 1 <= opcion_submenu <= 3
        //POS: Realiza la opcion del submenu tomada por el usuario
        void procesar_opcion_submenu(int opcion_submenu);

        //PRE: - 
        //POS: Imprime por pantalla las opciones individuales de cada animal de la reserva
        void mostrar_opciones_individuales();

        //PRE: -
        //POS: le pide al usuario la opcion individual que desea ejecutar y la valida
        void  pedir_opciones_individuales(int &opcion_individual);

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

        //PRE: -
        //POS: Le pide al usuario el espacio disponible para el animal y hace la validacion
        void pedir_espacio(string espacio);

        //PRE: -
        //POS: valida que el string recibido conste completamente de numeros, devolviendo true en caso afirmativo y false en caso contrario
        bool cadena_numeros_valida(string numeros);

        //PRE: -
        //POS: Imprime por pantalla los datos del animal de la reserva que cumple con el espacio dispobnible por el usuario
        void mostrar_animal_espacio(Animal* animal, int posicion);

        //PRE: -
        //POS: Valida los animales para mostrar los que cumplen con el espacio disponible por el usuario
        void validar_animales_espacio(Animal* animal, string espacio, int posicion); 

        //PRE: -
        //POS: Pide el numero del animal que el usuario desea adoptar o 0 en caso de que desee cancelar la adopcion y lo devuelve
        int pedir_opcion_adopcion();

        //PRE: -
        //POS: Muestra por pantalla todos los animales que cumplen con el espacio con el que dispone el usuario
        void listar_animales_espacio(string espacio, int posicion);
};
#endif //_SISTEMA_H_