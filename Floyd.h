#ifndef FLOYD_H
#define FLOYD_H

using namespace std;
#include "Vector.h"
#include <string>
#include <iostream>

const int INFINITO = 100000;
const int NO_ENCONTRO= -1;

class Floyd {
    //Atributos
    private:
    int ** matriz_costos;
    int ** matriz_caminos;
    int ** matriz_adyacencia;
    Vector <string> * vertices;// inicializar con 0 espacios
    int cantidad_vertices;

    //Metodos

    //PRE: matriz de adyacencia bien cargada
    //POS: crea la matriz costo inicializandola con los valores de la matriz de adyacencia
    int ** crear_matriz_costos(int ** matrizAdyacencia);

    //PRE: -
    //POS: crea una matriz de caminos
    int ** crear_matriz_caminos();
    
    //PRE: -
    //POS: libera la memoria de las matrices utilizadas
    void liberar_matrices();

    //PRE: -
    //POS: muestra la matriz de costo y de caminos.
    void mostrar_matrices();

    //PRE: -
    //POS:calcula las matrices de costos y caminos.
    void calcular_matrices();

    public:
    //PRE: -
    //PRE: inicializa primero y cursor en 0 (punteros a NULL) y cantidad en 0.
    Floyd(Vector<string>*vertices, int ** matrizAdyacencia);
    //PRE: -
    //POS: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
    void camino_minimo(int origen, int destino);


    ~Floyd() ;
};


#endif //FLOYD_H
