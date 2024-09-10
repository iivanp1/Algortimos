#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
//matriz de 316x316
// funcion para generar una matriz cuadrada con valores aleatorios
void generar_matriz_cuadrada_aleatoria(int dimension, const string& nombre_archivo) {
    ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "no se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(1);
    }

    // generar la matriz cuadrada con valores aleatorios
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            int valor_aleatorio = rand() % 100;  // generar un numero aleatorio entre 0 y 99
            archivo << valor_aleatorio << " ";  
        }
        archivo << endl;  
    }

    archivo.close();
    cout << "matriz cuadrada guardada en " << nombre_archivo << endl;
}

int main() {
    srand(time(0));  // inicializar la semilla para generar numeros aleatorios

    int dimension = 316;  // dimension de la matriz cuadrada (316 x 316 = 10^5 elementos)

    // generar la primera matriz cuadrada y guardarla en "matriz1_cuadrada.txt"
    generar_matriz_cuadrada_aleatoria(dimension, "matriz1_cuadrada.txt");

    // generar la segunda matriz cuadrada y guardarla en "matriz2_cuadrada.txt"
    generar_matriz_cuadrada_aleatoria(dimension, "matriz2_cuadrada.txt");

    return 0;
}
