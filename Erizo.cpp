#include "Erizo.h"

Erizo::Erizo(string nombre, int edad, char tamanio, char personalidad)
{
    this -> nombre = nombre;
    this -> hambre = HAMBRE_INICIAL;
    this -> higiene = HIGIENE_INICIAL;
    this -> edad = edad;
    this -> tamanio = tamanio;
    this -> personalidad = personalidad;
    this -> especie = ERIZO;
}

bool Erizo::requiere_ducha()
{
    return true;
}

string Erizo:: que_come()
{
    return comida;
}
