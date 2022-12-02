#include "Sistema.h"
#include <iostream>
#include <fstream>
#include "Constantes.h"
#include "Perro.h"
#include "Caballo.h"
#include "Gato.h"
#include "Lagartija.h"
#include "Erizo.h"
#include "Roedor.h"
#include "Conejo.h"
#include "Lista.h"
#include "Auto.h"
#include "Arbol.h"

using namespace std;

Sistema::Sistema()
{
    arbol_b = new ArbolB<Animal>(TRES_VIAS);
    animales_fugados = 0;
    //punteros_animales = new Vector<Animal*>;
    //vehiculo = new Auto;
    //grafo= new Grafo();
    //mapa= nullptr;
    //filas=0;
    //columnas=0;
}

int Sistema::obtener_animales_fugados()
{
    return animales_fugados;
}

void Sistema::leer_animales()
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

            if(tamanio == GIGANTE_TEXTO)
            {
                tamanio[0] = GIGANTE;
            }

            cargar_animal(especie[0], nombre, stoi(edad), tamanio[0], personalidad[0]);
        }
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
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

    arbol_b -> insertar(animal -> obtener_nombre(), animal);
}

/*void Sistema::cargar_mapa_grafo(){
    fstream archivo (PATH_MAPA);
    if (archivo.is_open())
    {   
        string vertice, total_filas, total_columnas, fila , columna , terreno, salto_linea;
        getline(archivo,total_filas,',');
        getline(archivo,total_columnas,',');
        getline(archivo,terreno,';');

        filas= stoi(total_filas);
        columnas= stoi(total_columnas);

        inicializar_mapa();

        while(getline(archivo,salto_linea,'\n'))
        {   
            getline(archivo,fila,',');
            getline(archivo,columna,',');
            getline(archivo,terreno,';');
            
            vertice = fila + columna;
            cargar_casilla(stoi(fila)-1 , stoi(columna)-1 , vertice, terreno);
            grafo->agregar_vertice(vertice);
            
        }
        
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();
}

void Sistema::inicializar_mapa(){

    mapa = new Casilla*[filas]();

    for (int i =0 ; i < filas; i++){

        mapa[i]= new Casilla[columnas]();

    }
}

void Sistema::cargar_casilla(int fila,int columna,string vertice,string terreno){
    if(terreno==TIERRA){

        mapa[fila][columna]= Casilla (vertice, TIERRA, RESTAR_COMBUSTIBLE_TIERRA, VACIO);

    }else if (terreno== PRECIPICIO){

        mapa[fila][columna]= Casilla (vertice, PRECIPICIO, RESTAR_COMBUSTIBLE_PRECIPICIO, VACIO);

    }else if (terreno== MONTANIA){ 

        mapa[fila][columna]= Casilla (vertice, MONTANIA, RESTAR_COMBUSTIBLE_MONTANIA, VACIO);

    }else{

        mapa[fila][columna]= Casilla (vertice, CAMINO, RESTAR_COMBUSTIBLE_CAMINO, VACIO);
    }
}

void Sistema::cargar_caminos(){
    string origen;
    for (int i = 0; i < this->filas; i++)
    {
        for (int j = 0; j < this->columnas; j++){
            origen = mapa[i][j].obtener_nombre();

            if (dentro_de_rango(i-1,j)){
                grafo->agregar_camino(origen, mapa[i-1][j].obtener_nombre(), mapa[i-1][j].obtener_costo() );
            }
            if (dentro_de_rango(i+1,j)){
                grafo->agregar_camino(origen, mapa[i+1][j].obtener_nombre(), mapa[i+1][j].obtener_costo());
            }
            if (dentro_de_rango(i,j-1)){
                grafo->agregar_camino(origen, mapa[i][j-1].obtener_nombre(), mapa[i][j-1].obtener_costo());
            }
            if (dentro_de_rango(i,j+1)){
                grafo->agregar_camino(origen, mapa[i][j+1].obtener_nombre(), mapa[i][j+1].obtener_costo());
            }
        }
    } 
}

bool Sistema::dentro_de_rango(int fila, int columna){
    return (fila >= 0 && fila < this->filas && columna >= 0 && columna < this->columnas);
}*/

