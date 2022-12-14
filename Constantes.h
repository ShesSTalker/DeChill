#ifndef CONSTANTES_H
#define CONSTANTES_H
#include <iostream>
#include <string>

using namespace std;

const int CANTIDAD_MAXIMA_FUGADOS = 3;

// Constantes emojis
const string
EMOJI_CONEJO = "\U0001f407",
EMOJI_PERRO = 	"\U0001f415",
EMOJI_GATO = "\U0001f408",
EMOJI_CABALLO = "\U0001f40e",
EMOJI_ROEDOR = "\U0001f400",
EMOJI_ERIZO = "\U0001f994",
EMOJI_LAGARTIJA = "\U0001f98e",
EMOJI_LISTA = "\U0001f4c4",
EMOJI_AUTO = "\U0001f697",
EMOJI_LUPA = "\U0001f50d",
EMOJI_CUIDAR = "\u2764\uFE0F\u200D\U0001fa79",
EMOJI_ADOPTAR = "\U0001f423",
EMOJI_GASOLINA = "\u26FD",
EMOJI_PUERTA = "\U0001f6aa",
EMOJI_TRISTE = "\U0001f622";

// Constantes leer datos
const string 
PATH_ANIMALES = "animales.csv",
PATH_MAPA = "mapa.csv";

// Constantes Grafos
const int INFINITO = 100000;

// Constantes Mapa
const string 
MONTANIA= "Montania",
PRECIPICIO= "Precipicio",
TIERRA= "Tierra",
CAMINO= "Camino";

const char
VACIO = ' ',
AUTO = 'A';

const int 
FILA_INICIAL_AUTO = 0,
COLUMNA_INICIAL_AUTO = 0,
ANIMALES_MAPA = 5;

// Constantes pasar tiempo
const int
HAMBRE_INICIAL = 0,
HIGIENE_INICIAL = 100,
SUMA_HAMBRE = 10,
RESTA_HIGIENE = 10,
HAMBRE_MAX = 100,
HIGIENE_MIN = 0;

// Constante delimitador edad
const int DELIMITADOR_EDAD = 101;

// Constante cantidad de tamanios
const int CANTIDAD_TAMANIOS = 5;

// Constante cantidad de personalidades
const int CANTIDAD_PERSONALIDADES = 4;

//Constante de elemento no encontrado
const int NO_ENCONTRO = -1;

// Constantes tamanio (char)
const char
DIMINUTO = 'd',
PEQUENIO = 'p',
MEDIANO = 'm',
GRANDE = 'g',
GIGANTE = 't';

// Constantes tamanio (string)
const string
DIMINUTO_TEXTO = "diminuto",
PEQUENIO_TEXTO = "pequenio",
MEDIANO_TEXTO = "mediano",
GRANDE_TEXTO = "grande",
GIGANTE_TEXTO = "gigante";

// Constantes delimitadores tamanio 
const int
DELIMITADOR_DIMINUTO = 2,
DELIMITADOR_PEQUENIO_MEDIANO = 10,
DELIMITADOR_GRANDE = 20,
DELIMITADOR_GIGANTE = 50;

// Constantes personalidad (int)
const int
DORMILON = 'd',
JUGUETON = 'j',
SOCIABLE = 's',
TRAVIESO = 't';

// Constantes personalidad (string)
const string
DORMILON_TEXTO = "dormilon",
JUGUETON_TEXTO = "jugueton",
SOCIABLE_TEXTO = "sociable",
TRAVIESO_TEXTO = "travieso";

// Constantes especie (char)
const char 
PERRO = 'P',
GATO = 'G',
CABALLO = 'C',
ROEDOR = 'R',
CONEJO = 'O',
ERIZO = 'E',
LAGARTIJA = 'L';
const int
CANTIDAD_ESPECIES= 7;

// Constantes especie (string)
const string
PERRO_TEXTO = "perro",
GATO_TEXTO = "gato",
CABALLO_TEXTO = "caballo",
ROEDOR_TEXTO = "roedor",
CONEJO_TEXTO = "conejo",
ERIZO_TEXTO = "erizo",
LAGARTIJA_TEXTO = "lagartija";

// Constantes comida (string)
const string
COMIDA_PERRO = "Huesos",
COMIDA_GATO = "Atun",
COMIDA_CABALLO = "Manzanas",
COMIDA_ROEDOR = "Queso",
COMIDA_CONEJO = "Lechuga",
COMIDA_ERIZO = "Insectos",
COMIDA_LAGARTIJA = "Insectos";


// Constantes combustible Auto
const int
MIN_COMBUSTIBLE = 0,
MAX_COMBUSTIBLE = 100;

// Constantes cargar combustible Auto
const int
CARGAR_COMBUSTIBLE_POR_ACCION = 5,
CARGAR_COMBUSTIBLE_COMPLETO =100;

// Constantes restar combustible Auto
const int
RESTAR_COMBUSTIBLE_MONTANIA = 5,
RESTAR_COMBUSTIBLE_PRECIPICIO = 40,
RESTAR_COMBUSTIBLE_CAMINO = 1,
RESTAR_COMBUSTIBLE_TIERRA = 2;

// Constantes estado animal
enum estado_animal {
    ADOPTADO,
    NO_ADOPTADO,
    FUGADO,
};

// Constantes menues
enum opciones_menu_principal {
    LISTAR_ANIMALES = 1,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMAL,
    ADOPTAR_ANIMAL,
    CARGAR_COMBUSTIBLE,
    GUARDAR_Y_SALIR,
};

const int MAX_OPCIONES_MENU_PRINCIPAL= 7;
const string
SI = "S",
NO = "N";

enum opciones_submenu {
    ELEGIR_INDIVIDUALMENTE = 1,
    REGRESAR_INICIO,
};

enum opciones_individuales {
    DUCHAR = 1,
    ALIMENTAR,
    SALTEAR_ANIMAL,
    VOLVER_INICIO,
};

// Constantes Arbol B
const int GRADO = 3;
const int TRES_VIAS = 3;

// Constantes nodo de Arbol B
const int 
PRIMERA_CLAVE = 0,
PRIMER_HIJO = 0,
SEGUNDO_HIJO = 1,
PRIMER_DATO = 0;

#endif 