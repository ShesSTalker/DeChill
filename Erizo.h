#ifndef ERIZO_H
#define ERIZO_H

#include "Animal.h"

class Erizo : public Animal
{
    public:
        // PRE: -
        // POS: crea un objeto Erizo e inicializa los atributos.
        Erizo(string nombre, int edad, char tamanio, char personalidad);

        // PRE: - 
        // POS: devuelve verdadero si requiere una ducha y falso si no requiere.
        bool requiere_ducha();
    
        // PRE: -
        // POS: devuelve el nombre de la comida del animal.
        string que_come();

        virtual ~Erizo();
};

#endif
