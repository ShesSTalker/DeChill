#include "Sistema.h"
#include <iostream>
#include <fstream>
#include "Constantes.h"
#include "Animal.h"

using namespace std;
void Sistema::cargar_animales(){
        fstream archivo (PATH_ANIMALES);
        if (archivo.is_open()){

                string nombre, edad, tamanio , especie, personalidad;

                while(getline(archivo,nombre, ',')){
                        getline(archivo,edad,',');
                        getline(archivo,tamanio,',');
                        getline(archivo,especie,',');
                        getline(archivo,personalidad);
                        
                }
        }else{
                cout<<"No se pudo abrir el archivo"<<endl;
        };
};