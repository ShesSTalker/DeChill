#include "Conejo.h"

Conejo::Conejo(string nombre, int edad, char tamanio, char personalidad) : Animal(nombre, edad, tamanio, personalidad){}

bool Conejo::requiere_ducha()
{
    return true;
}

string Conejo::que_come()
{
    return comida;
}
