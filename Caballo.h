#ifndef CABALLO_H
#define CABALLO_H

#include "Animal.h"

class Caballo : public Animal
{
    private:
    char especie=CABALLO;
    public:
    Caballo(string nombre ,int edad, char tamanio, char personalidad);
    string que_come();
};

#endif