void Sistema::procesar_opcion(int opcion_tomada)
{   
    /*cargar_caminos();
    grafo->usar_floyd();
    grafo->mostrar_grafo();

    for (int i = 0; i < this->filas; i++){
        for (int j = 0; j < this->columnas; j++){
            cout <<mapa[i][j].obtener_terreno_char();
        }
        cout<<endl;
    }
   
    string nombre, espacio, opcion_submenu, posicion_adopcion;
    int posicion, animales_validados;
    bool volver_a_intentar = false;*/

    pasar_tiempo();

    switch (opcion_tomada)
    {
        case LISTAR_ANIMALES:
            cout << "LISTAR ANIMALES:" << endl << endl;
            listar_animales();
            break;

        case RESCATAR_ANIMAL: 
            cout << endl << "RESCATAR ANIMAL:" << endl << endl;

            break;

        case BUSCAR_ANIMAL:
            buscar_animal();
            break;

        case CUIDAR_ANIMAL:
            cout << endl << "CUIDAR ANIMAL:" << endl << endl;
            cuidar_animal();
            break;

        case ADOPTAR_ANIMAL:
            cout << endl << "ADOPTAR ANIMAL:" << endl << endl;

            break;
        
        case CARGAR_COMBUSTIBLE:
            cout << endl << "CARGAR_COMBUSTIBLE:" << endl << endl;

            break;
    }
}

void recorrido_pasar_tiempo(Animal* animal)
{
    if (animal -> requiere_ducha())
        {
            animal -> dearmar_higiene();
        }
        animal -> aumentar_hambre();

    if(animal -> obtener_higiene() == HIGIENE_MIN || animal -> obtener_hambre() == HAMBRE_MAX)
    {
        animal -> cambiar_estado_animal(FUGADO);
        cout << "Oh no! " << animal -> obtener_nombre() << " se ha fugado de la reserva :(" << endl << endl;
    }
}

void Sistema::pasar_tiempo()
{
    arbol_b -> recorrer_creciente(recorrido_pasar_tiempo);
}

void Sistema::limpiar_pantalla()
{
    #ifdef _WIN32
            system("cls");
    #else
            system ("clear");
    #endif
}

void mostrar_animal(Animal* animal, int &iteracion)
{
    if(animal -> obtener_estado_animal() == NO_ADOPTADO)
    {
        cout <<
        ++iteracion << ") " << animal -> obtener_nombre() << endl <<
        "Edad: " << animal -> obtener_edad() << endl <<
        "Tamanio: " << animal -> obtener_tamanio_texto() << endl <<
        "Especie: " << animal -> obtener_especie_texto() << endl <<
        "Personalidad: " << animal -> obtener_personalidad_texto() << endl <<
        "Hambre: " << animal -> obtener_hambre() << endl <<
        "Higiene: " << animal -> obtener_higiene() << endl << endl <<
        "---------------------------------------------------" << endl << endl;
    }
}

void Sistema::listar_animales()
{
    if(arbol_b -> arbol_vacio())
    {
        cout << endl << "La reserva actualmente no tiene animales :( " << endl << endl;
    }
    else
    {
        arbol_b -> listar_creciente(mostrar_animal);
    }
}

void Sistema::buscar_animal()
{
    string nombre;
    Animal* animal;

    pedir_nombre(nombre);
    animal = buscar_nombre(nombre);
    mostrar_busqueda(animal);
}

void Sistema::pedir_nombre(string &nombre)
{
    cout << "Ingrese el nombre del animal: ";
    getline (cin >> ws, nombre);
}

Animal* Sistema::buscar_nombre(string nombre)
{
    Animal* animal;

    animal = arbol_b -> buscar_clave(nombre);

    return animal;
}

void Sistema::mostrar_busqueda(Animal* animal)
{
    if(animal == NULL)
    {
        cout << endl << "No se pudo encontrar el nombre en la reserva." << endl;
    }
    else
    {
        cout << "Datos del animal: " << endl;
        animal -> mostrar_animal();
    }
}

void Sistema::cuidar_animal()
{
    string opcion_submenu;

    mostrar_submenu();
    ingresar_opcion_submenu(opcion_submenu);
    procesar_opcion_submenu(opcion_submenu);
}

