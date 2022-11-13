#include "Conejo.h"

Conejo::Conejo(string nombre, int edad, char tamanio, char personalidad) 
{
    this -> nombre = nombre;
    this -> hambre = HAMBRE_INICIAL;
    this -> higiene = HIGIENE_INICIAL;
    this -> edad = edad;
    this -> especie = CONEJO;
    this -> tamanio = tamanio;
    this -> personalidad = personalidad;
}


bool Conejo::requiere_ducha()
{
    return true;
}

string Conejo::que_come()
{
    return COMIDA_CONEJO;
}

Conejo::~Conejo(){}