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

}

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
                                        animal= new Perro(nombre ,stoi(edad) , tamanio[0] , personalidad[0]); 
                                        break;
                                case GATO: 
                                        animal= new Gato(nombre ,stoi(edad) , tamanio[0] , personalidad[0]);
                                        break;
                                case CABALLO:
                                        animal= new Caballo(nombre ,stoi(edad) , tamanio[0] , personalidad[0]);
                                        break;
                                case ROEDOR: 
                                        animal= new Roedor(nombre ,stoi(edad) , tamanio[0] , personalidad[0]);
                                        break;
                                case CONEJO: 
                                        animal= new Conejo(nombre ,stoi(edad) , tamanio[0] , personalidad[0]);
                                        break;
                                case ERIZO: 
                                        animal= new Erizo(nombre ,stoi(edad) , tamanio[0] , personalidad[0]);
                                        break;
                                case LAGARTIJA:
                                        animal= new Lagartija(nombre ,stoi(edad) , tamanio[0] , personalidad[0]);
                                        break;
                        }
                        animales->alta(animal, animales->obtener_cantidad());
                }
        }
        else
        {
                cout<<"No se pudo abrir el archivo"<<endl;
        }
        archivo.close();
}

void Sistema::guardar(){
        Animal * animal;
        ofstream archivo (PATH_ANIMALES);
        if (archivo.is_open()){
                for (int i = 1; i <= animales->obtener_cantidad(); i++) // de 1 a cantidad porque la lista empieza desde el elemento 1 no 0
                {
                        animal=animales->consulta(i);
                        archivo<<animal->obtener_nombre()<<","<<animal->obtener_edad()<<","<<animal->obtener_tamanio_texto()<<
                        ","<<animal->obtener_especie_texto()<<","<<animal->obtener_personalidad_texto()<<endl;
                };
                
        }else{
                cout<<"No se pudo abrir el archivo"<<endl;
        }
        archivo.close();
}