/*bool Sistema::verificar_intentar_de_nuevo(int posicion, string nombre)
{
    string decision;

    cout << "El nombre ingresado ya existe en la reserva." << endl <<
    "Ingrese [1] si desea ingresar otro nombre, si desea volver al menu principal ingrese cualquier otro numero: ";      
        
    getline(cin >> ws, decision);

    while (!cadena_numeros_valida(decision))
    {
        cout << endl << "Decision invalida, ingrese un numero para su decision: ";
        getline(cin >> ws, decision);
    }
    
    if (stoi(decision) == 1)
        return true;

    return false;
}

void Sistema::rescatar_animal(string nombre)
{
    string edad, especie, tamanio, personalidad;

    cout << endl << "- P (Perro)" << endl << "- G (Gato)" << endl << "- C (Caballo)" << endl << "- R (Roedor)" << endl << "- O (Conejo)" <<
    endl << "- E (Erizo)" << endl << "- L (Lagartija)" << endl << "Ingrese el caracter la especie del animal: ";
    getline(cin >> ws, especie);

    while ((especie[0] != PERRO && especie[0] != GATO && especie[0] != CABALLO && especie[0] != ROEDOR && especie[0] != CONEJO && especie[0] != ERIZO && especie[0] != LAGARTIJA) || especie.size() != 1)
    {
        cout << endl << "- P (Perro)" << endl << "- G (Gato)" << endl << "- C (Caballo)" << endl << "- R (Roedor)" << endl << "- O (Conejo)" <<
        endl << "- E (Erizo)" << endl << "- L (Lagartija)" << endl << "Especie invalida, Ingrese el caracter la especie del animal: ";
        getline(cin >> ws, especie);
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
    getline(cin >> ws, tamanio);

    while ((tamanio[0] != DIMINUTO && tamanio[0] != PEQUENIO && tamanio[0] != MEDIANO && tamanio[0] != GRANDE && tamanio[0] != GIGANTE) || tamanio.size() != 1)
    {
        cout << endl << "- d (diminuto)" << endl << "- p (pequenio)" << endl << "- m (mediano)" << endl << "- g (grande)" << endl << "- t (gigante)"  <<endl<<
        "Tamanio invalido, ingrese el caracter del tamanio del animal: ";
        getline(cin >> ws, tamanio);
    }

    cout << endl << "- d (dormilon)" << endl << "- j (jugueton)" << endl << "- s (sociable)" << endl << "- t (travieso)" << endl << 
    "Ingrese el caracter de la personalidad del animal: ";
    getline(cin >> ws, personalidad);

    while ((personalidad[0] != DORMILON && personalidad[0] != JUGUETON && personalidad[0] != SOCIABLE && personalidad[0] != TRAVIESO) || personalidad.size() != 1)
    {
        cout << endl << "- d (dormilon)" << endl << "- j (jugueton)" << endl << "- s (sociable)" << endl << "- t (travieso)" << endl << 
        "Personalidad invalida, ingrese el caracter de la personalidad del animal: ";
        getline(cin >> ws, personalidad);
    }

    cargar_animal(especie[0], nombre, stoi(edad), tamanio[0], personalidad[0]);
}*/

void Sistema::mostrar_submenu()
{
    cout << "[1] Elegir individualmente." << endl <<
    "[2] Regresar al inicio." << endl << endl;
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
            break;
    }
}

void Sistema::elegir_individualmente()
{
    string opcion_individual;


}

void Sistema::mostrar_opciones_individuales()
{
    cout << "[1] Duchar." << endl <<
    "[2] Alimentar." << endl << 
    "[3] Saltear animal." << endl <<
    "[4]volver al inicio." << endl << endl;
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
            cout << animal -> obtener_nombre() << " ha sido alimentado con " << animal -> que_come() << endl;
            break;
    }
}

/*void Sistema::eleccion_individual()
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
}*/

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

