#ifndef CONEJO_H
#define CONEJO_H

#include "Animal.h"

class Conejo : public Animal
{
    //Metodos
    public:
        Conejo(string nombre, int edad, char tamanio, char personalidad);

        //PRE:
        //POS: Devuelve verdadero si requiere una ducha y falso si no requiere
        bool requiere_ducha();

        //PRE: -
        //POS: Devuelve la comida que come
        string que_come();
};

#endif
