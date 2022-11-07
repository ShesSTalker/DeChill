#ifndef ANIMAL_H
#define ANIMAL_H

#include "Constantes.h"

using namespace std;

class Animal 
{
    protected:
        string nombre;
        int hambre;
        int higiene;
        int edad;
        char especie;
        char tamanio;
        char personalidad;
  
    public:
        //Constructor por defecto.
        Animal(){};

        // PRE: -
        // POS: devuelve el valor de hambre actual del animal.
        int obtener_hambre();

        // PRE: -
        // POS: devuelve el valor de higiene actual del animal.
        int obtener_higiene();

        // PRE: -
        // POS: devuelve la edad del animal.
        int obtener_edad();

        // PRE: -
        // POS: devuelve el nombre del animal.
        string obtener_nombre();

        // PRE: -
        // POS: devuelve el tamaño del animal en formato de texto (forma completa).
        string obtener_tamanio_texto();

        // PRE: el objeto es una clase hija de Animal.
        // POS: devuelve la especie del animal en formato de texto (forma completa).
        string obtener_especie_texto();

        // PRE: el objeto es una clase hija de Animal.
        // POS: devuelve la especie del animal en formato de caracter.
        char obtener_especie_caracter();

        // PRE: -
        // POS: devuelve el tamanio del animal en formato de caracter.
        char obtener_tamanio_caracter();

        // PRE: -
        // POS: devuelve la personalidad del animal en formato de texto (forma completa).
        string obtener_personalidad_texto();

        // PRE: -
        // POS: aumenta el hambre del animal (varía dependiendo de la personalidad).
        void aumentar_hambre();

        //PRE: el animal debe requerir ducha.
        //POS: disminuye la higiene del animal (varía dependiendo de la personalidad).
        void dearmar_higiene();

        // PRE: -
        // POS: reduce el hambre del animal a 0.
        void alimentar();

        // PRE: -
        // POS: incrementa la higiene del animal a 100.
        void duchar();

        // PRE: -
        // POS: devuelve si el animal requiere ducharse o no.
        virtual bool requiere_ducha() = 0;
        
        // PRE: -
        // POS: devuelve el nombre de la comida del animal.
        virtual string que_come() = 0;

        // Destructor virtual
        virtual~Animal();
};

#endif
