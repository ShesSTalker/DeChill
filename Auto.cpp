#include "Auto.h"

Auto::Auto()
{
    combustible = CARGAR_COMBUSTIBLE_COMPLETO;
    fila= FILA_INICIAL_AUTO;
    columna = COLUMNA_INICIAL_AUTO;
}

void Auto::cargar_combustible_por_accion()
{
    combustible += CARGAR_COMBUSTIBLE_POR_ACCION;
}

{
    this->fila=fila;
    this->columna=columna;
}

int Auto::obtener_combustible()
{
    return combustible;
}

int Auto::obtener_fila()
{
    return fila;
}

int Auto::obtener_columna()
{
    return columna;
}

void Auto::cargar_combustible_completo()
{
    combustible = CARGAR_COMBUSTIBLE_COMPLETO;
}
void Auto::cargar_combustible(int combustible_cargar){
    
    combustible = +combustible_cargar;

    if(combustible > MAX_COMBUSTIBBLE){
        
        combustible = MAX_COMBUSTIBBLE;
    }

}

void Auto::restar_combustible_montania()
{
    combustible -= RESTAR_COMBUSTIBLE_MONTANIA;
}

void Auto::restar_combustible_precipicio()
{
    combustible -= RESTAR_COMBUSTIBLE_PRECIPICIO;
}

void Auto::restar_combustible_camino()
{
    combustible -= RESTAR_COMBUSTIBLE_CAMINO;
}