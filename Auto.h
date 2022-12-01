#ifndef _AUTO_H_
#define _AUTO_H_

#include "Constantes.h"

class Auto
{
    //Atributos 
    private:
        int combustible;
        int fila;
        int columna;

    //Metodos
    public:
        Auto();

        //PRE: Se debe ejecutar una accion del menu principal
        //POS: carga 5 de combustible 
        void cargar_combustible_por_accion();
        
        //PRE: 
        //POS: modifica la posicion del auto 
        void cambiar_posicion(int fila, int columna);

        //PRE: -
        //POS: devuelve la cantidad de combustible del auto
        int obtener_combustible();
        
        //PRE: -
        //POS: devuelve la fila
        int obtener_fila();

        //PRE: -
        //POS: devuelve la columna en la que se encuentra el auto
        int obtener_columna();

        //PRE: -
        //POS: carga la cantidad de combustible recibida
        void cargar_combustible(int combustible_cargar);

        //PRE: -
        //POS: resta la cantidad de combustible recibida
        void restar_combustible(int combustible_restar);

};

#endif