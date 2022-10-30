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
    int posicion, opcion_submenu, espacio;

    switch (opcion_tomada)
    {
        case LISTAR_ANIMALES: 
        cout << endl << "LISTA DE ANIMALES EN LA RESERVA:" << endl << endl;
        pasar_tiempo();
        listar_animales(animales);
        break;

        case RESCATAR_ANIMAL: 
        cout << endl << "RESCATAR ANIMAL:" << endl << endl;
        pasar_tiempo();
        pedir_nombre(nombre);
        posicion = buscar_nombre(nombre);
        verificar_nombre(posicion, nombre);
        break;

        case BUSCAR_ANIMAL:
        cout << endl << "BUSCAR ANIMAL DE LA RESERVA:" << endl << endl;
        pasar_tiempo();
        pedir_nombre(nombre);
        posicion = buscar_nombre(nombre);
        if (posicion != NULO)
        {
            mostrar_animal(animales -> consulta(posicion));
        }
        else
        {
            cout << endl << "ERROR, no se pudo encontrar el nombre ingresado" << endl << endl;
        }
        break;

        case CUIDAR_ANIMAL:
        cout << endl << "CUIDAR ANIMALES:" << endl << endl;
        pasar_tiempo();
        while (opcion_submenu != REGRESAR_INICIO)
        {
            mostrar_submenu();
            ingresar_opcion_submenu(opcion_submenu); 
            procesar_opcion_submenu(opcion_submenu);
        }
        break;

        case ADOPTAR_ANIMAL:
        cout << endl << "ADOPTAR ANIMAL:" << endl << endl;
        pasar_tiempo();
        pedir_espacio(espacio);
        break;
    }
}

void Sistema::pasar_tiempo()
{
    Animal* animal;

    while (animales -> hay_siguiente())
    {
        animal = animales -> siguiente();
        
        if (animal -> requiere_ducha())
        {
            animal -> dearmar_higiene();
        }
        animal -> aumentar_hambre();
    }
    animales -> iniciar();
}

void Sistema::listar_animales(Lista<Animal*>* animales)
{

    while (animales -> hay_siguiente())
    { 
        mostrar_animal(animales -> siguiente());
    }
    animales -> iniciar();
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

void Sistema:: verificar_nombre(int posicion, string nombre)
{
    int desicion;

    if (posicion != NULO)
        {
            cout << " El nombre ingresado ya existe en la reserva" << endl <<
            "Ingrese (1) si desea ingresar otro nombre, si desea volver al menu principal ingrese cualquier otro numero: ";
            cin >> desicion;
            if (desicion == 1)
            {
                procesar_opcion(RESCATAR_ANIMAL);
            }
        }
    else
    {
        rescatar_animal(nombre);
    }
    
}

void Sistema::rescatar_animal(string nombre)
{

}

void Sistema::mostrar_submenu()
{
    cout << "1) Elegir individualmente." << endl <<
    "2) Alimentar a todos." << 
    "3) Duchar a todos." <<
    "4) Regresar al inicio." << endl << endl;
}

void Sistema::ingresar_opcion_submenu(int &opcion_submenu)
{
    cout << "Ingrese el numero de la opcion que desa ejecutar: " << endl;
    cin >> opcion_submenu;

    while (opcion_submenu <= 0 &&  opcion_submenu > REGRESAR_INICIO)
    {
        cout << "opcion invalida, ingrese el numero de la opcion que desa ejecutar: " << endl;
        cin >> opcion_submenu;
    }
}

void Sistema::procesar_opcion_submenu(int opcion_submenu)
{
    switch(opcion_submenu)
    {
        case ELEGIR_INDIVIDUALMENTE:
        eleccion_individual();
        break;

        case ALIMENTAR_A_TODOS:
        alimentar_todos();
        cout << "se ha alimentado a todos los animales con exito." << endl << endl;
        break;

        case DUCHAR_A_TODOS:
        duchar_todos();
        cout << "se ha duchado a todos los animales con exito." << endl << endl;
        break;
    }
}

void Sistema::opciones_individuales(int &opcion_individual)
{
    cout << "1) Duchar." << endl <<
    "2) Alimentar." << endl << 
    "3) Saltear animal" << endl << endl <<
    "Ingrese la opcion a ejecutar: ";
    cin >> opcion_individual;

    while (opcion_individual <= 0 && opcion_individual > SALTEAR_ANIMAL)
    {
        cout << "Opcion invalida, ingrese la opcion a ejecutar: ";
        cin >> opcion_individual;
    }

}

void Sistema::procesar_opcion_indivual(int opcion_individual, Animal * animal)
{
    switch (opcion_individual)
    {
        case DUCHAR:
        if (animal -> requiere_ducha())
        {
            animal -> duchar();
        }
        else 
        {
           cout << animal -> obtener_nombre() << " no necesita ducharse porque es un/a " << animal -> obtener_especie_texto() << endl; 
        }
        break;

        case ALIMENTAR:
        animal -> alimentar();
        cout << animal -> obtener_nombre() << " ha sido alimentado";
        break;
    }
}

void Sistema::eleccion_individual()
{
    Animal * animal;
    int opcion_individual;

    while(animales ->hay_siguiente())
    {
        animal = animales -> siguiente ();
        mostrar_animal(animal);
        opciones_individuales(opcion_individual);
        
        if (opcion_individual != SALTEAR_ANIMAL)
        {
            procesar_opcion_indivual(opcion_individual, animal);
        }
    }
    animales -> iniciar();
}

void Sistema::alimentar_todos()
{
    Animal * animal;
    
    while (animales -> hay_siguiente())
    {
        animal = animales -> siguiente();
        animal -> alimentar();
    }
    animales -> iniciar();
}

void Sistema::duchar_todos()
{
    Animal * animal;

    while (animales -> hay_siguiente())
    {
        animal = animales -> siguiente();
        
        if (animal -> requiere_ducha())
        {
            animal -> duchar();
        }
        else
        {
            cout << animal -> obtener_nombre() << " no necesita ducharse porque es un/a " << animal -> obtener_especie_texto() << endl;
        }
    }
    animales -> iniciar();
}

void Sistema::pedir_espacio(int &espacio)
{
    cout << "Ingrese el espacio disponible para el animal (mayor a 0): ";
    cin >> espacio;

    while (espacio < 0)
    {
        cout << "Espacio invalido, ingrese el espacio disponible para el animal: ";
        cin >> espacio;
    }
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