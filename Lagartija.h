#ifndef LAGARTIJA_H
#define LAGARTIJA_H

#include "Animal.h"

class Lagartija : public Animal
{
    //Atributos
    private:
    char especie;
    string comida;
    //Metodos
    public:
    Lagartija(string nombre, int edad, char tamanio, char personalidad);


        //PRE: -
        //POS: Devuelve verdadero si requiere una ducha y falso si no requiere
        bool requiere_ducha();

        //PRE: -
        //POS: Devuelve la comida que come
        string que_come();
};

#endif
