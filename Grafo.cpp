#include "Grafo.h"
#include <iostream>

Grafo::Grafo(){
    matriz_de_adyacencia = nullptr;
    vertices = new Vector<string>();
    floyd = nullptr;
}

void Grafo::agregar_vertice(string nuevo_vertice){
    agrandar_matriz_de_adyacencia();
    vertices -> cargar(nuevo_vertice, vertices->obtener_longitud());
}

void Grafo::mostrar_grafo(){
    mostrar_vertices();
    mostrar_matriz_adyacencia();
}

void Grafo::agregar_camino(string origen, string destino, int peso){
    int posicion_origen = vertices ->obtener_posicion(origen);
    int posicion_destino = vertices ->obtener_posicion(destino);

    if(posicion_origen == NO_ENCONTRO){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicion_destino == NO_ENCONTRO){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    if(!(posicion_destino == NO_ENCONTRO || posicion_origen == NO_ENCONTRO)) {
        matriz_de_adyacencia[posicion_origen][posicion_destino] = peso;
    }
}

void Grafo::minimo_camino(string origen, string destino){

    int posicion_origen = vertices ->obtener_posicion(origen);
    int posicion_destino = vertices ->obtener_posicion(destino);

    if(posicion_origen == NO_ENCONTRO){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicion_destino == NO_ENCONTRO){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    calcular_camino_minimo(posicion_origen, posicion_destino);
}

void Grafo::agrandar_matriz_de_adyacencia(){
    int** matriz_auxiliar;
    int nueva_cantidad_de_vertices = vertices->obtener_longitud() + 1;

    matriz_auxiliar = new int*[nueva_cantidad_de_vertices];
    for(int i = 0; i < nueva_cantidad_de_vertices; i++){
        matriz_auxiliar[i] = new int[nueva_cantidad_de_vertices];
    }

    copiar_matriz_adyacente(matriz_auxiliar);
    inicializar_nuevo_vertice(matriz_auxiliar);
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = matriz_auxiliar;
}

void Grafo::copiar_matriz_adyacente(int** nueva_adyacente){
    for(int i = 0; i < vertices -> obtener_longitud(); i++){
        for(int j = 0; j < vertices -> obtener_longitud(); j++){
            nueva_adyacente[i][j] = matriz_de_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_nuevo_vertice(int** nueva_adyacente){

    for(int i = 0; i < vertices -> obtener_longitud(); i++){
        nueva_adyacente[vertices -> obtener_longitud()][i] = INFINITO;
        nueva_adyacente[i][vertices -> obtener_longitud()] = INFINITO;
    }
    nueva_adyacente[vertices -> obtener_longitud()][vertices -> obtener_longitud()] = 0;
}

void Grafo::liberar_matriz_adyacencia(){
    for(int i = 0; i < vertices -> obtener_longitud(); i++){
        delete[] matriz_de_adyacencia[i];
    }
    delete[] matriz_de_adyacencia;
}

Grafo::~Grafo(){
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = nullptr;
    delete vertices;
    delete floyd;
}

void Grafo::mostrar_vertices(){
    cout << "Lista de vértices: [";
    for(int i = 0; i < vertices -> obtener_longitud(); i++){
        cout << vertices -> obtener_elemento(i);
        if(i + 1 != vertices -> obtener_longitud()){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Grafo::mostrar_matriz_adyacencia(){
    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < vertices -> obtener_longitud(); i++){
        for(int j = 0; j < vertices -> obtener_longitud() * 2; j++) {
            if(j == vertices -> obtener_longitud() * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matriz_de_adyacencia[i][j/2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matriz_de_adyacencia[i][j/2];
                }
            } else{
                cout << "|";
            }
        }
    }
    cout << endl;
}

void Grafo::calcular_camino_minimo(int origen, int destino){

    floyd -> camino_minimo(origen, destino);
    
}

int Grafo::costo_camino(string origen, string destino){
    int posicion_origen = vertices ->obtener_posicion(origen);
    int posicion_destino = vertices ->obtener_posicion(destino);
    int costo= floyd->obtener_costo_camino(posicion_origen,posicion_destino);

    return costo;
}

void Grafo::usar_floyd() {
    delete floyd;
    floyd = new Floyd(vertices, matriz_de_adyacencia);
}