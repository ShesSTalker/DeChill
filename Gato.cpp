#include "Gato.h"

Gato::Gato(string nombre, int edad, char tamanio, char personalidad)
{
    this -> nombre = nombre;
    this -> hambre = HAMBRE_INICIAL;
    this -> higiene = HIGIENE_INICIAL;
    this -> edad = edad;
    this -> tamanio = tamanio;
    this -> personalidad = personalidad;
    this -> especie = GATO;
}

bool Gato:: requiere_ducha()
{
    return false;
}

string Gato:: que_come()
{
    return "Atun";
}

