#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <string>
#include "Constantes.h"

using namespace std;

// Tenemos que definir cómo traducimos tamaños,
// personalidades y especies desde que los leemos del
// archivo hasta que los usamos en las clases.

// Necesitamos establecer dónde van los métodos de validacion de cada dato

class Animal 
{
    //Atributos
    protected:
        string nombre;
        int hambre;
        int higiene;
        int edad;
        char especie;
        char tamanio;
        char personalidad;
    
    //Metodos 
    public:
        //Constructor por defecto  
        Animal(){};

        // PRE: 
        // POS: devuelve el valor de hambre actual del animal
        int obtener_hambre();

        // PRE: 
        // POS: devuelve el valor de higiene actual del animal
        int obtener_higiene();

        // PRE: 
        // POS: devuelve la edad del animal
        int obtener_edad();

        // PRE: 
        // POS: devuelve el nombre del animal
        string obtener_nombre();

        // PRE: 
        // POS: devuelve el tamaño del animal en formato de texto (forma completa)
        string obtener_tamanio_texto();

        // PRE: 
        // POS: devuelve la especie del animal en formato de texto (forma completa)
        string obtener_especie_texto();

        // PRE: 
        // POS: devuelve la especie del animal en formato de caracter
        char obtener_especie_char();

        string obtener_tamanio();

        // PRE: 
        // POS: devuelve la personalidad del animal en formato de texto (forma completa)
        string obtener_personalidad_texto();

        // PRE: 
        // POS: aumenta el hambre del animal y reduce (o no) su higiene, basándose en las características del animal particular
        void pasar_tiempo();

        //PRE:
        // POS: aumenta 
        void aumentar_hambre();

        void dearmar_higiene();

        // PRE: 
        // POS: reduce el hambre del animal a 0
        void alimentar();

        // PRE: 
        // POS: incrementa la higiene del animal a 100
        void duchar();

        // PRE: 
        // POS: devuelve si el animal requiere ducharse o no
        virtual bool requiere_ducha() = 0;
        
        // PRE: 
        // POS: devuelve el nombre de la comida del animal
        virtual string que_come() = 0;
};

#endif
