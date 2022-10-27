#include "Sistema.h"
#include <iostream>
#include <fstream>
#include "Constantes.h"
#include "Animal.h"
#include "Perro.h"
#include "Caballo.h"
#include "Gato.h"
#include "Lagartija.h"
#include "Erizo.h"
#include "Roedor.h"
#include "Conejo.h"

using namespace std;

void Sistema::iniciar_sistema(){

};

void Sistema::cargar_animales()
{
        fstream archivo (PATH_ANIMALES);
        if (archivo.is_open())
        {
                string nombre, edad, tamanio , especie, personalidad;
                
                while(getline(archivo,nombre, ','))
                {
                        Animal * animal;
                        getline(archivo,edad,',');
                        getline(archivo,tamanio,',');
                        getline(archivo,especie,',');
                        getline(archivo,personalidad);

                        char(especie);
                        
                        switch(especie)
                        {
                                case PERRO: 
                                        animal= new Perro(nombre ,stoi(edad) , tamanio[0] , personalidad[0], especie); 
                                        break;
                                case GATO: 
                                        animal= new Gato(nombre ,stoi(edad) , tamanio[0] , personalidad[0], especie);
                                        break;
                                case CABALLO:
                                        animal= new Caballo(nombre ,stoi(edad) , tamanio[0] , personalidad[0], especie);
                                        break;
                                case ROEDOR: 
                                        animal= new Roedor(nombre ,stoi(edad) , tamanio[0] , personalidad[0], especie);
                                        break;
                                case CONEJO: 
                                        animal= new Conejo(nombre ,stoi(edad) , tamanio[0] , personalidad[0], especie);
                                        break;
                                case ERIZO: 
                                        animal= new Erizo(nombre ,stoi(edad) , tamanio[0] , personalidad[0], especie);
                                        break;
                                case LAGARTIJA:
                                        animal= new Lagartija(nombre ,stoi(edad) , tamanio[0] , personalidad[0], especie);
                                        break;
                        }
                        animales->alta(animal, animales->obtener_cantidad());
                }
        }
        else
        {
                cout<<"No se pudo abrir el archivo"<<endl;
        }
};