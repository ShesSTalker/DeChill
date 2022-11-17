#include "Auto.h"

Auto::Auto()
{
    combustible = CARGAR_COMBUSTIBLE_COMPLETO;
}

void Auto::cargar_combustible_por_accion()
{
    combustible += CARGAR_COMBUSTIBLE_POR_ACCION;
}

int Auto::obtener_combustible()
{
    return combustible;
}

void Auto::cargar_combustible_completo()
{
    combustible = CARGAR_COMBUSTIBLE_COMPLETO;
}