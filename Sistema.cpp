#include "Sistema.h"
#include <iostream>
#include <fstream>
#include "Constantes.h"

using namespace std;
void Sistema::cargar_animales(){
        fstream archivo (PATH_ANIMALES);
        if (archivo.is_open()){
                string nombre;
                int edad;
                Tamanios tamanio;
                Especies especie;
                Personalidades personalidad;
                while(getline(archivo,nombre, ',')){
                        
                }
        }else{
                cout<<"No se pudo abrir el archivo"<<endl;
        };
};