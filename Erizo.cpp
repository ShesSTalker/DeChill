#include "Erizo.h"

Erizo::Erizo(string nombre, int edad, char tamanio, char personalidad, char especie) : Animal(nombre, edad, tamanio, personalidad, especie) {}

bool Erizo::requiere_ducha()
{
    return true;
}

string Erizo:: que_come()
{
    return "Insectos";
}
