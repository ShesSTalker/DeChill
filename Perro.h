#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

class Perro : public Animal
{
    public:
    Perro(string nombre ,int edad, char tamanio, char personalidad);
    string que_come();
};

#endif
