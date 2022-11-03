#ifndef GATO_H
#define GATO_H

#include "Animal.h"

class Gato : public Animal
{
    public:
        // PRE: -
        // POS: inicializa los atributos.
        Gato(string nombre, int edad, char tamanio, char personalidad);

        // PRE: - 
        // POS: devuelve verdadero si requiere una ducha y falso si no requiere.
        bool requiere_ducha();

        // PRE: -
        // POS: devuelve el nombre de la comida del animal.
        string que_come();  
};

#endif
