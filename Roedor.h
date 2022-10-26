#ifndef ROEDOR_H
#define ROEDOR_H

#include "Animal.h"

class Roedor : public Animal
{
    public:
    Roedor(string nombre ,int edad, char tamanio, char personalidad);
    string que_come();
    bool requiere_ducha();
};

#endif
