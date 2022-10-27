#ifndef GATO_H
#define GATO_H

#include "Animal.h"

class Gato : public Animal
{
    public:
    Gato(string nombre, int edad, char tamanio, char personalidad, char especie);

    //PRE: -
    //POS: Devuelve verdadero si requiere una ducha y falso si no requiere
    bool requiere_ducha();

    //PRE: -
    //POS: Devuelve la comida que come
    string que_come();
    
};

#endif
