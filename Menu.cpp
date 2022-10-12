#include <iostream>
#include "Menu.h"

using namespace std;

void Menu::bienvenida()
{
    cout << "Bienvenidos a la Reserva DeChill" << endl << endl;
}

void Menu::mostrar_menu()
{
    cout <<"--------MENU--------"<< endl <<
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

    this -> opcion_tomada = opcion_tomada;
}