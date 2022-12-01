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
        case DIMINUTO: 
            tamanio_texto = DIMINUTO_TEXTO;
            break;
        
        case PEQUENIO: 
            tamanio_texto = PEQUENIO_TEXTO; 
            break;     
        
        case MEDIANO:
            tamanio_texto = MEDIANO_TEXTO; 
            break;
        
        case GRANDE: 
            tamanio_texto = GRANDE_TEXTO; 
            break;
        
        case GIGANTE: 
            tamanio_texto = GIGANTE_TEXTO;
            break;
    }

    return tamanio_texto;
}

string Animal::obtener_especie_texto()
{
    string especie_texto;

    switch(especie)
    {
        case PERRO: 
            especie_texto = PERRO_TEXTO; 
            break;
        
        case GATO: 
            especie_texto = GATO_TEXTO; 
            break;
        
        case CABALLO: 
            especie_texto = CABALLO_TEXTO;
            break;
        
        case ROEDOR: 
            especie_texto = ROEDOR_TEXTO; 
            break;
        
        case CONEJO: 
            especie_texto = CONEJO_TEXTO; 
            break;
        
        case ERIZO: 
            especie_texto = ERIZO_TEXTO; 
            break;
        
        case LAGARTIJA: 
            especie_texto = LAGARTIJA_TEXTO;
            break;
    }

    return especie_texto;
}

char Animal::obtener_especie_caracter()
{
    char especie_caracter;

    switch(especie)
    {
        case PERRO: 
            especie_caracter = PERRO; 
            break;
        
        case GATO: 
            especie_caracter = GATO;
            break;
        
        case CABALLO:
            especie_caracter = CABALLO; 
            break;
        
        case ROEDOR: 
            especie_caracter = ROEDOR; 
            break;
        
        case CONEJO: 
            especie_caracter = CONEJO; 
            break;
        
        case ERIZO: 
            especie_caracter = ERIZO; 
            break;
        
        case LAGARTIJA: 
            especie_caracter = LAGARTIJA;
            break;
    }

    return especie_caracter;
}

char Animal::obtener_tamanio_caracter()
{
    return tamanio;
}

string Animal::obtener_personalidad_texto()
{
    string personalidad_texto;
    int tipo_personalidad = int(personalidad);

    switch(tipo_personalidad)
    {
        case DORMILON: 
            personalidad_texto = DORMILON_TEXTO; 
            break;
        
        case JUGUETON: 
            personalidad_texto = JUGUETON_TEXTO; 
            break;
        
        case SOCIABLE: 
            personalidad_texto = SOCIABLE_TEXTO; 
            break;
        
        case TRAVIESO: 
            personalidad_texto = TRAVIESO_TEXTO;
            break;
    }
    return personalidad_texto;
}

int Animal::obtener_estado_animal()
{
    return estado_animal;
}

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

        default:
            hambre += SUMA_HAMBRE;
    }

    if(hambre > HAMBRE_MAX)
    {
        hambre = HAMBRE_MAX;
    }
}

void Animal::dearmar_higiene()
{
    int tipo_personalidad = int(personalidad);

    switch(tipo_personalidad)
    {
        case SOCIABLE:
            higiene -= RESTA_HIGIENE / 2;
            break;
        
        case TRAVIESO:
            higiene -= RESTA_HIGIENE * 2;
            break;
        
        default:
            higiene -= RESTA_HIGIENE;
    }
    
    if (higiene < HIGIENE_MIN)
    {
        higiene = HIGIENE_MIN;
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

void Animal::cambiar_estado_animal(int estado)
{
    estado_animal = estado;
}

void Animal::mostrar_animal()
{
    cout <<
    "Nombre: " << obtener_nombre() << endl <<
    "Edad: " << obtener_edad() << endl <<
    "Tamanio: " << obtener_tamanio_texto() << endl <<
    "Especie: " << obtener_especie_texto() << endl <<
    "Personalidad: " << obtener_personalidad_texto() << endl <<
    "Hambre: " << obtener_hambre() << endl <<
    "Higiene: " << obtener_higiene() << endl << endl <<
    "---------------------------------------------------" << endl << endl;
}

Animal::~Animal(){}