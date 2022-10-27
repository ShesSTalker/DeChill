#ifndef ROEDOR_H
#define ROEDOR_H

#include "Animal.h"

class Roedor : public Animal
{
    private:
    char especie=ROEDOR;
    string comida ="Queso";
    public:
    Roedor(string nombre, int edad, char tamanio, char personalidad);

    //PRE: -
    //POS: Devuelve verdadero si requiere una ducha y falso si no requiere
    bool requiere_ducha();

    //PRE: -
    //POS: Devuelve la comida que come
    string que_come();
};

#endif
