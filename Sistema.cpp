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

Sistema::Sistema()
{
    animales = new Lista<Animal*>;
}

void Sistema::leer_datos()
{
    fstream archivo (PATH_ANIMALES);
    if (archivo.is_open())
    {
        string nombre, edad, tamanio , especie, personalidad;
        while(getline(archivo,nombre, ','))
        {
            getline(archivo,edad,',');
            getline(archivo,tamanio,',');
            getline(archivo,especie,',');
            getline(archivo,personalidad);

            cargar_animal(especie[0], nombre, stoi(edad), tamanio[0], personalidad[0]);
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
    Animal* animal;

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
    animales->alta(animal, animales -> obtener_cantidad()+1);
}

void Sistema::procesar_opcion(int opcion_tomada)
{
    string nombre, espacio, opcion_submenu, posicion_adopcion;
    int posicion;

    switch (opcion_tomada)
    {
        case LISTAR_ANIMALES: 
            cout << endl << "LISTA DE ANIMALES EN LA RESERVA:" << endl << endl;
            pasar_tiempo();
            listar_animales();
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
            mostrar_submenu();
            ingresar_opcion_submenu(opcion_submenu); 
            procesar_opcion_submenu(opcion_submenu);
            while (stoi(opcion_submenu) != REGRESAR_INICIO)
            {
                mostrar_submenu();
                ingresar_opcion_submenu(opcion_submenu); 
                procesar_opcion_submenu(opcion_submenu);
            }
            break;

        case ADOPTAR_ANIMAL:
            posicion = 1;
            cout << endl << "ADOPTAR ANIMAL:" << endl << endl;
            pasar_tiempo();
            pedir_espacio(espacio);
            listar_animales_espacio(espacio, posicion);
            posicion_adopcion = pedir_opcion_adopcion(); 
            if (stoi(posicion_adopcion) == 0)
            {
                cout << "Se ha cancelado la adopcion." << endl << endl;
            } 
            else
            {
                animales -> baja(stoi(posicion_adopcion));
                cout << "Felicidades por su adopcion." << endl << endl;
            }
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

void Sistema::listar_animales()
{
    while (animales -> hay_siguiente())
    { 
        mostrar_animal(animales -> siguiente());
    }
    animales -> iniciar();

    if (animales -> vacia())
    {
        cout << "La reserva de animales esta vacia." << endl << endl;
    }
}

void Sistema::mostrar_animal(Animal* animal)
{
    cout << "---------------------------------------------------" << endl << endl;
    cout << "Nombre: " << animal -> obtener_nombre() << endl <<
    "Edad: " << animal -> obtener_edad() << endl <<
    "Tamanio: " << animal -> obtener_tamanio_texto() << endl <<
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
    
    while (animales -> hay_siguiente() && !encontrado)
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
    string edad;
    char especie, tamanio, personalidad;

    cout << endl << "- P (Perro)" << endl << "- G (Gato)" << endl << "- C (Caballo)" << endl << "- R (Roedor)" << endl << "- O (Conejo)" <<
    endl << "- E (Erizo)" << endl << "- L (Lagartija)" << endl << "Ingrese el caracter la especie del animal: ";
    cin >> especie;

    while (especie != PERRO && especie != GATO && especie != CABALLO && especie != ROEDOR && especie != CONEJO && especie != ERIZO && especie != LAGARTIJA)
    {
        cout << endl << "- P (Perro)" << endl << "- G (Gato)" << endl << "- C (Caballo)" << endl << "- R (Roedor)" << endl << "- O (Conejo)" <<
        endl << "- E (Erizo)" << endl << "- L (Lagartija)" << endl << "Especie invalida, Ingrese el caracter la especie del animal: ";
        cin >> especie;
    }

    cout << endl << "Ingrese la edad del animal: ";
    getline(cin >> ws, edad);

    while (!cadena_numeros_valida(edad) || stoi(edad) > 100)
    {
        cout << endl << "Edad invalida, ingrese la edad del animal: ";
        getline(cin >> ws, edad);
    }

    cout << endl << "- d (diminuto)" << endl << "- p (pequeño)" << endl << "- m (mediano)" << endl << "- g (grande)" << endl << "- t (gigante)" << 
    endl << "Ingrese el caracter del tamanio del animal: ";
    cin >> tamanio;

    while (tamanio != DIMINUTO && tamanio != PEQUENIO && tamanio != MEDIANO && tamanio != GRANDE && tamanio != GIGANTE)
    {
       cout << endl << "- d (diminuto)" << endl << "- p (pequenio)" << endl << "- m (mediano)" << endl << "- g (grande)" << endl << "- t (gigante)"  <<endl<<
        "Tamanio invalido, ingrese el caracter del tamanio del animal: ";
        cin >> tamanio;
    }

    cout << endl << "- d (dormilon)" << endl << "- j (jugueton)" << endl << "- s (sociable)" << endl << "- t (travieso)" << endl << 
    "Ingrese el caracter de la personalidad del animal: ";
    cin >> personalidad;

    while (personalidad != DORMILON && personalidad != JUGUETON && personalidad != SOCIABLE && personalidad != TRAVIESO)
    {
        cout << endl << "- d (dormilon)" << endl << "- j (jugueton)" << endl << "- s (sociable)" << endl << "- t (travieso)" << endl << 
        "Personalidad invalida, ingrese el caracter de la personalidad del animal: ";
        cin >> personalidad;
    }

    cargar_animal(especie, nombre, stoi(edad), tamanio, personalidad);
}

void Sistema::mostrar_submenu()
{
    cout << "1) Elegir individualmente." << endl <<
    "2) Alimentar a todos." <<endl << 
    "3) Duchar a todos." <<endl <<
    "4) Regresar al inicio." << endl << endl;
}

void Sistema::ingresar_opcion_submenu(string &opcion_submenu)
{
    cout << "Ingrese el numero de la opcion que desa ejecutar: ";
    getline(cin >> ws, opcion_submenu);

    while (!cadena_numeros_valida(opcion_submenu) || stoi(opcion_submenu) == 0 || stoi(opcion_submenu) > REGRESAR_INICIO)
    {
        cout << "Opcion invalida, ingrese el numero de la opcion que desa ejecutar: ";
        getline(cin >> ws, opcion_submenu);
    }
}

void Sistema::procesar_opcion_submenu(string opcion_submenu)
{
    switch(stoi(opcion_submenu))
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

void Sistema::mostrar_opciones_individuales()
{
    cout << "1) Duchar." << endl <<
    "2) Alimentar." << endl << 
    "3) Saltear animal." << endl << endl;
}

void Sistema::pedir_opciones_individuales(string &opcion_individual)
{
    cout << "Ingrese la opcion a ejecutar: ";
    getline(cin >> ws, opcion_individual);

    while (!cadena_numeros_valida(opcion_individual) || stoi(opcion_individual) == 0 || stoi(opcion_individual) > SALTEAR_ANIMAL)
    {
        cout << "Opcion invalida, ingrese la opcion a ejecutar: ";
        getline(cin >> ws, opcion_individual);
    }

}

void Sistema::procesar_opcion_individual(int opcion_individual, Animal* animal)
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
            cout << animal -> obtener_nombre() << " ha sido alimentado" << endl;
            break;
    }
}

void Sistema::eleccion_individual()
{
    Animal* animal;
    string opcion_individual;

    while(animales ->hay_siguiente())
    {
        animal = animales -> siguiente ();
        mostrar_animal(animal);
        mostrar_opciones_individuales();
        pedir_opciones_individuales(opcion_individual);
        
        if (stoi(opcion_individual) != SALTEAR_ANIMAL)
        {
            procesar_opcion_individual(stoi(opcion_individual), animal);
        }
    }
    animales -> iniciar();
}

void Sistema::alimentar_todos()
{
    Animal* animal;
    
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

void Sistema::pedir_espacio(string &espacio)
{
    cout << "Ingrese el espacio disponible para el animal en m² (mayor a 0): ";
    getline(cin >> ws, espacio);

    while (!cadena_numeros_valida(espacio) || stoi(espacio) == 0)
    {
        cout << "Espacio invalido, ingrese el espacio en  m² disponible para el animal (mayor a 0): ";
        getline(cin >> ws, espacio);
    }
}

bool Sistema::cadena_numeros_valida(string numeros)
{
    int i = 0;
    long int tamanio = numeros.size();
    bool valido = true; 

    while (i < tamanio && valido)
    {
        if (!isdigit(numeros[i]))
        {
            valido = false;
        }
        i++;
    } 
    return valido;
}

void Sistema::mostrar_animal_espacio(Animal* animal, int posicion)
{
    cout << posicion << ") " << "Nombre: " << animal -> obtener_nombre() << endl <<
    "Edad: " << animal -> obtener_edad() << endl <<
    "Especie: " << animal -> obtener_especie_texto() << endl <<
    "Personalidad: " << animal -> obtener_personalidad_texto() << endl;
}

void Sistema::validar_animales_espacio(Animal* animal, string espacio, int posicion)
{
    char tamanio = animal -> obtener_tamanio_caracter();

    cout<<endl;
    if (stoi(espacio) < DELIMITADOR_DIMINUTO)
    {
        if (tamanio == DIMINUTO)
        {
            mostrar_animal_espacio(animal, posicion);
        }
    }
    else if (stoi(espacio) < DELIMITADOR_PEQUENIO_MEDIANO && stoi(espacio) >= DELIMITADOR_DIMINUTO)
    {
        if (tamanio == DIMINUTO || tamanio == PEQUENIO)
        {
            mostrar_animal_espacio(animal, posicion);
        }
    }
    else if (stoi(espacio) >= DELIMITADOR_PEQUENIO_MEDIANO && stoi(espacio) < DELIMITADOR_GRANDE) 
    {
        if (tamanio == DIMINUTO || tamanio == PEQUENIO || tamanio == MEDIANO)
        {
            mostrar_animal_espacio(animal, posicion);
        }
    }
    else if (stoi(espacio) >= DELIMITADOR_GRANDE && stoi(espacio) < DELIMITADOR_GIGANTE)
    {
        if (tamanio == DIMINUTO || tamanio == PEQUENIO || tamanio == MEDIANO || tamanio == GRANDE)
        {
            mostrar_animal_espacio(animal, posicion);
        }
    }
    else if (stoi(espacio) >= DELIMITADOR_GIGANTE)
    {
        if (tamanio == DIMINUTO || tamanio == PEQUENIO || tamanio == MEDIANO || tamanio == GRANDE || tamanio == GIGANTE)
        {
            mostrar_animal_espacio(animal, posicion);
        }
    }

} 

string Sistema::pedir_opcion_adopcion()
{
    string posicion_adopcion;

    cout << endl << "Ingrese el numero del animal que desea ingresar, si desea cancelar la adopcion ingrese 0: ";
    getline(cin >> ws, posicion_adopcion);

    while (!cadena_numeros_valida(posicion_adopcion) || stoi(posicion_adopcion) > animales -> obtener_cantidad())
    {
        cout << endl << "Opcion invalida, ingrese el numero del animal que desea ingresar, si desea cancelar la adopcion ingrese 0: ";
        getline(cin >> ws, posicion_adopcion);
    }

    return posicion_adopcion;
}

void Sistema::listar_animales_espacio(string espacio, int posicion)
{
    Animal* animal;

    while (animales -> hay_siguiente())
    {
        animal = animales -> siguiente();
        validar_animales_espacio(animal, espacio, posicion);
        posicion++;
    }

    animales -> iniciar();
}

void Sistema::guardar()
{
    Animal * animal;
    ofstream archivo (PATH_ANIMALES);
    if (archivo.is_open())
    {
        for (int i = 1; i <= animales -> obtener_cantidad(); i++)
        {
            animal = animales -> consulta(i);
            archivo << animal -> obtener_nombre() << "," << animal -> obtener_edad()<< "," << animal -> obtener_tamanio_texto() <<
            "," << animal -> obtener_especie_caracter() << "," << animal -> obtener_personalidad_texto() << endl;
        }        
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
    archivo.close();
}

Sistema::~Sistema()
{
    delete animales;    
}
