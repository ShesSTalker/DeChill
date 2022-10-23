#include <iostream>
#include "Menu.h"
#include "Constantes.h"

using namespace std;

Menu::Menu(Lista<Animal *> * mis_animales)
{
    opcion_tomada = 0;
    animales = mis_animales;
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

    if (opcion_tomada < 0 || opcion_tomada > GUARDAR_Y_SALIR)
    {
        cout << "La opcion tomada no es valida, ingrese una opcion valida: ";
        cin >> opcion_tomada;
    }

    this -> opcion_tomada = opcion_tomada;
}

void Menu::procesar_opcion()
{
    switch (opcion_tomada)
    {
        case MOSTRAR_MENU: Menu::mostrar_menu();
        break;

        case LISTAR_ANIMALES: Menu::listar_animales();
        break;

        case RESCATAR_ANIMALES:
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

void Menu::listar_animales()
{
    for(int i = 0; i < animales->cuantos_tiene(); i++)
    {
        animales->consulta(i)->obtener_nombre();
    }
}

void listar_animal(Animal *mi_animal)
{
    string sep = ", ";

    cout << mi_animal->obtener_nombre() << sep
         << mi_animal->obtener_edad() << " años" << sep
         << mi_animal->obtener_tamanio_texto() << sep
         << mi_animal->obtener_especie_texto() << sep
         << mi_animal->obtener_personalidad_texto() << sep
         << mi_animal->obtener_hambre() << " puntos de hambre" << sep 
         << mi_animal->obtener_higiene() << " puntos de higiene " << endl;
}
