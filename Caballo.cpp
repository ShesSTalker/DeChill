#include "Caballo.h"

Caballo::Caballo(string nombre, int edad, char tamanio, char personalidad)
{
    this -> nombre = nombre;
    this -> hambre = HAMBRE_INICIAL;
    this -> higiene = HIGIENE_INICIAL;
    this -> edad = edad;
    this -> especie = CABALLO;
    this -> tamanio = tamanio;
    this -> personalidad = personalidad;
    this -> estado_animal = NO_ADOPTADO; 
}

bool Caballo::requiere_ducha()
{
        return true;
}

string Caballo:: que_come()
{
        return COMIDA_CABALLO;
}

Caballo::~Caballo(){}