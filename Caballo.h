#ifndef CABALLO_H
#define CABALLO_H

#include "Animal.h"

class Caballo : public Animal
{
    //Atributos:
    private: 
    char especie;

    //Metodos
    public:
    Caballo(string nombre, int edad, char tamanio, char personalidad);

    //PRE: - 
    //POS: Devuelve verdadero si requiere una ducha y falso si no requiere
    bool requiere_ducha();

    //PRE: -
    //POS: Devuelve la comida que come 
    string que_come();
};

#endif
