#ifndef ERIZO_H
#define ERIZO_H

#include "Animal.h"

class Erizo : public Animal
{
    public:
    
    //PRE: -
    //POS: Devuelve verdadero si requiere una ducha y falso si no requiere
    bool requiere_ducha();
    
    //PRE: -
    //POS: Devuelve la comida que come
    string que_come();
};

#endif
