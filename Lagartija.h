#ifndef LAGARTIJA_H
#define LAGARTIJA_H

#include "Animal.h"

class Lagartija : public Animal
{
    public:
    Lagartija(string nombre ,int edad, char tamanio, char personalidad);
    string que_come();
    bool requiere_ducha();
};

#endif
