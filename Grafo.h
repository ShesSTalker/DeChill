#ifndef GRAFO_H
#define GRAFO_H
#include <string>
#include "Vector.h"
#include "Floyd.h"
using namespace std;

class Grafo {
    //Atributos
    private:
    int ** matriz_de_adyacencia;
    Vector<string>* vertices;
    Floyd * minimo_camino;

    //Metodos

    //PRE: tienen que existir tanto el origen como el destino. Ademas se deben haber calculado las matrices de Floyd
    //POS: muestra el camino minimo entre el origen y el destino
    void camino_minimo(int origen, int destino);

    //POS: agranda dinamicamente la matriz de adyacencia
    void agrandar_matriz_de_adyacencia();

    //PRE: la matriz que se le envie ya debe tener memoria reservada
    //POS: copia la matriz de adyacencia en la nueva matriz
    void copiar_matriz_adyacente(int** nueva_adyacente);

    //POS inicializa un nuevo vertice en la matriz de adyacencia con un valor de infinito
    void inicializar_nuevo_vertice(int** nueva_adyacente);

    //POS libera la memoria de la matriz de adyacencia
    void liberar_matriz_adyacencia();

    //POS: imprime por pantalla los vertices del grafo
    void mostrar_vertices();

    //POS: imprime por pantalla la matriz de adyacencia
    void mostrar_matriz_adyacencia();

    public:

    Grafo();
    //PRE: No hay vertices repetidos en nombre
    //POS: agrega un nuevo vertice al grafo
    void agregar_vertice(string nuevo_vertice);

    //PRE: se debe tener un algortimo para calcular el camino mínimo previamente elegido
    //POS: muestra por terminal el camino mínimo desde un origen a un destino
    void camino_minimo(string origen, string destino);

    //PRE: el peso es un valor positivo
    //POS: Ajusta la matriz de adyacencia con el peso ingresado
    void agregar_camino(string origen, string destino, int peso);

    //POS: imprime por pantalla el grafo
    void mostrar_grafo();

    //POS: selecciona el algortimo de Floyd para calcular el camino mínimo
    void usar_floyd();

    ~Grafo();
};


#endif //GRAFO_H
