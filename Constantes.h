#ifndef CONSTANTES_H
#define CONSTANTES_H
#include <iostream>
#include <string>

using namespace std;

// Constantes leer datos
const string PATH_ANIMALES = "animales.csv";

// Constantes pasar tiempo
const int
HAMBRE_INICIAL = 0,
HIGIENE_INICIAL = 100,
SUMA_HAMBRE = 10,
RESTA_HIGIENE = 10,
HAMBRE_MAX = 100,
HIGIENE_MIN = 0;

//Constantes buscar nombre
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

// Constantes comida (string)
const string
COMIDA_PERRO = "Huesos",
COMIDA_GATO = "Atun",
COMIDA_CABALLO = "Manzanas",
COMIDA_ROEDOR = "Queso",
COMIDA_CONEJO = "Lechuga",
COMIDA_ERIZO = "Insectos",
COMIDA_LAGARTIJA = "Insectos";

// Constantes adopcion
enum estado_adopcion {
    ADOPTADO,
    NO_ADOPTADO,
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

const int MAX_OPCIONES_MENU_PRINCIPAL = 7;

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

// Constantes Arbol B
enum arbol_b{
    DOS_CLAVES = 2,
    TRES_VIAS,
};

enum claves {
    PRIMERA_CLAVE,
    SEGUNDA_CLAVE,
};

enum vias{
    PRIMERA_VIA,
    SEGUNDA_VIA,
    TERCERA_VIA,
};

#endif 