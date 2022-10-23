#ifndef ROEDOR_H
#define ROEDOR_H

#include "Animal.h"

class Roedor : public Animal
{
    public:
        string que_come();
        bool requiere_ducha();
};

#endif
