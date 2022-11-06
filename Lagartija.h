#ifndef LAGARTIJA_H
#define LAGARTIJA_H

#include "Animal.h"

class Lagartija : public Animal
{
    public:
        // PRE: -
        // POS: crea un objeto Lagartija e inicializa los atributos.
        Lagartija(string nombre, int edad, char tamanio, char personalidad);

        // PRE: - 
        // POS: devuelve verdadero si requiere una ducha y falso si no requiere.
        bool requiere_ducha();

        // PRE: -
        // POS: devuelve el nombre de la comida del animal.
        string que_come();

        virtual ~Lagartija();
};

#endif
