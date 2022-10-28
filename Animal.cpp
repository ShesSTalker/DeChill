#include "Animal.h"

using namespace std;

int Animal::obtener_hambre()
{
    return hambre;
}

int Animal::obtener_higiene()
{
    return higiene;
}

int Animal::obtener_edad()
{
    return edad;
}

string Animal::obtener_nombre()
{
    return nombre;
}

string Animal::obtener_tamanio_texto()
{
    string tamanio_texto;

    switch(tamanio)
    {
        case DIMINUTO: tamanio_texto = "diminuto";
        break;
        case PEQUENIO: tamanio_texto = "pequeño"; 
        break;
        case MEDIANO: tamanio_texto = "mediano"; 
        break;
        case GRANDE: tamanio_texto = "grande"; 
        break;
        case GIGANTE: tamanio_texto = "gigante";
    }

    return tamanio_texto;
}

string Animal::obtener_especie_texto()
{
    string especie_texto;

    switch(especie)
    {
        case PERRO: especie_texto = "perro"; break;
        case GATO: especie_texto = "gato"; break;
        case CABALLO: especie_texto = "caballo"; break;
        case ROEDOR: especie_texto = "roedor"; break;
        case CONEJO: especie_texto = "conejo"; break;
        case ERIZO: especie_texto = "erizo"; break;
        case LAGARTIJA: especie_texto = "lagartija";
    }

    return especie_texto;
}

char Animal::obtener_especie_char()
{
    char especie_char;

    switch(especie)
    {
        case PERRO: especie_char = 'P'; break;
        case GATO: especie_char = 'G'; break;
        case CABALLO: especie_char = 'C'; break;
        case ROEDOR: especie_char = 'R'; break;
        case CONEJO: especie_char = 'O'; break;
        case ERIZO: especie_char = 'R'; break;
        case LAGARTIJA: especie_char = 'L';
    }

    return especie_char;
}

string Animal::obtener_personalidad_texto()
{
    string personalidad_texto;

    switch(personalidad)
    {
        case DORMILON: personalidad_texto = "dormilón"; break;
        case JUGUETON: personalidad_texto = "juguetón"; break;
        case SOCIABLE: personalidad_texto = "sociable"; break;
        case TRAVIESO: personalidad_texto = "travieso";
    }

    return personalidad_texto;
}

// Setters

void Animal::aumentar_hambre()
{
    int tipo_personalidad = int(personalidad);

    switch(tipo_personalidad)
    {
        case DORMILON:
            hambre += SUMA_HAMBRE / 2;
            break;
        case JUGUETON:
            hambre += SUMA_HAMBRE * 2;
            break;
        case SOCIABLE:
            hambre += SUMA_HAMBRE;
            break;
        case TRAVIESO:
            hambre += SUMA_HAMBRE;
            break;
    }
}

void Animal::dearmar_higiene()
{
     int tipo_personalidad = int(personalidad);

    switch(tipo_personalidad)
    {
        case DORMILON:
            higiene -= HIGIENE_INICIAL;
            break;
        case JUGUETON:
            higiene -= HIGIENE_INICIAL;
            break;
        case SOCIABLE:
            higiene -= HIGIENE_INICIAL / 2;
            break;
        case TRAVIESO:
            higiene -= HIGIENE_INICIAL * 2;
            break;
    }
}

void Animal::alimentar()
{
    hambre = HAMBRE_INICIAL;
}

void Animal::duchar()
{
    higiene = HIGIENE_INICIAL;
}
