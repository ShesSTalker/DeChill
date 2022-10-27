#include "Conejo.h"

Conejo::Conejo(string nombre, int edad, char tamanio, char personalidad) 
{
    this -> nombre = nombre;
    this -> hambre = HAMBRE_INICIAL;
    this -> higiene = HIGIENE_INICIAL;
    this -> edad = edad;
    this -> tamanio = tamanio;
    this -> personalidad = personalidad;
    this -> especie = CONEJO;
}


bool Conejo::requiere_ducha()
{
    return true;
}

string Conejo::que_come()
{
    return comida;
}
