#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

class Perro : public Animal
{
    public:
        // PRE: -
        // POS: inicializa los atributos.
        Perro(string nombre, int edad, char tamanio, char personalidad);

        // PRE: - 
        // POS: devuelve verdadero si requiere una ducha y falso si no requiere.
        bool requiere_ducha();

        // PRE: -
        // POS: devuelve el nombre de la comida del animal.
        string que_come();

        virtual ~Perro();
};

#endif
