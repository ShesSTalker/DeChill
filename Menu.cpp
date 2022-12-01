#include <iostream>
#include <cctype>

#include "Menu.h"

using namespace std;

Menu::Menu()
{
    opcion_tomada = 0;
}

void Menu::bienvenida()
{
    cout << "¡Bienvenidos a la Reserva DeChill!" << endl << endl;
}

void Menu::mostrar_menu()
{
    cout << endl << endl <<
    "--------MENU--------"<< endl <<
    "[1] Listar animales." << endl <<
    "[2] Rescatar animal." << endl <<
    "[3] Buscar animal." << endl <<
    "[4] Ciudar animales." << endl <<
    "[5] Adoptar animal." << endl <<
    "[6] Cargar combustible." << endl <<
    "[7] Guardar y salir." << endl << endl;
}

void Menu::mostrar_mapa(Casilla** mapa, int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            if (mapa[i][j].obtener_terreno()== CAMINO){

                cout<<"|" << BGND_GRAY_240 <<mapa[i][j].obtener_contenido() << END_COLOR; 

            }else if (mapa[i][j].obtener_terreno()== TIERRA){

                cout<<"|" << BGND_BROWN_136 <<mapa[i][j].obtener_contenido()<< END_COLOR; 

            }else if (mapa[i][j].obtener_terreno()== MONTANIA){

                cout<<"|" << BGND_DARK_RED_88 <<mapa[i][j].obtener_contenido()<< END_COLOR; 

            }else if (mapa[i][j].obtener_terreno()== PRECIPICIO){

                cout<<"|" << BGND_BLACK_16 <<mapa[i][j].obtener_contenido()<< END_COLOR; 

            }
        }    
        cout <<"|" <<i + 1 <<endl;
    }
}

void Menu::pedir_opcion()
{
    string opcion_tomada;
    
    cout << "Ingrese la opcion que desea ejecutar: ";
    getline(cin >>ws, opcion_tomada);

    while (!cadena_numeros_valida(opcion_tomada) || stoi(opcion_tomada) < LISTAR_ANIMALES || stoi(opcion_tomada) > MAX_OPCIONES_MENU_PRINCIPAL)
    {
        cout << "La opcion ingresada no es valida, ingrese una opcion valida: ";
        getline(cin >>ws, opcion_tomada);
    }

    this -> opcion_tomada = stoi(opcion_tomada);
}

int Menu::obtener_opcion_tomada()
{
    return opcion_tomada;
}

bool Menu::cadena_numeros_valida(string numeros)
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