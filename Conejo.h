#ifndef CONEJO_H
#define CONEJO_H

#include "Animal.h"

class Conejo : public Animal
{
    public:
    Conejo(string nombre ,int edad, char tamanio, char personalidad);
    string que_come();
};

#endif
