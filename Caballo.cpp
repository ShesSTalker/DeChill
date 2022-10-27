#include "Caballo.h"

Caballo::Caballo(string nombre, int edad, char tamanio, char personalidad, char especie) : Animal(nombre, edad, tamanio, personalidad, especie){}

bool Caballo::requiere_ducha()
{
        return true;
}

string Caballo:: que_come()
{
        return "Manzanas";
}
