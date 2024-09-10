#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
// matrices de 500x200 100000 elementos
// funcion para generar una matriz con filas y columnas diferentes
void generar_matriz_rectangular_aleatoria(int filas, int columnas, const string& nombre_archivo) {
    ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cout << "no se pudo abrir el archivo: " << nombre_archivo << endl;
        exit(1);
    }

    // generar la matriz rectangular con valores aleatorios
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            int valor_aleatorio = rand() % 100;  // generar un numero aleatorio entre 0 y 99
            archivo << valor_aleatorio << " ";   
        }
        archivo << endl;  
    }

    archivo.close();
    cout << "matriz rectangular guardada en " << nombre_archivo << endl;
}

int main() {
    srand(time(0)); 

    // generar una matriz de 500 x 200 y otra de 200 x 500 ambas con 10^5 elementos
    generar_matriz_rectangular_aleatoria(500, 200, "matriz1_rectangular.txt");
    generar_matriz_rectangular_aleatoria(200, 500, "matriz2_rectangular.txt");

    return 0;
}
