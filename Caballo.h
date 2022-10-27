#ifndef CABALLO_H
#define CABALLO_H

#include "Animal.h"

class Caballo : public Animal
{
    //Metodos
    public:
    //PRE: -
    //POS: Inicializa nombre = nombre, edad = edad, tamanio = tamanio y personalidad = personalidad 
    Caballo(string nombre ,int edad, char tamanio, char personalidad);
    //PRE: -
    //POS: Devuelve la comida que come 
    string que_come();
};

#endif
