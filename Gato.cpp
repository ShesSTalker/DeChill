#include "Gato.h"

Gato::Gato(string nombre, int edad, char tamanio, char personalidad, char especie) : Animal(nombre, edad, tamanio, personalidad, especie) {}

bool Gato:: requiere_ducha()
{
    return false;
}

string Gato:: que_come()
{
    return "Atun";
}

