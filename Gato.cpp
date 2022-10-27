#include "Gato.h"

Gato::Gato(string nombre, int edad, char tamanio, char personalidad) : Animal(nombre, edad, tamanio, personalidad) {}

bool Gato:: requiere_ducha()
{
    return false;
}

string Gato:: que_come()
{
    return "Atun";
}

