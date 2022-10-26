#ifndef ERIZO_H
#define ERIZO_H

#include "Animal.h"

class Erizo : public Animal
{
    public:
    Erizo(string nombre ,int edad, char tamanio, char personalidad);
    string que_come();
};

#endif
