#include "Casilla.h"
Casilla::Casilla(string nombre, string terreno, int costo, char contenido)
{   
    this->nombre = nombre;
    this -> terreno = terreno;
    this->costo=costo;
    this->contenido=contenido;
}

void Casilla::asignar_contenido(char contenido)
{
    this->contenido=contenido;
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

char Casilla::obtener_contenido()
{
    return contenido;
}

int Casilla::obtener_costo()
{
    return costo;
}

Casilla::~Casilla(){}