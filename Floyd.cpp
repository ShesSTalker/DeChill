#include "Floyd.h"

int ** Floyd::crear_matriz_caminos(){

    int ** caminos = new int*[cantidad_vertices];
    for(int i = 0; i < cantidad_vertices; i++){
        caminos[i] = new int[cantidad_vertices];
    }

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++) {
            caminos[i][j] = j;
        }
    }

    return caminos;
}

int ** Floyd::crear_matriz_costos(int ** matriz_adyacencia){

    int ** costos = new int*[cantidad_vertices];
    for(int i = 0; i < cantidad_vertices; i++){
        costos[i] = new int[cantidad_vertices];
    }

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++){
            costos[i][j] = matriz_adyacencia[i][j];
        }
    }
    return costos;
}

void Floyd::mostrar_matrices(){
    int i,j;
    for (i = 0; i < cantidad_vertices; i++)
    {
        cout<<"\nMinimo Costo Respecto de :"<<i<<endl;
        for (j = 0; j < cantidad_vertices; j++)
        {
            cout<<matriz_costos[i][j]<<"\t";
        }

    }
}

void Floyd::calcular_matrices() {

    cantidad_vertices = vertices -> obtener_longitud();
    matriz_costos = crear_matriz_costos(matriz_adyacencia);
    matriz_caminos = crear_matriz_caminos();

    int i,j,k;
    for (k = 0; k < cantidad_vertices; k++)
    {
        for (i = 0; i < cantidad_vertices; i++)
        {
            for (j = 0; j < cantidad_vertices; j++)
            {
                if ((matriz_costos[i][k] * matriz_costos[k][j] != 0) && (i != j))
                {
                    if ((matriz_costos[i][k] + matriz_costos[k][j] < matriz_costos[i][j]) || (matriz_costos[i][j] == 0))
                    {
                        matriz_costos[i][j] = matriz_costos[i][k] + matriz_costos[k][j];
                    }
                }
            }
        }
    }
    mostrar_matrices();
}

void Floyd::camino_minimo(int origen, int destino) {

    if(matriz_caminos[origen][destino] == NO_ENCONTRO){
        cout << "No hay un camino que conecte " <<  vertices->obtener_elemento(origen + 1) << " con " << vertices->obtener_elemento(destino + 1);
    } else {
        cout << "El camino minimo que une " <<  vertices->obtener_elemento(origen + 1) << " con " << vertices->obtener_elemento(destino + 1);
        cout << " tiene un costo de: " << matriz_costos[origen][destino] << " y es el siguiente: ";
        cout << vertices->obtener_elemento(origen + 1);
        do {
            origen = matriz_caminos[origen][destino];
            cout << " -> " << vertices->obtener_elemento(origen + 1);
        } while(origen != destino);
    }
    cout << endl;

}

void Floyd::liberar_matrices() {
    if(matriz_costos != nullptr && matriz_caminos != nullptr){
        for(int i = 0; i < cantidad_vertices; i++){
            delete[] matriz_costos[i];
            delete[] matriz_caminos[i];
        }
        delete[] matriz_costos;
        delete[] matriz_caminos;

        matriz_costos = nullptr;
        matriz_caminos = nullptr;
    }
}

Floyd::~Floyd(){
    liberar_matrices();
}
Floyd::Floyd(Vector<string> *vertices, int ** matriz_adyacencia) {
    this -> vertices = vertices;
    this -> matriz_adyacencia = matriz_adyacencia;
    cantidad_vertices = vertices -> obtener_longitud();  
    calcular_matrices();
}
