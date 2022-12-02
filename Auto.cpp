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

void Auto::cambiar_posicion(int fila, int columna)
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

void Auto::cargar_combustible(int combustible_cargar){
    
    combustible += combustible_cargar;

    if(combustible > MAX_COMBUSTIBLE){
        
        combustible = MAX_COMBUSTIBLE;
    }

}

void Auto::restar_combustible(int combustible_restar){
    
    combustible -= combustible_restar;

    if(combustible < MIN_COMBUSTIBLE){
        
        combustible = MIN_COMBUSTIBLE;
    }

}

