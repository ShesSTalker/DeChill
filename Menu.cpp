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
        mostrar_animal(animales->consulta(i));
    }
}

void Menu::mostrar_animal(Animal* animal)
{
    string sep = ", ";

    cout << animal->obtener_nombre() << sep
         << animal->obtener_edad() << " años" << sep
         << animal->obtener_tamanio_texto() << sep
         << animal->obtener_especie_texto() << sep
         << animal->obtener_personalidad_texto() << sep
         << animal->obtener_hambre() << " puntos de hambre" << sep 
         << animal->obtener_higiene() << " puntos de higiene" << endl;
}

void Menu::rescatar_animal()
{
    //string nombre = obtener_nombre(animales);

    Tamanios tamanio = obtener_tamanio();

    char especie = obtener_especie();

    Personalidades personalidad = obtener_personalidad();

    // Como creo la clase adecuada y la agrego a la lista?
}

/*string obtener_nombre(Lista<Animal*>* mis_animales)
{
    string nombre;

    cout << "Ingrese un nombre para su nuevo animal: " << endl;
    cin >> nombre;

    validar_nombre(nombre, mis_animales);

    return nombre;
}*/

void validar_nombre(string nombre, Lista<Animal*>* mis_animales)
{
    bool validado = true;

    for(int i = 0; i < mis_animales->obtener_cantidad(); i++)
    { // Poco eficiente
        if(nombre == mis_animales->consulta(i)->obtener_nombre())
        {
            validado = false;
            cout << "Este animal ya está en la reserva. Escoja otro nombre: " << endl;
            cin >> nombre;
            break;
        }
    }

    if(!validado)
        validar_nombre(nombre, mis_animales);
}

Tamanios obtener_tamanio()
{
    int tamanio;

    cout << "Ingrese un tamaño para su nuevo animal: " << endl <<
    "0) Diminuto (puede vivir en menos de 2m^2)" << endl <<
    "1) Pequeño (puede vivir en menos de 10m^2)" << endl <<
    "2) Mediano (puede vivir en un lugar de 10m^2 o más)" << endl <<
    "3) Grande (puede vivir en un lugar de 20m^2 o más)" << endl <<
    "4) Gigante (puede vivir en un lugar de 50m^2 o más)" << endl;
    cin >> tamanio;

    validar_tamanio(tamanio);

    return (Tamanios) tamanio;
}

void validar_tamanio(int &tamanio)
{
    while (tamanio < 0 || tamanio > MAX_TAMANIOS)
    {
        cout << "El tamaño ingresado no es válido, ingrese un tamaño válido: ";
        cin >> tamanio;
    }
}

char obtener_especie()
{
    char especie;

    cout << "Ingrese la letra correspondiente a la especie de su animal: " << endl <<
    "Perro[P]" << endl <<
    "Gato[G]" << endl <<
    "Caballo[C]" << endl <<
    "Roedor[R]" << endl <<
    "Conejo[O]" << endl <<
    "Erizo[E]" << endl <<
    "Lagartija[L]" << endl;
    cin >> especie;

    validar_especie(especie);

    return especie;
}

void validar_especie(char &especie)
{
    while (especie != PERRO || especie != GATO  || especie != CABALLO || especie != ROEDOR || 
    especie != CONEJO ||especie != ERIZO || especie !=LAGARTIJA )
    {
        cout << "La especie ingresada no es válida, ingrese una especie válida: ";
        cin >> especie;
    }
}

Personalidades obtener_personalidad()
{
    int personalidad;

    cout << "Ingrese la personalidad de su animal: " << endl <<
    "0) Dormilón" << endl <<
    "1) Juguetón" << endl <<
    "2) Sociable" << endl <<
    "3) Travieso" << endl;
    cin >> personalidad;

    validar_personalidad(personalidad);

    return (Personalidades) personalidad;
}

void validar_personalidad(int &personalidad)
{
    while(personalidad < 0 || personalidad > MAX_PERSONALIDADES)
    {
        cout << "La personalidad ingresada no es válida, ingrese una personalidad válida: ";
        cin >> personalidad;
    }
}
