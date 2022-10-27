#include "Roedor.h"

Roedor::Roedor(string nombre, int edad, char tamanio, char personalidad, char especie) : Animal(nombre, edad, tamanio, personalidad, especie) {}

bool Roedor:: requiere_ducha()
{
    return false;
}

string Roedor:: que_come()
{
    return "Queso";
}
