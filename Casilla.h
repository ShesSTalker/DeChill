#ifndef CASILLA_H
#define CASILLA_H

#include "Constantes.h"

class Casilla
{   //Atributos
    private:
        string terreno;
        string nombre;
        int costo;      //el costo de pisar esa casilla
        char contenido; 


    //Metodos    
    public:
        //Constructor por defecto
        Casilla(){};
        // PRE: -
        // POS: crea un objeto Casilla e inicializa los atributos.
        Casilla(string nombre, string terreno,int costo, char contenido);

        // PRE: -
        // POS: devuelve el tipo de terreno
        string obtener_terreno();

        // PRE: -
        // POS: devuelve el contenido de la casilla
        char obtener_contenido();

        // PRE: -
        // POS: devuelve nombre de la casilla
        string obtener_nombre(); 
        
        // PRE: -
        // POS: devuelve el costo de pisar la casilla
        int obtener_costo(); 

        //Destructor virtual
        virtual ~Casilla();
};

#endif //CASILLA_H
