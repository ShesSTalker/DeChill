#include "Perro.h"

Perro::Perro(string nombre, int edad, char tamanio, char personalidad)
{
    this -> nombre = nombre;
    this -> hambre = HAMBRE_INICIAL;
    this -> higiene = HIGIENE_INICIAL;
    this -> edad = edad;
    this -> especie = PERRO;
    this -> tamanio = tamanio;
    this -> personalidad = personalidad;
}

bool Perro::requiere_ducha()
{
    return true;
}

string Perro:: que_come()
{
    return COMIDA_PERRO;
}
