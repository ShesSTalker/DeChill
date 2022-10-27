#include <iostream>
#include <cctype>

#include "Menu.h"
#include "Constantes.h"

using namespace std;

Menu::Menu()
{
    opcion_tomada = 0;
}

void Menu::bienvenida()
{
    cout << "Bienvenidos a la Reserva DeChill" << endl << endl;
}

void Menu::mostrar_menu()
{
    cout <<"--------MENU--------"<< endl <<
    "0) Mostrar Menu" << endl <<
    "1) Listar animales." << endl <<
    "2) Rescatar animal." << endl <<
    "3) Buscar animal." << endl <<
    "4) Ciudar animales." << endl <<
    "5) Adoptar animal." << endl <<
    "6) Guardar y salir." << endl << endl; 
}

void Menu::pedir_opcion()
{
    int opcion_tomada;
    
    cout << "Ingrese la opcion que desea ejecutar: ";
    cin >> opcion_tomada;

    while (opcion_tomada < 0 || opcion_tomada > MAX_OPCIONES_MENU_PRINCIPAL)
    {
        cout << "La opcion tomada no es valida, ingrese una opcion valida: ";
        cin >> opcion_tomada;
    }

    this -> opcion_tomada = opcion_tomada;
}

int Menu::obtener_opcion_tomada()
{
    return opcion_tomada;
}

void Menu::procesar_opcion(Lista<Animal*>* animales)
{
    switch (opcion_tomada)
    {
        case LISTAR_ANIMALES: 
        listar_animales( animales);
        break;

        case RESCATAR_ANIMAL: 
        rescatar_animal();
        break;

        case BUSCAR_ANIMAL:
        break;

        case CUIDAR_ANIMAL:
        break;

        case ADOPTAR_ANIMAL:
        break;

        case GUARDAR_Y_SALIR:
        break;
    }
}

void Menu::listar_animales(Lista<Animal*>* animales)
{

    for(int i = 1; i < animales->obtener_cantidad(); i++)
    { 
        mostrar_animal(animales -> consulta(i));
    }
}

void Menu::mostrar_animal(Animal* animal)
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

void Menu::ingresar_nombre(Lista<Animal*>* animales)
{
    string nombre;
    char eleccion;

    cout << "Ingrese el nombre del animal rescatado: ";
    cin >> nombre;

    if (buscar_nombre(nombre, animales))
    {
        cout << "El nombre del animal rescatado ya existe." << endl;
        cout << " (M) volver al menu / (N) ingresar otro nombre: ";
        cin >> eleccion;
        
        while (eleccion != 'M' && eleccion != 'N')
        {
            cout << "Opcion invalida. (M) volver al menu / (N) ingresar otro nombre: ";
            cin >> eleccion;
        }
    }
}

bool Menu::buscar_nombre(string nombre, Lista<Animal*>* animales)
{
    bool encontrado = false;
    int i = 1;
    Animal* animal; 

    while (i <= animales -> obtener_cantidad() && !encontrado)
    {
        animal = animales -> consulta(i);
        
        if (nombre == animal -> obtener_nombre())
        {
            encontrado = true;
        }
        i++;
    }
    return encontrado;
}