#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

class Perro : public Animal
{
    public:
    Perro(string nombre, int edad, char tamanio, char personalidad, char especie);

    //PRE: -
    //POS: Devuelve verdadero si requiere una ducha y falso si no requiere
    bool requiere_ducha();

    //PRE: -
    //POS: Devuelve la comida que come
    string que_come();
};

#endif
