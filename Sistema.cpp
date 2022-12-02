#include "Sistema.h"
#include <iostream>

using namespace std;

Sistema::Sistema()
{
    grafo= new Grafo();
    vehiculo = new Auto();
    mapa= new Mapa();
    menu = new Menu();
    arbol_b = new ArbolB<Animal>(TRES_VIAS);
    animales_fugados = 0;
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

void Sistema::cargar_mapa_grafo(){
    fstream archivo (PATH_MAPA);
    if (archivo.is_open())
    {   
        string vertice, total_filas, total_columnas, fila , columna , terreno, salto_linea;
        getline(archivo,total_filas,',');
        getline(archivo,total_columnas,';');

        mapa->establecer_filas(stoi(total_filas));
        mapa->establecer_columnas(stoi(total_columnas));
        mapa->inicializar_tablero();

        while(getline(archivo,salto_linea,'\n'))
        {   
            getline(archivo,fila,',');
            getline(archivo,columna,',');
            getline(archivo,terreno,';');
            
            vertice = fila + columna;
            mapa->cargar_casilla(stoi(fila)-1 , stoi(columna)-1 , vertice, terreno);
            grafo->agregar_vertice(vertice);
            
        }    
        cargar_caminos();
        cargar_contenido_mapa();
        grafo->usar_floyd();
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
    archivo.close();
}


void Sistema::cargar_caminos(){
    string origen;
    for (int i = 0; i < this->mapa->obtener_filas(); i++)
    {
        for (int j = 0; j < this->mapa->obtener_columnas(); j++){

            origen = mapa->obtener_tablero()[i][j].obtener_nombre();

            if (dentro_de_rango(i-1,j)){

                grafo->agregar_camino(origen, mapa->obtener_tablero()[i-1][j].obtener_nombre(), mapa->obtener_tablero()[i-1][j].obtener_costo());

            }
            if (dentro_de_rango(i+1,j)){

                grafo->agregar_camino(origen, mapa->obtener_tablero()[i+1][j].obtener_nombre(), mapa->obtener_tablero()[i+1][j].obtener_costo());

            }
            if (dentro_de_rango(i,j-1)){

                grafo->agregar_camino(origen, mapa->obtener_tablero()[i][j-1].obtener_nombre(), mapa->obtener_tablero()[i][j-1].obtener_costo());

            }
            if (dentro_de_rango(i,j+1)){

                grafo->agregar_camino(origen, mapa->obtener_tablero()[i][j+1].obtener_nombre(), mapa->obtener_tablero()[i][j+1].obtener_costo());

            }
        }
    } 
}

void Sistema::cargar_contenido_mapa(){
    int fila_animal=0, columna_animal=0, animal_random;
    mapa->obtener_tablero()[vehiculo->obtener_fila()][vehiculo->obtener_columna()].asignar_contenido(AUTO);

    for (int i = 0 ; i < ANIMALES_MAPA; i++){
        animal_random =  rand() % CANTIDAD_ESPECIES;

        do{
        fila_animal= rand() % mapa->obtener_filas();
        columna_animal= rand() % mapa->obtener_columnas();
            
        }while (mapa->obtener_tablero()[fila_animal][columna_animal].obtener_contenido() != VACIO);

        switch (animal_random)
        {
        case 0:
            mapa->obtener_tablero()[fila_animal][columna_animal].asignar_contenido(PERRO);
            break;

        case 1:
            mapa->obtener_tablero()[fila_animal][columna_animal].asignar_contenido(GATO);
            break;

        case 2:
            mapa->obtener_tablero()[fila_animal][columna_animal].asignar_contenido(CABALLO);
            break;

        case 3:
            mapa->obtener_tablero()[fila_animal][columna_animal].asignar_contenido(ROEDOR);
            break;

        case 4:
            mapa->obtener_tablero()[fila_animal][columna_animal].asignar_contenido(CONEJO);
            break;

        case 5:
            mapa->obtener_tablero()[fila_animal][columna_animal].asignar_contenido(ERIZO);
            break;

        case 6:
            mapa->obtener_tablero()[fila_animal][columna_animal].asignar_contenido(LAGARTIJA);
            break;

        }
    }
}

bool Sistema::dentro_de_rango(int fila, int columna){
    return (fila >= 0 && fila < this->mapa->obtener_filas() && columna >= 0 && columna < this->mapa->obtener_columnas());
}

void Sistema::pedir_movimiento(int &fila , int &columna){
    
    cout<<"Ingrese la fila a la cual desea moverse: "<<endl;
    cin>>fila;
    cout<<"Ingrese la columna a la cual desea moverse: "<<endl;
    cin>>columna;
     
    while (!dentro_de_rango(fila-1,columna -1))
    {
        cout << "Uno o ambos datos ingresados no son válidos, ingreselos nuevamente." << endl;
        cout << "Fila: " << endl;
        cin >> fila;
        cout << "Columna: " << endl;
        cin >> columna;
    }
    fila--;
    columna--;
}
void Sistema::procesar_movimiento(){

    int fila , columna, costo_combustible;
    string nombre, origen , destino;

    pedir_movimiento(fila , columna);

    origen= mapa->obtener_tablero()[vehiculo->obtener_fila()][vehiculo->obtener_columna()].obtener_nombre();

    destino= mapa->obtener_tablero()[fila][columna].obtener_nombre();

    costo_combustible= grafo->costo_camino( origen, destino);

    if (vehiculo->obtener_combustible() < costo_combustible){

        cout<<"Combustible insuficiente."<<endl;
        cout<< "Combustible actual: "<<vehiculo->obtener_combustible()<<endl;
        cout<<"Combustible necesario: "<< costo_combustible <<endl;

    }else{

        vehiculo->restar_combustible(costo_combustible);
        grafo->minimo_camino(origen, destino);
        cout<< "Combustible restante: "<<vehiculo->obtener_combustible()<<endl;

        mapa->obtener_tablero()[vehiculo->obtener_fila()][vehiculo->obtener_columna()].asignar_contenido(VACIO);
        
        switch (mapa->obtener_tablero()[fila][columna].obtener_contenido())
        {
        case PERRO:
            
            cout<<"Encontraste un Perro!"<<endl;

            pedir_nombre(nombre);
            rescatar_animal(nombre, PERRO);
            break;

        case GATO:
            
            cout<<"Encontraste un Gato!"<<endl;

            pedir_nombre(nombre);
            rescatar_animal(nombre, GATO);     
            break;

        case CABALLO:
            
            cout<<"Encontraste un Caballo!"<<endl;

            pedir_nombre(nombre);
            rescatar_animal(nombre, CABALLO);
            break;

        case ROEDOR:
            
            cout<<"Encontraste un Roedor!"<<endl;

            pedir_nombre(nombre);
            rescatar_animal(nombre, ROEDOR);
            break;

        case CONEJO:
            
            cout<<"Encontraste un Conejo!"<<endl;

            pedir_nombre(nombre);
            rescatar_animal(nombre, CONEJO);
            break;

        case ERIZO:
            
            cout<<"Encontraste un Erizo!"<<endl;

            pedir_nombre(nombre);
            rescatar_animal(nombre, ERIZO);   
            break;

        case LAGARTIJA:
            
            cout<<"Encontraste una Lagartija!"<<endl;
            
            pedir_nombre(nombre);
            rescatar_animal(nombre, LAGARTIJA);
            break;

        }
        vehiculo->cambiar_posicion(fila,columna);
        mapa->obtener_tablero()[vehiculo->obtener_fila()][vehiculo->obtener_columna()].asignar_contenido(AUTO);
    }
}
void Sistema::procesar_opcion(int opcion_tomada)
{

    pasar_tiempo();

    switch (opcion_tomada)
    {
        case LISTAR_ANIMALES:
            cout << "LISTAR ANIMALES:" << endl << endl;
            listar_animales();
            break;

        case RESCATAR_ANIMAL: 
        
            cout << endl << "RESCATAR ANIMAL:" << endl << endl;

            menu->mostrar_mapa(mapa->obtener_tablero() , mapa->obtener_filas() , mapa->obtener_columnas());
            procesar_movimiento();

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
            carga_de_combustible(vehiculo->obtener_combustible());
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
        cout << ++iteracion << ") ";
        animal -> mostrar_animal();
    }
}

void Sistema::listar_animales()
{
    if(arbol_b -> arbol_vacio())
    {
        cout << endl << "La reserva actualmente no tiene animales ☹️ " << endl << endl;
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

void Sistema::rescatar_animal(string nombre,char especie)
{
    string tamanio, personalidad;
    int edad;

    edad = rand() % DELIMITADOR_EDAD;

    tamanio = tamanio_animal_aleatorio (1 + (rand() % CANTIDAD_TAMANIOS));

    personalidad = personalidad_animal_aleatoria (1 + (rand() % CANTIDAD_PERSONALIDADES));

    cargar_animal(especie, nombre, edad, tamanio[0], personalidad[0]);
}

string Sistema::tamanio_animal_aleatorio(int numero)
{
    string tamanio;
    
    switch(numero)
    {
    case 1: 
        tamanio = DIMINUTO_TEXTO;
        break;

    case 2:
        tamanio = PEQUENIO_TEXTO;
        break;

    case 3:
        tamanio = MEDIANO_TEXTO;
        break;

    case 4:
        tamanio = GRANDE_TEXTO;
        break;

    case 5:
        tamanio = GIGANTE_TEXTO;
        break;
    }
    return tamanio;
}

string Sistema::personalidad_animal_aleatoria (int numero)
{
    string personalidad;
    
    switch(numero)
    {
    case 1: 
        personalidad = DORMILON_TEXTO;
        break;

    case 2:
        personalidad = JUGUETON_TEXTO;
        break;

    case 3:
        personalidad = SOCIABLE_TEXTO;
        break;

    case 4:
        personalidad = TRAVIESO_TEXTO;
        break;

    }
    return personalidad;
}

void Sistema::mostrar_submenu()
{
    cout <<
    "[1] Elegir individualmente." << endl <<
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
            elegir_individualmente();
            break;
    }
}

bool interactuar_individualmente(Sistema* sistema, Animal* animal)
{
    string opcion_individual;

    animal -> mostrar_animal();
    sistema -> mostrar_opciones_individuales();
    sistema -> pedir_opciones_individuales(opcion_individual);
    
    int int_opcion_individual = stoi(opcion_individual);

    if(int_opcion_individual == VOLVER_INICIO)
        return false;

    if(int_opcion_individual != SALTEAR_ANIMAL)
        sistema -> procesar_opcion_individual(int_opcion_individual, animal);

    return true;
}

void Sistema::elegir_individualmente()
{
    arbol_b -> interactuar_sistema_creciente(this, interactuar_individualmente);
}

void Sistema::mostrar_opciones_individuales()
{
    cout << 
    "[1] Duchar." << endl <<
    "[2] Alimentar." << endl <<
    "[3] Saltear animal." << endl <<
    "[4] Volver al inicio." << endl << endl;
}

void Sistema::pedir_opciones_individuales(string &opcion_individual)
{
    cout << "Ingrese la opcion a ejecutar: ";
    getline(cin >> ws, opcion_individual);

    while (!cadena_numeros_valida(opcion_individual) || stoi(opcion_individual) == 0 || stoi(opcion_individual) > VOLVER_INICIO)
    {
        cout << "Opcion invalida, ingrese la opcion a ejecutar: ";
        getline(cin >> ws, opcion_individual);
    }

    cout << endl;
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
                cout << animal -> obtener_nombre() << " no necesita ducharse porque es un/a " << animal -> obtener_especie_texto() << "." << endl; 
            }
            break;

        case ALIMENTAR:
            animal -> alimentar();
            cout << animal -> obtener_nombre() << " ha sido alimentado con " << animal -> que_come() << "." << endl;
            break;
    }
    cout << endl;
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

void Sistema::carga_de_combustible (int numero)
{
    string combustible_cargar, opcion;

    cout << "Combustible actual: " << numero << endl << endl;

    cout << "Desea cargar combustible? (S/N): ";
    cin >> opcion;

    while (opcion != SI && opcion != NO)
    {
        cout << "La opcion ingresada no es valida, ingrese nuevamente:";
        cin >> opcion;
    }

    if (opcion == SI)
    {
        cout << endl << "Ingrese la cantidad de combustible que desea cargar: ";
        cin >> combustible_cargar;

        while(!cadena_numeros_valida(combustible_cargar) || stoi(combustible_cargar) < 1 )
        {
            cout << endl <<"La cantidad de combustible ingresada es inválida, ingrese nuevamente: "<< endl;
            cin >> combustible_cargar;
        }
        
        vehiculo -> cargar_combustible(stoi(combustible_cargar));
    }
}

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
    delete vehiculo;
    delete grafo;
    delete mapa;
    delete menu;
}
