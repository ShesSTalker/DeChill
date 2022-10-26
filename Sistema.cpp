#include "Sistema.h"
#include <iostream>
#include <fstream>
#include "Constantes.h"
#include "Animal.h"

using namespace std;



void Sistema::iniciar_sistema(){

};

void Sistema::cargar_animales(){
        fstream archivo (PATH_ANIMALES);
        if (archivo.is_open()){

                string nombre, edad, tamanio , especie, personalidad;
                
                while(getline(archivo,nombre, ',')){
                        Animal * animal;
                        getline(archivo,edad,',');
                        getline(archivo,tamanio,',');
                        getline(archivo,especie,',');
                        getline(archivo,personalidad);

                        char(especie);
                        switch(especie)
                        {
                                case PERRO: 
                                        animal= new Perro(nombre ,stoi(edad) , tamanio , personalidad); break;
                                case GATO: 
                                        animal= new Gato(nombre ,stoi(edad) , tamanio , personalidad);break;
                                case CABALLO:
                                        animal= new Caballo(nombre ,stoi(edad) , tamanio , personalidad);break;
                                case ROEDOR: 
                                        animal= new Roedor(nombre ,stoi(edad) , tamanio , personalidad);break;
                                case CONEJO: 
                                        animal= new Conejo(nombre ,stoi(edad) , tamanio , personalidad);break;
                                case ERIZO: 
                                        animal= new Erizo(nombre ,stoi(edad) , tamanio , personalidad);break;
                                case LAGARTIJA:
                                        animal= new Lagartija(nombre ,stoi(edad) , tamanio , personalidad);break;
                        }
                }
        }else{
                cout<<"No se pudo abrir el archivo"<<endl;
        };
};