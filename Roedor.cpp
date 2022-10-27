#include "Roedor.h"

Roedor::Roedor(string nombre, int edad, char tamanio, char personalidad) 
{
    this -> nombre = nombre;
    this -> hambre = HAMBRE_INICIAL;
    this -> higiene = HIGIENE_INICIAL;
    this -> edad = edad;
    this -> tamanio = tamanio;
    this -> personalidad = personalidad;
    this -> especie = ROEDOR;
}

bool Roedor:: requiere_ducha()
{
    return false;
}

string Roedor:: que_come()
{
    return comida;
}
