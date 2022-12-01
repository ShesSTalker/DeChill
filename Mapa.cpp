#include "Mapa.h"
#include <iostream>

using namespace std;


Mapa::Mapa()
{
    tablero= nullptr;
    filas=0;
    columnas=0;
}

int Mapa::obtener_filas()
{
    return filas;
}

int Mapa::obtener_columnas()
{
    return columnas;
}

Casilla **Mapa::obtener_tablero()
{
    return tablero;
}

void Mapa::establecer_filas(int filas)
{
    this->filas=filas;
}

void Mapa::establecer_columnas(int columnas)
{
    this->columnas=columnas;
}

void Mapa::inicializar_tablero(){

    tablero = new Casilla*[obtener_filas()]();

    for (int i =0 ; i < obtener_filas(); i++){

        tablero[i]= new Casilla[obtener_columnas()]();

    }
}

void Mapa::cargar_casilla(int fila,int columna,string vertice,string terreno){
    
    if(terreno==TIERRA){

        tablero[fila][columna]= Casilla (vertice, TIERRA, RESTAR_COMBUSTIBLE_TIERRA, VACIO);

    }else if (terreno== PRECIPICIO){

        tablero[fila][columna]= Casilla (vertice, PRECIPICIO, RESTAR_COMBUSTIBLE_PRECIPICIO, VACIO);

    }else if (terreno== MONTANIA){ 

        tablero[fila][columna]= Casilla (vertice, MONTANIA, RESTAR_COMBUSTIBLE_MONTANIA, VACIO);

    }else{

        tablero[fila][columna]= Casilla (vertice, CAMINO, RESTAR_COMBUSTIBLE_CAMINO, VACIO);
    }
}

Mapa ::~Mapa(){
    for (int i =0 ; i < this->filas; i++){
        delete []tablero[i];
    }
    delete [] tablero;
}