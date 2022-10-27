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
        cout << "El nombre del animal rescato ya existe." << endl;
        cout << " (M) volver al menu / (N) ingresar otro nombre:";
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

    while (i < animales -> obtener_cantidad() && !encontrado)
    {
        
    }
}

void Menu::rescatar_animal()
{
    //string nombre = obtener_nombre(animales);

    char tamanio = obtener_tamanio();

    char especie = obtener_especie();

    char personalidad = obtener_personalidad();

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

char obtener_tamanio()
{
    char tamanio;

    cout << "Ingrese un tamaño para su nuevo animal: " << endl <<
    "- Diminuto (puede vivir en menos de 2m^2)[d]" << endl <<
    "- Pequeño (puede vivir en menos de 10m^2)[p]" << endl <<
    "- Mediano (puede vivir en un lugar de 10m^2 o más)[m]" << endl <<
    "- Grande (puede vivir en un lugar de 20m^2 o más)[g]" << endl <<
    "- Gigante (puede vivir en un lugar de 50m^2 o más)[t]" << endl;
    cin >> tamanio;

    validar_tamanio(tamanio);

    return  tamanio;
}

void validar_tamanio(char &tamanio)
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
    while (especie != PERRO && especie != GATO  && especie != CABALLO && especie != ROEDOR && 
    especie != CONEJO && especie != ERIZO && especie !=LAGARTIJA )
    {
        cout << "La especie ingresada no es válida, ingrese una especie válida: ";
        cin >> especie;
    }
}

char obtener_personalidad()
{
    char personalidad;

    cout << "Ingrese la personalidad de su animal: " << endl <<
    "-Dormilón[d]" << endl <<
    "-Juguetón[j]" << endl <<
    "-Sociable[s]" << endl <<
    "-Travieso[t]" << endl;
    cin >> personalidad;

    validar_personalidad(personalidad);

    return personalidad;
}

void validar_personalidad(char &personalidad)
{
    while(personalidad != TRAVIESO && personalidad != JUGUETON && personalidad !=DORMILON && personalidad !=SOCIABLE)
    {
        cout << "La personalidad ingresada no es válida, ingrese una personalidad válida: ";
        cin >> personalidad;
    }
}
