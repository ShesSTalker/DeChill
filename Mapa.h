#ifndef MAPA_H
#define MAPA_H
#include "Casilla.h"


class Mapa
{
    //Atributos
    private:
    Casilla** tablero;
    int filas;
    int columnas;

    //Metodos
    public:
    //PRE: -
    //POS: crea un objeto Mapa e incializa los atributos
    Mapa();

    //PRE: -
    //POS: devuelve el atributo filas
    int obtener_filas();

    //PRE: -
    //POS: devuelve el atributo columnas
    int obtener_columnas();

    //PRE: -
    //POS: devuelve el atributo tablero
    Casilla **obtener_tablero();

    //PRE: -
    //POS: establece un nuevo valor al atributo filas
    void establecer_filas(int filas);

    //PRE: -
    //POS: establece un nuevo valor al atributo columnas
    void establecer_columnas(int columnas);

    //PRE: -    
    //POS: inicializa las dimensiones del tablero 
    void inicializar_tablero();

    //PRE: -
    //POS: carga la casilla al mapa
    void cargar_casilla(int fila,int columna,string vertice,string terreno);
    
    //PRE: -
    //POS: libera la memoria asociada con este objeto.
    ~Mapa();
};

#endif