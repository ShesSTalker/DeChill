#ifndef CONEJO_H
#define CONEJO_H

#include "Animal.h"

class Conejo : public Animal
{
    public:
        // PRE: -
        // POS: inicializa los atributos.
        Conejo(string nombre, int edad, char tamanio, char personalidad);

        // PRE: - 
        // POS: devuelve verdadero si requiere una ducha y falso si no requiere.
        bool requiere_ducha();

        // PRE: -
        // POS: devuelve el nombre de la comida del animal.
        string que_come();

        virtual ~Conejo();
};

#endif
