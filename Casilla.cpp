#include "Casilla.h"
Casilla::Casilla(string nombre, string terreno, int costo)
{   
    this->nombre = nombre;
    this -> terreno = terreno;
    this->costo=costo;
}

string Casilla::obtener_nombre()
{   
    return nombre;
}

string Casilla::obtener_terreno()
{   
    return terreno;
}

char Casilla::obtener_terreno_char()
{   
    return terreno[0];
}

int Casilla::obtener_costo()
{
    return costo;
}

Casilla::~Casilla(){}