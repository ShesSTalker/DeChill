#include "Grafo.h"
#include <iostream>

Grafo::Grafo() {
    matriz_de_adyacencia = nullptr;
    vertices = new Vector<string>;
    Camino_minimo = nullptr;
}

void Grafo::agregar_vertice(string nuevoVertice) {
    agrandar_matriz_de_adyacencia();
    vertices -> cargar(nuevoVertice, vertices->obtener_longitud());
}

void Grafo::mostrar_grafo() {
    mostrar_vertices();
    mostrar_matriz_adyacencia();
}

void Grafo::agregar_camino(string origen, string destino, int peso) {
    int posicionOrigen = vertices ->obtener_posicion(origen);
    int posicionDestino = vertices ->obtener_posicion(destino);

    if(posicionOrigen == NO_ENCONTRO){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == NO_ENCONTRO){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    if(!(posicionDestino == NO_ENCONTRO || posicionOrigen == NO_ENCONTRO)) {
        matriz_de_adyacencia[posicionOrigen][posicionDestino] = peso;
        matriz_de_adyacencia[posicionDestino][posicionOrigen] = peso;
    }
}

void Grafo::camino_minimo(string origen, string destino) {
    int posicionOrigen = vertices ->obtener_posicion(origen);
    int posicionDestino = vertices ->obtener_posicion(destino);

    if(posicionOrigen == NO_ENCONTRO){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == NO_ENCONTRO){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    camino_minimo(posicionOrigen, posicionDestino);
}

void Grafo::agrandar_matriz_de_adyacencia() {
    int** matrizAuxiliar;
    int nuevaCantidadDeVertices = vertices->obtener_longitud() + 1;

    matrizAuxiliar = new int*[nuevaCantidadDeVertices];
    for(int i = 0; i < nuevaCantidadDeVertices; i++){
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiar_matriz_adyacente(matrizAuxiliar);
    inicializar_nuevo_vertice(matrizAuxiliar);
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = matrizAuxiliar;
}

void Grafo::copiar_matriz_adyacente(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtener_longitud(); i++){
        for(int j = 0; j < vertices -> obtener_longitud(); j++){
            nuevaAdyacente[i][j] = matriz_de_adyacencia[i][j];
        }
    }
}

void Grafo::inicializar_nuevo_vertice(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtener_longitud(); i++){
        nuevaAdyacente[vertices -> obtener_longitud()][i] = INFINITO;
        nuevaAdyacente[i][vertices -> obtener_longitud()] = INFINITO;
    }
    nuevaAdyacente[vertices -> obtener_longitud()][vertices -> obtener_longitud()] = 0;
}

void Grafo::liberar_matriz_adyacencia() {
    for(int i = 0; i < vertices -> obtener_longitud(); i++){
        delete[] matriz_de_adyacencia[i];
    }
    delete[] matriz_de_adyacencia;
}

Grafo::~Grafo() {
    liberar_matriz_adyacencia();
    matriz_de_adyacencia = nullptr;
    delete vertices;
    delete Camino_minimo;
}

void Grafo::mostrar_vertices() {
    cout << "Lista de vértices: [";
    for(int i = 0; i < vertices -> obtener_longitud(); i++){
        cout << vertices -> obtener_elemento(i + 1);
        if(i + 1 != vertices -> obtener_longitud()){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Grafo::mostrar_matriz_adyacencia() {
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

void Grafo::camino_minimo(int origen, int destino) {
    Camino_minimo -> camino_minimo(origen, destino);
}

void Grafo::usar_floyd() {
    delete Camino_minimo;
    Camino_minimo = new Floyd(vertices, matriz_de_adyacencia);
}