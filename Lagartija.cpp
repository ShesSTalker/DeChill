#include "Lagartija.h"

Lagartija::Lagartija(string nombre, int edad, char tamanio, char personalidad)
{
    this -> nombre = nombre;
    this -> hambre = HAMBRE_INICIAL;
    this -> higiene = HIGIENE_INICIAL;
    this -> edad = edad;
    this -> tamanio = tamanio;
    this -> personalidad = personalidad;
    this -> especie = LAGARTIJA;
}

bool Lagartija:: requiere_ducha()
{
    return false;
}

string Lagartija:: que_come()
{
    return "Insectos";
}