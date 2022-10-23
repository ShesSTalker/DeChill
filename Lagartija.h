#ifndef LAGARTIJA_H
#define LAGARTIJA_H

#include "Animal.h"

class Lagartija : public Animal
{
    public:
        string que_come();
        bool requiere_ducha();
};

#endif
