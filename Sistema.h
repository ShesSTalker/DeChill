#ifndef SISTEMA_H
#define SISTEMA_H

#include<stdlib.h>
#include "Menu.h"
#include "Auto.h"
#include "Vector.h"
#include "Grafo.h"
#include <fstream>
#include "Constantes.h"
#include "Perro.h"
#include "Caballo.h"
#include "Gato.h"
#include "Lagartija.h"
#include "Erizo.h"
#include "Roedor.h"
#include "Conejo.h"
#include "Mapa.h"
#include "Arbol.h"


class Sistema
{
    //Atributos
    private:
        ArbolB<Animal>* arbol_b;
        Menu * menu;
        Mapa * mapa;
        Grafo * grafo;
        Auto * vehiculo;
    //Metodos
    public:
        //PRE: -
        //POS: crea un objeto Sistema e incializa los atributos. 
        Sistema();

        //PRE: el archivo debe estar bien formado
        //POS: lee los datos del archivo PATH_ANIMALES de la reserva.
        void leer_animales();

        //PRE: el archivo debe estar bien formado
        //POS: carga el mapa del archivo PATH_MAPA al grafo del sistema
        void cargar_mapa_grafo();

        //PRE: 0 < opcion_tomada <= 6.
        //POS: procesa opcion_tomada para ejecutar las operaciones de la opción correspondiente.
        void procesar_opcion(int opcion_tomada);

        //PRE: -
        //POS: guarda todos los cambios realizados al archivo CSV de la reserva.
        void guardar();
        
        //PRE: - 
        //POS: limpia la pantalla para mejorar la interfaz del usuario.
        void limpiar_pantalla();

        //PRE: -
        //POS: libera la memoria asociada con este objeto.
        ~Sistema();

    private:

        //PRE: -
        //POS: carga los parámetros como un animal nuevo en la reserva.
        void cargar_animal(char especie, string nombre, int edad, char tamanio, char personalidad);


        //PRE: -    
        //POS: carga el grafo con los caminos.
        void cargar_caminos();

        //PRE: -    
        //POS: carga el mapa con su contenido ( Auto y Animales)
        void cargar_contenido_mapa();

        //PRE: -    
        //POS: le pide al usuario ingresar la fila y columna donde desea moverse
        void pedir_movimiento(int &fila , int &columna);

        //PRE: -    
        //POS: mueve el vehiculo a la posicion indicada
        void procesar_movimiento();

        //PRE: -
        //POS: devuelve verdadero si esta dentro del rango del mapa y falso en caso contrario.
        bool dentro_de_rango(int fila, int columna);

        // PRE: -
        // POS: aumenta el hambre del animal y reduce (o no) su higiene, basándose en las características del animal particular.
        void pasar_tiempo();

        //PRE: -
        //POS: lista los animales del la reserva.
        void listar_animales();

        //PRE: -
        //POS: llama a los metodos correspondientes a buscar animal.
        void buscar_animal();

        //PRE: -
        //POS: le pide al usario que ingrese el nombre del animal rescatado.
        void pedir_nombre(string &nombre);

        //PRE: - 
        //POS: devuelve el animal si se encuentra en el arbol y NULL en caso contrario      
        Animal* buscar_nombre(string nombre);

        //PRE: -
        //POS: imprime por pantalla los datos del animal si el nombre fue encontrado en la reserva o un mensaje de error en caso contrario.
        void mostrar_busqueda(Animal* animal);

        //PRE: -
        //POS: llama a los metodos correspondientes a cuidar animal.
        void cuidar_animal();

        //PRE: -
        //POS: devuelve un tamanio de animal aleatorio
        string tamanio_animal_aleatorio(int numero);

        //PRE: -
        //POS: devuelve una personalidad de animal aleatorio
        string personalidad_animal_aleatoria (int numero);

        //PRE: el nombre del animal no debe estar en la lista.
        //POS: pide el resto de datos del animal para rescatarlo y agregarlo a a la lista de animales.
        void rescatar_animal(string nombre, char especie);

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
        //POS: llama a los metodos correspondientes a elegir individualmente.
        void elegir_individualmente();

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
        //POS: valida los animales para mostrar los que cumplen con el espacio disponible definido por el usuario.
        void validar_animales_espacio(Animal* animal, string espacio, int posicion, bool* animales_validos, int &contador_validos); 
        
        //PRE: -
        //POS: valida los animales que cumplen con el espacio disponible definido por el usuario. Si posición está en -1, el usuario quiere cancelar la adopción.
        bool posicion_espacio_validado(int posicion, bool* animales_validos);

        //PRE: -
        //POS: pide el número del animal que el usuario desea adoptar o 0 en caso de que desee cancelar la adopción y lo devuelve.
        string pedir_opcion_adopcion(bool* animales_validos);

        //PRE: -
        //POS: muestra por pantalla todos los animales que cumplen con el espacio con el que dispone el usuario.
        void listar_animales_espacio(string espacio, int posicion, bool* animales_validos, int &animales_validados);
};

#endif