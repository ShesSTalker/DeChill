#include "Roedor.h"

Roedor::Roedor(string nombre, int edad, char tamanio, char personalidad) 
{
    this -> nombre = nombre;
    this -> hambre = HAMBRE_INICIAL;
    this -> higiene = HIGIENE_INICIAL;
    this -> edad = edad;
    this -> especie = ROEDOR;
    this -> tamanio = tamanio;
    this -> personalidad = personalidad;
    this -> estado_adopcion = NO_ADOPTADO;
}

bool Roedor:: requiere_ducha()
{
    return false;
}

string Roedor:: que_come()
{
    return COMIDA_ROEDOR;
}

Roedor::~Roedor(){}