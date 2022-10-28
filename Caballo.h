#ifndef CABALLO_H
#define CABALLO_H

#include "Animal.h"

class Caballo : public Animal
{
    //Metodos
    public:
        //PRE: -
        //POS: Inicializa los atributos
        Caballo(string nombre, int edad, char tamanio, char personalidad);

        //PRE: - 
        //POS: Devuelve verdadero si requiere una ducha y falso si no requiere
        bool requiere_ducha();

        //PRE: -
        //POS: Devuelve la comida que come 
        string que_come();
};

#endif
