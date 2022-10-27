#include "Lagartija.h"

Lagartija::Lagartija(string nombre, int edad, char tamanio, char personalidad) : Animal(nombre, edad, tamanio, personalidad) {} 

bool Lagartija:: requiere_ducha()
{
    return false;
}

string Lagartija:: que_come()
{
    return comida;
}