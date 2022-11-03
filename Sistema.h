#ifndef SISTEMA_H
#define SISTEMA_H

#include "Menu.h"

class Sistema
{
    private:
        Lista<Animal*>* animales;
        Animal **punteros;
        int cantidad_de_punteros; 

    public:
        Sistema();

        //PRE: - 
        //POS: lee los datos del archivo CSV de la reserva.
        void leer_datos();

        //PRE: 0 < opcion_tomada <= 5.
        //POS: procesa opcion_tomada para ejecutar las operaciones de la opción correspondiente.
        void procesar_opcion(int opcion_tomada);

        //PRE: -
        //POS: guarda todos los cambios realizados al archivo CSV de la reserva.
        void guardar();

        ~Sistema();

    private:
        //PRE: -
        //POS: carga los parámetros como un animal nuevo en la reserva.
        void cargar_animal(char especie, string nombre, int edad, char tamanio, char personalidad);

        // PRE: -
        // POS: aumenta el hambre del animal y reduce (o no) su higiene, basándose en las características del animal particular.
        void pasar_tiempo();

        //PRE: -
        //POS: imprime por pantalla todos los animales de la lista.
        void listar_animales(); 

        //PRE: -
        //POS: muestra por pantalla la información del animal.
        void mostrar_animal(Animal* mi_animal);

        //PRE: -
        //POS: le pide al usario que ingrese el nombre del animal rescatado.
        void pedir_nombre(string &nombre);

        //PRE: - 
        //POS: devuelve la posicion del animal en la lista si el nombre existe en la lista y -1 si no existe.      
        int buscar_nombre(string nombre);

        //PRE: -
        //POS: si el nombre ya existe en la lista, le da la opcion al usuario de volver a ingresar otro nombre o volver al menú principal. Si no existe, rescata al animal. 
        void verificar_nombre(int posicion, string nombre);

        //PRE: el nombre del animal no debe estar en la lista.
        //POS: pide el resto de datos del animal para rescatarlo y agregarlo a a la lista de animales.
        void rescatar_animal(string nombre);

        //PRE: -
        //POS: imprime por pantalla las opciones del submenú.
        void mostrar_submenu();

        //PRE: -
        //POS: le pide al usuario que ingrese la opción del submenú que desea ejecutar y realiza la validación correspondiente.
        void ingresar_opcion_submenu(string &opcion_submenu);

        //PRE: 1 <= opcion_submenu <= 3.
        //POS: realiza la opcion del submenú tomada por el usuario.
        void procesar_opcion_submenu(string opcion_submenu);

        //PRE: - 
        //POS: imprime por pantalla las opciones individuales para cada animal de la reserva.
        void mostrar_opciones_individuales();

        //PRE: -
        //POS: le pide al usuario la opción individual que desea ejecutar y la valida.
        void  pedir_opciones_individuales(string &opcion_individual);

        //PRE: la opción individual tomada por el usuario no debe ser la tercera de las opciones individuales.
        //POS: realiza la opción individual tomada por el usuario.
        void procesar_opcion_individual (int opcion_individual, Animal* animal);

        //PRE: -
        //POS: recorre toda la lista para que el usuario pueda elegir qué hacer (opciones individuales) con cada animal de la reserva.
        void eleccion_individual();

        //PRE: -
        //POS: reduce a 0 el hambre de todos los animales de la reserva.
        void alimentar_todos();

        //PRE: -
        //POS: por cada animal de la reserva, incrementa su higiene a 100 o imprime que no requiere una ducha.
        void duchar_todos();

        //PRE: -
        //POS: le pide al usuario el espacio disponible para la adopción de un animal y hace la validación correspondiente.
        void pedir_espacio(string &espacio);

        //PRE: -
        //POS: valida que el string recibido conste completamente de números, devolviendo true en caso afirmativo y false en caso contrario.
        bool cadena_numeros_valida(string numeros);

        //PRE: -
        //POS: imprime por pantalla los datos del animal de la reserva que cumple con el espacio dispobnible por el usuario
        void mostrar_animal_espacio(Animal* animal, int posicion);

        //PRE: -
        //POS: valida los animales para mostrar los que cumplen con el espacio disponible por el usuario.
        void validar_animales_espacio(Animal* animal, string espacio, int posicion); 

        //PRE: -
        //POS: pide el número del animal que el usuario desea adoptar o 0 en caso de que desee cancelar la adopción y lo devuelve.
        string pedir_opcion_adopcion();

        //PRE: -
        //POS: muestra por pantalla todos los animales que cumplen con el espacio con el que dispone el usuario.
        void listar_animales_espacio(string espacio, int posicion);
};

#endif