#include "Gato.h"

Gato::Gato(string nombre, int edad, char tamanio, char personalidad)
{
    this -> nombre = nombre;
    this -> hambre = HAMBRE_INICIAL;
    this -> higiene = HIGIENE_INICIAL;
    this -> edad = edad;
    this -> especie = GATO;
    this -> tamanio = tamanio;
    this -> personalidad = personalidad;
}

bool Gato:: requiere_ducha()
{
    return false;
}

string Gato:: que_come()
{
    return COMIDA_GATO;
}

