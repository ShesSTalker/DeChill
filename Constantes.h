#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

const int MIN = 0;
const int MAX = 100;
const int PASO = 10;

enum Tamanios
{
    DIMINUTO,
    PEQUENIO,
    MEDIANO,
    GRANDE,
    GIGANTE
};

enum Personalidades
{
    DORMILON,
    JUGUETON,
    SOCIABLE,
    TRAVIESO
};

enum Especies
{
    PERRO = 'P',
    GATO = 'G',
    CABALLO = 'C',
    ROEDOR = 'R',
    CONEJO = 'O',
    ERIZO = 'E',
    LAGARTIJA = 'L'
};

enum opciones_menu_principal {
LISTAR_ANIMALES = 1,
RESCATAR_ANIMALES,
BUSCAR_ANIMAL,
CUIDAR_ANIMAL,
ADOPTAR_ANIMAL,
GUARDAR_Y_SALIR,
};

#endif 