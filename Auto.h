#ifndef _AUTO_H_
#define _AUTO_H_

#include "Constantes.h"

class Auto
{
    //Atributos 
    private:
        int combustible;

    //Metodos
    public:
        Auto();

        //PRE: Se debe ejecutar una accion del menu principal
        //POS: carga 5 de combustible 
        void cargar_combustible_por_accion();

        //PRE: -
        //POS: devuelve la cantidad de combustible del auto
        int obtener_combustible();
        
        //PRE: -
        //POS: carga al 100 el combustible del auto
        void cargar_combustible_completo();

        //PRE: -
        //POS: resta 5 de combustible del auto
        void restar_combustible_montania();

        //PRE: -
        //POS: resta 40 de combustible del auto
        void restar_combustible_precipicio();

        //PRE: -
        //POS: resta 1 de combustible del auto
        void restar_combustible_camino();
};

#endif