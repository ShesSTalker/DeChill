#include "Conejo.h"

Conejo::Conejo(string nombre, int edad, char tamanio, char personalidad, char especie) : Animal(nombre, edad, tamanio, personalidad, especie){}

bool Conejo::requiere_ducha()
{
    return true;
}

string Conejo::que_come()
{
    return "Lechuga";
}
