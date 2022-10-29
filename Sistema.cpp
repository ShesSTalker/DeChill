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

void Sistema::leer_datos()
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

                        cargar_animal(especie, nombre, stoi(edad), tamanio[0], personalidad[0]);
                }
        }
        else
        {
                cout<<"No se pudo abrir el archivo"<<endl;
        }
        archivo.close();
}

void Sistema::cargar_animal(char especie, string nombre, int edad, char tamanio, char personalidad)
{
        Animal * animal;

        switch(especie)
        {
                case PERRO: 
                    animal = new Perro(nombre, edad, tamanio, personalidad); 
                    break;
                case GATO: 
                    animal = new Gato(nombre, edad, tamanio, personalidad);
                    break;
                case CABALLO:
                    animal = new Caballo(nombre, edad, tamanio, personalidad);
                    break;
                case ROEDOR: 
                    animal = new Roedor(nombre, edad, tamanio, personalidad);
                    break;
                case CONEJO: 
                    animal = new Conejo(nombre, edad, tamanio, personalidad);
                    break;
                case ERIZO: 
                    animal = new Erizo(nombre, edad, tamanio, personalidad);
                    break;
                case LAGARTIJA:
                    animal = new Lagartija(nombre, edad, tamanio, personalidad);
                    break;
        }
        animales->alta(animal, animales->obtener_cantidad());
}

void Sistema::procesar_opcion(int opcion_tomada)
{
    string nombre;

    switch (opcion_tomada)
    {
        case LISTAR_ANIMALES: 
        cout << endl << "LISTA DE ANIMALES EN LA RESERVA:" << endl << endl;
        pasar_tiempo();
        listar_animales(animales);
        break;

        case RESCATAR_ANIMAL: 
        pasar_tiempo();
        rescatar_animal();
        break;

        case BUSCAR_ANIMAL:
        cout << endl << "BUSCAR ANIMAL DE LA RESERVA:" << endl << endl;
        pasar_tiempo();
        pedir_nombre(nombre);
        if (buscar_nombre(nombre) != NULO)
        {
            mostrar_animal(animales -> consulta(buscar_nombre(nombre)));
        }
        else
        {
            cout << endl << "ERROR, no se pudo encontrar el nombre ingresado" << endl << endl;
        }
        break;

        case CUIDAR_ANIMAL:
        pasar_tiempo();
        break;

        case ADOPTAR_ANIMAL:
        pasar_tiempo();
        break;
    }
}

void Sistema::pasar_tiempo()
{
    Animal* animal;

    for(int i = 1; i < animales->obtener_cantidad(); i++)
    {
        animal = animales -> consulta(i);
        if (animal -> requiere_ducha())
        {
            animal -> dearmar_higiene();
        }
        animal -> aumentar_hambre();
    }
}

void Sistema::listar_animales(Lista<Animal*>* animales)
{

    for(int i = 1; i < animales->obtener_cantidad(); i++)
    { 
        mostrar_animal(animales -> consulta(i));
    }
}

void Sistema::mostrar_animal(Animal* animal)
{
    cout << "---------------------------------------------------" << endl << endl;
    cout << "Nombre: " << animal -> obtener_nombre() << endl <<
    "Edad: " << animal -> obtener_edad() << endl <<
    "Tamanio: " << animal -> obtener_tamanio() << endl <<
    "Especie: " << animal -> obtener_especie_texto() << endl <<
    "Personalidad: " << animal -> obtener_personalidad_texto() << endl <<
    "Hambre: " << animal -> obtener_hambre() << endl <<
    "Higiene: " << animal -> obtener_higiene() << endl << endl;
}

void Sistema::pedir_nombre(string &nombre)
{
    cout << "Ingrese el nombre del animal rescatado: ";
    getline (cin >> ws, nombre);
}

int Sistema::buscar_nombre(string nombre)
{
    bool encontrado = false;
    int posicion = NULO, i = 1;
    Animal* animal; 

    while (animales -> siguiente() && !encontrado)
    {
        animal = animales -> siguiente();

        if (nombre == animal -> obtener_nombre())
        {
            encontrado = true;
            posicion = i;
        }
        i++;
    }
    animales -> iniciar();
    return posicion;
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