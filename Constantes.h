#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

const string PATH_ANIMALES("animales.csv");
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

const int MAX_TAMANIOS = 4;

enum Personalidades
{
    DORMILON,
    JUGUETON,
    SOCIABLE,
    TRAVIESO
};

const int MAX_PERSONALIDADES = 3;

enum Especies
{
    PERRO,
    GATO,
    CABALLO,
    ROEDOR,
    CONEJO,
    ERIZO,
    LAGARTIJA
};

const int MAX_ESPECIES = 6;

enum opciones_menu_principal {
    MOSTRAR_MENU,
    LISTAR_ANIMALES,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMAL,
    ADOPTAR_ANIMAL,
    GUARDAR_Y_SALIR,
};

const int MAX_OPCIONES_MENU_PRINCIPAL = 6;

#endif 