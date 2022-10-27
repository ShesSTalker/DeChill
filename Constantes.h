#ifndef _CONSTANTES_H_
#define _CONSTANTES_H_

const string PATH_ANIMALES("animales.csv");
const int HAMBRE_INICIAL = 0;
const int HIGIENE_INICIAL = 100;
const int PASO = 10;


const char
DIMINUTO='d',
PEQUENIO='p',
MEDIANO='m',
GRANDE='g',
GIGANTE='t';

const int MAX_TAMANIOS = 4;

const char
DORMILON='d',
JUGUETON='j',
SOCIABLE='s',
TRAVIESO='t';

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


const string
COMIDA_PERRO = "Huesos",
COMIDA_GATO = "Atun",
COMIDA_CABALLO = "Manzanas",
COMIDA_ROEDOR = "Queso",
COMIDA_CONEJO = "Lechuga",
COMIDA_ERIZO = "Insectos",
COMIDA_LAGARTIJA = "Insectos";


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