#ifndef GATO_H
#define GATO_H

#include "Animal.h"

class Gato : public Animal
{
    public:
    Gato(string nombre ,int edad, char tamanio, char personalidad);
    string que_come();
    bool requiere_ducha();
};

#endif
