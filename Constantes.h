#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

const string PATH_ANIMALES("animales.csv");
const int MIN = 0;
const int MAX = 100;
const int PASO = 10;

enum Tamanios
{
    DIMINUTO='D',
    PEQUENIO='P',
    MEDIANO='M',
    GRANDE='G',
    GIGANTE='T'
};

const int MAX_TAMANIOS = 4;

enum Personalidades
{
    DORMILON='D',
    JUGUETON='J',
    SOCIABLE='S',
    TRAVIESO='T'
};

const int MAX_PERSONALIDADES = 3;


    const char 
    PERRO='P',
    GATO='G',
    CABALLO='C',
    ROEDOR='R',
    CONEJO='O',
    ERIZO='E',
    LAGARTIJA='L';


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