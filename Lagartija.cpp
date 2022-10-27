#include "Lagartija.h"

Lagartija::Lagartija(string nombre, int edad, char tamanio, char personalidad, char especie) : Animal(nombre, edad, tamanio, personalidad, especie) {} 

bool Lagartija:: requiere_ducha()
{
    return false;
}

string Lagartija:: que_come()
{
    return "Insectos";
}