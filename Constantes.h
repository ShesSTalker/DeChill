#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_
#include <iostream>
#include <string>

using namespace std;

//Constantes leer datos
const string PATH_ANIMALES = "animales.csv";

//Constantes pasar tiempo
const int HAMBRE_INICIAL = 0;
const int HIGIENE_INICIAL = 100;
const int SUMA_HAMBRE = 10;
const int RESTA_HIGIENE = 10;
const int HAMBRE_MAX = 100;
const int HIGIENE_MIN = 0;

const int NULO = -1;

//Constantes tamanio
const char
DIMINUTO = 'd',
PEQUENIO = 'p',
MEDIANO = 'm',
GRANDE = 'g',
GIGANTE = 't';

//Constantes delimitadores tamanio
const int
DELIMITADOR_DIMINUTO = 2,
DELIMITADOR_PEQUENIO_MEDIANO = 10,
DELIMITADOR_GRANDE = 20,
DELIMITADOR_GIGANTE = 50;

//Constantes personalidad
const int
DORMILON = 'd',
JUGUETON = 'j',
SOCIABLE = 's',
TRAVIESO = 't';

//Constantes especie
const char 
PERRO = 'P',
GATO = 'G',
CABALLO = 'C',
ROEDOR = 'R',
CONEJO = 'O',
ERIZO = 'E',
LAGARTIJA = 'L';

//Constantes comida
const string
COMIDA_PERRO = "Huesos",
COMIDA_GATO = "Atun",
COMIDA_CABALLO = "Manzanas",
COMIDA_ROEDOR = "Queso",
COMIDA_CONEJO = "Lechuga",
COMIDA_ERIZO = "Insectos",
COMIDA_LAGARTIJA = "Insectos";


enum opciones_menu_principal {
    LISTAR_ANIMALES = 1 ,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMAL,
    ADOPTAR_ANIMAL,
    GUARDAR_Y_SALIR,
};

const int MAX_OPCIONES_MENU_PRINCIPAL= 6;

enum opciones_submenu {
    ELEGIR_INDIVIDUALMENTE = 1,
    ALIMENTAR_A_TODOS,
    DUCHAR_A_TODOS,
    REGRESAR_INICIO,
};

enum opciones_individuales {
    DUCHAR = 1,
    ALIMENTAR,
    SALTEAR_ANIMAL,
};

#endif 