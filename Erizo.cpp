#include "Erizo.h"

Erizo::Erizo(string nombre, int edad, char tamanio, char personalidad) : Animal(nombre, edad, tamanio, personalidad) {}

bool Erizo::requiere_ducha()
{
    return true;
}

string Erizo:: que_come()
{
    return comida;
}
