#ifndef CONSTANTES_H
#define CONSTANTES_H
#include <iostream>
#include <string>

using namespace std;

// Constantes leer datos
const string 
PATH_ANIMALES = "animales.csv",
PATH_MAPA = "mapa.csv";


// Constantes Grafos
const int INFINITO = 100000;


// Constantes Mapa
const string 
MONTANIA = "Montania",
PRECIPICIO = "Precipicio",
TIERRA = "Tierra",
CAMINO = "Camino",
ANIMAL = "Animal";

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

// Constantes especie (string)
const string
PERRO_TEXTO = "perro",
GATO_TEXTO = "gato",
CABALLO_TEXTO = "caballo",
ROEDOR_TEXTO = "roedor",
CONEJO_TEXTO = "conejo",
ERIZO_TEXTO = "erizo",
LAGARTIJA_TEXTO = "lagartija";
const int 
CANTIDAD_ESPECIES = 7;
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
MAX_COMBUSTIBBLE = 100;
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
const char
SI= 'S',
NO= 'N';

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
const int TRES_VIAS = 3;

// Constantes nodo de Arbol B
const int PRIMERA_CLAVE = 0;

const int PRIMER_HIJO = 0,
SEGUNDO_HIJO = 1;

const int PRIMER_DATO = 0;

const int HIJO_AUXILIAR = 3; 

#endif 