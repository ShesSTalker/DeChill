#ifndef FLOYD_H
#define FLOYD_H

using namespace std;

#include "Vector.h"
#include <string>
#include <iostream>

class Floyd {
    //Atributos
    private:
        int** matriz_costos;
        int** matriz_caminos;
        int** matriz_adyacencia;
        Vector<string>* vertices;
        int cantidad_vertices;

    //Metodos
        //PRE: matriz de adyacencia bien cargada
        //POS: crea la matriz costo inicializandola con los valores de la matriz de adyacencia
        int** crear_matriz_costos(int** matrizAdyacencia);

        //PRE: -
        //POS: crea una matriz de caminos
        int** crear_matriz_caminos();
        
        //PRE: -
        //POS: libera la memoria de las matrices utilizadas
        void liberar_matrices();

        //PRE: -
        //POS:calcula las matrices de costos y caminos.
        void calcular_matrices();

    public:
    
        //PRE: -
        //PRE: inicializa los vertices y matrices.
        Floyd(Vector<string>*vertices, int** matrizAdyacencia);

        //PRE: -
        //POS: muestra por pantalla el camino mínimo entre el origen y el destino, detallando su recorrido y peso
        void camino_minimo(int origen, int destino);

        //PRE: la matriz de costos debe estar calculada
        //POS: devuelve el costo del camino
        int obtener_costo_camino(int origen, int destino);

        ~Floyd();
};

#endif //FLOYD_H
