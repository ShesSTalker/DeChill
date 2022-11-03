#include "Lagartija.h"

Lagartija::Lagartija(string nombre, int edad, char tamanio, char personalidad)
{
    this -> nombre = nombre;
    this -> hambre = HAMBRE_INICIAL;
    this -> higiene = HIGIENE_INICIAL;
    this -> edad = edad;
    this -> especie = LAGARTIJA;
    this -> tamanio = tamanio;
    this -> personalidad = personalidad;
}

bool Lagartija:: requiere_ducha()
{
    return false;
}

string Lagartija:: que_come()
{
    return COMIDA_LAGARTIJA;
}

Lagartija::~Lagartija(){};