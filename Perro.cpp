#include "Perro.h"

Perro::Perro(string nombre, int edad, char tamanio, char personalidad, char especie) : Animal(nombre, edad, tamanio, personalidad, especie) {}

bool Perro::requiere_ducha()
{
    return true;
}

string Perro:: que_come()
{
    return "Huesos";
}
