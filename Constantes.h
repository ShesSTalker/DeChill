#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

const string PATH_ANIMALES("animales.csv");

const int HAMBRE_INICIAL = 0;
const int HIGIENE_INICIAL = 100;
const int SUMA_HAMBRE = 10;
const int RESTA_HIGIENE = 10;

const int NULO = -1;

//Constantes tamanio
const char
DIMINUTO = 'd',
PEQUENIO = 'p',
MEDIANO = 'm',
GRANDE = 'g',
GIGANTE = 't';

const int MAX_TAMANIOS = 4;

//Constantes personalidad
const int
DORMILON = 'd',
JUGUETON = 'j',
SOCIABLE = 's',
TRAVIESO = 't';

const int MAX_PERSONALIDADES = 3;

//Constantes especie
const char 
PERRO = 'P',
GATO = 'G',
CABALLO = 'C',
ROEDOR = 'R',
CONEJO = 'O',
ERIZO = 'E',
LAGARTIJA = 'L';


const int MAX_ESPECIES = 6;

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
    LISTAR_ANIMALES = 1,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMAL,
    ADOPTAR_ANIMAL,
    GUARDAR_Y_SALIR,
};

enum opciones_submenu {
    ELEGIR_INDIVIDUALMENTE = 1,
    ALIMENTAR_A_TODOS,
    DUCHAR_A_TODOS,
    REGRESAR_INICIO,
};

const int MAX_OPCIONES_MENU_PRINCIPAL = 6;

#endif 