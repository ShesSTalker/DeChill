#include "Roedor.h"

Roedor::Roedor(string nombre, int edad, char tamanio, char personalidad) : Animal(nombre, edad, tamanio, personalidad) {}

bool Roedor:: requiere_ducha()
{
    return false;
}

string Roedor:: que_come()
{
    return comida;
}