/*void Sistema::mostrar_animal_espacio(Animal* animal, int posicion)
{
    cout << posicion << ") " << "Nombre: " << animal -> obtener_nombre() << endl <<
    "Edad: " << animal -> obtener_edad() << endl <<
    "Especie: " << animal -> obtener_especie_texto() << endl <<
    "Personalidad: " << animal -> obtener_personalidad_texto() << endl;
}

void Sistema::validar_animales_espacio(Animal* animal, string espacio, int posicion, bool* animales_validos, int &contador_validos)
{
    char tamanio = animal -> obtener_tamanio_caracter();
    contador_validos = 0;

    int espacio_int = stoi(espacio);
    
    if (espacio_int < DELIMITADOR_DIMINUTO)
    {
        if (tamanio == DIMINUTO)
        {
            mostrar_animal_espacio(animal, posicion);
            animales_validos[posicion - 1] = true;
            contador_validos++;
        }
        else
            animales_validos[posicion - 1] = false;
    } 

    else

    if (espacio_int < DELIMITADOR_PEQUENIO_MEDIANO)
    {
        if (tamanio == DIMINUTO || tamanio == PEQUENIO)
        {
            mostrar_animal_espacio(animal, posicion);
            animales_validos[posicion - 1] = true;
            contador_validos++;
        }
        else
            animales_validos[posicion - 1] = false;
    }

    else 

    if (espacio_int < DELIMITADOR_GRANDE) 
    {
        if (tamanio != GIGANTE && tamanio != GRANDE)
        {
            mostrar_animal_espacio(animal, posicion);
            animales_validos[posicion - 1] = true;
            contador_validos++;
        }
        else
            animales_validos[posicion - 1] = false;
    }

    else 

    if (espacio_int < DELIMITADOR_GIGANTE)
    {
        if (tamanio != GIGANTE)
        {
            mostrar_animal_espacio(animal, posicion);
            animales_validos[posicion - 1] = true;
            contador_validos++;
        }
        else
            animales_validos[posicion - 1] = false;
    }

    else

    {
        mostrar_animal_espacio(animal, posicion);
        animales_validos[posicion - 1] = true;
        contador_validos++;
    }
} 

bool Sistema::posicion_espacio_validado(int posicion, bool* animales_validos)
{
    if(posicion == -1) 
    {
        return true;
    }

    bool valido = false;

    if(posicion < animales -> obtener_cantidad() && posicion >= 0)
    {
        valido = animales_validos[posicion];
    }

    return valido;
}

string Sistema::pedir_opcion_adopcion(bool* animales_validos)
{
    string posicion_adopcion;

    cout << endl << "Ingrese el numero del animal que desea ingresar, si desea cancelar la adopcion ingrese [0]: ";
    getline(cin >> ws, posicion_adopcion);

    while (!cadena_numeros_valida(posicion_adopcion) || stoi(posicion_adopcion) > animales -> obtener_cantidad() || !posicion_espacio_validado(stoi(posicion_adopcion) -1, animales_validos))
    {
        cout << endl << "Opcion invalida, ingrese el numero del animal que desea ingresar, si desea cancelar la adopcion ingrese [0]: ";
        getline(cin >> ws, posicion_adopcion);
    }

    return posicion_adopcion;
}

void Sistema::listar_animales_espacio(string espacio, int posicion , bool* animales_validos, int &animales_validados)
{
    Animal* animal;
    int contador_validos;

    while (animales -> hay_siguiente())
    {

        animal = animales -> siguiente();
        validar_animales_espacio(animal, espacio, posicion , animales_validos, contador_validos);
        posicion++;
    }
    animales_validados = contador_validos;

    animales -> iniciar();
}*/

void guardar_animal(Animal* animal, ofstream& archivo)
{
    archivo << 
    animal -> obtener_nombre() << "," << 
    animal -> obtener_edad()<< "," << 
    animal -> obtener_tamanio_texto() << "," << 
    animal -> obtener_especie_caracter() << "," << 
    animal -> obtener_personalidad_texto() << 
    endl;
}

void Sistema::guardar()
{
    ofstream archivo (PATH_ANIMALES);
    if (archivo.is_open())
    {
        arbol_b -> guardar_creciente(archivo, guardar_animal);      
    }
    else
    {
        cout << "No se pudo abrir el archivo" << endl;
    }
    archivo.close();
}


Sistema::~Sistema()
{
    delete arbol_b;
    /*delete punteros_animales;
    delete vehiculo;
    delete grafo;
    for (int i =0 ; i < this->filas; i++){
        delete []mapa[i];
    }
    delete [] mapa;*/
}