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