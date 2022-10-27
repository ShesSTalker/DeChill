#include "Caballo.h"

Caballo::Caballo(string nombre, int edad, char tamanio, char personalidad) : Animal(nombre, edad, tamanio, personalidad){}

bool Caballo::requiere_ducha()
{
        return true;
}

string Caballo:: que_come()
{
        return "Manzanas";
}
